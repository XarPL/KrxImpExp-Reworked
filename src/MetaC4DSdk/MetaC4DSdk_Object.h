///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Object.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 12, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static BaseObject* CopyObj(BaseObject* obj)
{
	BaseObject* obj2 = (BaseObject*) obj->GetClone(COPYFLAGS_NO_HIERARCHY|COPYFLAGS_NO_BITS, NULL);
	BaseDocument* doc = obj->GetDocument();
	doc->InsertObject(obj2, NULL, NULL, FALSE);
	return obj2;
}

static void DeleteObj(BaseObject* obj)
{
	BaseObject* parent = obj->GetUp();
	BaseDocument* doc = obj->GetDocument();
	for(BaseObject* child = obj->GetDown(); child != NULL; child = child->GetNext())
	{
		if(child != obj)
		{
			Matrix childMg = child->GetMg();
			child->Remove();
			doc->InsertObject(child, parent, NULL, FALSE);
			child->SetMg(childMg /*, FALSE */);
		}
	}
	BaseObject::Free(obj);
}

static void ReplaceObj(BaseObject* destObj, BaseObject* srcObj)
{
	if(destObj->GetType() == srcObj->GetType())
	{
		String destName = destObj->GetName();
		Matrix destMg = destObj->GetMg();
		srcObj->CopyTo(destObj, COPYFLAGS_NO_HIERARCHY | COPYFLAGS_NO_ANIMATION | COPYFLAGS_NO_BITS, NULL);
		destObj->SetMg(destMg);
		destObj->SetName(destName);
	}
}

inline void SetObjName(BaseObject* obj, const std::tstring& name)
{
	obj->SetName(name.c_str());
}

inline std::tstring GetObjName(BaseObject* obj)
{
	const String& str = obj->GetName();
	int len = str.GetCStringLen();
	std::tstring tstr(len, ' ');
	str.GetCString(&tstr[0], len + 1);
	return tstr;
}

static BaseObject* FindObjByName(const std::tstring& name, BaseObject* startObj = NULL)
{
	BaseDocument* doc = GetActiveDocument();
	if(startObj == NULL)
	{
		startObj = doc->GetFirstObject();
	}

	std::tstring tstr;
	BaseObject* obj = startObj;
	while(obj)
	{
		const String& str = obj->GetName();
		int len = str.GetCStringLen();
		tstr.reserve(len);
		str.GetCString(&tstr[0], len + 1);
		if(_tcsicmp(tstr.c_str(), name.c_str()) == 0)
			return obj;
		BaseObject* child = obj->GetDown();
		if(child)
		{
			BaseObject* obj2 = FindObjByName(name, child);
			if(obj2) return obj2;
		}
		obj = obj->GetNext();
	}
	return NULL;
}

static std::tstring UniqueNam(const std::tstring& name)
{
	std::tstring txt = name.c_str();
	for(int i = (int) txt.length() - 1; i >= 0; --i)
		if(txt[i] < '0' || txt[i] >= '9')
		{
			txt.erase(i + 1);
			break;
		}
	int idx = 0;
	std::string name2 = name;
	while(FindObjByName(name2))
	{
		++idx;
		TCHAR buf[32] = _T("0");
		TCHAR* sidx = buf + 1;
		_itot(idx, sidx, 10);
		if(_tcslen(sidx) < 2)
		{
			--sidx;
		}
		name2 = txt + sidx;
	}
	return name2;
}		
		
inline BaseObject* RootObj()
{
	return NULL;
}

inline BaseObject* GetParentObj(BaseObject* obj)
{
	return obj->GetUp();
}

inline void SetParentObj(BaseObject* obj, BaseObject* newParent)
{
	if(obj->GetUp() != newParent)
	{
		BaseDocument* doc = obj->GetDocument();
		Matrix objMg = obj->GetMg();
		
		BaseObject* brokenChild = NULL;
		for(BaseObject* rt = newParent; rt != NULL; rt = rt->GetUp())
			if(rt->GetUp() == obj)
			{
				// obj
				// |--> child_0 child_1 brokenChild child_3 ... child_n
				//                      |--> ...
				//                           |--> ...
				//                                |--> newParent
				brokenChild = rt;
				break;
			}

		if(brokenChild)
		{
			SetParentObj(brokenChild, obj->GetUp());
			// obj                                        brokenChild
			// |--> child_0 child_1 child_3 ... child_n   |--> ...
			//                                                 |--> ...
			//                                                      |--> newParent
		}

		obj->Remove();
		doc->InsertObject(obj, newParent, NULL, FALSE);
		obj->SetMg(objMg /*, FALSE */);
		// breakChild 
		// |--> ...
		//      |--> ...
		//           |--> newParent
		//                |--> obj
		//                     |--> child_0 child_1 child_3 ... child_n
	}
	// newParent
	// |--> obj
}

static std::vector<BaseObject*> GetChildrenObj(BaseObject* obj)
{
	BaseObject* child;
	if(obj != NULL)
		child = obj->GetDown();
	else
		child = GetActiveDocument()->GetFirstObject();

	std::vector<BaseObject*> children;
	for(; child != NULL; child = child->GetNext())
		children.push_back(child);

	return children;
}

inline bool IsObjSelected(BaseObject* obj)
{
	return obj->GetBit(BIT_ACTIVE) != 0;
}

inline void SelectObj(BaseObject* obj)
{
	BaseDocument* doc = obj->GetDocument();
	doc->SetActiveObject(obj, SELECTION_ADD);
}

inline void DeselectObj(BaseObject* obj)
{
	BaseDocument* doc = obj->GetDocument();
	doc->SetActiveObject(obj, SELECTION_SUB);
}

inline void DeselectAllObjs()
{
	GetActiveDocument()->SetActiveObject(NULL, SELECTION_NEW);
}

inline bool IsBoneObj(BaseObject* obj)
{
	LONG type = obj->GetType();

#	if USE_JOINTS
	{
		if(type == Ojoint)
			return true;
	}
#	endif // USE_JOINTS

#	if USE_BONES
	{
		if(type == Obone_EX)
			return true;
	}
#	endif // USE_BONES

	return false;
}

inline Matrix GetTransform(BaseObject* obj)
{
	Matrix tm = obj->GetMg();
	if(IsBoneObj(obj))
	{
		const Matrix axeschange_mat(Vector(0, 0, 0), Vector(0, 0, 1), Vector(0, 1, 0), Vector(-1, 0, 0));
		tm = tm * axeschange_mat;
	}
	return tm;
}

inline void SetTransform(BaseObject* obj, const Matrix& transform)
{
	Matrix tm = transform;
	if(IsBoneObj(obj))
	{
		const Matrix axeschange_invmat(Vector(0, 0, 0), Vector(0, 0, -1), Vector(0, 1, 0), Vector(1, 0, 0));
		tm = tm * axeschange_invmat;
	}
	obj->SetMg(tm /*, TRUE */);
}

inline Matrix GetObjectTransform(BaseObject* obj)
{
	return GetTransform(obj);
}

inline void SetObjWireColor(BaseObject* obj, const Vector& clr)
{
	ObjectColorProperties props;
	obj->GetColorProperties(&props);
	props.usecolor = 1; // automatic mode - shows wire color if no material assigned
	props.color = clr;
	obj->SetColorProperties(&props);
}

inline Vector GetObjWireColor(BaseObject* obj)
{
	ObjectColorProperties props;
	obj->GetColorProperties(&props);
	return props.color;
}

inline void ShowObj(BaseObject* obj, bool show)
{
	obj->SetEditorMode(show ? MODE_ON : MODE_OFF);
}

inline bool IsObjVisible(BaseObject* obj)
{
	return obj->GetEditorMode() != MODE_OFF;
}

inline void SetObjRenderable(BaseObject* obj, bool renderable)
{
	obj->SetRenderMode(renderable ? MODE_ON : MODE_OFF);
}

inline bool GetObjRenderable(BaseObject* obj)
{
	return obj->GetRenderMode() != MODE_OFF;
}

inline void SetObjBoxMode(BaseObject* obj, bool boxMode)
{
	// not supported in Cinema 4D
}

inline bool GetObjBoxMode(BaseObject* obj)
{
	// not supported in Cinema 4D
	return false;
}

inline void SetObjTransparent(BaseObject* obj, bool transp)
{
	ObjectColorProperties props;
	obj->GetColorProperties(&props);
	props.xray = transp;
	obj->SetColorProperties(&props);
}

inline bool GetObjTransparent(BaseObject* obj)
{
	ObjectColorProperties props;
	obj->GetColorProperties(&props);
	return props.xray != 0;
}

// Calculate number of vertices. This is equivalent of GET_NUM_VERTS(GET_MESH(obj)),
// but CALCULATE_NUM_VERTS works more faster.
inline int CalculateNumVerts(BaseObject* obj, bool virtualObject = false)
{
	int n = 0;
	BaseObject *cache = obj->GetDeformCache();
	if(cache)
	{
		n += CalculateNumVerts(cache, true);
	}
	else
	{
		cache = obj->GetCache(NULL);
		if(cache)
		{
			n += CalculateNumVerts(cache, true);
		}
		else
		{
			if(obj->IsInstanceOf(Opolygon) && !obj->GetBit(BIT_CONTROLOBJECT))
			{
				PolygonObject* poly = ToPoly(obj);
				n += poly->GetPointCount();
			}
		}
	}
	if(virtualObject)
	{
		for(BaseObject* child = obj->GetDown(); child; child = child->GetNext())
		{
			n += CalculateNumVerts(child, true);
		}
	}	
	return n;
}

// Calculate number of faces. This is equivalent of GET_NUM_FACES(GET_MESH(obj)),
// but CALCULATE_NUM_FACES works more faster.
inline int CalculateNumFaces(BaseObject* obj, bool virtualObject = false)
{
	int n = 0;
	BaseObject *cache = obj->GetDeformCache();
	if(cache)
	{
		n += CalculateNumFaces(cache, true);
	}
	else
	{
		cache = obj->GetCache(NULL);
		if(cache)
		{
			n += CalculateNumFaces(cache, true);
		}
		else
		{
			if(obj->IsInstanceOf(Opolygon) && !obj->GetBit(BIT_CONTROLOBJECT))
			{
				PolygonObject* poly = ToPoly(obj);
				int numPolys = poly->GetPolygonCount();
				const CPolygon* polygonR = poly->GetPolygonR();
				
				n += numPolys;
				for(int i = 0; i < numPolys; ++i)
				{
					const CPolygon& poly = polygonR[i];
					if(poly.c != poly.d)
						++n;
				}
			}
		}
	}
	if(virtualObject)
	{
		for(BaseObject* child = obj->GetDown(); child; child = child->GetNext())
		{
			n += CalculateNumFaces(child, true);
		}
	}	
	return n;
}

// Calculate number of materials.
inline int CalculateNumMtls(BaseObject* obj, bool virtualObject = false)
{
	int n = 0;
	BaseObject *cache = obj->GetDeformCache();
	if(cache)
	{
		n += CalculateNumMtls(cache, true);
	}
	else
	{
		cache = obj->GetCache(NULL);
		if(cache)
		{
			n += CalculateNumMtls(cache, true);
		}
		else
		{
			if(obj->IsInstanceOf(Opolygon) && !obj->GetBit(BIT_CONTROLOBJECT))
			{
				for(BaseTag* tag = obj->GetFirstTag(); tag != NULL; tag = tag->GetNext())
				{
					if(tag->GetType() == Ttexture)
						++n;
				}
			}
		}
	}
	if(virtualObject)
	{
		for(BaseObject* child = obj->GetDown(); child; child = child->GetNext())
		{
			n += CalculateNumMtls(child, true);
		}
	}	
	return n;
}

// Objects
#define TOBJECT                     BaseObject*
#define INVALID_OBJECT              NULL

// Set name of an object
#define SET_OBJECT_NAME(obj, name)	SetObjName(obj, name);

// Get name of an object
#define GET_OBJECT_NAME(obj)        (GetObjName(obj))

// Make an independent copy of object
#define COPY_OBJECT(obj)		   	(CopyObj(obj))

// Find object by name; returns INVALID_OBJECT if not found
#define FIND_OBJECT_BY_NAME(nam)	(FindObjByName(nam))

// Make an unique name based on the specified one
#define UNIQUE_OBJECT_NAME(nam)		(UniqueNam(nam))

// Delete an object from scene
#define DELETE_OBJECT(obj)      	DeleteObj(obj);

// Replace the first object with the second object
#define REPLACE_OBJECT(destObj, srcObj)	ReplaceObj(destObj, srcObj);

// Root object
#define ROOT_OBJECT					(RootObj())

// Object's parent
#define GET_PARENT(obj)				(GetParentObj(obj))
#define SET_PARENT(obj, new_parent)	SetParentObj(obj, new_parent);

// Array of object's children
#define GET_CHILDREN(obj)			(GetChildrenObj(obj))

// Object selection
#define IS_SELECTED(obj)			(IsObjSelected(obj))
#define SELECT(obj)					SelectObj(obj);
#define DESELECT(obj)               DeselectObj(obj);
#define DESELECT_ALL				DeselectAllObjs();

// The world space transformation matrix of the object. This matrix contains its parents transformation.
#define SET_TRANSFORM(obj, tm)		SetTransform(obj, tm);
#define GET_TRANSFORM(obj)			(GetTransform(obj))

// The object transform matrix is the transform matrix an objects's geometry needs to be multiplied by to transform into world space.
// This matrix can be used, for example, if you have a mesh object and wanted to get world space coordinate of one of its vertices.
#define GET_OBJECT_TRANSFORM(obj)	(GetObjectTransform(obj))

// Object's wireframe color
#define SET_WIRE_COLOR(obj, clr)		SetObjWireColor(obj, clr);
#define GET_WIRE_COLOR(obj)				(GetObjWireColor(obj))

// Whether the object is flagged as hidden in the viewport
#define SHOW(obj, hide)					ShowObj(obj, hide);
#define IS_VISIBLE(obj)					(IsObjVisible(obj))

// Wehether the object is renderable
#define SET_RENDERABLE(obj, renderable)	SetObjRenderable(obj, renderable);
#define GET_RENDERABLE(obj)				(GetObjRenderable(obj))

// Whether the object is displayed in box mode in the viewport
#define SET_BOX_MODE(obj, boxMode)		SetObjBoxMode(obj, boxMode);
#define GET_BOX_MODE(obj)				(GetObjBoxMode(obj))

// Whether the object is displayed in See Through mode in shaded viewport
#define SET_TRANSPARENT(obj, transp)	SetObjTransparent(obj, transp);
#define GET_TRANSPARENT(obj)			(GetObjTransparent(obj))

// Calculate number of faces. This is equivalent of GET_NUM_FACES(GET_MESH(obj)),
// but CALCULATE_NUM_FACES works more faster.
#define CALCULATE_NUM_FACES(obj)		(CalculateNumFaces(obj))

// Calculate number of vertices. This is equivalent of GET_NUM_VERTS(GET_MESH(obj)),
// but CALCULATE_NUM_VERTS works more faster.
#define CALCULATE_NUM_VERTS(obj)		(CalculateNumVerts(obj))

// Calculate number of materials. This function can returns an approximate value.
#define CALCULATE_NUM_MTLS(obj)     	(CalculateNumMtls(obj))


// Name:        MetaMaxSdk_Object.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static INode* CopyObj(INode* node)
{
	INodeTab nodes;
	nodes.Append(1, &node);
	Point3 offset(0, 0, 0);
	INodeTab resultTarget;
	theHold.Suspend();
	GetInterface()->CloneNodes(nodes, offset, false, NODE_COPY, NULL, &resultTarget);
	theHold.Resume();
	if(resultTarget.Count() == 0)
		return NULL;
	else
		return resultTarget[0];
}

static void DeleteObj(INode* node)
{
	GetInterface()->DeleteNode(node);
}

static void ReplaceObj(INode* destNode, INode* srcNode)
{
	Object* objSrc = srcNode->GetObjectRef();
	Mtl* mtlSrc = srcNode->GetMtl();
	destNode->SetObjectRef(objSrc);
	destNode->SetMtl(mtlSrc);
}

inline void SetObjName(INode* node, const std::tstring& name)
{
	node->SetName((TCHAR*) (name.c_str()));
}

inline std::tstring GetObjName(INode* node)
{
	return (std::tstring) node->GetName();
}

static INode* FindObjByName(const std::tstring& name)
{
	INode* node = GetInterface()->GetINodeByName(name.c_str());
	return node;
}

static std::tstring UniqueNam(const std::tstring& name)
{
	TSTR tstr = name.c_str();
	GetInterface()->MakeNameUnique(tstr);
	return tstr.data();
}

inline INode* RootObj()
{
	return GetInterface()->GetRootNode();
}

inline INode* GetParentObj(INode* node)
{
	return node->GetParentNode();
}

inline void SetParentObj(INode* node, INode* newParent)
{
	newParent->AttachChild(node, 1);
}

static std::vector<INode*> GetChildrenObj(INode* node)
{
	std::vector<INode*> children;
	int numChildren = node->NumberOfChildren();
	children.reserve(numChildren);
	for(int i = 0; i < numChildren; ++i)
	{
		children.push_back(node->GetChildNode(i));
	}
	return children;
}

inline bool IsObjSelected(INode* node)
{
	return node->Selected() != 0;
}

inline void SelectObj(INode* node)
{
	GetInterface()->SelectNode(node, 0);
}

inline void DeselectObj(INode* node)
{
	GetInterface()->DeSelectNode(node);
}

inline void DeselectAllObjs()
{
	GetInterface()->ClearNodeSelection();
}

inline Matrix3 GetTransform(INode* node)
{
	return node->GetNodeTM(GetInterface()->GetTime());
}

inline void SetTransform(INode* node, const Matrix3& transform)
{
	node->SetNodeTM(GetInterface()->GetTime(), (Matrix3&) transform);
}

inline Matrix3 GetObjectTransform(INode* node)
{
	return node->GetObjectTM(GetInterface()->GetTime());
}

inline void SetObjWireColor(INode* node, Color clr)
{
	node->SetWireColor(RGB(FLto255(clr.r), FLto255(clr.g), FLto255(clr.b)));
}

inline Color GetObjWireColor(INode* node)
{
	return Color(node->GetWireColor());
}

inline void ShowObj(INode* node, bool show)
{
	node->Hide(!show);
}

inline bool IsObjVisible(INode* node)
{
	return node->IsHidden() == 0;
}

inline void SetObjRenderable(INode* node, bool renderable)
{
	node->SetRenderable(renderable);
}

inline bool GetObjRenderable(INode* node)
{
	return node->Renderable() != 0;
}

inline void SetObjBoxMode(INode* node, bool boxMode)
{
	node->BoxMode(boxMode);
}

inline bool GetObjBoxMode(INode* node)
{
	return node->GetBoxMode() != 0;
}

inline void SetObjTransparent(INode* node, bool transp)
{
	node->XRayMtl(transp);
}

inline bool GetObjTransparent(INode* node)
{
	return node->HasXRayMtl() != 0;
}

inline int CalculateNumVerts(INode* node)
{
	int numFaces;
	int numVerts;
	node->GetObjectRef()->PolygonCount(GetInterface()->GetTime(), numFaces, numVerts);
	return numVerts;
}

inline int CalculateNumFaces(INode* node)
{
	int numFaces;
	int numVerts;
	node->GetObjectRef()->PolygonCount(GetInterface()->GetTime(), numFaces, numVerts);
	return numFaces;
}

inline int CalculateNumMtls(INode* node)
{
	int numMtls = 0;
	Mtl* m = node->GetMtl();
	if(m != NULL)
	{
		if(m->ClassID() == Class_ID(DMTL_CLASS_ID, 0) || m->ClassID() == Class_ID(DMTL2_CLASS_ID, 0))
		{
			numMtls = 1;
		}
		else if(m->ClassID() == Class_ID(MULTI_CLASS_ID, 0))
		{
			numMtls = m->NumSubMtls();
		}
	}
	return numMtls;
}

// Objects
#define TOBJECT                     INode*
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

// Calculate number of materials. This function can return an approximate value.
#define CALCULATE_NUM_MTLS(obj)         (CalculateNumMtls(obj))

///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Mesh.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 12, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static BaseObject* NewMeshObj(const std::tstring& name)
{
	// insert polygon object
	BaseObject* obj = (PolygonObject*) BaseObject::Alloc(Opolygon);
	GetActiveDocument()->InsertObject(obj, NULL, NULL, FALSE);
	obj->SetName(name.c_str());	
	
	// insert phong tag
	BaseTag* phong = BaseTag::Alloc(Tphong);
	BaseContainer* bc = phong->GetDataInstance();
	bc->SetBool(PHONGTAG_PHONG_ANGLELIMIT, TRUE);
	bc->SetReal(PHONGTAG_PHONG_ANGLE, Rad(Real(80)));
	bc->SetBool(PHONGTAG_PHONG_USEEDGES, TRUE);
	obj->InsertTag(phong);
	
	return obj;
}

static bool IsMeshObj(BaseObject* obj)
{
	int numVerts = CalculateNumVerts(obj);
	return numVerts != 0;
}

class MeshMatData
{
private:
	int                   __refCount;
	BaseObject*           __obj;
	PolygonObject*        __poly;
	int                   __numVerts;
	int                   __numFaces;
	int                   __numPolys;
	std::vector<Vector>   __verts;
	std::vector<CPolygon> __faces;
	std::vector<Vector>   __tverts;
	std::vector<CPolygon> __tvfaces;
	std::vector<BaseMaterial*> __materials;

private:
	void __AddMesh(PolygonObject* poly, BaseMaterial* defaultMaterial)
	{
		// getting object's name
		char objName[256];
		poly->GetName().GetCString(objName, 256);

		// getting number of vertices and number of faces
		int addNumVerts = poly->GetPointCount();
		int addNumPolys = poly->GetPolygonCount();
		int oldNumVerts = __numVerts;
		int oldNumPolys = __numPolys;
		__numVerts += addNumVerts;
		__numPolys += addNumPolys;

		// getting vertices
		const Vector* pointR = poly->GetPointR();
		const CPolygon* polygonR = poly->GetPolygonR();

		Matrix mat = !__obj->GetMg() * poly->GetMg();
		__verts.reserve(__verts.size() + addNumVerts);
		for(int iv = 0; iv < addNumVerts; ++iv)
		{
			Vector v = mat * pointR[iv];
			__verts.push_back(v);
		}
		
		// getting polygons (3- and 4-sided)
		__faces.reserve(__faces.size() + addNumPolys);
		__materials.reserve(__materials.size() + addNumPolys);
		for(int ip = 0; ip < addNumPolys; ++ip)
		{
			CPolygon pgn = polygonR[ip];
			pgn.a += oldNumVerts;
			pgn.b += oldNumVerts;
			pgn.c += oldNumVerts;
			pgn.d += oldNumVerts;
			__faces.push_back(pgn);
			__materials.push_back(defaultMaterial);
		}
		
		// processing tags
		for(BaseTag* tag = poly->GetFirstTag(); tag != NULL; tag = tag->GetNext())
		{
			LONG typ = tag->GetType();
			if(typ == Ttexture)
			{
				TextureTag* txttag = (TextureTag*)tag;
				BaseMaterial* mat = txttag->GetMaterial();
				if(mat != NULL)
				{
					BaseContainer bc = txttag->GetData();
					String seltagname = bc.GetString(TEXTURETAG_RESTRICTION);
					if(seltagname == "")
					{
						for(int j = oldNumPolys; j < __numPolys; ++j)
							__materials[j] = mat;
					}
					else
					{
						SelectionTag* seltag = NULL;
						for(BaseTag* tag = poly->GetFirstTag(); tag != NULL; tag = tag->GetNext())
						{
							LONG typ = tag->GetType();
							if(typ == Tpolygonselection && tag->GetName() == seltagname)
							{
								seltag = (SelectionTag*) tag;
								break;
							}
						}
						if(seltag != NULL)
						{
							BaseSelect* sel = seltag->GetBaseSelect();
							for(int t = 0; t < sel->GetSegments(); ++t)
							{
								LONG a, b;
								sel->GetRange(t, &a, &b);
								a += oldNumPolys;
								b += oldNumPolys;
								for(int j = a; j <= b; ++j)
									__materials[j] = mat;
							}
						}
					}
				}
			}
			else if(typ == Tuvw)
			{
				__tverts.reserve(__tverts.size() + addNumPolys * 3);
				__tvfaces.reserve(__tvfaces.size() + addNumPolys);
			
				UVWStruct uvwstruct;
				UVWTag* uvwtag = (UVWTag*) tag;

#				if USE_UVW_HANDLE
					const UVWHandle uvwhandle = uvwtag->GetDataAddressR();
#				endif // USE_UVW_HANDLE

				for(int i = 0; i < addNumPolys; ++i)
				{
#					if USE_UVW_HANDLE
						UVWTag::Get(uvwhandle, i, uvwstruct);
#					else // !USE_UVW_HANDLE
						uvwstruct = uvwtag->Get(i);
#					endif // USE_UVW_HANDLE

					int index = (int) __tverts.size();
					__tverts.push_back(uvwstruct.a);
					__tverts.push_back(uvwstruct.b);
					__tverts.push_back(uvwstruct.c);
					__tverts.push_back(uvwstruct.d);
					__tvfaces.push_back(CPolygon(index, index + 1, index + 2, index + 3));
				}
			}
		}
	}

	void __Triangulate()
	{
		int addNumFaces = 0;
		int i;
		for(i = 0; i < __numPolys; ++i)
		{
			const CPolygon& pgn = __faces[i];
			if(pgn.c != pgn.d)
				++addNumFaces;
		}

		__faces.reserve(__faces.size() + addNumFaces);
		__tvfaces.reserve(__tvfaces.size() + addNumFaces);
		__materials.reserve(__materials.size() + addNumFaces);

		for(i = 0; i < __numPolys; ++i)
		{
			CPolygon& poly = __faces[i];
			if(poly.d != poly.c)
			{
				CPolygon poly2 = CPolygon(poly.a, poly.c, poly.d);
				__faces.push_back(poly2);
				poly.d = poly.c;
				
				BaseMaterial* mat = __materials[i];
				__materials.push_back(mat);
				
				if(__tvfaces.size() != 0)
				{
					CPolygon& tvpoly = __tvfaces[i];
					CPolygon tvpoly2 = CPolygon(tvpoly.a, tvpoly.c, tvpoly.d);
					__tvfaces.push_back(tvpoly2);
					tvpoly.d = tvpoly.c;
				}
			}
		}
		__numFaces = __numPolys + addNumFaces;
	}

	void __ProcessCache(bool virtualObject, BaseObject* obj, BaseMaterial* defaultMaterial)
	{
		BaseMaterial* defMatForCache = defaultMaterial;
		for(BaseTag* tag = obj->GetFirstTag(); tag != NULL; tag = tag->GetNext())
		{
			LONG typ = tag->GetType();
			if(typ == Ttexture)
			{
				TextureTag* txttag = (TextureTag*)tag;
				defMatForCache = txttag->GetMaterial();
			}
		}
		
		BaseObject* cache = obj->GetDeformCache();
		if(cache)
			__ProcessCache(true, cache, defMatForCache);
		else
		{
			cache = obj->GetCache();
			if(cache)
				__ProcessCache(true, cache, defMatForCache);
			else
			{
				if(obj->IsInstanceOf(Opolygon) && !obj->GetBit(BIT_CONTROLOBJECT))
				{
					PolygonObject* poly = ToPoly(obj);
					__AddMesh(poly, defaultMaterial);
					if(!virtualObject)
						__poly = poly;
				}
			}
		}
		if(virtualObject)
		{
			for(BaseObject* child = obj->GetDown(); child; child = child->GetNext())
			{
				__ProcessCache(true, child, defaultMaterial);
			}
		}
	}

public:
	void AddRef()
	{
		if(this)
			__refCount++;
	}

	void Release()
	{
		if(this)
			if(!--__refCount)
				delete this;
	}

	MeshMatData(BaseObject* obj)
	{
		__refCount = 1;
		__obj = obj;
		__poly = NULL;
		__numVerts = 0;
		__numFaces = 0;
		__numPolys = 0;
		__ProcessCache(false, obj, NULL);
		__Triangulate();
	}
	
	std::vector<BaseObject*> Update()
	{
		std::vector<BaseObject*> result;
		result.push_back(__obj);
		if(!__poly) return result;

		// init points and polygons
		int numVerts = (int) __verts.size();
		int numFaces = (int) __faces.size();
		__poly->ResizeObject(numVerts, numFaces);
		
		Vector* pointW = __poly->GetPointW();
		CPolygon* polygonW = __poly->GetPolygonW();

		for(int i = 0; i < numVerts; ++i)
			pointW[i] = __verts[i];
			
		for(int j = 0; j < numFaces; ++j)
		{
			__faces[j].d = __faces[j].c;
			polygonW[j] = __faces[j];
		}
		
		// delete old tags
		BaseTag* tag = __poly->GetFirstTag(); 
		while(tag != NULL)
		{
			BaseTag* nexttag = tag->GetNext();
			LONG typ = tag->GetType();
			if(typ == Ttexture || typ == Tpolygonselection || typ == Tuvw)
			{
				BaseTag::Free(tag);
			}
			tag = nexttag;
		}

		// insert new UVWTaq
		BaseTag* lasttag = __poly->GetFirstTag();
		if(__tverts.size() != 0)
		{
			UVWTag* uvwtag = UVWTag::Alloc(numFaces);

#			if USE_UVW_HANDLE
				UVWHandle uvwhandle = uvwtag->GetDataAddressW();
#			endif // USE_UVW_HANDLE

			for(int l = 0; l < numFaces; ++l)
			{
				UVWStruct uvwstruct;
				uvwstruct.a = __tverts[__tvfaces[l].a];
				uvwstruct.b = __tverts[__tvfaces[l].b];
				uvwstruct.c = __tverts[__tvfaces[l].c];

#				if USE_UVW_HANDLE
					UVWTag::Set(uvwhandle, l, uvwstruct);
#				else // !USE_UVW_HANDLE
					uvwtag->Set(l, uvwstruct);
#				endif // USE_UVW_HANDLE
			}
			__poly->InsertTag(uvwtag, lasttag);
			lasttag = uvwtag;
		}

		// calculate list of materials without repeating
		// building array of materials without repeating
		std::vector<BaseMaterial*> mtls;
		mtls.reserve(__materials.size());
		bool facesWithoutMaterials = false;
		for(size_t i = 0; i < __materials.size(); ++i)
		{
			BaseMaterial* m = __materials[i];
			if(m)
			{
				bool found = false;
				for(size_t j = 0; j < mtls.size(); ++j)
				{
					if(mtls[j] == m)
					{
						found = true;
						break;
					}
				}
				if(!found)
				{
					mtls.push_back(m);
				}
			}
			else
			{
				facesWithoutMaterials = true;
			}
		}
		
		// insert new TextureTags and SelectionTags
		BaseDocument* doc = __poly->GetDocument();
		for(size_t i = 0; i < mtls.size(); ++i)
		{
			BaseMaterial* m = mtls[i];
			String seltagname = "";

			if(mtls.size() != 1 || facesWithoutMaterials)
			{
				SelectionTag* seltag = SelectionTag::Alloc(Tpolygonselection);
				seltagname = "Selection " + LongToString((int)i);
				seltag->SetName(seltagname);
				BaseSelect* sel = seltag->GetBaseSelect();
				for(int j = 0; j < (int) __materials.size(); ++j)
				{
					if(__materials[j] == m)
						sel->Select(j);
				}
				__poly->InsertTag(seltag, lasttag);
				lasttag = seltag;
			}

			TextureTag* txttag = TextureTag::Alloc();
			txttag->SetMaterial(m);
			BaseContainer bc = txttag->GetData();
			bc.SetLong(TEXTURETAG_PROJECTION, TEXTURETAG_PROJECTION_UVW);
			bc.SetString(TEXTURETAG_RESTRICTION, seltagname);
			bc.SetLong(TEXTURETAG_SIDE, TEXTURETAG_SIDE_FRONT);
			bc.SetLong(TEXTURETAG_TILE, 1);
			txttag->SetData(bc);
			__poly->InsertTag(txttag, lasttag);
			lasttag = txttag;
		}

		// update bounding-box
		__poly->Message(MSG_UPDATE);
		return result;
	}
	
	int GetNumVerts()
	{
		return __numVerts;
	}
	
	void SetNumVerts(int numVerts)
	{
		__verts.resize(numVerts);
		__numVerts = numVerts;
	}
	
	Vector GetVert(int vertIndex)
	{
		return __verts[vertIndex];
	}
	
	void SetVert(int vertIndex, const Vector& pt)
	{
		__verts[vertIndex] = pt;
	}
	
	int GetNumFaces()
	{
		return __numFaces;
	}
	
	void SetNumFaces(int numFaces)
	{
		int oldNumFaces = __numFaces;
		__faces.resize(numFaces);
		__materials.resize(numFaces);
		__numFaces = numFaces;
		for(int i = oldNumFaces; i < numFaces; ++i)
			__materials[i] = NULL;
	}
	
	CPolygon GetFace(int faceIndex)
	{
		return __faces[faceIndex];
	}
	
	void SetFace(int faceIndex, const CPolygon& face)
	{
		__faces[faceIndex] = face;
	}
	
	BaseMaterial* GetFaceMat(int faceIndex)
	{
		return __materials[faceIndex];
	}
	
	void SetFaceMat(int faceIndex, BaseMaterial* mat)
	{
		__materials[faceIndex] = mat;
	}
	
	int GetNumTVerts()
	{
		return (int) __tverts.size();
	}
	
	void SetNumTVerts(int numTVerts)
	{
		__tverts.resize(numTVerts);
	}
	
	Vector GetTVert(int tVertIndex)
	{
		return __tverts[tVertIndex];
	}
	
	void SetTVert(int tVertIndex, const Vector& pt)
	{
		__tverts[tVertIndex] = pt;
	}
	
	int GetNumTVFaces()
	{
		return (int) __tvfaces.size();
	}
	
	void SetNumTVFaces(int numTVFaces)
	{
		__tvfaces.resize(numTVFaces);
	}
	
	CPolygon GetTVFace(int faceIndex)
	{
		return __tvfaces[faceIndex];
	}
	
	void SetTVFace(int faceIndex, const CPolygon& tvface)
	{
		__tvfaces[faceIndex] = tvface;
	}
};

class MeshMat
{
private:
	MeshMatData* __data;

public:
	MeshMat()
	{
		__data = NULL;
	}
	
	MeshMat(BaseObject* obj)
	{
		__data = new MeshMatData(obj);
	}
	
	MeshMat(const MeshMat& src)
	{
		src.__data->AddRef();
		__data = src.__data;
	}
	
	const MeshMat& operator=(const MeshMat& src)
	{
		src.__data->AddRef();
		__data->Release();
		__data = src.__data;
		return *this;
	}	
	
	~MeshMat()
	{
		__data->Release();
	}		

	std::vector<BaseObject*> Update() {return __data->Update();}
	int GetNumVerts() const {return __data->GetNumVerts();}
	void SetNumVerts(int numVerts) {__data->SetNumVerts(numVerts);}
	Vector GetVert(int vertIndex) {return __data->GetVert(vertIndex);}
	void SetVert(int vertIndex, const Vector& pt) {__data->SetVert(vertIndex, pt);}
	int GetNumFaces() const {return __data->GetNumFaces();}
	void SetNumFaces(int numFaces) {__data->SetNumFaces(numFaces);}
	CPolygon GetFace(int faceIndex) {return __data->GetFace(faceIndex);}
	void SetFace(int faceIndex, const CPolygon& face) {__data->SetFace(faceIndex, face);}
	BaseMaterial* GetFaceMat(int faceIndex) {return __data->GetFaceMat(faceIndex);}
	void SetFaceMat(int faceIndex, BaseMaterial* mat) {__data->SetFaceMat(faceIndex, mat);}
	int GetNumTVerts() const {return __data->GetNumTVerts();}
	void SetNumTVerts(int numTVerts) {__data->SetNumTVerts(numTVerts);}
	Vector GetTVert(int tVertIndex) {return __data->GetTVert(tVertIndex);}
	void SetTVert(int tVertIndex, const Vector& pt) {__data->SetTVert(tVertIndex, pt);}
	int GetNumTVFaces() const {return __data->GetNumTVFaces();}
	void SetNumTVFaces(int numTVFaces) {__data->SetNumTVFaces(numTVFaces);}
	CPolygon GetTVFace(int faceIndex) {return __data->GetTVFace(faceIndex);}
	void SetTVFace(int faceIndex, const CPolygon& tvface) {__data->SetTVFace(faceIndex, tvface);}
};

// functions to use faces
inline CPolygon NewFace(int v0, int v1, int v2)
{
	return CPolygon(v0, v2, v1);
}

inline int GetFaceVert(const CPolygon& face, int faceVertIdx)
{
	int vertIdx = -1;
	switch(faceVertIdx)
	{
		case 0:	vertIdx = face.a; break;
		case 1: vertIdx = face.c; break;
		case 2: vertIdx = face.b; break;
	}
	return vertIdx;
}

inline void SetFaceVert(CPolygon& face, int faceVertIdx, int vertIdx)
{
	switch(faceVertIdx)
	{
		case 0:	face.a = vertIdx; break;
		case 1: face.c = vertIdx; break;
		case 2: face.b = vertIdx; break;
	}
}

int WeldVerts(PolygonObject* obj, float threshold)
{
	BaseContainer bc;
	bc.SetBool(MDATA_OPTIMIZE_POINTS,TRUE);
	bc.SetReal(MDATA_OPTIMIZE_TOLERANCE, threshold);
	ModelingCommandData md;
	md.doc = obj->GetDocument();
	md.op  = obj;
	md.bc  = &bc;
	Bool bOk = SendModelingCommand(MCOMMAND_OPTIMIZE, md);
	return obj->GetPointCount();
}

// Create triangular mesh object
#define NEW_MESH_OBJECT(name)			(NewMeshObj(name))

// Check if the object specified is a triangular mesh object
#define IS_MESH_OBJECT(obj)				(IsMeshObj(obj))

// Triangular mesh type
#define TMESH							MeshMat

// Invalid mesh (this value is returned by the GET_MESH(obj) macro when it's failed)
#define INVALID_MESH					MeshMat()

// Get mesh from triangular mesh object; throws exception if it is not a triangular mesh object
#define GET_MESH(obj)					(MeshMat(obj))

// Updates mesh, returns array of all objects which were changed; 
// this command must be called after completion of mesh changes.
#define UPDATE_MESH(msh)  				(msh.Update())

// Get the number of vertices in this mesh.
#define GET_NUM_VERTS(msh)				(msh.GetNumVerts())

// Set the number of vertices in this mesh.
#define SET_NUM_VERTS(msh, numVerts)	msh.SetNumVerts(numVerts);

// Retrieves coordinates of the single vertex; vertIndex is zero-based.
// The returning value is a position in the mesh's local coordinate system.
#define GET_VERT(msh, vertIdx)			(msh.GetVert(vertIdx))

// Set a single vertex; vertIndex is zero-based; pt is an object of the TPoint3 class.
// pt is a position in the mesh's local coordinate system.
#define SET_VERT(msh, vertIdx, pt)		msh.SetVert(vertIdx, pt);

// Returns the number of faces in the mesh. 
#define GET_NUM_FACES(msh)				(msh.GetNumFaces())

// Sets the number of faces in the mesh.
#define SET_NUM_FACES(msh, numFaces)	msh.SetNumFaces(numFaces);

// Returns a single face
#define GET_FACE(msh, faceIdx)			(msh.GetFace(faceIdx))

// Set a single face
#define SET_FACE(msh, faceIdx, face)	msh.SetFace(faceIdx, face);

// Get edge visibility; edge can be 0, 1, or 2.
#define GET_EDGE_VIS(msh, faceIdx, edge)		TRUE

// Set edge visibility; edge can be 0, 1, or 2.
#define SET_EDGE_VIS(msh, faceIdx, edge, vis)	

// Retrieves material for the specified face
#define GET_FACE_MAT(msh, faceIdx)				(msh.GetFaceMat(faceIdx))

// Set material for the specified face
#define SET_FACE_MAT(msh, faceIdx, mat)			msh.SetFaceMat(faceIdx, mat);

// Returns the indexed face's smoothing groups as a 32-bit integer. 
// There are 32 possible smoothing groups. Each bit in the returned value 
// corresponds to a smoothing group. If a bit is turned on, the face 
// is part of that smoothing group.
#define GET_FACE_SMOOTH_GROUP(msh, faceIdx)				0

// Sets the indexed face's smoothing groups.
#define SET_FACE_SMOOTH_GROUP(msh, faceIdx, smGroup)	

// Returns the number of tvFaces in the mesh. 
#define GET_NUM_TVFACES(msh)				(msh.GetNumTVFaces())

// Sets the number of tvFaces in the mesh;
// The number of tvFaces must be equal to the number of faces.
#define SET_NUM_TVFACES(msh, numTVFaces)	msh.SetNumTVFaces(numTVFaces);

// Get TVFace
#define GET_TVFACE(msh, faceIdx)			(msh.GetTVFace(faceIdx))

// Set TVFace
#define SET_TVFACE(msh, faceIdx, tvFace)	msh.SetTVFace(faceIdx, tvFace);

// Get number of texture vertices
#define GET_NUM_TVERTS(msh)					(msh.GetNumTVerts())

// Set number of texture vertices
#define SET_NUM_TVERTS(msh, numTVerts)		msh.SetNumTVerts(numTVerts);

// Get texture vertex
#define GET_TVERT(msh, tVertIdx)			(msh.GetTVert(tVertIdx))

// Set texture vertex
#define SET_TVERT(msh, tVertIdx, uvVert)	msh.SetTVert(tVertIdx, uvVert);

// Face
#define TFACE											CPolygon
#define NEW_FACE(v0, v1, v2)							(NewFace(v0, v1, v2))
#define GET_FACE_VERT(face, faceVertIdx)				(GetFaceVert(face, faceVertIdx))
#define SET_FACE_VERT(face, faceVertIdx, vertIdx)		SetFaceVert(face, faceVertIdx, vertIdx);

// Face texture
#define TTVFACE											CPolygon
#define NEW_TVFACE(t0, t1, t2)							(NewFace(t0, t1, t2))
#define GET_TVFACE_VERT(tvFace, faceVertIdx)			(GetFaceVert(tvFace, faceVertIdx))
#define SET_TVFACE_VERT(tvFace, faceVertIdx, tVertIdx)	SetFaceVert(tvFace, faceVertIdx, tVertIdx);

// Mapping coordinates (uv)
#define TUVVERT								Vector
#define ZERO_UVVERT							Vector(0.0f, 0.0f, 0.0f)
#define NEW_UVVERT(u, v)					Vector((Real) (u), 1 - (Real) (v), 0.0f)
#define SET_U(uvvert, u)					uvvert.x = (Real) (u);
#define SET_V(uvvert, v)					uvvert.y = 1 - (Real) (v);
#define GET_U(uvvert)						((float) (uvvert).x)
#define GET_V(uvvert)						((float) (1 - (uvvert).y))

// Welds the specified vertices that are within the threshold distance;
// returns new number of vertices
#define WELD_VERTICES(obj, threshold)		(WeldVerts(ToPoly(obj), threshold))

///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Mesh.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static INode* NewMeshObj(const std::tstring& name)
{
	TriObject* tri = CreateNewTriObject();
	INode* node = GetInterface()->CreateObjectNode(tri);
	node->SetName((LPTSTR) (name.c_str()));
	return node;
}

static bool IsMeshObj(INode* node)
{
	Object* obj = node->EvalWorldState(GetInterface()->GetTime()).obj;
	return (obj->ClassID() == Class_ID(EDITTRIOBJ_CLASS_ID, 0)) != 0
		|| obj->CanConvertToType(triObjectClassID) != 0;
}

// Internal class
class MeshMatData
{
private:
	int               __refCount;
	INode*            __node;
	Object*           __tempobj;
	Mesh*             __mesh;
	std::vector<Mtl*> __materials;

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

	MeshMatData(INode* node)
	{
		__refCount = 1;
		Object* obj = node->EvalWorldState(GetInterface()->GetTime()).obj;
		Mtl* m = node->GetMtl();
		
		if((obj->ClassID() != Class_ID(EDITTRIOBJ_CLASS_ID, 0)) != 0)
		{
			Object* conv = obj->ConvertToType(GetInterface()->GetTime(), triObjectClassID);
			if(!conv || conv->ClassID() != Class_ID(EDITTRIOBJ_CLASS_ID, 0))
			{
				conv = obj->ConvertToType(GetInterface()->GetTime(), polyObjectClassID);
				if(conv) 
					conv = conv->ConvertToType(GetInterface()->GetTime(), triObjectClassID);
			}
			TriObject* tri = (TriObject*) conv;
			__mesh = &(tri->mesh);				
			__tempobj = conv;
			__node = NULL;
		}
		else
		{
			TriObject* tri = (TriObject*) obj;
			__mesh = &(tri->mesh);
			__tempobj = NULL;
			__node = node;
		}
		
		int numFaces = __mesh->getNumFaces();
		__materials.resize(numFaces);
		if(m == NULL)
		{
			for(int i = 0; i < numFaces; ++i)
				__materials[i] = NULL;
		}
		else if(m->ClassID() == Class_ID(DMTL_CLASS_ID, 0) || m->ClassID() == Class_ID(DMTL2_CLASS_ID, 0))
		{
			for(int i = 0; i < numFaces; ++i)
				__materials[i] = m;
		}
		else if(m->ClassID() == Class_ID(MULTI_CLASS_ID, 0))
		{
			for(int i = 0; i < numFaces; ++i)
			{
				int matIndex = __mesh->getFaceMtlIndex(i);
				matIndex = matIndex % m->NumSubMtls();
				Mtl* subm = m->GetSubMtl(matIndex);	
				if(subm != NULL && subm->ClassID() != Class_ID(DMTL_CLASS_ID, 0) && subm->ClassID() != Class_ID(DMTL2_CLASS_ID, 0))
					subm = NULL;
				__materials[i] = subm;
			}
		}
	}

	~MeshMatData()
	{
		if(__tempobj)
			delete __tempobj;
	}
	
	std::vector<INode*> Update()
	{
		// if mesh is not linked to a node then it should not be updated
		if(__node == NULL)
		{
			if(__tempobj)
			{
				delete __tempobj;
				__tempobj = NULL;
			}
			return std::vector<INode*>();
		}
	
		// update mesh
		__mesh->InvalidateGeomCache();
		__mesh->buildNormals();
		
		// building array of materials without repeating
		std::vector<Mtl*> mtls;
		mtls.reserve(__materials.size());
		for(int i = 0; i < (int) __materials.size(); ++i)
		{
			Mtl* m = __materials[i];
			if(m)
			{
				int matIndex = -1;
				for(size_t j = 0; j < mtls.size(); ++j)
				{
					if(mtls[j] == m)
					{
						matIndex = (int) j;
						break;
					}
				}
				if(matIndex == -1)
				{
					matIndex = (int) mtls.size();
					mtls.push_back(m);
				}
				__mesh->setFaceMtlIndex(i, matIndex);
			}
			else
			{
				__mesh->setFaceMtlIndex(i, 0);
			}
		}
		
		// applying materials to object
		if(mtls.size() == 0)
		{
			__node->SetMtl(NULL);
		}
		else if(mtls.size() == 1)
		{
			__node->SetMtl(mtls[0]);
		}
		else
		{
			MultiMtl* m = NewDefaultMultiMtl();
			m->SetNumSubMtls((int) mtls.size());
			for(unsigned int i = 0; i < mtls.size(); ++i)
				m->SetSubMtl(i, mtls[i]);
			__node->SetMtl(m);
		}
		
		std::vector<INode*> result;
		result.push_back(__node);
		return result;
	}
	
	// Vertices
	int GetNumVerts()
	{
		return __mesh->getNumVerts();
	}

	void SetNumVerts(int numVerts)
	{
		__mesh->setNumVerts(numVerts);
	}

	Point3 GetVert(int vertIdx)
	{
		return __mesh->getVert(vertIdx);
	}
		
	void SetVert(int vertIdx, const Point3& pt)
	{
		__mesh->setVert(vertIdx, pt);
	}

	// Faces
	int GetNumFaces()
	{
		return __mesh->getNumFaces();
	}

	void SetNumFaces(int numFaces)
	{
		int oldNumFaces = __mesh->getNumFaces();
		__mesh->setNumFaces(numFaces);
		__materials.resize(numFaces);
		for(int i = oldNumFaces; i < numFaces; ++i)
			__materials[i] = NULL;
	}

	Face GetFace(int faceIdx)
	{
		return __mesh->faces[faceIdx];
	}

	void SetFace(int faceIdx, const Face& face)
	{
		__mesh->faces[faceIdx] = face;
	}

	// Edge visibility
	void SetEdgeVis(int faceIdx, int edge, bool vis)
	{
		__mesh->faces[faceIdx].setEdgeVis(edge, vis);
	}

	bool GetEdgeVis(int faceIdx, int edge)
	{
		return __mesh->faces[faceIdx].getEdgeVis(edge) != 0;
	}

	// Face material
	Mtl* GetFaceMat(int faceIdx)
	{
		return __materials[faceIdx];
	}

	void SetFaceMat(int faceIdx, Mtl* mtl)
	{
		__materials[faceIdx] = mtl;
	}

	// Face smooth group
	int GetFaceSmoothGroup(int faceIdx)
	{
		return __mesh->faces[faceIdx].getSmGroup();
	}

	void SetFaceSmoothGroup(int faceIdx, int smGroup)
	{
		__mesh->faces[faceIdx].setSmGroup(smGroup);
	}

	// Face texturing
	void SetNumTVFaces(int numTVFaces)
	{
		__mesh->setNumTVFaces(__mesh->getNumFaces());
	}

	int GetNumTVFaces()
	{
		return __mesh->getNumFaces();
	}

	TVFace GetTVFace(int faceIdx)
	{
		return __mesh->tvFace[faceIdx];
	}

	void SetTVFace(int faceIdx, const TVFace& tvFace)
	{
		__mesh->tvFace[faceIdx] = tvFace;
	}

	// Mapping coordinates
	int GetNumTVerts()
	{
		return __mesh->getNumTVerts();
	}

	void SetNumTVerts(int numTVerts)
	{
		__mesh->setNumTVerts(numTVerts);
	}

	UVVert GetTVert(int tVertIdx)
	{
		return __mesh->tVerts[tVertIdx];
	}
		
	void SetTVert(int tVertIdx, const UVVert& uvVert)
	{
		__mesh->tVerts[tVertIdx] = uvVert;
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
	
	MeshMat(INode* node)
	{
		__data = new MeshMatData(node);
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

	std::vector<INode*> Update() {return __data->Update();}
	int GetNumVerts() const {return __data->GetNumVerts();}
	void SetNumVerts(int numVerts) {__data->SetNumVerts(numVerts);}
	Point3 GetVert(int vertIndex) {return __data->GetVert(vertIndex);}
	void SetVert(int vertIndex, const Point3& pt) {__data->SetVert(vertIndex, pt);}
	int GetNumFaces() const {return __data->GetNumFaces();}
	void SetNumFaces(int numFaces) {__data->SetNumFaces(numFaces);}
	Face GetFace(int faceIndex) {return __data->GetFace(faceIndex);}
	void SetFace(int faceIndex, const Face& face) {__data->SetFace(faceIndex, face);}
	bool GetEdgeVis(int faceIndex, int edge) {return __data->GetEdgeVis(faceIndex, edge);}
	void SetEdgeVis(int faceIndex, int edge, bool vis) {__data->SetEdgeVis(faceIndex, edge, vis);}
	Mtl* GetFaceMat(int faceIndex) {return __data->GetFaceMat(faceIndex);}
	void SetFaceMat(int faceIndex, Mtl* mtl) {__data->SetFaceMat(faceIndex, mtl);}
	int GetFaceSmoothGroup(int faceIndex) {return __data->GetFaceSmoothGroup(faceIndex);}
	void SetFaceSmoothGroup(int faceIndex, int smGroup) {__data->SetFaceSmoothGroup(faceIndex, smGroup);}
	int GetNumTVerts() const {return __data->GetNumTVerts();}
	void SetNumTVerts(int numTVerts) {__data->SetNumTVerts(numTVerts);}
	UVVert GetTVert(int tVertIndex) {return __data->GetTVert(tVertIndex);}
	void SetTVert(int tVertIndex, const UVVert& pt) {__data->SetTVert(tVertIndex, pt);}
	int GetNumTVFaces() const {return __data->GetNumTVFaces();}
	void SetNumTVFaces(int numTVFaces) {__data->SetNumTVFaces(numTVFaces);}
	TVFace GetTVFace(int faceIndex) {return __data->GetTVFace(faceIndex);}
	void SetTVFace(int faceIndex, const TVFace& tvface) {__data->SetTVFace(faceIndex, tvface);}
};

// functions to use faces
inline Face NewFace(int v0, int v1, int v2)
{
	Face face;
	face.v[0] = v0;
	face.v[1] = v1;
	face.v[2] = v2;
	return face;
}

inline int GetFaceVert(const Face& face, int faceVertIdx)
{
	return face.v[faceVertIdx];
}

inline void SetFaceVert(Face& face, int faceVertIdx, int vertIdx)
{
	face.v[faceVertIdx] = vertIdx;
}

// functions to use texture faces
inline TVFace NewTVFace(int t0, int t1, int t2)
{
	TVFace tvFace;
	tvFace.t[0] = t0;
	tvFace.t[1] = t1;
	tvFace.t[2] = t2;
	return tvFace;
}

inline int GetTVFaceVert(const TVFace& tvFace, int faceVertIdx)
{
	return tvFace.t[faceVertIdx];
}

inline void SetTVFaceVert(TVFace& tvFace, int faceVertIdx, int tVertIdx)
{
	tvFace.t[faceVertIdx] = tVertIdx;
}

// Welds the specified vertices that are within the threshold distance.
static int WeldVerts(INode* node, float threshold)
{
	TriObject* tri = (TriObject*) node->EvalWorldState(GetInterface()->GetTime()).obj;
	Mesh* msh = &(tri->mesh);
	
	BitArray& ba = msh->vertSel;
	ba.SetSize(msh->getNumVerts());
	ba.SetAll();
	
	MeshDelta md;
	md.WeldByThreshold(*msh, ba, threshold);
	md.Apply(*msh);
	return msh->getNumVerts();
}



// Create triangular mesh object
#define NEW_MESH_OBJECT(name)			(NewMeshObj(name))

// Check if the object specified is a triangular mesh object
#define IS_MESH_OBJECT(node)			(IsMeshObj(node))

// Triangular mesh type
#define TMESH							MeshMat

// Invalid mesh (this value is returned by the GET_MESH(obj) macro when it's failed)
#define INVALID_MESH					MeshMat()

// Get mesh from triangular mesh object; throws exception if it is not a triangular mesh object
#define GET_MESH(node)					(MeshMat(node))

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
#define GET_EDGE_VIS(msh, faceIdx, edge)		(msh.GetEdgeVis(faceIdx, edge))

// Set edge visibility; edge can be 0, 1, or 2.
#define SET_EDGE_VIS(msh, faceIdx, edge, vis)	msh.SetEdgeVis(faceIdx, edge, vis);

// Retrieves material for the specified face
#define GET_FACE_MAT(msh, faceIdx)				(msh.GetFaceMat(faceIdx))

// Set material for the specified face
#define SET_FACE_MAT(msh, faceIdx, mtl)			msh.SetFaceMat(faceIdx, mtl);

// Returns the indexed face's smoothing groups as a 32-bit integer. 
// There are 32 possible smoothing groups. Each bit in the returned value 
// corresponds to a smoothing group. If a bit is turned on, the face 
// is part of that smoothing group.
#define GET_FACE_SMOOTH_GROUP(msh, faceIdx)				(msh.GetFaceSmoothGroup(faceIdx))

// Sets the indexed face's smoothing groups.
#define SET_FACE_SMOOTH_GROUP(msh, faceIdx, smGroup)	msh.SetFaceSmoothGroup(faceIdx, smGroup);

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
#define TFACE											Face
#define NEW_FACE(v0, v1, v2)							(NewFace(v0, v1, v2))
#define GET_FACE_VERT(face, faceVertIdx)				(GetFaceVert(face, faceVertIdx))
#define SET_FACE_VERT(face, faceVertIdx, vertIdx)		SetFaceVert(face, faceVertIdx, vertIdx);

// Face texture
#define TTVFACE											TVFace
#define NEW_TVFACE(t0, t1, t2)							(NewTVFace(t0, t1, t2))
#define GET_TVFACE_VERT(tvFace, faceVertIdx)			(GetTVFaceVert(tvFace, faceVertIdx))
#define SET_TVFACE_VERT(tvFace, faceVertIdx, tVertIdx)	SetTVFaceVert(tvFace, faceVertIdx, tVertIdx);

// Mapping coordinates (uv)
#define TUVVERT								UVVert
#define ZERO_UVVERT							UVVert(0.0f, 0.0f, 0.0f)
#define NEW_UVVERT(u, v)					UVVert((float) (u), (float) (v), 0.0f)
#define SET_U(uvvert, u)					uvvert.x = (float) (u);
#define SET_V(uvvert, v)					uvvert.y = (float) (v);
#define GET_U(uvvert)						((uvvert).x)
#define GET_V(uvvert)						((uvvert).y)

// Welds the specified vertices that are within the threshold distance;
// returns new number of vertices
#define WELD_VERTICES(node, threshold)			(WeldVerts(node, threshold))

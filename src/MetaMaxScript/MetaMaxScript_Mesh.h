///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Mesh.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function IsMeshObj obj = 
(
	return (classof(obj) == Editable_mesh) or (canConvertTo obj Editable_mesh)
)

function WeldVerts obj threshold = 
(
	local msh = obj.mesh
	meshop.weldVertsByThreshold msh HASH{1..(getNumVerts msh)} threshold
	return (getNumVerts msh)
)

struct MeshMat
(
	__obj,
	__mesh,
	__materials,
	
	function InitMeshMat obj =
	(
		local m = obj.material
		if(classof(obj) == Editable_mesh) then
		(
			__obj = obj
			__mesh = obj.mesh
		)
		else
		(
			__obj = undefined
			__mesh = obj.mesh
		)
	
		__materials = HASH()
		numFaces = (getNumFaces __mesh)

		if classOf(m) == StandardMaterial then
		(
			for i in 1 to numFaces do
			(
				append __materials m
			)
		)
		else if classOf(m) == MultiMaterial then
		(
			for i in 1 to numFaces do
			(
				matIndex = (getFaceMatID __mesh i) - 1
				matIndex = matIndex - (matIndex / m.numsubs) * m.numsubs
				subm = m[matIndex + 1]
				if (subm != undefined) and (classOf(subm) != StandardMaterial) then
				(
					subm = undefined
				)
				append __materials subm
			)
		)
		else
		(
			for i in 1 to numFaces do
			(
				append __materials undefined
			)
		)
	),
	
	function updateMeshMat =
	(
		// mesh should be linked to an object to update
		if __obj == undefined then
		(
			return HASH()
		)
		
		// update mesh
		update __mesh
		
		// building array of materials without repeating
		mtls = HASH()
		for i in 1 to __materials.count do
		(
			m = __materials[i]
			if m != undefined then
			(
				matIndex = 0
				for j in 1 to mtls.count do
				(
					if mtls[j] == m then
					(
						matIndex = j
						exit
					)
				)
				if matIndex == 0 then
				(
					append mtls m
					matIndex = mtls.count
				)
				setFaceMatID __mesh i matIndex
			)
			else
			(
				setFaceMatID __mesh i 1
			)
		)
		
		// applying materials to object
		if mtls.count == 0 then
		(
			__obj.material = undefined
		)
		else if mtls.count == 1 then
		(
			__obj.material = mtls[1]
		)
		else
		(
			local mm = multimaterial numsubs: (mtls.count)
			for i in 1 to mtls.count do
				mm[i] = mtls[i]
			__obj.material = mm
		)
		return HASH(__obj)
	),

	function getNumberOfVertices = 
	(
		return (getNumVerts __mesh)
	),
	
	function setNumberOfVertices numVerts =
	(
		setNumVerts __mesh numVerts
	),
	
	function getVertex vertIndex =
	(
		return (getVert __mesh (vertIndex + 1))
	),
	
	function setVertex vertIndex pt =
	(
		setVert __mesh (vertIndex + 1) pt
	),
	
	function getNumberOfFaces =
	(
		return (getNumFaces __mesh)
	),
	
	function setNumberOfFaces numFaces =
	(
		oldNumFaces = (getNumFaces __mesh)
		setNumFaces __mesh numFaces
		if numFaces > oldNumFaces then
		(
			for i in (oldNumFaces + 1) to numFaces do
				append __materials undefined
		)
		else
		(
			for i in oldNumFaces to numFaces + 1 by -1 do
				deleteItem __materials i
		)
	),
	
	function getFFace faceIndex =
	(
		return (getFace __mesh (faceIndex + 1))
	),
	
	function setFFace faceIndex face =
	(
		setFace __mesh (faceIndex + 1) face
	),

	function getEdgeVisibility faceIndex edge =
	(
		return (getEdgeVis __mesh (faceIndex + 1) (edge + 1))
	),
	
	function setEdgeVisibility faceIndex edge vis = 
	(
		setEdgeVis __mesh (faceIndex + 1) (edge + 1) vis
	),
	
	function getFaceMat faceIndex =
	(
		return __materials[faceIndex + 1]
	),
	
	function setFaceMat faceIndex m =
	(
		__materials[faceIndex + 1] = m
	),
	
	function getFaceSmGroup faceIndex =
	(
		return (getFaceSmoothGroup __mesh (faceIndex + 1))
	),
	
	function setFaceSmGroup faceIndex smGroup =
	(
		setFaceSmoothGroup __mesh (faceIndex + 1) smGroup
	),
	
	function getNumberOfTFaces =
	(
		return (getNumFaces __mesh)
	),
	
	function setNumberOfTFaces numTFaces =
	(
		buildTVFaces __mesh
	),
	
	function getTFace faceIndex =
	(
		return (getTVFace __mesh (faceIndex + 1))
	),
	
	function setTFace faceIndex tFace =
	(
		setTVFace __mesh (faceIndex + 1) tFace
	), 
	
	function getNumberOfTVertices =
	(
		return getNumTVerts __mesh
	),
	
	function setNumberOfTVertices numTVerts =
	(
		setNumTVerts __mesh numTVerts
	),
	
	function getTVertex tVertIndex =
	(
		return getTVert __mesh (tVertIndex + 1)
	), 
	
	function setTVertex tVertIndex uvvert =
	(
		setTVert __mesh (tVertIndex + 1) uvvert
	)
)
	
	

// Create triangular mesh object
#define NEW_MESH_OBJECT(nam)			(editable_mesh name:(nam))

// Check if the object specified is a triangular mesh object
#define IS_MESH_OBJECT(obj)				(IsMeshObj (obj))

// Triangular mesh type (unused macro)
#define TMESH							MeshMat

// Invalid mesh (this value is returned by the GET_MESH(obj) macro when it's failed)
#define INVALID_MESH					undefined

// Get mesh from triangular mesh object; throws exception if it is not a triangular mesh object
#define GET_MESH(obj)					(local msh = MeshMat(); msh.initMeshMat(obj); msh)

// Updates mesh, returns array of all objects which were changed; 
// this command must be called after completion of mesh changes.
#define UPDATE_MESH(msh)  				msh.updateMeshMat()

// Get the number of vertices in this mesh.
#define GET_NUM_VERTS(msh)				(msh.getNumberOfVertices())

// Set the number of vertices in this mesh.
#define SET_NUM_VERTS(msh, numVerts)	msh.setNumberOfVertices(numVerts)

// Retrieves coordinates of the single vertex; vertIndex is zero-based.
// The returning value is a position in the mesh's local coordinate system.
// Type of the returning value is TPOINT3
#define GET_VERT(msh, vertIndex)		(msh.getVertex(vertIndex))

// Set a single vertex; vertIndex is zero-based; pt is an object of the TPoint3 class.
// pt is a position in the mesh's local coordinate system.
#define SET_VERT(msh, vertIndex, pt)	msh.setVertex (vertIndex) (pt)

// Returns the number of faces in the mesh. 
#define GET_NUM_FACES(msh)				(msh.getNumberOfFaces())

// Sets the number of faces in the mesh.
#define SET_NUM_FACES(msh, numFaces)	msh.setNumberOfFaces(numFaces)

// Returns a single face; faceIndex is zero-based.
// Type of the returning value is TFACE.
#define GET_FACE(msh, faceIndex)		(msh.getFFace(faceIndex))

// Set a single face; faceIndex is zero-based.
#define SET_FACE(msh, faceIndex, face)	msh.setFFace (faceIndex) (face)

// Get edge visibility; edge can be 0, 1, or 2.
#define GET_EDGE_VIS(msh, faceIndex, edge)			(msh.getEdgeVisibility (faceIndex) (edge))

// Set edge visibility; edge can be 0, 1, or 2.
#define SET_EDGE_VIS(msh, faceIndex, edge, vis)		msh.setEdgeVisibility (faceIndex) (edge) (vis)

// Retrieves material for the specified face
#define GET_FACE_MAT(msh, faceIndex)				(msh.getFaceMat (faceIndex))

// Set material for the specified face
#define SET_FACE_MAT(msh, faceIndex, m)				msh.setFaceMat (faceIndex) (m)

// Returns the indexed face's smoothing groups as a 32-bit integer. 
// There are 32 possible smoothing groups. Each bit in the returned value 
// corresponds to a smoothing group. If a bit is turned on, the face 
// is part of that smoothing group.
#define GET_FACE_SMOOTH_GROUP(msh, faceIndex)				(msh.getFaceSmGroup (faceIndex))

// Sets the indexed face's smoothing groups.
#define SET_FACE_SMOOTH_GROUP(msh, faceIndex, smoothGroup)	msh.setFaceSmGroup (faceIndex) (smoothGroup)

// Returns the number of tvFaces in the mesh. 
#define GET_NUM_TVFACES(msh)						(msh.getNumberOfTFaces())

// Sets the number of tvFaces in the mesh;
// The number of tvFaces must be equal to the number of faces.
#define SET_NUM_TVFACES(msh, numTVFaces)			msh.setNumberOfTFaces(numTVFaces)

// Get TVFace
#define GET_TVFACE(msh, faceIndex)					(msh.getTFace(faceIndex))

// Set TVFace
#define SET_TVFACE(msh, faceIndex, tvFace)			msh.setTFace (faceIndex) (tvFace)

// Get number of TVerts
#define GET_NUM_TVERTS(msh)						(msh.getNumberOfTVertices())
#define SET_NUM_TVERTS(msh, numTVerts)			msh.setNumberOfTVertices (numTVerts)

#define GET_TVERT(msh, vertIndex)				(msh.getTVertex (vertIndex))
#define SET_TVERT(msh, vertIndex, uvvert)		msh.setTVertex (vertIndex) (uvvert)

// Face
#define TFACE											Point3
#define NEW_FACE(v0, v1, v2)							(Point3 (v0 + 1) (v1 + 1) (v2 + 1))
#define GET_FACE_VERT(face, vertIndexInFace)			(((face)[vertIndexInFace + 1] - 1) as integer)
#define SET_FACE_VERT(face, vertIndexInFace, vertIndex)	face[vertIndexInFace + 1] = (vertIndex + 1)

// Face texture
#define TTVFACE													Point3
#define NEW_TVFACE(t0, t1, t2)									(Point3 (t0 + 1) (t1 + 1) (t2 + 1))
#define GET_TVFACE_VERT(tvFace, vertIndexInFace)				(((tvFace)[vertIndexInFace + 1] - 1) as integer)
#define SET_TVFACE_VERT(tvFace, vertIndexInFace, tVertIndex)	tvFace[vertIndexInFace + 1] = (tVertIndex + 1)

// Mapping coordinates (uv)
#define TUVVERT								Point3
#define NEW_UVVERT(u, v)					(Point3 (u) (v) 0)
#define SET_U(uvvert, u)					uvvert[1] = (u)
#define SET_V(uvvert, v)					uvvert[2] = (v)
#define GET_U(uvvert)						((uvvert)[1])
#define GET_V(uvvert)						((uvvert)[2])

// Welds the specified vertices that are within the threshold distance;
// returns new number of vertices
#define WELD_VERTICES(obj, threshold)				(WeldVerts(obj) (threshold))


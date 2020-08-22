///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Mesh.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 7, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Create triangular mesh object
#define NEW_MESH_OBJECT(name)			new_mesh_object(name)

// Check if the object specified is a triangular mesh object
#define IS_MESH_OBJECT(obj)				is_mesh_object(obj)

// Triangular mesh
#define TMESH					
#define INVALID_MESH					None

// Get mesh from triangular mesh object; throws exception if it is not a triangular mesh object
#define GET_MESH(obj)					MeshData(obj)

// Updates mesh, returns array of all objects which were changed; 
// this command must be called after completion of mesh changes.
#define UPDATE_MESH(md)                 (md.update())

// Get the number of vertices in this mesh.
#define GET_NUM_VERTS(md)				(md.get_num_verts())

// Set the number of vertices in this mesh.
#define SET_NUM_VERTS(md, numVerts)	    md.set_num_verts(numVerts)

// Retrieves coordinates of the single vertex; vertIndex is zero-based.
// The returning value is a position in the mesh's local coordinate system.
#define GET_VERT(md, vertIndex)			(md.get_vert(vertIndex))

// Set a single vertex; vertIndex is zero-based; pt is an object of the TPOINT3 class.
// pt is a position in the mesh's local coordinate system.
#define SET_VERT(md, vertIndex, pt)		(md.set_vert(vertIndex, pt))

// Returns the number of faces in the mesh. 
#define GET_NUM_FACES(md)				(md.get_num_faces())

// Sets the number of faces in the mesh.
#define SET_NUM_FACES(md, numFaces)		md.set_num_faces(numFaces)

// Get zero-based index of face vertex in a mesh object's array of vertices;
// vertInFaceIndex can be 0, 1, or 2 only.
#define GET_FACE(md, faceIndex)			(md.get_face(faceIndex))

// Set an index of face vertex in a mesh object's array of vertices;
// vertInFaceIndex can be 0, 1, or 2 only.
#define SET_FACE(md, faceIndex, face)	md.set_face(faceIndex, face)

// Get edge visibility; edge can be 0, 1, or 2.
#define GET_EDGE_VIS(md, faceIndex, edge)			True

// Set edge visibility; edge can be 0, 1, or 2.
#define SET_EDGE_VIS(md, faceIndex, edge, vis)		pass

// Retrieves material for the specified face
#define GET_FACE_MAT(md, faceIndex)					(md.get_face_material(faceIndex))

// Set material for the specified face
#define SET_FACE_MAT(md, faceIndex, mat)			md.set_face_material(faceIndex, mat)

// Returns the indexed face's smoothing groups as a 32-bit integer. 
// There are 32 possible smoothing groups. Each bit in the returned value 
// corresponds to a smoothing group. If a bit is turned on, the face 
// is part of that smoothing group.
#define GET_FACE_SMOOTH_GROUP(md, faceIndex)				0

// Sets the indexed face's smoothing groups.
#define SET_FACE_SMOOTH_GROUP(md, faceIndex, smoothGroup)	pass

// Returns the number of tvFaces in the mesh. 
#define GET_NUM_TVFACES(md)							(md.get_num_faces())

// Sets the number of tvFaces in the mesh.
#define SET_NUM_TVFACES(md, numTVFaces)				md.set_num_tvfaces(md.get_num_faces())

// Get TVFace
#define GET_TVFACE(md, faceIndex)					(md.get_tvface(faceIndex))

// Set TVFace
#define SET_TVFACE(md, faceIndex, tvFace)			md.set_tvface(faceIndex, tvFace)

// Get number of TVerts
#define GET_NUM_TVERTS(md)					(md.get_num_tverts())
#define SET_NUM_TVERTS(md, numTVerts)		md.set_num_tverts(numTVerts)

#define GET_TVERT(md, vertIndex)			(md.get_tvert(vertIndex))
#define SET_TVERT(md, vertIndex, uvvert)	md.set_tvert(vertIndex, uvvert)

// Face
#define TFACE									
#define NEW_FACE(v0, v1, v2)							new_face(v0, v1, v2)
#define GET_FACE_VERT(face, vertIndexInFace)			get_face_vert(face, vertIndexInFace)
#define SET_FACE_VERT(face, vertIndexInFace, vertIndex)	set_face_vert(face, vertIndexInFace, vertIndex)

// Face texture
#define TTVFACE									
#define NEW_TVFACE(t0, t1, t2)									new_tvface(t0, t1, t2)
#define GET_TVFACE_VERT(tvFace, vertIndexInFace)				get_tvface_vert(tvFace, vertIndexInFace)
#define SET_TVFACE_VERT(tvFace, vertIndexInFace, tVertIndex)	set_tvface_vert(tvFace, vertIndexInFace, tVertIndex)

// Mapping coordinates (uv)
#define TUVVERT					
#define NEW_UVVERT(u, v)					new_uvvert(u, v)
#define ZERO_UVVERT							zero_uvvert()
#define SET_U(uvvert, u)					set_u(uvvert, u)
#define SET_V(uvvert, v)					set_v(uvvert, v)
#define GET_U(uvvert)						get_u(uvvert)
#define GET_V(uvvert)						get_v(uvvert)

// Welds the specified vertices that are within the threshold distance;
// returns new number of vertices
#define WELD_VERTICES(mobj, threshold)		weld_vertices(obj, threshold)


///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Bone.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     April 2, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal function
function NewBoneObj nam parentBone boundBoxMinPoint boundBoxMaxPoint skinType = 
(
	local obj = editable_mesh name:(nam)
	obj.parent = parentBone
	local msh = obj.mesh
	
	minx = boundBoxMinPoint.x
	miny = boundBoxMinPoint.y
	minz = boundBoxMinPoint.z
	maxx = boundBoxMaxPoint.x
	maxy = boundBoxMaxPoint.y
	maxz = boundBoxMaxPoint.z

	setNumVerts msh 8
	setVert msh 1 (Point3 minx miny minz)
	setVert msh 2 (Point3 maxx miny minz)
	setVert msh 3 (Point3 minx maxy minz)
	setVert msh 4 (Point3 maxx maxy minz)
	setVert msh 5 (Point3 minx miny maxz)
	setVert msh 6 (Point3 maxx miny maxz)
	setVert msh 7 (Point3 minx maxy maxz)
	setVert msh 8 (Point3 maxx maxy maxz)
	
	setNumFaces msh 12
	setFace msh  1 (Point3 1 3 4)
	setFace msh  2 (Point3 4 2 1)
	setFace msh  3 (Point3 5 6 8)
	setFace msh  4 (Point3 8 7 5)
	setFace msh  5 (Point3 1 2 6)
	setFace msh  6 (Point3 6 5 1)
	setFace msh  7 (Point3 2 4 8)
	setFace msh  8 (Point3 8 6 2)
	setFace msh  9 (Point3 4 3 7)
	setFace msh 10 (Point3 7 8 4)
	setFace msh 11 (Point3 3 1 5)
	setFace msh 12 (Point3 5 7 3)	
	
	for i = 1 to (getNumFaces msh) do
		for j = 1 to 3 do
			setEdgeVis msh i j true
	
	return obj
)

// Create object which will be used as bone;
// If parentBone == ROOT_OBJECT, then this function will create a bone without a parent
#define NEW_BONE_OBJECT(name, parentBone, boundBoxMinPoint, boundBoxMaxPoint, skinType)	(NewBoneObj (name) (parentBone) (boundBoxMinPoint) (boundBoxMaxPoint) (skinType))

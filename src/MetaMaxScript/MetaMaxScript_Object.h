///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Object.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function GetChildrenObj obj =
(
	local obj2 = obj
	if obj == undefined then
	(
		obj2 = rootNode
	)
	local children = HASH()
	local num = obj2.children.count
	for i in 1 to num do
		append children obj2.children[i]
	children
)

function replaceObj destObj srcObj =
(
	replaceInstances destObj srcObj
	destObj.material = srcObj.material
)

function CalculateNumVerts obj =
(
	local fv = (getPolygonCount obj)
	return fv[2]
)

function CalculateNumFaces obj =
(
	local fv = (getPolygonCount obj)
	return fv[1]
)

function CalculateNumMtls obj =
(
	local numMtls = 0
	if obj.material != undefined then
	(
		if classOf(obj.material) == StandardMaterial then
		(
			numMtls = 1
		)
		else if classOf(obj.material) == MultiMaterial then
		(
			numMtls = obj.material.numsubs
		)
	)
	return numMtls
)

// Objects
#define TOBJECT                     Node
#define INVALID_OBJECT              undefined

// Set name of an object
#define SET_OBJECT_NAME(obj, nam)	obj.name = (nam)

// Get name of an object
#define GET_OBJECT_NAME(obj)        ((obj).name)

// Make independent copy of an object
#define COPY_OBJECT(obj)            (copy (obj))

// Find object by name; returns INVALID_OBJECT if not found
#define FIND_OBJECT_BY_NAME(nam)	(getNodeByName (copy (nam)))

// Make an unique name based on the specified one
#define UNIQUE_OBJECT_NAME(nam)		(uniqueName (nam))

// Delete an object from scene
#define DELETE_OBJECT(obj)      	delete (obj)

// Replace the first object with the second object
#define REPLACE_OBJECT(destObj, srcObj)	(replaceObj (destObj) (srcObj))

// Root object
#define ROOT_OBJECT					undefined

// Object's parent
#define GET_PARENT(obj)				((obj).parent)
#define SET_PARENT(obj, new_parent)	obj.parent = (new_parent)

// Array of object's children
#define GET_CHILDREN(obj)			(GetChildrenObj (obj))

// Object selection
#define IS_SELECTED(obj)			((obj).isSelected)
#define SELECT(obj)					obj.isSelected = true
#define DESELECT(obj)               obj.isSelected = false
#define DESELECT_ALL				clearSelection()

// The world space transformation matrix of the object. This matrix contains its parents transformation.
#define SET_TRANSFORM(obj, matrix)	obj.transform = (matrix)
#define GET_TRANSFORM(obj)			((obj).transform)

// The object transform matrix is the transform matrix an objects's geometry needs to be multiplied by to transform into world space.
// This matrix can be used, for example, if you have a mesh object and wanted to get world space coordinate of one of its vertices.
#define GET_OBJECT_TRANSFORM(obj)	((obj).objecttransform)

// Object's wireframe color
#define SET_WIRE_COLOR(obj, clr)	obj.wireColor = clr
#define GET_WIRE_COLOR(obj)			((obj).wireColor)

// Whether the object is flagged as hidden in the viewport
#define SHOW(obj, s)				obj.isHidden = not(s)
#define IS_VISIBLE(obj)				(not((obj).isHidden))

// Wehether the object is renderable
#define SET_RENDERABLE(obj, rndbl)	obj.renderable = rndbl
#define GET_RENDERABLE(obj)			((obj).renderable)

// Whether the object is displayed in box mode in the viewport
#define SET_BOX_MODE(obj, bm)		obj.boxMode = bm
#define GET_BOX_MODE(obj)			((obj).boxMode)

// Whether the object is displayed in See Through mode in shaded viewport
#define SET_TRANSPARENT(obj, tr)	obj.xray = tr
#define GET_TRANSPARENT(obj)		((obj).xray)

// Calculate number of faces. This is equivalent of GET_NUM_FACES(GET_MESH(obj)),
// but CALCULATE_NUM_FACES works more faster.
#define CALCULATE_NUM_FACES(obj)		(CalculateNumFaces (obj))

// Calculate number of vertices. This is equivalent of GET_NUM_VERTS(GET_MESH(obj)),
// but CALCULATE_NUM_VERTS works more faster.
#define CALCULATE_NUM_VERTS(obj)		(CalculateNumVerts (obj))

// Calculate number of materials. This function can return an approximate value.
#define CALCULATE_NUM_MTLS(obj)         (CalculateNumMtls (obj))

///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Object.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Object type (unused macro)
#define TOBJECT

// Invalid object
#define INVALID_OBJECT              None

// Set name of an object
#define SET_OBJECT_NAME(obj, name)	set_object_name(obj, name)

// Get name of an object
#define GET_OBJECT_NAME(obj)       (get_object_name(obj))

// Make independent copy of an object
#define COPY_OBJECT(obj)           (copy_object(obj))

// Find object by name; returns INVALID_OBJECT if not found
#define FIND_OBJECT_BY_NAME(name)	(find_object_by_name(name))

// Make an unique name based on the specified one
#define UNIQUE_OBJECT_NAME(name)	(unique_object_name(name))

// Delete an object from scene
#define DELETE_OBJECT(obj)      	delete_object(obj)

// Replace the first object with the second object
#define REPLACE_OBJECT(destMObj, srcMObj)	replace_object(destMObj, srcMObj)

// Root object
#define ROOT_OBJECT					None

// Object's parent
#define GET_PARENT(obj)			 	(get_parent(obj))
#define SET_PARENT(obj, new_parent) set_parent(obj, new_parent)

// Array of object's children
#define GET_CHILDREN(obj)			(get_children(obj))

// Object selection
#define IS_SELECTED(obj)			(is_selected(obj))
#define SELECT(obj)					select(obj)
#define DESELECT(obj)              	deselect(obj)
#define DESELECT_ALL				deselect_all()

// The world space transformation matrix of the object. This matrix contains its parents transformation.
#define SET_TRANSFORM(obj, mat)		set_transform(obj, mat)
#define GET_TRANSFORM(obj)			(get_transform(obj))

// The object transform matrix is the transform matrix an objects's geometry needs to be multiplied by to transform into world space.
// This matrix can be used, for example, if you have a mesh object and wanted to get world space coordinate of one of its vertices.
#define GET_OBJECT_TRANSFORM(obj)	(get_transform(obj))

// Object color
#define SET_WIRE_COLOR(obj, clr)	set_wire_color(obj, clr)
#define GET_WIRE_COLOR(obj)			(get_wire_color(obj))

// Whether the object is flagged as hidden in the viewport
#define SHOW(obj, vis)		        show(obj, vis)
#define IS_VISIBLE(obj)				(is_visible(obj))

// Wehether the object is renderable
#define SET_RENDERABLE(obj, rndbl)	set_renderable(obj, rndbl)
#define GET_RENDERABLE(obj)			(get_renderable(obj))

// Whether the object is displayed in box mode in the viewport
#define SET_BOX_MODE(obj, boxMode)	set_box_mode(obj, boxMode)
#define GET_BOX_MODE(obj)			(get_box_mode(obj))

// Whether the object is displayed in See Through mode in shaded viewport
#define SET_TRANSPARENT(obj, transp) set_transparent(obj, transp)
#define GET_TRANSPARENT(obj)		(get_transparent(obj))

// Calculate number of faces. This is equivalent of GET_NUM_FACES(GET_MESH(obj)),
// but CALCULATE_NUM_FACES works more faster.
#define CALCULATE_NUM_FACES(obj)	(calculate_num_faces(obj))

// Calculate number of vertices. This is equivalent of GET_NUM_VERTS(GET_MESH(obj)),
// but CALCULATE_NUM_VERTS works more faster.
#define CALCULATE_NUM_VERTS(obj)	(calculate_num_verts(obj))

// Calculate number of materials. This function can return an approximate value.
#define CALCULATE_NUM_MTLS(obj)    (calculate_num_materials(obj))

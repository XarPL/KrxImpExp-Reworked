///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Skin.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     April 5, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Get list of skin types supported by the 3D Editor
#define GET_SUPPORTED_SKIN_TYPES				get_supported_skin_types()

// Convert triangular mesh object to skin object
#define CONVERT_TO_SKIN_OBJECT(obj, skintype)	SkinData(obj, skintype)

// Check if the object specified is a skin object
#define IS_SKIN_OBJECT(obj)						is_skin_object(obj)

// Skin data
#define TSKIN								

// Create an instance of the SkinData struct to access to the skin properties
#define GET_SKIN(obj)						SkinData(obj)

// Get skin type
#define GET_SKIN_TYPE(sd)					sd.get_skin_type()

// Adds a bone to the current system.
#define ADD_BONES_TO_SKIN(sd, bones)		sd.add_bones(bones)

// This method returns the actual number of bones in the system.
#define GET_NUM_SKIN_BONES(sd)				(sd.get_num_bones())

// This method returns the INode of a particular bone. 
#define GET_SKIN_BONE(sd, boneID)			(sd.get_bone(boneID))

// Returns the number of vertices for the object the Skin modifier is applied to. 
#define GET_NUM_SKIN_VERTS(sd)				(sd.get_num_verts())

// Sets the influence of the specified bones to the specified vertex.
#define SET_VERTEX_WEIGHTS(sd, vertIdx, bones, weights) \
	sd.set_vert_weights(vertIdx, bones, weights)

// Returns the number of bones influencing the specified vertex. 
#define GET_VERTEX_NUM_WEIGHTS(sd, vertIdx)	\
	(sd.get_vert_num_weights(vertIdx))

// Returns the influence of the Nth bone affecting the specified vertex. 
#define GET_VERTEX_WEIGHT(sd, vertIdx, vertBoneIdx) \
	(sd.get_vert_weight(vertIdx, vertBoneIdx))

// Returns the system bone index of the Nth bone affecting the specified vertex. 
#define GET_VERTEX_WEIGHT_BONE(sd, vertIdx, vertBoneIdx) \
	(sd.get_vert_weight_bone(vertIdx, vertBoneIdx))

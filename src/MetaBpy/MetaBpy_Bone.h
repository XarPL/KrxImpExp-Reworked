///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Bone.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 7, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Create object which will be used as bone;
// If parentBone == ROOT_OBJECT, then this function will create a bone without a parent
#define NEW_BONE_OBJECT(name, parentBone, boundBoxMinPoint, boundBoxMaxPoint, skinType)	\
	new_bone_object(name, parentBone, boundBoxMinPoint, boundBoxMaxPoint, skinType)

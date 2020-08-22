///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Quat.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Quaternion
#define QUAT        
#define IDENTITY_QUAT           identity_quaternion()

// Representation of quaternion as orientation to axis in 3D space 
// using an angle in radians and a rotation axis 
#define NEW_QUAT(axis, angle)   new_quaternion(axis, angle)
#define GET_ANGLE(q)            get_angle(q)
#define GET_AXIS(q)             get_axis(q)


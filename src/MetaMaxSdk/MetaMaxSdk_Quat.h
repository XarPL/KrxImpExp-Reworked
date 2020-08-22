///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Quat.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Quaternion
#define TQUAT                   Quat
#define IDENTITY_QUAT           Quat(0, 0, 0, 1)

// Representation of quaternion as orientation to axis in 3D space 
// using an angle in radians and a rotation axisand 
#define NEW_QUAT(axis, angle)   Quat(AngAxis(axis, angle))
#define GET_ANGLE(q)            (AngAxis(q).angle)
#define GET_AXIS(q)             (AngAxis(q).axis)

///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Quat.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Quaternion
#define QUAT                    Quat
#define IDENTITY_QUAT           (Quat 0 0 0 1)

// Representation of quaternion as orientation to axis in 3D space 
// using an angle in radians and a rotation axisand 
#define NEW_QUAT(axis, angle)   ((AngleAxis (radToDeg (angle)) (axis)) as quat)
#define GET_ANGLE(q)            (degToRad (((q) as AngleAxis).angle))
#define GET_AXIS(q)             (((q) as AngleAxis).axis)


///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Point3.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define TPOINT3                 Point3
#define ZERO_POINT3				(point3 0 0 0)
#define NEW_POINT3(x, y, z)  (point3 (x) (y) (z))

// Set point coordinates
#define SET_X(pt, val)          pt.x = (val)
#define SET_Y(pt, val)          pt.y = (val)
#define SET_Z(pt, val)          pt.z = (val)

// Get point coordinates
#define GET_X(pt)               ((pt).x)
#define GET_Y(pt)               ((pt).y)
#define GET_Z(pt)               ((pt).z)

// Vector's length
#define VECLEN(pt)				 (length (pt))

// Dot production
#define DOTPROD(pt1, pt2)		 (dot (pt1) (pt2))

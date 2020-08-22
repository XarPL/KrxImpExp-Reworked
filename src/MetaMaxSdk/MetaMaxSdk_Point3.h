///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Point3.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define TPOINT3                 Point3
#define ZERO_POINT3				Point3(0.0f, 0.0f, 0.0f)
#define NEW_POINT3(x, y, z)  Point3( (float)(x), (float)(y), (float)(z))

// Set point coordinates
#define SET_X(pt, val)           pt.x = (float) (val);
#define SET_Y(pt, val)           pt.y = (float) (val);
#define SET_Z(pt, val)           pt.z = (float) (val);

// Get point coordinates
#define GET_X(pt)                ((pt).x)
#define GET_Y(pt)                ((pt).y)
#define GET_Z(pt)                ((pt).z)

// Vector's length
#define VECLEN(pt)				 ((pt).Length())

// Dot production
#define DOTPROD(pt1, pt2)		 (DotProd(pt1, pt2))
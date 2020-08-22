///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Point3.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define TPOINT3 
#define ZERO_POINT3			 	zero_vector()
#define NEW_POINT3(x, y, z)  	new_vector(x, y, z)

// Set point coordinates
#define SET_X(pt, val)          set_x(pt, val)
#define SET_Y(pt, val)          set_y(pt, val)
#define SET_Z(pt, val)          set_z(pt, val)

// Get point coordinates
#define GET_X(pt)               get_x(pt)
#define GET_Y(pt)               get_y(pt)
#define GET_Z(pt)               get_z(pt)

// Vector's length
#define VECLEN(pt)				 get_vector_length(pt)

// Dot production
#define DOTPROD(pt1, pt2)		 dot_product(pt1, pt2)

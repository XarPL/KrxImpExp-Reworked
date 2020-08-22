///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Color.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 12, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Color
#define TCOLOR
#define BLACK_COLOR					black_color()
#define NEW_COLOR(r, g, b)			new_color(r, g, b)

// Set color components as floats in the range 0.0 to 1.0
#define SET_RED(clr, val)         	set_red(clr, val)
#define SET_GREEN(clr, val)      	set_green(clr, val)
#define SET_BLUE(clr, val)        	set_blue(clr, val)

// Get color components as floats in the range 0.0 to 1.0
#define GET_RED(clr)              	get_red(clr)
#define GET_GREEN(clr)            	get_green(clr)
#define GET_BLUE(clr)             	get_blue(clr)

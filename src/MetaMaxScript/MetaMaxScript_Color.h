///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Color.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Color
#define TCOLOR                    	Color
#define BLACK_COLOR					(color 0 0 0)
#define NEW_COLOR(r, g, b)			(color ((r)*255) ((g)*255) ((b)*255))

// Set color components as floats in the range 0.0 to 1.0
#define SET_RED(clr, val)         	clr.r = (val) * 255
#define SET_GREEN(clr, val)      	clr.g = (val) * 255
#define SET_BLUE(clr, val)        	clr.b = (val) * 255

// Get color components as floats in the range 0.0 to 1.0
#define GET_RED(clr)              	((clr).r / 255)
#define GET_GREEN(clr)            	((clr).g / 255)
#define GET_BLUE(clr)             	((clr).b / 255)

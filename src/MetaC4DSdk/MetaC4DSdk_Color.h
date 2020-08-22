///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Color.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Color
#define TCOLOR                    Vector
#define BLACK_COLOR				  Vector(0, 0, 0)
#define NEW_COLOR(r, g, b)		  Vector(r, g, b)

// Set color components as floats in the range 0.0 to 1.0
#define SET_RED(clr, val)         clr.x = (val);
#define SET_GREEN(clr, val)       clr.y = (val);
#define SET_BLUE(clr, val)        clr.z = (val);

// Get color components as floats in the range 0.0 to 1.0
#define GET_RED(clr)              ((float) (clr).x)
#define GET_GREEN(clr)            ((float) (clr).y)
#define GET_BLUE(clr)             ((float) (clr).z)

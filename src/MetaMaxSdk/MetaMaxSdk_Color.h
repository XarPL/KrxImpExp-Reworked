///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Color.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Color
#define TCOLOR                      Color
#define BLACK_COLOR					Color(0, 0, 0)
#define NEW_COLOR(r, g, b)			Color(r, g, b)

// Set color components as floats in the range 0.0 to 1.0
#define SET_RED(clr, val)         clr.r = (val);
#define SET_GREEN(clr, val)       clr.g = (val);
#define SET_BLUE(clr, val)        clr.b = (val);

// Get color components as floats in the range 0.0 to 1.0
#define GET_RED(clr)              ((clr).r)
#define GET_GREEN(clr)            ((clr).g)
#define GET_BLUE(clr)             ((clr).b)

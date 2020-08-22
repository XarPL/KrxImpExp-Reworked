///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_Numeric.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Boolean type
#define TBOOL						bool

#ifdef FALSE
#undef FALSE
#endif
#define FALSE						false

#ifdef TRUE
#undef TRUE
#endif
#define TRUE						true

// Integer type
#define TINT						int

// Float type
#define TFLOAT                      float

// Invalid integer and invalid float - special return values for functions
#define INVALID_INT		INT_MIN
#define INVALID_FLOAT 	FLT_MAX


///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Numeric.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Boolean type
#define TBOOL						BooleanClass

#ifdef FALSE
#undef FALSE
#endif
#define FALSE						false

#ifdef TRUE
#undef TRUE
#endif
#define TRUE						true

// Integer type
#define TINT						Integer

// Float type
#define TFLOAT                      Float

// Invalid integer and invalid float - special return values for functions
#define INVALID_INT					undefined
#define INVALID_FLOAT 				undefined

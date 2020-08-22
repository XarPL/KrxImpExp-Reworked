///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_Var.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Declare local variable and initialize it
#define LOCAL_VAR(type, varname, val)	type varname = (val);

// Assign variable (local or member in a class)
#define ASSIGN(varname, val)			varname = (val);


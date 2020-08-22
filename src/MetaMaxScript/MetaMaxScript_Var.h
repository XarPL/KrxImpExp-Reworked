///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Var.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define LOCAL_VAR(type, varname, val)	local varname = val
#define ASSIGN(varname, val)			varname = val

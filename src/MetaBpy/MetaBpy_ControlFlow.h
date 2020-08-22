///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_ControlFlow.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 8, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define IF(cond) if(cond): INDENT 
#define ELSE END_INDENT else: INDENT
#define ELSE_IF(cond) END_INDENT elif(cond): INDENT
#define END_IF END_INDENT

#define AND and
#define OR or
#define NOT not

#define WHILE(expr) while(expr): INDENT
#define END_WHILE END_INDENT

#define FOR(varname, start, stop) for varname in range((start), (stop)): INDENT
#define END_FOR END_INDENT

#define CONTINUE continue
#define BREAK break

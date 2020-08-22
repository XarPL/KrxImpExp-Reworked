///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_ControlFlow.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define IF(cond) if(cond) then (
#define ELSE ) else (
#define ELSE_IF(cond) ) else if(cond) then (
#define END_IF )

#define AND and
#define OR or
#define NOT not

#define WHILE(expr) while(expr) do (
#define END_WHILE )

#define FOR(varname, start, stop) for varname in (start) to (stop - 1) do (
#define END_FOR )

#define CONTINUE continue
#define BREAK exit

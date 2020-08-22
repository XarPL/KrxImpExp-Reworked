///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_ControlFlow.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define IF(cond) if(cond) {
#define ELSE } else {
#define ELSE_IF(cond) } else if(cond) {
#define END_IF }

#define AND &&
#define OR ||
#define NOT !

#define WHILE(expr) while(expr) {
#define END_WHILE }

#define FOR(varname, start, stop) {int varname; for(varname = (start); varname < stop; ++varname) {
#define END_FOR }}

#define CONTINUE continue;
#define BREAK break;

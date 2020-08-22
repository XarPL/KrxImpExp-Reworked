///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_System.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Passes the cmd to the command interpreter, which executes the string as an operation-system command
#define SYSTEM(cmd)		DosCommand("\"" + cmd + "\"")


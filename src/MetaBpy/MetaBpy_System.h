///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_System.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 7, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Passes the cmd to the command interpreter, which executes the string as an operation-system command
#define SYSTEM(cmd)		system("\"" + cmd + "\"")

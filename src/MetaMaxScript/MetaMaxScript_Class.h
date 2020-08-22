///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Class.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Begin class declaration
#define CLASS(classname) struct classname (

// End class declaration
#define END_CLASS function doNothing =() )

// Member data
#define MEMBER_VAR(type, varname)     varname, 

// Member function with no arguments - used only inside class declaration
#define MEMBER_FUNC_0(rettype, funcname) \
	function funcname = (

// Member function with 1 argument - used only inside class declaration
#define MEMBER_FUNC_1(rettype, funcname, argtype1, argname1) \
	function funcname argname1 = (

// Member function with 2 arguments - used only inside class declaration
#define MEMBER_FUNC_2(rettype, funcname, argtype1, argname1, argtype2, argname2) \
	function funcname argname1 argname2 = (

// Member function with 3 arguments - used only inside class declaration
#define MEMBER_FUNC_3(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3) \
	function funcname argname1 argname2 argname3 = (

// Member function with 4 arguments - used only inside class declaration
#define MEMBER_FUNC_4(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4) \
	function funcname argname1 argname2 argname3 argname4 = (

// Member function with 5 arguments - used only inside class declaration
#define MEMBER_FUNC_5(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5) \
	function funcname argname1 argname2 argname3 argname4 argname5 = (

// Member function with 6 arguments - used only inside class declaration
#define MEMBER_FUNC_6(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6) \
	function funcname argname1 argname2 argname3 argname4 argname5 argname6 = (

// Member function with 7 arguments - used only inside class declaration
#define MEMBER_FUNC_7(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7) \
	function funcname argname1 argname2 argname3 argname4 argname5 argname6 argname7 = (

// Member function with 8 arguments - used only inside class declaration
#define MEMBER_FUNC_8(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7, argtype8, argname8) \
	function funcname argname1 argname2 argname3 argname4 argname5 argname6 argname7 argname8 = (
	
// End of member function declaration (for any number of arguments)
#define END_MEMBER_FUNC ),

// Member procedure with no arguments - used only inside class declaration
#define MEMBER_PROC_0(procname) \
	function procname = (

// Member procedure with 1 argument - used only inside class declaration
#define MEMBER_PROC_1(procname, argtype1, argname1) \
	function procname argname1 = (

// Member procedure with 2 arguments - used only inside class declaration
#define MEMBER_PROC_2(procname, argtype1, argname1, argtype2, argname2) \
	function procname argname1 argname2 = (

// Member procedure with 3 arguments - used only inside class declaration
#define MEMBER_PROC_3(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3) \
	function procname argname1 argname2 argname3 = (

// Member procedure with 4 arguments - used only inside class declaration
#define MEMBER_PROC_4(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4) \
	function procname argname1 argname2 argname3 argname4 = (

// Member procedure with 5 arguments - used only inside class declaration
#define MEMBER_PROC_5(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5) \
	function procname argname1 argname2 argname3 argname4 argname5 = (

// Member procedure with 6 arguments - used only inside class declaration
#define MEMBER_PROC_6(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6) \
	function procname argname1 argname2 argname3 argname4 argname5 argname6 = (

// Member procedure with 7 arguments - used only inside class declaration
#define MEMBER_PROC_7(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7) \
	function procname argname1 argname2 argname3 argname4 argname5 argname6 argname7 = (

// Member procedure with 8 arguments - used only inside class declaration
#define MEMBER_PROC_8(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7, argtype8, argname8) \
	function procname argname1 argname2 argname3 argname4 argname5 argname6 argname7 argname8 = (
	
// End of member procedure declaration (for any number of arguments)
#define END_MEMBER_PROC ),

// Prefix for a member variable/function of this class - used only in member functions
#define SELF

// Default value of class object
#define NEW_VAL(classname)				classname()

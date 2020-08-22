///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Class.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Begin class declaration
#define CLASS(classname) \
	class classname: INDENT

// End class declaration
#define END_CLASS END_INDENT

// Member data
#define MEMBER_VAR(type, varname)		

// Member function with no arguments - used only inside class declaration
#define MEMBER_FUNC_0(rettype, funcname) \
	def funcname(self): INDENT

// Member function with 1 argument - used only inside class declaration
#define MEMBER_FUNC_1(rettype, funcname, argtype1, argname1) \
	def funcname(self, argname1): INDENT

// Member function with 2 arguments - used only inside class declaration
#define MEMBER_FUNC_2(rettype, funcname, argtype1, argname1, argtype2, argname2) \
	def funcname(self, argname1, argname2): INDENT

// Member function with 3 arguments - used only inside class declaration
#define MEMBER_FUNC_3(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3) \
	def funcname(self, argname1, argname2, argname3): INDENT

// Member function with 4 arguments - used only inside class declaration
#define MEMBER_FUNC_4(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4) \
	def funcname(self, argname1, argname2, argname3, argname4): INDENT

// Member function with 5 arguments - used only inside class declaration
#define MEMBER_FUNC_5(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5) \
	def funcname(self, argname1, argname2, argname3, argname4, argname5): INDENT

// Member function with 6 arguments - used only inside class declaration
#define MEMBER_FUNC_6(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6) \
	def funcname(self, argname1, argname2, argname3, argname4, argname5, argname6): INDENT

// Member function with 7 arguments - used only inside class declaration
#define MEMBER_FUNC_7(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7) \
	def funcname(self, argname1, argname2, argname3, argname4, argname5, argname6, argname7): INDENT

// Member function with 8 arguments - used only inside class declaration
#define MEMBER_FUNC_8(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7, argtype8, argname8) \
	def funcname(self, argname1, argname2, argname3, argname4, argname5, argname6, argname7, argname8): INDENT
	
// End of member function declaration (for any number of arguments)
#define END_MEMBER_FUNC END_INDENT

// Member procedure with no arguments - used only inside class declaration
#define MEMBER_PROC_0(procname) \
	def procname(self): INDENT

// Member procedure with 1 argument - used only inside class declaration
#define MEMBER_PROC_1(procname, argtype1, argname1) \
	def procname(self, argname1): INDENT

// Member procedure with 2 arguments - used only inside class declaration
#define MEMBER_PROC_2(procname, argtype1, argname1, argtype2, argname2) \
	def procname(self, argname1, argname2): INDENT

// Member procedure with 3 arguments - used only inside class declaration
#define MEMBER_PROC_3(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3) \
	def procname(self, argname1, argname2, argname3): INDENT

// Member procedure with 4 arguments - used only inside class declaration
#define MEMBER_PROC_4(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4) \
	def procname(self, argname1, argname2, argname3, argname4): INDENT

// Member procedure with 5 arguments - used only inside class declaration
#define MEMBER_PROC_5(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5) \
	def procname(self, argname1, argname2, argname3, argname4, argname5): INDENT

// Member procedure with 6 arguments - used only inside class declaration
#define MEMBER_PROC_6(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6) \
	def procname(self, argname1, argname2, argname3, argname4, argname5, argname6): INDENT

// Member procedure with 7 arguments - used only inside class declaration
#define MEMBER_PROC_7(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7) \
	def procname(self, argname1, argname2, argname3, argname4, argname5, argname6, argname7): INDENT

// Member procedure with 8 arguments - used only inside class declaration
#define MEMBER_PROC_8(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7, argtype8, argname8) \
	def procname(self, argname1, argname2, argname3, argname4, argname5, argname6, argname7, argname8): INDENT
	
// End of member procedure declaration (for any number of arguments)
#define END_MEMBER_PROC END_INDENT

// Prefix for a member variable/function of this class - used only in member functions
#define SELF self.

// Default value of class object
#define NEW_VAL(classname)	classname()

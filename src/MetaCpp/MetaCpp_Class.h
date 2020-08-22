///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_Class.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Begin class declaration
#define CLASS(classname) \
	template <typename UNUSED_TEMPLATE_TYPE> struct __##classname;  \
	typedef __##classname<int> classname; \
	template <> struct FC<classname> {typedef classname& ArgType;}; \
	template <typename UNUSED_TEMPLATE_TYPE> struct __##classname {

// End class declaration
#define END_CLASS };

// Member data
#define MEMBER_VAR(type, varname)     type varname;

// Member function with no arguments - used only inside class declaration
#define MEMBER_FUNC_0(rettype, funcname) \
	rettype funcname() {

// Member function with 1 argument - used only inside class declaration
#define MEMBER_FUNC_1(rettype, funcname, argtype1, argname1) \
	rettype funcname(FC<argtype1>::ArgType argname1) {

// Member function with 2 arguments - used only inside class declaration
#define MEMBER_FUNC_2(rettype, funcname, argtype1, argname1, argtype2, argname2) \
	rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2) {

// Member function with 3 arguments - used only inside class declaration
#define MEMBER_FUNC_3(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3) \
	rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3) {

// Member function with 4 arguments - used only inside class declaration
#define MEMBER_FUNC_4(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4) \
	rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4) {

// Member function with 5 arguments - used only inside class declaration
#define MEMBER_FUNC_5(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5) \
	rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5) {

// Member function with 6 arguments - used only inside class declaration
#define MEMBER_FUNC_6(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6) \
	rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6) {

// Member function with 7 arguments - used only inside class declaration
#define MEMBER_FUNC_7(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7) \
	rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7) {

// Member function with 8 arguments - used only inside class declaration
#define MEMBER_FUNC_8(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7, argtype8, argname8) \
	rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7, FC<argtype8>::ArgType argname8) {
	
// End of member function declaration (for any number of arguments)
#define END_MEMBER_FUNC }

// Member procedure with no arguments - used only inside class declaration
#define MEMBER_PROC_0(procname) \
	void procname() {

// Member procedure with 1 argument - used only inside class declaration
#define MEMBER_PROC_1(procname, argtype1, argname1) \
	void procname(FC<argtype1>::ArgType argname1) {

// Member procedure with 2 arguments - used only inside class declaration
#define MEMBER_PROC_2(procname, argtype1, argname1, argtype2, argname2) \
	void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2) {

// Member procedure with 3 arguments - used only inside class declaration
#define MEMBER_PROC_3(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3) \
	void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3) {

// Member procedure with 4 arguments - used only inside class declaration
#define MEMBER_PROC_4(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4) \
	void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4) {

// Member procedure with 5 arguments - used only inside class declaration
#define MEMBER_PROC_5(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5) \
	void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5) {

// Member procedure with 6 arguments - used only inside class declaration
#define MEMBER_PROC_6(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6) \
	void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6) {

// Member procedure with 7 arguments - used only inside class declaration
#define MEMBER_PROC_7(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7) \
	void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7) {

// Member procedure with 8 arguments - used only inside class declaration
#define MEMBER_PROC_8(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7, argtype8, argname8) \
	void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7, FC<argtype8>::ArgType argname8) {
	
// End of member procedure declaration (for any number of arguments)
#define END_MEMBER_PROC }

// Prefix for a member variable/function of this class - used only in member functions
#define SELF this->

// Create new instance of class
#define NEW_VAL(classname)	classname()

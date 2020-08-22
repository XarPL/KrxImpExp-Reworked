///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_Function.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// Type of an argument of function

// Default behaviour - an argument is transferred by its value to a function
template<typename T> 
struct FC
{
	typedef T ArgType;
};



////////////////////////////////////////////////////////////////
// Modificators

// Type modificator for variables to speed up processing of returning values from functions.
// REF(type) means variable must be transferred from function by reference, 
// not by copying variable's instance. It may be used in macroses LOCAL_VAR, 
// and as a return value type for GLOBAL_FUNC and MEMBER_FUNC
// Example of usage:
// GLOBAL_FUNC_2(REF(TSomeClass), SomeFunc, TINT, firstParam, TSTRING, secondParam)
// ...
// END_GLOBAL_FUNC
// ...
// LOCAL_VAR(REF(TSomeClass), a, CALLF2(SomeFunc, 5, _T("ABC")))
//
#define REF(type)                  type&

// Inline specificator -  may be used for short function
// Example of declaration:
// INLINE GLOBAL_FUNC_1(TINT, factorial, TINT, n)
//
#define INLINE inline	



////////////////////////////////////////////////////////////////
// Global functions

// Function with no arguments
#define GLOBAL_FUNC_0(rettype, funcname) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(); \
	inline rettype funcname() \
		{return __##funcname<int>();} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname() {

// Function with 1 argument
#define GLOBAL_FUNC_1(rettype, funcname, argtype1, argname1) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1); \
	inline rettype funcname(FC<argtype1>::ArgType argname1) \
		{return __##funcname<int>(argname1);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1) {

// Function with 2 arguments
#define GLOBAL_FUNC_2(rettype, funcname, argtype1, argname1, argtype2, argname2) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2); \
	inline rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2) \
		{return __##funcname<int>(argname1, argname2);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2) {

// Function with 3 arguments
#define GLOBAL_FUNC_3(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3); \
	inline rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3) \
		{return __##funcname<int>(argname1, argname2, argname3);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3) {

// Function with 4 arguments
#define GLOBAL_FUNC_4(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4); \
	inline rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4) \
		{return __##funcname<int>(argname1, argname2, argname3, argname4);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4) {

// Function with 5 arguments
#define GLOBAL_FUNC_5(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5); \
	inline rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5) \
		{return __##funcname<int>(argname1, argname2, argname3, argname4, argname5);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5) {

// Function with 6 arguments
#define GLOBAL_FUNC_6(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6); \
	inline rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6) \
		{return __##funcname<int>(argname1, argname2, argname3, argname4, argname5, argname6);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6) {

// Function with 7 arguments
#define GLOBAL_FUNC_7(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7); \
	inline rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7) \
		{return __##funcname<int>(argname1, argname2, argname3, argname4, argname5, argname6, argname7);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7) {

// Function with 8 arguments
#define GLOBAL_FUNC_8(rettype, funcname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7, argtype8, argname8) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7, FC<argtype8>::ArgType argname8); \
	inline rettype funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7, FC<argtype8>::ArgType argname8) \
		{return __##funcname<int>(argname1, argname2, argname3, argname4, argname5, argname6, argname7, argname8);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		rettype __##funcname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7, FC<argtype8>::ArgType argname8) {
		
// End of function declaration (for any number of arguments)
#define END_GLOBAL_FUNC }

// Return a result (used in function declaration)
#define RETURN_VAL(retval) return (retval);

// Function calling
#define CALLF0(funcname)									funcname()
#define CALLF1(funcname, arg1)								funcname(arg1)
#define CALLF2(funcname, arg1, arg2)						funcname(arg1, arg2)
#define CALLF3(funcname, arg1, arg2, arg3)					funcname(arg1, arg2, arg3)
#define CALLF4(funcname, arg1, arg2, arg3, arg4)			funcname(arg1, arg2, arg3, arg4)
#define CALLF5(funcname, arg1, arg2, arg3, arg4, arg5)				funcname(arg1, arg2, arg3, arg4, arg5)
#define CALLF6(funcname, arg1, arg2, arg3, arg4, arg5, arg6)		funcname(arg1, arg2, arg3, arg4, arg5, arg6)
#define CALLF7(funcname, arg1, arg2, arg3, arg4, arg5, arg6, arg7)			funcname(arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define CALLF8(funcname, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)	funcname(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)


////////////////////////////////////////////////////////////////
// Global procedures

// Procedure with 0 argument
#define GLOBAL_PROC_0(procname) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(); \
	inline void procname() \
		{__##procname<int>();} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname() {

// Procedure with 1 argument
#define GLOBAL_PROC_1(procname, argtype1, argname1) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1); \
	inline void procname(FC<argtype1>::ArgType argname1) \
		{__##procname<int>(argname1);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1) {

// Procedure with 2 arguments
#define GLOBAL_PROC_2(procname, argtype1, argname1, argtype2, argname2) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2); \
	inline void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2) \
		{__##procname<int>(argname1, argname2);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2) {

// Procedure with 3 arguments
#define GLOBAL_PROC_3(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3); \
	inline void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3) \
		{__##procname<int>(argname1, argname2, argname3);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3) {

// Procedure with 4 arguments
#define GLOBAL_PROC_4(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4); \
	inline void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4) \
		{__##procname<int>(argname1, argname2, argname3, argname4);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4) {

// Procedure with 5 arguments
#define GLOBAL_PROC_5(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5); \
	inline void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5) \
		{__##procname<int>(argname1, argname2, argname3, argname4, argname5);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5) {

// Procedure with 6 arguments
#define GLOBAL_PROC_6(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6); \
	inline void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6) \
		{__##procname<int>(argname1, argname2, argname3, argname4, argname5, argname6);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6) {

// Procedure with 7 arguments
#define GLOBAL_PROC_7(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7); \
	inline void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7) \
		{__##procname<int>(argname1, argname2, argname3, argname4, argname5, argname6, argname7);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7) {

// Procedure with 8 arguments
#define GLOBAL_PROC_8(procname, argtype1, argname1, argtype2, argname2, argtype3, argname3, argtype4, argname4, argtype5, argname5, argtype6, argname6, argtype7, argname7, argtype8, argname8) \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7, FC<argtype8>::ArgType argname8); \
	inline void procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7, FC<argtype8>::ArgType argname8) \
		{__##procname<int>(argname1, argname2, argname3, argname4, argname5, argname6, argname7, argname8);} \
	template<typename UNUSED_TEMPLATE_TYPE> \
		void __##procname(FC<argtype1>::ArgType argname1, FC<argtype2>::ArgType argname2, FC<argtype3>::ArgType argname3, FC<argtype4>::ArgType argname4, FC<argtype5>::ArgType argname5, FC<argtype6>::ArgType argname6, FC<argtype7>::ArgType argname7, FC<argtype8>::ArgType argname8) {
		
// End of function declaration (for any number of arguments)
#define END_GLOBAL_PROC }

// Return from procedure (used in procedure declaration)
#define RETURN return;

// Procedure calling
#define CALLP0(procname)									procname();
#define CALLP1(procname, arg1)								procname(arg1);
#define CALLP2(procname, arg1, arg2)						procname(arg1, arg2);
#define CALLP3(procname, arg1, arg2, arg3)					procname(arg1, arg2, arg3);
#define CALLP4(procname, arg1, arg2, arg3, arg4)			procname(arg1, arg2, arg3, arg4);
#define CALLP5(procname, arg1, arg2, arg3, arg4, arg5)				procname(arg1, arg2, arg3, arg4, arg5);
#define CALLP6(procname, arg1, arg2, arg3, arg4, arg5, arg6)		procname(arg1, arg2, arg3, arg4, arg5, arg6);
#define CALLP7(procname, arg1, arg2, arg3, arg4, arg5, arg6, arg7)			procname(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
#define CALLP8(procname, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)	procname(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);


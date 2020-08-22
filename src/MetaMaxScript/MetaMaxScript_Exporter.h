///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Exporter.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Main export function
// Example of arguments:
// expname: Exp3ds
// ext: "3DS"
// desc: "Autodesk 3D Studio Mesh"
// author: "Christer Janson"
// year: 2000
// version: 1.10
// maxida: 0x4a26450c
// maxidb: 0x85548e0b
#define EXPORT_FUNC(expname, ext, desc, author, year, version, maxida, maxidb, c4did) \
function expname filename:"" quiet:false = \
( \
	local tskmod = getCommandPanelTaskMode(); \
	setCommandPanelTaskMode mode:HASHcreate; \
	selectionSets[#expname] = selection; \
	local r = execute("__" + #expname + " " + (Stringize filename) + " " + (quiet as String)); \
	setCommandPanelTaskMode mode:tskmod; \
	if selectionSets[#expname] != undefined then \
	(\
		select selectionSets[#expname]; \
		deleteItem selectionSets #expname; \
	);\
	return (r == IMPEXP_SUCCESS); \
); \
\
function __##expname filename_param quiet_param = \
( \
	local QUIET = quiet_param; \
	local EXPORT_FILE_NAME = filename_param; \
	if EXPORT_FILE_NAME == "" then \
		EXPORT_FILE_NAME = getSaveFileName caption:"Select File to Export" types:(desc + " (*." + ext + ")|*." + ext + "|"); \
	if (EXPORT_FILE_NAME == undefined) or (EXPORT_FILE_NAME == "") then \
		return IMPEXP_CANCEL; \
		
// Put it after export function's body
#define END_EXPORT_FUNC )

// Call exporter
#define CALL_EXPORTER(filename_param, quiet_param, expname, maxida, maxidb, c4did) \
( \
	if (classOf(expname) == UndefinedClass) then \
	( \
		fileIn (#expname + ".ms"); \
	); \
	local str = #expname; \
	str = str + " filename:" + Stringize(filename_param); \
	str = str + " quiet:" + (quiet_param as string); \
	execute(str) \
)

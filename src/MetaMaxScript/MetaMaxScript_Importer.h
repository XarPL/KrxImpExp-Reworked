///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Importer.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Return values for import/export functions
#define IMPEXP_FAIL		0
#define IMPEXP_SUCCESS	1
#define IMPEXP_CANCEL	2

// Double backslashes
function Stringize str =
(
  local rstr = "\""
  for i = 1 to str.count do
  (
    local ch = str[i]
    if ch == "\"" then
      ch = "\\\""
    if ch == "\n" then
      ch = "\\n"
    if ch == "\r" then
      ch = "\\r"
    else if ch == "\t" then
      ch = "\\t"
    else if ch == "\*" then
      ch = "\\\*"
    else if ch == "\?" then
      ch = "\\\?"
    else if ch == "\\" then
      ch = "\\\\"
    else if ch == "\%" then
      ch = "\\\%"
    rstr = rstr + ch
  )
  rstr = rstr + "\""
  return rstr
)

// Resume command panel if needed
/*function ResumeEditingIfNeeded =
(
	if(classOf(resumeEditing) == UndefinedClass) then
		return undefined
	
	local testNode
	local delTestNode
	if(rootNode.children.count == 0) then
	(
		testNode = box()
		delTestNode = true
	)
	else
	(
		testNode = rootNode.children[1]
		delTestNode = false
	)
	clearSelection()
	testNode.isSelected = true
	setCommandPanelTaskMode mode:HASHmodify
	while(modPanel.getCurrentObject() != testNode) do
	(
		resumeEditing()
	)
	if(delTestNode) then
		delete testNode
)*/


// Main import function
// Example of arguments:
// impname: Imp3ds
// ext: "3DS"
// desc: "Autodesk 3D Studio Mesh"
// author: "Christer Janson"
// year: 2000
// version: 1.10
// maxida: 0x4a26450c
// maxidb: 0x85548e0b
#define IMPORT_FUNC(impname, ext, desc, author, year, version, maxida, maxidb, c4did) \
function impname filename:"" quiet:false = \
( \
	local tskmod = getCommandPanelTaskMode(); \
	setCommandPanelTaskMode mode:HASHcreate; \
	selectionSets[#impname] = selection; \
	local r = execute("__" + #impname + " " + (Stringize filename) + " " + (quiet as String)); \
	setCommandPanelTaskMode mode:tskmod; \
	if r == IMPEXP_SUCCESS then \
	( \
		select objects; \
		max zoomext sel all; \
		clearSelection(); \
	); \
	if selectionSets[#impname] != undefined then \
	(\
		select selectionSets[#impname]; \
		deleteItem selectionSets #impname; \
	);\
	return (r == IMPEXP_SUCCESS); \
); \
\
function __##impname filename_param quiet_param = \
( \
	local QUIET = quiet_param; \
	local IMPORT_FILE_NAME = filename_param; \
	if IMPORT_FILE_NAME == "" then \
	IMPORT_FILE_NAME = getOpenFileName caption:"Select File to Import" types:(desc + " (*." + ext + ")|*." + ext + "|"); \
	if (IMPORT_FILE_NAME == undefined) or (IMPORT_FILE_NAME == "") then \
		return IMPEXP_CANCEL; \
	local IMPORT_FILE_SIZE = GetFileSize IMPORT_FILE_NAME; \
	if (IMPORT_FILE_SIZE == undefined) then \
		return IMPEXP_CANCEL; \ 

// Put it after import function's body
#define END_IMPORT_FUNC )

// Call importer
#define CALL_IMPORTER(filename_param, quiet_param, impname, maxida, maxidb, c4did) \
( \
	if (classOf(impname) == UndefinedClass) then \
	( \
		fileIn (#impname + ".ms"); \
	); \
	local str = #impname; \
	str = str + " filename:" + Stringize(filename_param); \
	str = str + " quiet:" + (quiet_param as string); \
	execute(str) \
)


///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_StdDirs.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function AppendSlashIfNeeded dir =
(
	local last = dir[dir.count]
	if last != "\\" then
		dir = dir + "\\"
	return dir
)

function GetRootDir =
(
	return (AppendSlashIfNeeded (GetDir #maxroot))
)

function GetPlugCfgDir = 
(
	return (AppendSlashIfNeeded (GetDir #plugcfg))
)

// Get main max executable folder full path. 
// For example, "C:\\Program Files\\Autodesk\\3ds max 2009\\" 
#define ROOT_DIR		(GetRootDir())

// Get folder for plug-in configuration files. 
// For example, "C:\\Program Files\\Autodesk\\3ds max 5\\plugcfg" 
// or "C:\\Documents and Settings\\Username\\Local Settings\\Application Data\\Autodesk\\3ds max\\2009 - 32bit\\enu\\plugcfg\\".
#define PLUGCFG_DIR		(GetPlugCfgDir())


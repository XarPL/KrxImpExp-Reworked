-------------------------------------------------------------------------------
-- Name:        KrxImpExpUtil.ms
-- Purpose:     Panel in the "Utility" tab to allow user to import/export 
--              3ds/asc files from gmax and 3ds max
-- Author:      Vitaly Baranov
-- Created:     January 14, 2009
-- Licence:     GNU General Public License
-------------------------------------------------------------------------------

-- Check if this is gmax
function _IsGMax =
(
	return (classOf(gmax_file_finder) != UndefinedClass)
)

-- Includes "KrxGMaxExtender.ms" if this is gmax
-- (Order of executing of startup scripts is not defined
-- therefore the following "fileIn" is needed to ensure
-- KrxGMaxExtender.ms have been evaluated)
if(_IsGMax()) then
	fileIn "startup\\KrxGMaxExtender.ms"

-- The pure gmax doesn't supported the write-to-file operations
-- This function returns true if this is gmax and it wasn't extended
function _IsPureGMax =
(
	return ((_IsGMax()) and not(_IsKrxGMaxExtenderDllLoaded()))
)

-- Get path to configuration file
function _GetCfgFilename =
(
	local dir = (GetDir #plugcfg)
	local last = dir[dir.count]
	if last != "\\" then
		dir = dir + "\\"
	return dir + "KrxImpExpUtil.cfg"
)

-- Parameters in configuration file
global _cfgLang

-- Read configuration file
function _ReadCfgFile =
(
	_cfgLang = "MAXScript"
	if not(_IsGMax()) then
	(
		_cfgLang = "C++"
		local filename = _GetCfgFileName()
		local strm = (openFile filename)
		if(strm != undefined) then
		(
			local s = readLine strm
			if(s != undefined and s != "") then
			(
				if((findString s "MAXScript") != undefined) then
					_cfgLang = "MAXScript"
				else
					_cfgLang = "C++"
			)
			close strm
		)
	)
)

-- Write configuration file
function _WriteCfgFile =
(
	if not(_IsGMax()) then
	(
		local filename = _GetCfgFileName()
		local strm = (createFile filename)
		if(strm != undefined) then
		(
			format "Language = \"%\"\n" _cfgLang to:strm
			close strm
		)
	)
)

-- Panel in the "Utility" tab
utility utilKrxImpExp "KrxImpExp" width:160 height:429
(
	button btnImportASC "Import ASC..." pos:[22,20] width:117 height:25
	button btnImport3DS "Import 3DS..." pos:[22,55] width:117 height:25
	button btnImportMSH "Import MSH..." pos:[22,90] width:117 height:25
	button btnImportMRM "Import MRM..." pos:[22,125] width:117 height:25
	button btnImportZEN "Import ZEN..." pos:[22,160] width:117 height:25
	button btnExportASC "Export ASC..." pos:[22,195] width:117 height:25
	button btnExport3DS "Export 3DS..." pos:[22,230] width:117 height:25
	button btnClose "Close" pos:[22,264] width:117 height:25
	button btnStdCloseBtnMover "StdCloseBtnMover" pos:[22,400] width:117 height:1 enabled:false
	dropdownList ddLang "" pos:[22,300] width:117 height:21 items:#("MAXScript", "C++")
	on utilKrxImpExp open do
	(
		utilKrxImpExp.height = 330
		ddLang.items = #("MAXScript")
		if not(_IsGMax()) then
		(
			local items = ddLang.items
			append items "C++"
			ddLang.items = items
		)
		_ReadCfgFile()
		for i in 1 to ddLang.items.count do
		(
			if(ddLang.items[i] == _cfgLang) then
			(
				ddLang.selection = i
				exit
			)
		)
	)
	on ddLang selected sel do
	(
		_cfgLang = ddLang.items[ddLang.selection]
		_WriteCfgFile()
	)
	on btnImportASC pressed do
	(
		if(_IsPureGMax()) then
		(
			closeUtility utilKrxImpExp
		)
		else if(_cfgLang == "C++") then
		(
			filename = getOpenFileName caption:"Select File to Import" types:("Kerrax ASCII Model (*.ASC)|*.ASC|")
			if (filename != undefined) and (filename != "") then
			(
				importFile filename
			)
		)
		else
		(
			if(classOf(KrxAscImp) == UndefinedClass) then
			(
				fileIn "KrxAscImp.ms"
			)
			execute("KrxAscImp()")
		)
	)
	on btnImport3DS pressed do
	(
		if(_IsPureGMax()) then
		(
			closeUtility utilKrxImpExp
		)
		else if(_cfgLang == "C++") then
		(
			filename = getOpenFileName caption:"Select File to Import" types:("Kerrax 3D Studio Mesh (*.3DS)|*.3DS|")
			if (filename != undefined) and (filename != "") then
			(
				importFile filename
			)
		)
		else
		(
			if(classOf(Krx3dsImp) == UndefinedClass) then
			(
				fileIn "Krx3dsImp.ms"
			)
			execute("Krx3dsImp()")
		)
	)
	on btnImportMSH pressed do
	(
		if(_IsPureGMax()) then
		(
			closeUtility utilKrxImpExp
		)
		else if(_cfgLang == "C++") then
		(
			filename = getOpenFileName caption:"Select File to Import" types:("Kerrax Compiled Mesh (*.MSH)|*.MSH|")
			if (filename != undefined) and (filename != "") then
			(
				importFile filename
			)
		)
		else
		(
			if(classOf(KrxMshImp) == UndefinedClass) then
			(
				fileIn "KrxMshImp.ms"
			)
			execute("KrxMshImp()")
		)
	)
	on btnImportMRM pressed do
	(
		if(_IsPureGMax()) then
		(
			closeUtility utilKrxImpExp
		)
		else if(_cfgLang == "C++") then
		(
			filename = getOpenFileName caption:"Select File to Import" types:("Kerrax Multi-Resolution Mesh (*.MRM)|*.MRM|")
			if (filename != undefined) and (filename != "") then
			(
				importFile filename
			)
		)
		else
		(
			if(classOf(KrxMrmImp) == UndefinedClass) then
			(
				fileIn "KrxMrmImp.ms"
			)
			execute("KrxMrmImp()")
		)
	)
	on btnImportZEN pressed do
	(
		if(_IsPureGMax()) then
		(
			closeUtility utilKrxImpExp
		)
		else if(_cfgLang == "C++") then
		(
			filename = getOpenFileName caption:"Select File to Import" types:("Kerrax ZenGin World (*.ZEN)|*.ZEN|")
			if (filename != undefined) and (filename != "") then
			(
				importFile filename
			)
		)
		else
		(
			if(classOf(KrxZenImp) == UndefinedClass) then
			(
				fileIn "KrxZenImp.ms"
			)
			execute("KrxZenImp()")
		)
	)
	on btnExportASC pressed do
	(
		if(_IsPureGMax()) then
		(
			closeUtility utilKrxImpExp
		)
		else if(_cfgLang == "C++") then
		(
			filename = getSaveFileName caption:"Select File to Export" types:("Kerrax ASCII Model (*.ASC)|*.ASC|")
			if (filename != undefined) and (filename != "") then
			(
				exportFile filename
			)
		)
		else
		(
			if(classOf(KrxAscExp) == UndefinedClass) then
			(
				fileIn "KrxAscExp.ms"
			)
			execute("KrxAscExp()")
		)
	)
	on btnExport3DS pressed do
	(
		if(_IsPureGMax()) then
		(
			closeUtility utilKrxImpExp
		)
		else if(_cfgLang == "C++") then
		(
			filename = getSaveFileName caption:"Select File to Export" types:("Kerrax 3D Studio Mesh (*.3DS)|*.3DS|")
			if (filename != undefined) and (filename != "") then
			(
				exportFile filename
			)
		)
		else
		(
			if(classOf(Krx3dsExp) == UndefinedClass) then
			(
				fileIn "Krx3dsExp.ms"
			)
			execute("Krx3dsExp()")
		)
	)
	on btnClose pressed do
	(
		closeUtility utilKrxImpExp
	)
)
if(not(_IsPureGMax())) then
	openUtility utilKrxImpExp
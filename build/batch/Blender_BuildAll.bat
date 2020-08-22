@cls
@ECHO OFF
SET /p ver="Enter target blender version: "
call "%~dp0internal\Bpy_Copy_Help_" %ver%
call "%~dp0internal\Bpy_Copy_Locale_" %ver%
call "%~dp0internal\Bpy_Copy_SampleMeshes_" %ver%
:choice
set /P c=Are you wanna use scripts for old API (before 2.8 version)[Y/N]?
if /I "%c%" EQU "Y" goto :old
if /I "%c%" EQU "N" goto :new
goto :choice
:old
call "%~dp0internal\Bpy_Copy_ReadyScripts_" %ver% old
goto :continue
:new
call "%~dp0internal\Bpy_Copy_ReadyScripts_" %ver% new
goto :continue
:continue
call "%~dp0internal\Bpy_Make_ImpExpScript_" 3dsExp %ver%
call "%~dp0internal\Bpy_Make_ImpExpScript_" 3dsImp %ver%
call "%~dp0internal\Bpy_Make_ImpExpScript_" AscExp %ver%
call "%~dp0internal\Bpy_Make_ImpExpScript_" AscImp %ver%
call "%~dp0internal\Bpy_Make_ImpExpScript_" MrmImp %ver%
call "%~dp0internal\Bpy_Make_ImpExpScript_" MshImp %ver%
call "%~dp0internal\Bpy_Make_ImpExpScript_" ZenImp %ver%
@set XCPYOPT=/y /f
@xcopy "%KRXIMPEXP_INSTALL%\blender\wxImpExpUI.exe" "%KRXIMPEXP_INSTALL%\blender\%ver%\scripts\addons\KrxImpExp\" %XCPYOPT%
@pause
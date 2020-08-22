@cls
@ECHO OFF
SET /p ver="Enter target blender version: "
:choice
set /P c=Are you wanna use scripts for old API (before 2.8 version)[Y/N]?
if /I "%c%" EQU "Y" goto :old
if /I "%c%" EQU "N" goto :new
goto :choice
:old
call "%~dp0internal\Blender_BuildAll_" %ver% old
goto :continue
:new
call "%~dp0internal\Blender_BuildAll_" %ver% new
goto :continue
:continue
@pause
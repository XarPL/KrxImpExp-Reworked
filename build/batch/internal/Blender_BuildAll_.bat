
call "%~dp0Bpy_Copy_Help_" %1
call "%~dp0Bpy_Copy_Locale_" %1
call "%~dp0Bpy_Copy_SampleMeshes_" %1
call "%~dp0Bpy_Copy_ReadyScripts_" %1 %2
call "%~dp0Bpy_Make_ImpExpScript_" 3dsExp %1
call "%~dp0Bpy_Make_ImpExpScript_" 3dsImp %1
call "%~dp0Bpy_Make_ImpExpScript_" AscExp %1
call "%~dp0Bpy_Make_ImpExpScript_" AscImp %1
call "%~dp0Bpy_Make_ImpExpScript_" MrmImp %1
call "%~dp0Bpy_Make_ImpExpScript_" MshImp %1
call "%~dp0Bpy_Make_ImpExpScript_" ZenImp %1
@set XCPYOPT=/y /f
@xcopy "%KRXIMPEXP_INSTALL%\blender\wxImpExpUI.exe" "%KRXIMPEXP_INSTALL%\blender\%1\scripts\addons\KrxImpExp\" %XCPYOPT%
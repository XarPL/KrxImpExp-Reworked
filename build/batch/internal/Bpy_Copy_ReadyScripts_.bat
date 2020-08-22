@set XCPYOPT=/y /s /f
@if %2 == old goto :OldScripts
goto :NewScripts

:NewScripts
@xcopy "%KRXIMPEXP%\src\BlenderScripts\*.py"       "%KRXIMPEXP_INSTALL%\blender\%1\scripts\addons\KrxImpExp\" %XCPYOPT%
goto :EOF

:OldScripts
@xcopy "%KRXIMPEXP%\src\BlenderScriptsOld\*.py"       "%KRXIMPEXP_INSTALL%\blender\%1\scripts\addons\KrxImpExp\" %XCPYOPT%
goto :EOF

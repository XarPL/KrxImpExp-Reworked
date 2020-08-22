@set XCPYOPT=/y /s /f

@xcopy "%KRXIMPEXP%\locale\*.*" "%KRXIMPEXP_INSTALL%\blender\%1\scripts\addons\KrxImpExp\locale\" %XCPYOPT%

@set XCPYOPT=/y /s /f

@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%KRXIMPEXP_INSTALL%\blender\%1\scripts\addons\KrxImpExp\sample_meshes\" %XCPYOPT%

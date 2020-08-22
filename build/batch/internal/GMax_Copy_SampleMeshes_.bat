@set XCPYOPT=/y /s /f

@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%GMAXDIR%\KrxImpExp\sample_meshes\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%KRXIMPEXP_INSTALL%\gmax\KrxImpExp\sample_meshes\" %XCPYOPT%

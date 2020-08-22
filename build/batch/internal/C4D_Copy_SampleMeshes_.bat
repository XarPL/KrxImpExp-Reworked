@set XCPYOPT=/y /s /f

@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%C4DDIR_96%\plugins\KrxImpExp\sample_meshes\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%C4DDIR_100%\plugins\KrxImpExp\sample_meshes\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%C4DDIR_105%\plugins\KrxImpExp\sample_meshes\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%C4DDIR_120%\plugins\KrxImpExp\sample_meshes\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%KRXIMPEXP_INSTALL%\c4d96\plugins\KrxImpExp\sample_meshes\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%KRXIMPEXP_INSTALL%\c4d100\plugins\KrxImpExp\sample_meshes\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%KRXIMPEXP_INSTALL%\c4d105\plugins\KrxImpExp\sample_meshes\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\sample_meshes\*.3ds" "%KRXIMPEXP_INSTALL%\c4d120\plugins\KrxImpExp\sample_meshes\" %XCPYOPT%

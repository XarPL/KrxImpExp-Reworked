@set XCPYOPT=/y /s /f

@xcopy "%KRXIMPEXP%\locale\*.*" "%C4DDIR_96%\plugins\KrxImpExp\locale\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\locale\*.*" "%C4DDIR_100%\plugins\KrxImpExp\locale\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\locale\*.*" "%C4DDIR_105%\plugins\KrxImpExp\locale\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\locale\*.*" "%C4DDIR_120%\plugins\KrxImpExp\locale\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\locale\*.*" "%KRXIMPEXP_INSTALL%\c4d96\plugins\KrxImpExp\locale\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\locale\*.*" "%KRXIMPEXP_INSTALL%\c4d100\plugins\KrxImpExp\locale\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\locale\*.*" "%KRXIMPEXP_INSTALL%\c4d105\plugins\KrxImpExp\locale\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\locale\*.*" "%KRXIMPEXP_INSTALL%\c4d120\plugins\KrxImpExp\locale\" %XCPYOPT%

@set XCPYOPT=/y /s /f

@xcopy "%KRXIMPEXP%\locale\*.*" "%GMAXDIR%\KrxImpExp\locale\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\locale\*.*" "%KRXIMPEXP_INSTALL%\gmax\KrxImpExp\locale\" %XCPYOPT%

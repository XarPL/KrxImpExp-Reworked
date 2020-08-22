@set XCPYOPT=/y /s /f

@xcopy "%KRXIMPEXP%\src\MaxImpExpUtil\KrxImpExpUtil.ms" "%GMAXDIR%\scripts\startup\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\src\MaxImpExpUtil\KrxImpExpUtil.ms" "%KRXIMPEXP_INSTALL%\gmax\scripts\startup\" %XCPYOPT%

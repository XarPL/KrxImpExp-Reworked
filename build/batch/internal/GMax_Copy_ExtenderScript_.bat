@set XCPYOPT=/y /s /f

@xcopy "%KRXIMPEXP%\src\GMaxExtenderScript\KrxGMaxExtender.ms" "%GMAXDIR%\scripts\startup\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\src\GMaxExtenderScript\KrxGMaxExtender_test*.ms" "%GMAXDIR%\scripts\" %XCPYOPT%
@xcopy "%GMAXDIR%\scripts\startup\KrxGMaxExtender.ms" "%KRXIMPEXP_INSTALL%\gmax\scripts\startup\" %XCPYOPT%

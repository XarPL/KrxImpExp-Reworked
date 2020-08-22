@if "%1" == "exe" goto :CopyExe
@if "%1" == "dll" goto :CopyDll

:CopyExe
@set XCPYOPT=/y /s /f
@xcopy "%KRXIMPEXP_INTERMEDIATE%\GMaxExtender\%2\KrxGMaxExtender.exe" "%KRXIMPEXP_INSTALL%\gmax\" %XCPYOPT%
@goto :EOF

:CopyDll
@set XCPYOPT=/y /s /f
@xcopy "%KRXIMPEXP_INTERMEDIATE%\GMaxExtenderDLL\%2\KrxGMaxExtender.dll" "%KRXIMPEXP_INSTALL%\gmax\" %XCPYOPT%
@goto :EOF

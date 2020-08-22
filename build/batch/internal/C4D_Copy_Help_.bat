@if "%1" == "" goto :PlanCopy
goto :DoCopy

:PlanCopy
@call "%0" all3d
@call "%0" cinema4d
@goto :EOF

:DoCopy
@set XCPYOPT=/y /s /f
@xcopy "%KRXIMPEXP%\help\%1" "%C4DDIR_96%\plugins\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%C4DDIR_100%\plugins\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%C4DDIR_105%\plugins\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%C4DDIR_120%\plugins\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\c4d96\plugins\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\c4d100\plugins\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\c4d105\plugins\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\c4d120\plugins\KrxImpExp\help\" %XCPYOPT%

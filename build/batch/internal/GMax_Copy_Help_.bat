@if "%1" == "" goto :PlanCopy
goto :DoCopy

:PlanCopy
@call "%0" all3d
@call "%0" gmax
@call "%0" gmax_and_3dsmax
@goto :EOF

:DoCopy
@set XCPYOPT=/y /s /f
@xcopy "%KRXIMPEXP%\help\%1"   "%GMAXDIR%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1"   "%KRXIMPEXP_INSTALL%\gmax\KrxImpExp\help\" %XCPYOPT%

@if "%1" == "" goto :PlanCopy
goto :DoCopy

:PlanCopy
@call "%0" all3d
@call "%0" 3dsmax
@call "%0" gmax_and_3dsmax
@goto :EOF

:DoCopy
@set XCPYOPT=/y /s /f
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_5%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_6%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_9%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_9_X64%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_11%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_11_X64%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_12%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_12_X64%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_14%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_14_X64%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_15%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%MAXDIR_15_X64%\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max5\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max6\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max9\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max9_x64\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max11\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max11_x64\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max12\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max12_x64\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max14\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max14_x64\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max15\KrxImpExp\help\" %XCPYOPT%
@xcopy "%KRXIMPEXP%\help\%1" "%KRXIMPEXP_INSTALL%\max15_x64\KrxImpExp\help\" %XCPYOPT%

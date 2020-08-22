@if "%2" == "" goto :PlanCopy
goto :DoCopy

:PlanCopy
@call "%0" %1 all3d 
@call "%0" %1 blender
@goto :EOF

:DoCopy
@set XCPYOPT=/y /s /f
@xcopy "%KRXIMPEXP%\help\%2"   "%KRXIMPEXP_INSTALL%\blender\%1\scripts\addons\KrxImpExp\help\" %XCPYOPT%

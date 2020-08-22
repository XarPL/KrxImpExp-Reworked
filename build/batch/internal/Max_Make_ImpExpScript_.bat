@if "%1" == "3dsImp" goto :CopyPoint
@if "%1" == "3dsExp" goto :CopyPoint
@if "%1" == "AscImp" goto :CopyPoint
@if "%1" == "AscExp" goto :CopyPoint
@if "%1" == "MshImp" goto :CopyPoint
@if "%1" == "ZenImp" goto :CopyPoint
@if "%1" == "MrmImp" goto :CopyPoint

@echo Syntax: Make_MaxScript_ImpExp name testmode
@echo where
@echo     name is either "3dsImp" or "3dsExp" or "AscImp" or "AscExp"
@echo     or "MshImp" or "ZenImp" or "MrmImp", without quotes.
@echo     testmode is either empty or any non-empty value.
@goto :EOF

:CopyPoint
@md "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp"
"%WAVEDIR%\wave.exe" "%KRXIMPEXP%\src\Meta\%1orter.meta" -I "%KRXIMPEXP%\src\Meta" -I "%KRXIMPEXP%\src\MetaMaxScript" -o "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.wave"
"%SEDDIR%\bin\sed.exe" -f %~dp0Max_PostProcessScript_.sed "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.wave" > "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms"

@set XCPYOPT=/y /s /f	
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max5\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max6\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max9\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max9_x64\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max11\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max11_x64\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max12\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max12_x64\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max14\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max14_x64\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max15\scripts\" %XCPYOPT%
@xcopy "%KRXIMPEXP_INTERMEDIATE%\MaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\max15_x64\scripts\" %XCPYOPT%

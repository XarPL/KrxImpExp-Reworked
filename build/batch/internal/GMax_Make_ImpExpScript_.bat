@if "%1" == "3dsImp" goto :CopyPoint
@if "%1" == "3dsExp" goto :CopyPoint
@if "%1" == "AscImp" goto :CopyPoint
@if "%1" == "AscExp" goto :CopyPoint
@if "%1" == "MshImp" goto :CopyPoint
@if "%1" == "ZenImp" goto :CopyPoint
@if "%1" == "MrmImp" goto :CopyPoint

@echo Syntax: Make_GMaxScript_ImpExp name testmode
@echo where
@echo     name is either "3dsImp" or "3dsExp" or "AscImp" or "AscExp"
@echo     or "MshImp" or "ZenImp" or "MrmImp", without quotes.
@echo     testmode is either empty or any non-empty value.
@goto :EOF

:CopyPoint
@md "%KRXIMPEXP_INTERMEDIATE%\GMaxScriptImpExp"
"%WAVEDIR%\wave.exe" "%KRXIMPEXP%\src\Meta\%1orter.meta" -I "%KRXIMPEXP%\src\Meta" -I "%KRXIMPEXP%\src\MetaGMaxScript" -I "%KRXIMPEXP%\src\MetaMaxScript" -o "%KRXIMPEXP_INTERMEDIATE%\GMaxScriptImpExp\Krx%1.wave"
"%SEDDIR%\bin\sed.exe" -f %~dp0Max_PostProcessScript_.sed "%KRXIMPEXP_INTERMEDIATE%\GMaxScriptImpExp\Krx%1.wave" > "%KRXIMPEXP_INTERMEDIATE%\GMaxScriptImpExp\Krx%1.ms"

@set XCPYOPT=/y /s /f	
@xcopy "%KRXIMPEXP_INTERMEDIATE%\GMaxScriptImpExp\Krx%1.ms" "%KRXIMPEXP_INSTALL%\gmax\scripts\" %XCPYOPT%

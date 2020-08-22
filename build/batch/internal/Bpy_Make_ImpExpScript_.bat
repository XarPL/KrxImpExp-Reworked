@if "%1" == "3dsImp" goto :CopyPoint
@if "%1" == "3dsExp" goto :CopyPoint
@if "%1" == "AscImp" goto :CopyPoint
@if "%1" == "AscExp" goto :CopyPoint
@if "%1" == "MshImp" goto :CopyPoint
@if "%1" == "ZenImp" goto :CopyPoint
@if "%1" == "MrmImp" goto :CopyPoint

@echo Syntax: Make_BpyBased_ImpExp name testmode
@echo where
@echo     name is either "3dsImp" or "3dsExp" or "AscImp" or "AscExp" 
@echo     or "MshImp" or "ZenImp" or "MrmImp", without quotes.
@echo     testmode is either empty or any non-empty value.
@goto :EOF

:CopyPoint
@md "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp"
@"%WAVEDIR%\wave.exe" "%KRXIMPEXP%\src\Meta\%1orter.meta" -I "%KRXIMPEXP%\src\Meta" -I "%KRXIMPEXP%\src\MetaBpy" -o "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1.wave"
@"%SEDDIR%\bin\sed.exe" -f %~dp0Bpy_PostProcessScript_A_.sed "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1.wave" > "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-A.py"
@"%SEDDIR%\bin\sed.exe" -f %~dp0Bpy_PostProcessScript_B_.sed "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-A.py" > "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-B.py"
@"%SEDDIR%\bin\sed.exe" -f %~dp0Bpy_PostProcessScript_C_.sed "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-B.py" > "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-C.py"
@"%SEDDIR%\bin\sed.exe" -f %~dp0Bpy_PostProcessScript_D_.sed "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-C.py" > "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-D.py"
@"%SEDDIR%\bin\sed.exe" -f %~dp0Bpy_PostProcessScript_E_.sed "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-D.py" > "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-E.py"
copy "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1-E.py" "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1.py"

@set XCPYOPT=/y /s /f
@xcopy "%KRXIMPEXP_INTERMEDIATE%\BpyImpExp\Krx%1.py" "%KRXIMPEXP_INSTALL%\blender\%2\scripts\addons\KrxImpExp\" %XCPYOPT%

@if "%1" == "3dsImp" goto :CheckCfg
@if "%1" == "3dsExp" goto :CheckCfg
@if "%1" == "AscImp" goto :CheckCfg
@if "%1" == "AscExp" goto :CheckCfg
@if "%1" == "MshImp" goto :CheckCfg
@if "%1" == "ZenImp" goto :CheckCfg
@if "%1" == "MrmImp" goto :CheckCfg
goto :ShowInfo

:CheckCfg
if "%2" == "Debug96"        goto :Debug96
if "%2" == "Release96"      goto :Release96
if "%2" == "Debug96_x64"    goto :Debug96_x64
if "%2" == "Release96_x64"  goto :Release96_x64
if "%2" == "Debug100"       goto :Debug100
if "%2" == "Release100"     goto :Release100
if "%2" == "Debug100_x64"   goto :Debug100_x64
if "%2" == "Release100_x64" goto :Release100_x64
if "%2" == "Debug105"       goto :Debug105
if "%2" == "Release105"     goto :Release105
if "%2" == "Debug105_x64"   goto :Debug105_x64
if "%2" == "Release105_x64" goto :Release105_x64
if "%2" == "Debug120"       goto :Debug120
if "%2" == "Release120"     goto :Release120
if "%2" == "Debug120_x64"   goto :Debug120_x64
if "%2" == "Release120_x64" goto :Release120_x64
goto :ShowInfo

:ShowInfo
echo Syntax: PBE_C4DSdkBased_ImpExp name cfg
echo where
echo     name is either "3dsImp" or "3dsExp" or "AscImp" or "AscExp" 
echo          or "MshImp" or "ZenImp" or "MrmImp", without quotes.
echo     cfg  is either "Debug96" or "Release96" or "Debug96_x64"
echo          or "Release96_x64" or "Debug100" or "Release100" 
echo          or "Debug100_x64" or "Release100_x64" or "Debug120" 
echo          or "Release120" or "Debug120_x64" or "Release120_x64", 
echo          without quotes.
goto :EOF

:Debug96
set KRXIMPEXP_CURC4DDIR=%C4DDIR_96%
set KRXIMPEXP_CURINSTALLDIR=
goto :CopyPoint

:Release96
set KRXIMPEXP_CURC4DDIR=%C4DDIR_96%
set KRXIMPEXP_CURINSTALLDIR=%KRXIMPEXP_INSTALL%\c4d96
goto :CopyPoint

:Debug96_x64
set KRXIMPEXP_CURC4DDIR=%C4DDIR_96%
set KRXIMPEXP_CURINSTALLDIR=
goto :CopyPoint_x64

:Release96_x64
set KRXIMPEXP_CURC4DDIR=%C4DDIR_96%
set KRXIMPEXP_CURINSTALLDIR=%KRXIMPEXP_INSTALL%\c4d96
goto :CopyPoint_x64

:Debug100
set KRXIMPEXP_CURC4DDIR=%C4DDIR_100%
set KRXIMPEXP_CURINSTALLDIR=
goto :CopyPoint

:Release100
set KRXIMPEXP_CURC4DDIR=%C4DDIR_100%
set KRXIMPEXP_CURINSTALLDIR=%KRXIMPEXP_INSTALL%\c4d100
goto :CopyPoint

:Debug100_x64
set KRXIMPEXP_CURC4DDIR=%C4DDIR_100%
set KRXIMPEXP_CURINSTALLDIR=
goto :CopyPoint_x64

:Release100_x64
set KRXIMPEXP_CURC4DDIR=%C4DDIR_100%
set KRXIMPEXP_CURINSTALLDIR=%KRXIMPEXP_INSTALL%\c4d100
goto :CopyPoint_x64

:Debug105
set KRXIMPEXP_CURC4DDIR=%C4DDIR_105%
set KRXIMPEXP_CURINSTALLDIR=
goto :CopyPoint

:Release105
set KRXIMPEXP_CURC4DDIR=%C4DDIR_105%
set KRXIMPEXP_CURINSTALLDIR=%KRXIMPEXP_INSTALL%\c4d105
goto :CopyPoint

:Debug105_x64
set KRXIMPEXP_CURC4DDIR=%C4DDIR_105%
set KRXIMPEXP_CURINSTALLDIR=
goto :CopyPoint_x64

:Release105_x64
set KRXIMPEXP_CURC4DDIR=%C4DDIR_105%
set KRXIMPEXP_CURINSTALLDIR=%KRXIMPEXP_INSTALL%\c4d105
goto :CopyPoint_x64

:Debug120
set KRXIMPEXP_CURC4DDIR=%C4DDIR_120%
set KRXIMPEXP_CURINSTALLDIR=
goto :CopyPoint

:Release120
set KRXIMPEXP_CURC4DDIR=%C4DDIR_120%
set KRXIMPEXP_CURINSTALLDIR=%KRXIMPEXP_INSTALL%\c4d120
goto :CopyPoint

:Debug120_x64
set KRXIMPEXP_CURC4DDIR=%C4DDIR_120%
set KRXIMPEXP_CURINSTALLDIR=
goto :CopyPoint_x64

:Release120_x64
set KRXIMPEXP_CURC4DDIR=%C4DDIR_120%
set KRXIMPEXP_CURINSTALLDIR=%KRXIMPEXP_INSTALL%\c4d120
goto :CopyPoint_x64

:CopyPoint
set XCPYOPT=/y /s /f
xcopy "%KRXIMPEXP_INTERMEDIATE%\C4D%1orter\%2\Krx%1.cdl" "%KRXIMPEXP_CURC4DDIR%\plugins\KrxImpExp\" %XCPYOPT%
if "%KRXIMPEXP_CURINSTALLDIR%" == "" goto :EOF
xcopy "%KRXIMPEXP_CURC4DDIR%\plugins\KrxImpExp\Krx%1.cdl" "%KRXIMPEXP_CURINSTALLDIR%\plugins\KrxImpExp\" %XCPYOPT%
goto :EOF

:CopyPoint_x64
set XCPYOPT=/y /s /f
xcopy "%KRXIMPEXP_INTERMEDIATE%\C4D%1orter\%2\Krx%1.cdl64" "%KRXIMPEXP_CURC4DDIR%\plugins\KrxImpExp\" %XCPYOPT%
if "%KRXIMPEXP_CURINSTALLDIR%" == "" goto :EOF
xcopy "%KRXIMPEXP_CURC4DDIR%\plugins\KrxImpExp\Krx%1.cdl64" "%KRXIMPEXP_CURINSTALLDIR%\plugins\KrxImpExp\" %XCPYOPT%

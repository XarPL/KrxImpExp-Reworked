@if "%1" == "Debug5"        goto :Debug5
@if "%1" == "Release5"      goto :Release5
@if "%1" == "Debug6"        goto :Debug6
@if "%1" == "Release6"      goto :Release6
@if "%1" == "Debug9"        goto :Debug9
@if "%1" == "Release9"      goto :Release9
@if "%1" == "Debug9_x64"    goto :Debug9_x64
@if "%1" == "Release9_x64"  goto :Release9_x64
@if "%1" == "Debug11"       goto :Debug11
@if "%1" == "Release11"     goto :Release11
@if "%1" == "Debug11_x64"   goto :Debug11_x64
@if "%1" == "Release11_x64" goto :Release11_x64
@if "%1" == "Debug12"       goto :Debug12
@if "%1" == "Release12"     goto :Release12
@if "%1" == "Debug12_x64"   goto :Debug12_x64
@if "%1" == "Release12_x64" goto :Release12_x64
@if "%1" == "Debug14"       goto :Debug14
@if "%1" == "Release14"     goto :Release14
@if "%1" == "Debug14_x64"   goto :Debug14_x64
@if "%1" == "Release14_x64" goto :Release14_x64
@if "%1" == "Debug15"       goto :Debug15
@if "%1" == "Release15"     goto :Release15
@if "%1" == "Debug15_x64"   goto :Debug15_x64
@if "%1" == "Release15_x64" goto :Release15_x64

@echo Syntax: PBE_IPhysique cfg
@echo where
@echo     cfg  is either "Debug5" or "Release5" or "Debug6" or "Release6" 
@echo          or "Debug9" or "Release9" or "Debug_x64" or "Release_x64
@echo          or "Debug11" or "Release11" or "Debug11_x64" or "Release11_x64",
@echo          or "Debug12" or "Release12" or "Debug12_x64" or "Release12_x64",
@echo          or "Debug14" or "Release14" or "Debug14_x64" or "Release14_x64",
@echo          or "Debug15" or "Release15" or "Debug15_x64" or "Release15_x64",
@echo          without quotes.
@goto :EOF

:Debug5
@set CURMAXDIR=%MAXDIR_5%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release5
@set CURMAXDIR=%MAXDIR_5%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max5
@goto :CopyPoint

:Debug6
@set CURMAXDIR=%MAXDIR_6%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release6
@set CURMAXDIR=%MAXDIR_6%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max6
@goto :CopyPoint

:Debug9
@set CURMAXDIR=%MAXDIR_9%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release9
@set CURMAXDIR=%MAXDIR_9%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max9
@goto :CopyPoint

:Debug9_x64
@set CURMAXDIR=%MAXDIR_9_X64%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release9_x64
@set CURMAXDIR=%MAXDIR_9_X64%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max9_x64
@goto :CopyPoint

:Debug11
@set CURMAXDIR=%MAXDIR_11%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release11
@set CURMAXDIR=%MAXDIR_11%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max11
@goto :CopyPoint

:Debug11_x64
@set CURMAXDIR=%MAXDIR_11_X64%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release11_x64
@set CURMAXDIR=%MAXDIR_11_X64%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max11_x64
@goto :CopyPoint

:Debug12
@set CURMAXDIR=%MAXDIR_12%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release12
@set CURMAXDIR=%MAXDIR_12%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max12
@goto :CopyPoint

:Debug12_x64
@set CURMAXDIR=%MAXDIR_12_X64%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release12_x64
@set CURMAXDIR=%MAXDIR_12_X64%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max12_x64
@goto :CopyPoint

:Debug14
@set CURMAXDIR=%MAXDIR_14%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release14
@set CURMAXDIR=%MAXDIR_14%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max14
@goto :CopyPoint

:Debug14_x64
@set CURMAXDIR=%MAXDIR_14_X64%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release14_x64
@set CURMAXDIR=%MAXDIR_14_X64%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max14_x64
@goto :CopyPoint

:Debug15
@set CURMAXDIR=%MAXDIR_15%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release15
@set CURMAXDIR=%MAXDIR_15%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max15
@goto :CopyPoint

:Debug15_x64
@set CURMAXDIR=%MAXDIR_15_X64%
@set CURINSTALLDIR=
@goto :CopyPoint

:Release15_x64
@set CURMAXDIR=%MAXDIR_15_X64%
@set CURINSTALLDIR=%KRXIMPEXP_INSTALL%\max15_x64
@goto :CopyPoint

:CopyPoint
@set XCPYOPT=/y /s /f
@xcopy "%KRXIMPEXP_INTERMEDIATE%\IPhysique\%1\IPhysique.gup" "%CURMAXDIR%\plugins\" %XCPYOPT%

@if "%CURINSTALLDIR%" == "" goto :EOF
@xcopy "%CURMAXDIR%\plugins\IPhysique.gup" "%CURINSTALLDIR%\plugins\" %XCPYOPT%

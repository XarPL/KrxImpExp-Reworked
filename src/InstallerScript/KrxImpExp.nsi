; KrxImpExp.nsi
; This is a main script file. It should be compiled to produce installer.

;--------------------------------
;Include Modern UI
!include "MUI.nsh"

; nsDialogs Plug-in
!include nsDialogs.nsh
!include LogicLib.nsh

; Word functions Plug-in
!include "WordFunc.nsh"


;---------------------------------------------------------------------------------------------------------------------------------------------------
; Macro definitions

!ifndef TYPEVER
  !define TYPEVER gmax
  !define BLENDERSHORTVER 0.0
!endif

!if ${TYPEVER} == max5
  !define FULLDESC "3D Studio Max 5"
  !define INSTNAME "max5"
  !define PLATFORM "x86"
!else if ${TYPEVER} == max6
  !define FULLDESC "3D Studio Max 6-8"
  !define INSTNAME "max6-8"
  !define PLATFORM "x86"
!else if ${TYPEVER} == max9
  !define FULLDESC "3D Studio Max 9-2008 (x86)"
  !define INSTNAME "max9-2008-x86"
  !define PLATFORM "x86"
!else if ${TYPEVER} == max9_x64
  !define FULLDESC "3D Studio Max 9-2008 (x64)"
  !define INSTNAME "max9-2008-x64"
  !define PLATFORM "x64"
!else if ${TYPEVER} == max11
  !define FULLDESC "3D Studio Max 2009 (x86)"
  !define INSTNAME "max2009-x86"
  !define PLATFORM "x86"
!else if ${TYPEVER} == max11_x64
  !define FULLDESC "3D Studio Max 2009 (x64)"
  !define INSTNAME "max2009-x64"
  !define PLATFORM "x64"
!else if ${TYPEVER} == max12
  !define FULLDESC "3D Studio Max 2010-2011 (x86)"
  !define INSTNAME "max2010-2011-x86"
  !define PLATFORM "x86"
!else if ${TYPEVER} == max12_x64
  !define FULLDESC "3D Studio Max 2010-2011 (x64)"
  !define INSTNAME "max2010-2011-x64"
  !define PLATFORM "x64"
!else if ${TYPEVER} == max14
  !define FULLDESC "3D Studio Max 2012 (x86)"
  !define INSTNAME "max2012-x86"
  !define PLATFORM "x86"
!else if ${TYPEVER} == max14_x64
  !define FULLDESC "3D Studio Max 2012 (x64)"
  !define INSTNAME "max2012-x64"
  !define PLATFORM "x64"
!else if ${TYPEVER} == max15
  !define FULLDESC "3D Studio Max 2013 (x86)"
  !define INSTNAME "max2013-x86"
  !define PLATFORM "x86"
!else if ${TYPEVER} == max15_x64
  !define FULLDESC "3D Studio Max 2013 (x64)"
  !define INSTNAME "max2013-x64"
  !define PLATFORM "x64"  
!else if ${TYPEVER} == gmax
  !define FULLDESC "gmax 1.2"
  !define INSTNAME "gmax1.2"
  !define PLATFORM "x86"
!else if ${TYPEVER} == blender
  !define FULLDESC "Blender ${BLENDERSHORTVER}"
  !define INSTNAME "blender${BLENDERSHORTVER}"
  !define PLATFORM "x86"
!else if ${TYPEVER} == c4d96
  !define FULLDESC "Cinema 4D Release 9.6"
  !define INSTNAME "c4d9.6"
  !define PLATFORM "x86"
!else if ${TYPEVER} == c4d100
  !define FULLDESC "Cinema 4D Release 10"
  !define INSTNAME "c4d10.0"
  !define PLATFORM "x86"
!else if ${TYPEVER} == c4d105
  !define FULLDESC "Cinema 4D Release 10.5-11.5"
  !define INSTNAME "c4d10.5-11.5"
  !define PLATFORM "x86"
!else if ${TYPEVER} == c4d120
  !define FULLDESC "Cinema 4D Release 12.0"
  !define INSTNAME "c4d12.0"
  !define PLATFORM "x86"
!else
  !error "Unknown 3D editor type or version!"
!endif

!define /date RELEASEDATE	 "%b-%d-%Y"

!define CAPTION	"KrxImpExp for ${FULLDESC}"
!define EXENAME	"KrxImpExp-${INSTNAME}-${RELEASEDATE}"

;---------------------------------------------------------------------------------------------------------------------------------------------------
; General properties

; The name of the installer
Name "${CAPTION}"
Caption "${CAPTION}"

; The file to write
OutFile "..\..\release\${EXENAME}.exe"


;---------------------------------------------------------------------------------------------------------------------------------------------------
; Variables

; cleaned or not
Var /GLOBAL Cleaned

; path to uninstaller executable
Var /GLOBAL UninstallerExe

; path to wxImpExpUI.exe
Var /GLOBAL wxImpExpUIExe

;---------------------------------------------------------------------------------------------------------------------------------------------------
; Functions

; Guess an install directory -it's a main directory for
Function GuessInstallDir

  StrCpy $INSTDIR ""
  
!if ${TYPEVER} == max5
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\5.0" 0
  IfErrors notFound
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\5.0\$0" "uninstallpath"
  StrCpy $InstDir $1
  Goto done

!else if ${TYPEVER} == max6
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\6.0" 0
  IfErrors guess_max7
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\6.0\$0\AdLM" "InfoPath"
  StrCpy $InstDir $1
  Goto done
guess_max7:
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\7.0" 0
  IfErrors guess_max8
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\7.0\$0\AdLM" "InfoPath"
  StrCpy $InstDir $1
  Goto done
guess_max8:
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\8.0" 0
  IfErrors notFound
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\8.0\$0\AdLM" "InfoPath"
  StrCpy $InstDir $1
  Goto done
  
!else if ${TYPEVER} == max9
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\9.0" 0
  IfErrors guess_max10
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\9.0\$0\AdLM" "InfoPath"
  StrCpy $InstDir $1
  Goto done
guess_max10:
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\10.0" 0
  IfErrors notFound
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\10.0\$0\AdLM" "InfoPath"
  StrCpy $InstDir $1
  Goto done
  
!else if ${TYPEVER} == max9_x64
  ClearErrors
  SetRegView 64
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\9.0" 0
  SetRegView 32
  IfErrors guess_max10_x64
  SetRegView 64
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\9.0\$0\AdLM" "InfoPath"
  SetRegView 32
  StrCpy $InstDir $1
  Goto done
guess_max10_x64:
  ClearErrors
  SetRegView 64
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\10.0" 0
  SetRegView 32
  IfErrors notFound
  SetRegView 64
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\10.0\$0\AdLM" "InfoPath"
  SetRegView 32
  StrCpy $InstDir $1
  Goto done
  
!else if ${TYPEVER} == max11
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\11.0" 0
  IfErrors notFound
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\11.0\$0\AdLM" "InfoPath"
  StrCpy $InstDir $1
  Goto done
  
!else if ${TYPEVER} == max11_x64
  ClearErrors
  SetRegView 64
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\11.0" 0
  SetRegView 32
  IfErrors notFound
  SetRegView 64
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\11.0\$0\AdLM" "InfoPath"
  SetRegView 32
  StrCpy $InstDir $1
  Goto done
  
!else if ${TYPEVER} == max12
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\12.0" 0
  IfErrors guess_max13
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\12.0\$0\AdLM" "InfoPath"
  StrCpy $InstDir $1
  Goto done
guess_max13:
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\13.0" 0
  IfErrors notFound
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\13.0\$0" "Installdir"
  StrCpy $InstDir $1
  Goto done  
  
!else if ${TYPEVER} == max12_x64
  ClearErrors
  SetRegView 64
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\12.0" 0
  SetRegView 32
  IfErrors guess_max13_x64
  SetRegView 64
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\12.0\$0\AdLM" "InfoPath"
  SetRegView 32
  StrCpy $InstDir $1
  Goto done
guess_max13_x64:
  ClearErrors
  SetRegView 64
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\13.0" 0
  SetRegView 32
  IfErrors notFound
  SetRegView 64
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\13.0\$0" "Installdir"
  SetRegView 32
  StrCpy $InstDir $1
  Goto done

!else if ${TYPEVER} == max14
  ClearErrors
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\14.0" 0
  IfErrors notFound
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\14.0\$0" "Installdir"
  StrCpy $InstDir $1
  Goto done
  
!else if ${TYPEVER} == max14_x64
  ClearErrors
  SetRegView 64
  EnumRegKey $0 HKLM "Software\Autodesk\3DSMAX\14.0" 0
  SetRegView 32
  IfErrors notFound
  SetRegView 64
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\14.0\$0" "Installdir"
  SetRegView 32
  StrCpy $InstDir $1
  Goto done

!else if ${TYPEVER} == max15
  ClearErrors
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\15.0" "Installdir"
  IfErrors notFound
  StrCpy $InstDir $1
  Goto done
  
!else if ${TYPEVER} == max15_x64
  ClearErrors
  SetRegView 64
  ReadRegStr $1 HKLM "Software\Autodesk\3DSMAX\15.0" "Installdir"
  SetRegView 32
  IfErrors notFound
  StrCpy $InstDir $1
  Goto done
  
!else if ${TYPEVER} == gmax
  ClearErrors
  ReadRegStr $1 HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\gmax" "uninstallpath"
  IfErrors notFound
  StrCpy $InstDir $1
  Goto done  
  
!else if ${TYPEVER} == blender
  ClearErrors
  ReadRegStr $1 HKLM "Software\BlenderFoundation" "Install_Dir"
  IfErrors guess_blender_x64
  StrCpy $InstDir $1
  Goto done
guess_blender_x64:
  ClearErrors
  SetRegView 64
  ReadRegStr $1 HKLM "Software\BlenderFoundation" "Install_Dir"
  SetRegView 32
  IfErrors notFound
  StrCpy $InstDir $1
  Goto done

!else if ${TYPEVER} == c4d96
  Goto c4d

!else if ${TYPEVER} == c4d100
  Goto c4d

!else if ${TYPEVER} == c4d105
  Goto c4d

!else if ${TYPEVER} == c4d120
  Goto c4d

!else
  !error "Unknown 3D editor type or version!"
!endif
  
c4d:
  ClearErrors
  ReadRegStr $1 HKLM "Software\Classes\Cinema 4D Document\shell\open\command" ""
  IfErrors c4d_x64
  ${WordFind} $1 "$\"" "+1" $2
  ${WordFind} $2 "\" "-2{*" $1
  StrCpy $InstDir $1
  Goto done

c4d_x64:
  ClearErrors
  SetRegView 64
  ReadRegStr $1 HKLM "Software\Classes\Cinema 4D Document\shell\open\command" ""
  SetRegView 32
  IfErrors notFound
  ${WordFind} $1 "$\"" "+1" $2
  ${WordFind} $2 "\" "-2{*" $1
  StrCpy $InstDir $1
  Goto done
  
; Required 3D Editor wasn't found, maybe it was not installed
notFound:

; Required 3D Editor was found!
done:
FunctionEnd

; Uninstall all installed versions of the "KrxImpExp" plugins
Function DeleteAnyVersion

  ; there is only one clean up here
  StrCmp $Cleaned "1" done
  StrCpy $Cleaned "1"
  
  ; Run uninstaller (if exists)
  ExecWait '"$INSTDIR\KrxImpExp\Uninstall.exe" /S _?=$INSTDIR'
  ExecWait '"$INSTDIR\KrxImpExp-Uninstaller.exe" /S _?=$INSTDIR'
  ExecWait '"$INSTDIR\stdplugs\KrxMaxPlugins_Uninstall.exe"'
  ExecWait '"$INSTDIR\plugins\KrxImpExp\Uninstall.exe" /S _?=$INSTDIR'
  
  ; Delete files
  Delete "$INSTDIR\scripts\KrxAscImp.ms"
  Delete "$INSTDIR\scripts\KrxAscExp.ms"
  Delete "$INSTDIR\scripts\Krx3dsImp.ms"
  Delete "$INSTDIR\scripts\Krx3dsExp.ms"
  Delete "$INSTDIR\scripts\startup\KrxImpExpUtil.ms"
  Delete "$INSTDIR\scripts\startup\KrxGMaxExtender.ms"
  Delete "$INSTDIR\scripts\startup\KrxGMaxExtender.ms.disabled"

  Delete "$INSTDIR\stdplugs\krxexp.dle"
  Delete "$INSTDIR\stdplugs\krximp.dli"
  Delete "$INSTDIR\stdplugs\KrxAscExp.dle"
  Delete "$INSTDIR\stdplugs\KrxAscImp.dli"
  Delete "$INSTDIR\stdplugs\Krx3dsExp.dle"
  Delete "$INSTDIR\stdplugs\Krx3dsImp.dli"
  Delete "$INSTDIR\stdplugs\0KrxAscExp.dle"
  Delete "$INSTDIR\stdplugs\0KrxAscImp.dli"
  Delete "$INSTDIR\stdplugs\0Krx3dsExp.dle"
  Delete "$INSTDIR\stdplugs\0Krx3dsImp.dli"

  Delete "$INSTDIR\plugcfg\krxexp.cfg"
  Delete "$INSTDIR\plugcfg\KrxAscExp.cfg"
  Delete "$INSTDIR\plugcfg\Krx3dsImp.cfg"
  Delete "$INSTDIR\plugcfg\Krx3dsUtils.cfg"
  Delete "$INSTDIR\plugcfg\KrxLangUtils.cfg"
  Delete "$INSTDIR\plugcfg\KrxImpExpDlgInput.bin"
  Delete "$INSTDIR\plugcfg\KrxImpExpDlgOutput.bin"
  Delete "$INSTDIR\plugcfg\KrxImpExpUI.cfg"
  
  Delete "$INSTDIR\KrxLangUtils.dll"
  Delete "$INSTDIR\Krx3dsUtils.dll"
  Delete "$INSTDIR\KrxImpExpUI.exe"
  Delete "$INSTDIR\KrxGMaxExtender.exe"
  Delete "$INSTDIR\KrxGMaxExtender.dll"
  Delete "$INSTDIR\stdplugs\KrxMaxPlugins_Uninstall.exe"
  Delete "$INSTDIR\KrxImpExp-Uninstaller.exe"

  RMDir /r "$INSTDIR\meshes\KrxImpExpSamples"
  RMDir /r "$INSTDIR\KrxImpExp"
  RMDir /r "$INSTDIR\plugins\KrxImpExp"
  RMDir /r "$INSTDIR\${BLENDERSHORTVER}\scripts\op\KrxImpExp"
  RMDir /r "$INSTDIR\${BLENDERSHORTVER}\scripts\addons\KrxImpExp"
done:
FunctionEnd

; Is microsoft visual C++ 2008 x86 redistributable package installed
Function IsVCRedistX86Installed
  StrCpy $0 0
loop:
  EnumRegKey $1 HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall" $0
  StrCmp $1 "" notFound
  ReadRegStr $2 HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\$1" "DisplayName"
  StrCpy $3 $2 47
  StrCmp $3 "Microsoft Visual C++ 2008 Redistributable - x86" found
  IntOp $0 $0 + 1
  Goto loop
notFound:
  StrCpy $R0 0
  Goto done
found:
  StrCpy $R0 1
done:
FunctionEnd

; Is microsoft visual C++ 2008 x64 redistributable package installed
Function IsVCRedistX64Installed
  SetRegView 64
  StrCpy $0 0
loop:
  EnumRegKey $1 HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall" $0
  StrCmp $1 "" notFound
  ReadRegStr $2 HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\$1" "DisplayName"
  StrCpy $3 $2 47
  StrCmp $3 "Microsoft Visual C++ 2008 Redistributable - x64" found
  IntOp $0 $0 + 1
  Goto loop
notFound:
  StrCpy $R0 0
  Goto done
found:
  StrCpy $R0 1
done:
  SetRegView 32
FunctionEnd

;---------------------------------------------------------------------------------------------------------------------------------------------------
;Interface Settings

!define MUI_WELCOMEFINISHPAGE_BITMAP ".\welcome2.bmp"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP ".\welcome2.bmp"
!define MUI_WELCOMEPAGE_TITLE_3LINES
!define MUI_WELCOMEPAGE_TEXT "$(WelcomeText)\r\n\r\n$_CLICK"
!define MUI_DIRECTORYPAGE_TEXT_DESTINATION "$(DestDirText)"
!define MUI_COMPONENTSPAGE_NODESC
!define MUI_LANGDLL_ALLLANGUAGES

;---------------------------------------------------------------------------------------------------------------------------------------------------
; Pages

!insertmacro MUI_PAGE_WELCOME 
Page custom  VCRedistPage
!insertmacro MUI_PAGE_LICENSE "$(LicText)"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES


;---------------------------------------------------------------------------------------------------------------------------------------------------
; Page with warning "VCRedist is not installed"

Var /GLOBAL VCRedistLabelText1
Var /GLOBAL VCRedistLinkText1
Var /GLOBAL VCRedistLabelText2
Var /GLOBAL VCRedistLinkText2
Var /GLOBAL VCRedistDialog
Var /GLOBAL VCRedistLabel1
Var /GLOBAL VCRedistLink1
Var /GLOBAL VCRedistHorLine
Var /GLOBAL VCRedistLabel2
Var /GLOBAL VCRedistLink2

Function VCRedistPage
  !insertmacro MUI_HEADER_TEXT "$(VCRedist_HeaderText)" "$(VCRedist_HeaderSubText)"

  ; get message "VCRedist is not installed" and link to download for "VCRedist x86" and "VCRedist x64"
  ; if they are both installed then labeltext1 and labeltext2 will be empty
  ; if there is only one installed of them then labeltext2 will be empty
  ; if they are both uninstalled then labeltext1 and labeltext2 both will not be empty
  StrCpy $VCRedistLabelText1 ""
  StrCpy $VCRedistLabelText2 ""

!if ${PLATFORM} == x64 
  Call IsVCRedistX64Installed
  StrCmp $R0 1 done_x64
  StrCpy $VCRedistLabelText1 "$(VCRedist_X64Text)"
  StrCpy $VCRedistLinkText1 "http://www.microsoft.com/Downloads/details.aspx?familyid=BA9257CA-337F-4B40-8C14-157CFDFFEE4E&displaylang=en"
done_x64:
!endif
  Call IsVCRedistX86Installed
  StrCmp $R0 1 done_x86
  StrCpy $VCRedistLabelText2 "$(VCRedist_X86Text)"
  StrCpy $VCRedistLinkText2 "http://www.microsoft.com/Downloads/details.aspx?familyid=A5C84275-3B97-4AB7-A40D-3802B2AF5FC2&displaylang=en"
  ${If} $VCRedistLabelText1 == ""
  	StrCpy $VCRedistLabelText1 "$VCRedistLabelText2"
	StrCpy $VCRedistLabelText2 ""
	StrCpy $VCRedistLinkText1 "$VCRedistLinkText2"
	StrCpy $VCRedistLinkText2 ""
  ${Endif}
done_x86:

  ; Returns from this function and doesn't show dialog if there isn't warning message
  ${If} $VCRedistLabelText1 == ""
  ${AndIf} $VCRedistLabelText2 == ""
    Return
  ${EndIf}
  
  ; Create dialog and controls
  nsDialogs::Create 1018
  Pop $VCRedistDialog

  ${NSD_CreateLabel} 0 0 100% 36u "$VCRedistLabelText1"
  Pop $VCRedistLabel1

  ${NSD_CreateLink} 0 36u 200% 12u "$VCRedistLinkText1"
  Pop $VCRedistLink1
  ${NSD_OnClick} $VCRedistLink1 OnVCRedistLink1

  ${If} $VCRedistLabelText2 != ""
    ${NSD_CreateHLine} 0 52u 100% 3u ""
	Pop $VCRedistHorLine
	System::Call "user32::SetWindowLong(i $VCRedistHorLine, i ${GWL_STYLE}, i ${WS_VISIBLE} )"
		
    ${NSD_CreateLabel} 0 60u 100% 36u "$VCRedistLabelText2"
    Pop $VCRedistLabel2

    ${NSD_CreateLink} 0 96u 200% 12u "$VCRedistLinkText2"
    Pop $VCRedistLink2
    ${NSD_OnClick} $VCRedistLink2 OnVCRedistLink2
  ${EndIf}
  nsDialogs::Show
	
FunctionEnd

Function OnVCRedistLink1
  ExecShell "open" "$VCRedistLinkText1"
FunctionEnd

Function OnVCRedistLink2
  ExecShell "open" "$VCRedistLinkText2"
FunctionEnd

;---------------------------------------------------------------------------------------------------------------------------------------------------
;Languages

; List of supported languages
!include "installer_messages_en.nsi"
!include "installer_messages_ru.nsi"
!include "installer_messages_pl.nsi"


;---------------------------------------------------------------------------------------------------------------------------------------------------
; Main initialization function

Function .onInit

  ; not cleaned yet
  StrCpy $Cleaned "0"

  ; select language
  !insertmacro MUI_LANGDLL_DISPLAY

  ; find 3D Editor installation
  call GuessInstallDir

  ; calculate path to uninstaller executable
!if ${TYPEVER} == c4d96
  Goto c4d
!else if ${TYPEVER} == c4d100
  Goto c4d
!else if ${TYPEVER} == c4d105
  Goto c4d
!else if ${TYPEVER} == c4d120
  Goto c4d
!else if ${TYPEVER} == blender
  Goto blender
!endif
  
  ; 3dsmax or gmax
  StrCpy $UninstallerExe "KrxImpExp\Uninstall.exe"
  StrCpy $wxImpExpUIExe  "KrxImpExp\wxImpExpUI.exe"
  Goto done
  
c4d:
  StrCpy $UninstallerExe "plugins\KrxImpExp\Uninstall.exe"
  StrCpy $wxImpExpUIExe  "plugins\KrxImpExp\wxImpExpUI.exe"
  Goto done

blender:
  StrCpy $UninstallerExe "${BLENDERSHORTVER}\scripts\addons\KrxImpExp\Uninstall.exe"
  StrCpy $wxImpExpUIExe  "${BLENDERSHORTVER}\scripts\addons\KrxImpExp\wxImpExpUI.exe"
  Goto done
  
done:
FunctionEnd

Function .onInstSuccess
	Exec "$InstDir\$wxImpExpUIExe"
FunctionEnd

Function un.onInit
  
  ; select language
  !insertmacro MUI_LANGDLL_DISPLAY

  ; get the installation path from the registry
  ReadRegStr $InstDir HKLM "SOFTWARE\Kerrax\${CAPTION}" "Path"  
  
FunctionEnd

;---------------------------------------------------------------------------------------------------------------------------------------------------
; Sections

; The stuff to install
Section "Import and Export Plugins"
  SectionIn "RO"
  call DeleteAnyVersion
  !if ${TYPEVER} == blender
  	SetOutPath "$INSTDIR\${BLENDERSHORTVER}"
	File /r "..\..\install\${TYPEVER}\${BLENDERSHORTVER}\*.*"
  !else
	SetOutPath $INSTDIR
	File /r "..\..\install\${TYPEVER}\*.*"
  !endif
  IfFileExists "$INSTDIR\stdplugs\IPhysique.gup" renamIPhyGup afterRenamIPhyGup
	renamIPhyGup:
  Rename "$INSTDIR\stdplugs\IPhysique.gup" "$INSTDIR\stdplugs\IPhysique.gup.disabled"
  afterRenamIPhyGup:
  
  WriteRegStr HKLM "SOFTWARE\Kerrax\${CAPTION}" "Path" "$INSTDIR"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${CAPTION}" "DisplayName" "${CAPTION}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${CAPTION}" "UninstallString" '"$InstDir\$UninstallerExe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${CAPTION}" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${CAPTION}" "NoRepair" 1
  WriteUninstaller "$InstDir\$UninstallerExe"
  
SectionEnd
  
Section "Start Menu ShortCuts"
  CreateDirectory "$SMPROGRAMS\${CAPTION}"
!if ${TYPEVER} == gmax
  CreateShortCut  "$SMPROGRAMS\${CAPTION}\KrxGMaxExtender.lnk" "$INSTDIR\KrxGMaxExtender.exe"
!endif
  CreateShortCut  "$SMPROGRAMS\${CAPTION}\Help.lnk" "$InstDir\$wxImpExpUIExe" "" "$PROGRAMFILES\Internet Explorer\IExplore.exe" 0
  CreateShortCut  "$SMPROGRAMS\${CAPTION}\Uninstall KrxImpExp.lnk" "$InstDir\$UninstallerExe"
SectionEnd

!if ${TYPEVER} == gmax
Section "Desktop ShortCut for KrxGMaxExtender"
  CreateShortCut  "$DESKTOP\KrxGMaxExtender.lnk" "$INSTDIR\KrxGMaxExtender.exe"
SectionEnd
!endif

;---------------------------------------------------------------------------------------------------------------------------------------------------
; Uninstaller

Section "Uninstall"

  ; Delete files
  Delete "$INSTDIR\.blender\scripts\KrxAscImp.py"
  Delete "$INSTDIR\.blender\scripts\KrxAscExp.py"
  Delete "$INSTDIR\.blender\scripts\Krx3dsImp.py"
  Delete "$INSTDIR\.blender\scripts\Krx3dsExp.py"
  Delete "$INSTDIR\.blender\scripts\ConfigImageSearch.py"
  Delete "$INSTDIR\.blender\scripts\ConfigMtlLongName.py"
  Delete "$INSTDIR\.blender\scripts\bpymodules\MtlLongName.py"
  Delete "$INSTDIR\.blender\scripts\bpydata\KrxImpExpDlgInput.bin"
  Delete "$INSTDIR\.blender\scripts\bpydata\KrxImpExpDlgOutput.bin"
  Delete "$INSTDIR\.blender\scripts\bpydata\KrxImpExpUI.cfg"

  Delete "$INSTDIR\scripts\KrxAscImp.ms"
  Delete "$INSTDIR\scripts\KrxAscExp.ms"
  Delete "$INSTDIR\scripts\Krx3dsImp.ms"
  Delete "$INSTDIR\scripts\Krx3dsExp.ms"
  Delete "$INSTDIR\scripts\startup\KrxImpExpUtil.ms"
  Delete "$INSTDIR\scripts\startup\KrxGMaxExtender.ms"

  Delete "$INSTDIR\stdplugs\0KrxAscExp.dle"
  Delete "$INSTDIR\stdplugs\0KrxAscImp.dli"
  Delete "$INSTDIR\stdplugs\0Krx3dsExp.dle"
  Delete "$INSTDIR\stdplugs\0Krx3dsImp.dli"
  
  Delete "$INSTDIR\plugcfg\KrxImpExpDlgInput.bin"
  Delete "$INSTDIR\plugcfg\KrxImpExpDlgOutput.bin"
  Delete "$INSTDIR\plugcfg\KrxImpExpUI.cfg"

  Delete "$INSTDIR\KrxGMaxExtender.exe"
  Delete "$INSTDIR\KrxGMaxExtender.dll"
  
  RMDir /r "$INSTDIR\KrxImpExp"
  RMDir /r "$INSTDIR\plugins\KrxImpExp"
  RMDir /r "$INSTDIR\${BLENDERSHORTVER}\scripts\op\KrxImpExp"
  RMDir /r "$INSTDIR\${BLENDERSHORTVER}\scripts\addons\KrxImpExp"

  ; Remove shortcuts
  RMDir /r "$SMPROGRAMS\${CAPTION}"
!if ${TYPEVER} == gmax
  Delete "$DESKTOP\KrxGMaxExtender.lnk"
!endif

  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${EXENAME}"
  DeleteRegKey HKLM "SOFTWARE\Kerrax\${EXENAME}"

SectionEnd

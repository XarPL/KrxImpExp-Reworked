; installer_messages_en.nsi
; This file should not to be compiled. It is included into the "KrxImpExp.nsi" main script file.

!insertmacro MUI_LANGUAGE "English"

LangString WelcomeText ${LANG_ENGLISH} "This wizard will guide you through the installation KrxImpExp.\r\n\r\nKrxImpExp is a set of plugins for 3ds max and gmax. These plugins allow you to import and export ASC and 3DS files in the format of Gothic and Gothic II. Gothic and Gothic II are Piranha Bytes' games.\r\n\r\nBefore starting the installation, make sure ${FULLDESC} is not running."
LicenseLangString LicText ${LANG_ENGLISH} "gpl-3.0.txt"
LangString DestDirText ${LANG_ENGLISH} "Select the root ${FULLDESC} folder"

LangString VCRedist_HeaderText ${LANG_ENGLISH} "Required Libraries"
LangString VCRedist_HeaderSubText ${LANG_ENGLISH} "This program requires additional libraries to run, which should be installed separately"
LangString VCRedist_X86Text ${LANG_ENGLISH} "This program requires the following 32-bit dynamic libraries: msvcp90.dll, msvcr90.dll. These libraries can be installed with Microsoft Visual C++ 2008 Redistributable Package (x86), which can be downloaded with a link below."
LangString VCRedist_X64Text ${LANG_ENGLISH} "This program requires the following 64-bit dynamic libraries: msvcp90.dll, msvcr90.dll. These libraries can be installed with Microsoft Visual C++ 2008 Redistributable Package (x64), which can be downloaded with a link below."

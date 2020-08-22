; installer_messages_pl.nsi
; This file should not to be compiled. It is included in the "KrxImpExp.nsi" main script file.

!insertmacro MUI_LANGUAGE "Polish"

LangString WelcomeText ${LANG_POLISH} "Program instalacyjny poprowadzi cię przez instalację KrxImpExp. \r\n\r\nKrxImpExp to zestaw pluginów do programu ${FULLDESC}. Te pluginy pozwolą ci na importowanie i eksportowanie plików ASC i 3DS do formatu Gothic i Gothic II. Gothic i Gothic II są grami Piranhi Bytes.\r\n\r\nZanim rozpoczniesz instalację, upewnij się, że program ${FULLDESC} nie jest uruchomiony."
LicenseLangString LicText ${LANG_POLISH} "gpl-3.0.txt"
LangString DestDirText ${LANG_POLISH} "Wybierz główny folder ${FULLDESC}"

LangString VCRedist_HeaderText ${LANG_POLISH} "Wymagane biblioteki"
LangString VCRedist_HeaderSubText ${LANG_POLISH} "Ten program wymaga bibliotek które powinny być zainstalowane oddzielnie"
LangString VCRedist_X86Text ${LANG_POLISH} "Ten program wymaga następujących 32-bitowych bibliotek dynamicznych: msvcp90.dll, msvcr90.dll. Mogą być one zainstalowane wraz z Microsoft Visual C++ 2008 Redistributable Package (x86), który możesz pobrać z linku poniżej. Możesz jednak zignorować to ostrzeżenie i kontynuować instalacje"
LangString VCRedist_X64Text ${LANG_POLISH} "Ten program wymaga następujących 64-bitowych bibliotek dynamicznyc: msvcp90.dll, msvcr90.dll. Mogą być one zainstalowane wraz z Microsoft Visual C++ 2008 Redistributable Package (x64), który możesz pobrać z linku poniżej. Możesz jednak zignorować to ostrzeżenie i kontynuować instalacje"

; installer_messages_ru.nsi
; This file should not to compile. It is included in the "KrxImpExp.nsi" main script file.

!insertmacro MUI_LANGUAGE "Russian"

LangString WelcomeText ${LANG_RUSSIAN} "Этот мастер поможет установить KrxImpExp.\r\n\r\nKrxImpExp - это набор плагинов для 3ds max и gmax. Эти плагины позволяют импортировать и экспортировать ASC и 3DS файлы в формате Готики и Готики II. Готика и Готика II - это игры, созданные разработчиком Piranha Bytes.\r\n\r\nПеред началом установки необходимо выйти из ${FULLDESC}, если он запущен."
LicenseLangString LicText ${LANG_RUSSIAN} "gpl-3.0.txt"
LangString DestDirText ${LANG_RUSSIAN} "Выберите каталог с установленным ${FULLDESC}"

LangString VCRedist_HeaderText ${LANG_RUSSIAN} "Необходимые библиотеки"
LangString VCRedist_HeaderSubText ${LANG_RUSSIAN} "Для работы программы требуются дополнительные библиотеки, не входящие в ее состав"
LangString VCRedist_X86Text ${LANG_RUSSIAN} "Для работы этой программы необходимы 32-битные библиотеки msvcp90.dll, msvcr90.dll. Эти библиотеки входят в состав Microsoft Visual C++ 2008 Redistributable Package (x86), который можно скачать по ссылке ниже. Однако вы можете проигнорировать это предупреждение и продолжить установку."
LangString VCRedist_X64Text ${LANG_RUSSIAN} "Для работы этой программы необходимы 64-битные библиотеки msvcp90.dll, msvcr90.dll. Эти библиотеки входят в состав Microsoft Visual C++ 2008 Redistributable Package (x64), который можно скачать по ссылке ниже. Однако вы можете проигнорировать это предупреждение и продолжить установку."

LangString Python_HeaderText ${LANG_RUSSIAN} "Требуется Python 2.6"
LangString Python_HeaderSubText ${LANG_RUSSIAN} "Для работы программы требуется Python 2.6"
LangString Python_Text ${LANG_RUSSIAN} "Необходимо также установить Python 2.6.2. Рекомендуется устанавливать именно эту версию (если вы используете Blender 2.49). Вы можете скачать его с официального сайта."

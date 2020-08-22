@cls
call "%~dp0internal\GMax_Copy_Help_"
call "%~dp0internal\GMax_Copy_Locale_"
call "%~dp0internal\GMax_Copy_ReadyScripts_"
call "%~dp0internal\GMax_Copy_SampleMeshes_"
call "%~dp0internal\GMax_Make_ImpExpScript_" 3dsExp
call "%~dp0internal\GMax_Make_ImpExpScript_" 3dsImp
call "%~dp0internal\GMax_Make_ImpExpScript_" AscExp
call "%~dp0internal\GMax_Make_ImpExpScript_" AscImp
call "%~dp0internal\GMax_Make_ImpExpScript_" MrmImp
call "%~dp0internal\GMax_Make_ImpExpScript_" MshImp
call "%~dp0internal\GMax_Make_ImpExpScript_" ZenImp
@pause
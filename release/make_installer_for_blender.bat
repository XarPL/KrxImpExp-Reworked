@cls
SET /p ver="Enter target blender version: "
"%NSISDIR%\makensis.exe" /DTYPEVER=blender  /DBLENDERSHORTVER=%ver%  "..\src\InstallerScript\KrxImpExp.nsi"
@pause

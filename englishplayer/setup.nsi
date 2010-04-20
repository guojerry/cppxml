;NSIS Modern User Interface
;Multilingual Example Script
;Written by Joost Verburg

;--------------------------------
;Include Modern UI

  !include "MUI2.nsh"

;--------------------------------
;General

  ;Name and file
  Name "EnglishPlayer"
  OutFile "bin\EnglishPlayerSetup.exe"

  ;Default installation folder
  InstallDir "$PROGRAMFILES\English Player"
  
  ;Get installation folder from registry if available
  InstallDirRegKey HKCU "Software\EnglishPlayer" ""

  ;Request application privileges for Windows Vista
  RequestExecutionLevel admin

; MUI Settings / Icons
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\orange-install-nsis.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\orange-uninstall-nsis.ico"
 
; MUI Settings / Header
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_RIGHT
!define MUI_HEADERIMAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Header\orange-r-nsis.bmp"
!define MUI_HEADERIMAGE_UNBITMAP "${NSISDIR}\Contrib\Graphics\Header\orange-uninstall-r-nsis.bmp"
 
; MUI Settings / Wizard
!define MUI_WELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\orange-nsis.bmp"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\orange-uninstall-nsis.bmp"

;--------------------------------
;Interface Settings

  !define MUI_ABORTWARNING

;--------------------------------
;Language Selection Dialog Settings

  ;Remember the installer language
  !define MUI_LANGDLL_REGISTRY_ROOT "HKCU" 
  !define MUI_LANGDLL_REGISTRY_KEY "Software\EnglishPlayer" 
  !define MUI_LANGDLL_REGISTRY_VALUENAME "Installer Language"

;--------------------------------
;Pages

  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES

;--------------------------------
;Languages

  !insertmacro MUI_LANGUAGE "English" ;first language is the default language
  !insertmacro MUI_LANGUAGE "SimpChinese"

;--------------------------------
;Reserve Files
  
  ;If you are using solid compression, files that are required before
  ;the actual installation should be stored first in the data block,
  ;because this will make your installer start faster.
  
  !insertmacro MUI_RESERVEFILE_LANGDLL

;--------------------------------
;Installer Sections

;This constant specifies Windows uninstall key for your application.
!define REG_UNINSTALL "Software\Microsoft\Windows\CurrentVersion\Uninstall\EnglishPlayer"

Section "EnglishPlayer" SecEnglishPlayer
SectionIn RO

  SetOutPath "$INSTDIR"
  
  ;ADD YOUR OWN FILES HERE...
  File bin\release\dbghelp.dll
  File bin\release\EnglishPlayer.exe
  File bin\release\mfc90.dll
  File bin\release\mfc90u.dll
  File bin\release\mfcm90.dll
  File bin\release\mfcm90u.dll
  File bin\release\Microsoft.VC90.CRT.manifest
  File bin\release\Microsoft.VC90.MFC.manifest
  File bin\release\msvcm90.dll
  File bin\release\msvcp90.dll
  File bin\release\msvcr90.dll
  File bin\release\template.htm
  File bin\release\tutorial.htm

  SetOutPath "$INSTDIR\samples"
  File bin\release\samples\02.mp3

  SetOutPath "$INSTDIR\samples\.transcriptions"
  File bin\release\samples\.transcriptions\02.mp3.htm

  SetOutPath "$INSTDIR\zh-CN"
  File bin\release\zh-CN\template.htm
  File bin\release\zh-CN\tutorial.htm
  File bin\release\zh-CN\main.txt

  CreateShortCut "$DESKTOP\EnglishPlayer.lnk" "$INSTDIR\EnglishPlayer.exe" "" "$INSTDIR\EnglishPlayer.exe" 0

  ;Store installation folder
  WriteRegStr HKCU "Software\EnglishPlayer" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"
  
  ;Writing uninstall info to registry:
  WriteRegStr HKLM "${REG_UNINSTALL}" "DisplayName" "English Player"
  WriteRegStr HKLM "${REG_UNINSTALL}" "DisplayIcon" "$INSTDIR\Uninstall.exe"
  WriteRegStr HKLM "${REG_UNINSTALL}" "DisplayVersion" "1.0"
  WriteRegStr HKLM "${REG_UNINSTALL}" "Publisher" "Bayou Studio"
  WriteRegStr HKLM "${REG_UNINSTALL}" "InstallSource" "$EXEDIR\"
  ;"Modify" will run installer and "Remove" will run uninstaller.
  WriteRegDWord HKLM "${REG_UNINSTALL}" "NoModify" 0
  WriteRegDWord HKLM "${REG_UNINSTALL}" "NoRepair" 0
  WriteRegStr HKLM "${REG_UNINSTALL}" "UninstallString" '"$INSTDIR\Uninstall.exe"'
  WriteRegStr HKLM "${REG_UNINSTALL}" "ModifyPath" '"$EXEDIR\EnglishPlayerSetup.exe"'
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\EnglishPlayer"
  CreateShortCut "$SMPROGRAMS\EnglishPlayer\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\EnglishPlayer\EnglishPlayer.lnk" "$INSTDIR\EnglishPlayer.exe" "" "$INSTDIR\EnglishPlayer.exe" 0
SectionEnd

;--------------------------------
;Installer Functions

Function .onInit

  !insertmacro MUI_LANGDLL_DISPLAY

FunctionEnd

;--------------------------------
;Descriptions

  ;USE A LANGUAGE STRING IF YOU WANT YOUR DESCRIPTIONS TO BE LANGAUGE SPECIFIC

  ;Assign descriptions to sections
  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${SecEnglishPlayer} "Installing EnglishPlayer."
  !insertmacro MUI_FUNCTION_DESCRIPTION_END

 
;--------------------------------
;Uninstaller Section

Section "Uninstall"

  ;ADD YOUR OWN FILES HERE...

  Delete "$INSTDIR\Uninstall.exe"
  Delete "$DESKTOP\EnglishPlayer.lnk"

  Delete "$SMPROGRAMS\EnglishPlayer\*.*"
  RMDir "$SMPROGRAMS\EnglishPlayer"
  RMDir "$INSTDIR"

  DeleteRegKey /ifempty HKCU "Software\EnglishPlayer"
  DeleteRegKey HKLM "${REG_UNINSTALL}"

SectionEnd

;--------------------------------
;Uninstaller Functions

Function un.onInit

  !insertmacro MUI_UNGETLANGUAGE
  
FunctionEnd
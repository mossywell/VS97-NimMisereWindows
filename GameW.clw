; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGameWDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GameW.h"

ClassCount=3
Class1=CGameWApp
Class2=CGameWDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GAMEW_DIALOG
Resource4=IDR_MENU1
Resource5=IDD_ABOUTBOX (English (U.S.))
Resource6=IDD_GAMEW_DIALOG (English (U.S.))
Resource7=IDR_MAIN_MENU

[CLS:CGameWApp]
Type=0
HeaderFile=GameW.h
ImplementationFile=GameW.cpp
Filter=N
LastObject=CGameWApp

[CLS:CGameWDlg]
Type=0
HeaderFile=GameWDlg.h
ImplementationFile=GameWDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CGameWDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=GameWDlg.h
ImplementationFile=GameWDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_GAMEW_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CGameWDlg

[DLG:IDD_GAMEW_DIALOG (English (U.S.))]
Type=1
Class=CGameWDlg
ControlCount=27
Control1=IDC_OUTPUT_LIST,listbox,1353793793
Control2=IDC_GO_BUTTON,button,1342242816
Control3=IDC_CLEAR_BUTTON,button,1342242816
Control4=IDC_EXIT_BUTTON,button,1342242816
Control5=IDC_COLUMNS_EDIT,edit,1350631552
Control6=IDC_COLUMNS_SPIN,msctls_updown32,1342177328
Control7=IDC_BASE_EDIT,edit,1350631552
Control8=IDC_BASE_SPIN,msctls_updown32,1342177328
Control9=IDC_TOTAL_EDIT,edit,1350633600
Control10=IDC_CURRENT_EDIT,edit,1350633600
Control11=IDC_LOST_EDIT,edit,1350633600
Control12=IDC_RESERVED_EDIT,edit,1350633600
Control13=IDC_TOTAL_STATIC,static,1342308352
Control14=IDC_CURRENT_STATIC,static,1342308864
Control15=IDC_RESERVED_STATIC,static,1342308864
Control16=IDC_LOST_STATIC,static,1342308864
Control17=IDC_COLUMNS_STATIC,static,1342308352
Control18=IDC_BASE_STATIC,static,1342308352
Control19=IDC_INPUT_STATIC,button,1342177287
Control20=IDC_OUTPUT_STATIC,button,1342177287
Control21=IDC_LOST_RADIO,button,1342308361
Control22=IDC_ALL_RADIO,button,1342177289
Control23=IDC_ALLANDLOST_RADIO,button,1342177289
Control24=IDC_TOTAL_PROGRESS,msctls_progress32,1350565888
Control25=IDC_POSITIONS_STATIC,button,1342177287
Control26=IDC_CURRENTPOSITION_STATIC,button,1342177287
Control27=IDC_CURRENTPOSITION_EDIT,edit,1350633600

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MENU1]
Type=1
Class=CGameWDlg
Command1=ID_FILE_EXIT
Command2=ID_ACTIONS_GOLOST
Command3=ID_ACTIONS_CLEAR
Command4=ID_HELP_ABOUT
CommandCount=4

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=ID_FILE_EXIT
Command2=ID_ACTIONS_GOLOST
Command3=ID_ACTIONS_CLEAR
Command4=ID_HELP_ABOUT
CommandCount=4


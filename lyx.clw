; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLyxDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lyx.h"

ClassCount=3
Class1=CLyxApp
Class2=CLyxDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LYX_DIALOG

[CLS:CLyxApp]
Type=0
HeaderFile=lyx.h
ImplementationFile=lyx.cpp
Filter=N

[CLS:CLyxDlg]
Type=0
HeaderFile=lyxDlg.h
ImplementationFile=lyxDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_MONTHCALENDAR3

[CLS:CAboutDlg]
Type=0
HeaderFile=lyxDlg.h
ImplementationFile=lyxDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LYX_DIALOG]
Type=1
Class=CLyxDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTTON1,button,1342242816
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631552
Control10=IDC_MONTHCALENDAR3,SysMonthCal32,1342242832
Control11=IDC_STATIC1,static,1342308864


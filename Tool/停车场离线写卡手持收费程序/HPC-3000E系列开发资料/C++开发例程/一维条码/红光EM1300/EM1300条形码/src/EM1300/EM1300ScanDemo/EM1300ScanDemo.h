// EM1300ScanDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif

// CEM1300ScanDemoApp:
// �йش����ʵ�֣������ EM1300ScanDemo.cpp
//

class CEM1300ScanDemoApp : public CWinApp
{
public:
	CEM1300ScanDemoApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEM1300ScanDemoApp theApp;

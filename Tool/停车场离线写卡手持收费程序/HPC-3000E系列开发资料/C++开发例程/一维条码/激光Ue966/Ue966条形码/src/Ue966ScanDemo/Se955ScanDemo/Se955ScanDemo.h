// Se955ScanDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif

// CSe955ScanDemoApp:
// �йش����ʵ�֣������ Se955ScanDemo.cpp
//

class CSe955ScanDemoApp : public CWinApp
{
public:
	CSe955ScanDemoApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSe955ScanDemoApp theApp;

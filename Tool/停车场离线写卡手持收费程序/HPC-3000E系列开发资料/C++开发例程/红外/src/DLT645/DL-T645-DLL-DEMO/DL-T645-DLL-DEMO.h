// DL-T645-DLL-DEMO.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif

// CDLT645DLLDEMOApp:
// �йش����ʵ�֣������ DL-T645-DLL-DEMO.cpp
//

class CDLT645DLLDEMOApp : public CWinApp
{
public:
	CDLT645DLLDEMOApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDLT645DLLDEMOApp theApp;

// BlueToothS10Test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif

// CBlueToothS10TestApp:
// �йش����ʵ�֣������ BlueToothS10Test.cpp
//

bool AssertResult(int result);

class CBlueToothS10TestApp : public CWinApp
{
public:
	CBlueToothS10TestApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBlueToothS10TestApp theApp;

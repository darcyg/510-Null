// BKLAdj.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif

// CBKLAdjApp:
// See BKLAdj.cpp for the implementation of this class
//

class CBKLAdjApp : public CWinApp
{
public:
	CBKLAdjApp();
	
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CBKLAdjApp theApp;

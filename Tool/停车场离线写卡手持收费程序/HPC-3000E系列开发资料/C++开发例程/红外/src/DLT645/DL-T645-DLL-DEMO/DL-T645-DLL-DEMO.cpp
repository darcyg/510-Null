// DL-T645-DLL-DEMO.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "DL-T645-DLL-DEMO.h"
#include "DL-T645-DLL-DEMODlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDLT645DLLDEMOApp

BEGIN_MESSAGE_MAP(CDLT645DLLDEMOApp, CWinApp)
END_MESSAGE_MAP()


// CDLT645DLLDEMOApp ����
CDLT645DLLDEMOApp::CDLT645DLLDEMOApp()
	: CWinApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDLT645DLLDEMOApp ����
CDLT645DLLDEMOApp theApp;

// CDLT645DLLDEMOApp ��ʼ��

BOOL CDLT645DLLDEMOApp::InitInstance()
{

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CDLT645DLLDEMODlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

// HPC_RFID_DEMO.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "HPC_RFID_DEMO.h"
#include "HPC_RFID_DEMODlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHPC_RFID_DEMOApp

BEGIN_MESSAGE_MAP(CHPC_RFID_DEMOApp, CWinApp)
END_MESSAGE_MAP()


// CHPC_RFID_DEMOApp ����
CHPC_RFID_DEMOApp::CHPC_RFID_DEMOApp()
	: CWinApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CHPC_RFID_DEMOApp ����
CHPC_RFID_DEMOApp theApp;

// CHPC_RFID_DEMOApp ��ʼ��

BOOL CHPC_RFID_DEMOApp::InitInstance()
{

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CHPC_RFID_DEMODlg dlg;
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

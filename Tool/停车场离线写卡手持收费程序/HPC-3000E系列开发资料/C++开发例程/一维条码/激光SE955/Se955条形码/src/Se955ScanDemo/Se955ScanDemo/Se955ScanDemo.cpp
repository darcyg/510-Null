// Se955ScanDemo.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Se955ScanDemo.h"
#include "Se955ScanDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSe955ScanDemoApp

BEGIN_MESSAGE_MAP(CSe955ScanDemoApp, CWinApp)
END_MESSAGE_MAP()


// CSe955ScanDemoApp ����
CSe955ScanDemoApp::CSe955ScanDemoApp()
	: CWinApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CSe955ScanDemoApp ����
CSe955ScanDemoApp theApp;

// CSe955ScanDemoApp ��ʼ��

BOOL CSe955ScanDemoApp::InitInstance()
{

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CSe955ScanDemoDlg dlg;
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

// EM1300ScanDemo.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "EM1300ScanDemo.h"
#include "EM1300ScanDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEM1300ScanDemoApp

BEGIN_MESSAGE_MAP(CEM1300ScanDemoApp, CWinApp)
END_MESSAGE_MAP()


// CEM1300ScanDemoApp ����
CEM1300ScanDemoApp::CEM1300ScanDemoApp()
	: CWinApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CEM1300ScanDemoApp ����
CEM1300ScanDemoApp theApp;

// CEM1300ScanDemoApp ��ʼ��

BOOL CEM1300ScanDemoApp::InitInstance()
{

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CEM1300ScanDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

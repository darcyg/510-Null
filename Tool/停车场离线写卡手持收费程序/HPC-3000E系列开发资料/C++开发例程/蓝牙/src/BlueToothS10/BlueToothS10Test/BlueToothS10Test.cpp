// BlueToothS10Test.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "BlueToothS10Test.h"
#include "BlueToothS10TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBlueToothS10TestApp

BEGIN_MESSAGE_MAP(CBlueToothS10TestApp, CWinApp)
END_MESSAGE_MAP()


// CBlueToothS10TestApp ����
CBlueToothS10TestApp::CBlueToothS10TestApp()
	: CWinApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CBlueToothS10TestApp ����
CBlueToothS10TestApp theApp;

// CBlueToothS10TestApp ��ʼ��

BOOL CBlueToothS10TestApp::InitInstance()
{

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CBlueToothS10TestDlg dlg;
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

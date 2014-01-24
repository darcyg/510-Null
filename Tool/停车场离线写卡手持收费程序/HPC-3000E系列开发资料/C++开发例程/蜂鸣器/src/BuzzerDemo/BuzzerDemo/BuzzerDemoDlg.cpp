// BuzzerDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BuzzerDemo.h"
#include "BuzzerDemoDlg.h"
#include "epcBuzzerLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBuzzerDemoDlg �Ի���

CBuzzerDemoDlg::CBuzzerDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBuzzerDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBuzzerDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBuzzerDemoDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BZR_ON, &CBuzzerDemoDlg::OnBnClickedBzrOn)
	ON_BN_CLICKED(IDC_BZR_OFF, &CBuzzerDemoDlg::OnBnClickedBzrOff)
	ON_BN_CLICKED(IDC_BZR_BEEPS, &CBuzzerDemoDlg::OnBnClickedBzrBeeps)
	ON_BN_CLICKED(IDC_BZR_STATUS, &CBuzzerDemoDlg::OnBnClickedBzrStatus)
END_MESSAGE_MAP()


// CBuzzerDemoDlg ��Ϣ�������

BOOL CBuzzerDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CBuzzerDemoDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_BUZZERDEMO_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_BUZZERDEMO_DIALOG));
	}
}
#endif


void CBuzzerDemoDlg::OnBnClickedBzrOn()
{
	// TODO: Add your control notification handler code here    
	BOOL bRet;

	bRet = epcBuzzerOn(0);                                   /*  ʹ������һֱ����            */
	if (bRet == FALSE ){
		MessageBox(_T("����������ʧ��"));
		return;
	}
	return;

}

void CBuzzerDemoDlg::OnBnClickedBzrOff()
{
	// TODO: Add your control notification handler code here
	BOOL bRet;

	bRet = epcBuzzerOff();                                   /*  ��������ֹ                  */
	if (bRet == FALSE ){
		MessageBox(_T("��������ֹʧ��"));
		return;
	}
	return;

}

void CBuzzerDemoDlg::OnBnClickedBzrBeeps()
{
	// TODO: Add your control notification handler code here
	BOOL bRet; 
	bRet = epcBuzzerBeeps(5,200,200);                         /*  ����������5��               */
	if (bRet == FALSE ){
		MessageBox(_T("����������ʧ��"));
		return;
	}    

}

void CBuzzerDemoDlg::OnBnClickedBzrStatus()
{
	// TODO: Add your control notification handler code here
	DWORD dwStatus; 

	dwStatus = epcBuzzerGetStatus();                          /*  ��������״̬                */
	if (dwStatus > 1){
		MessageBox(_T("��������״̬ʧ��"));
		return;
	}
	if (dwStatus == 0){
		MessageBox(_T("���������ڷ���״̬"));
	} else {
		MessageBox(_T("���������ڽ�ֹ״̬"));
	}
}

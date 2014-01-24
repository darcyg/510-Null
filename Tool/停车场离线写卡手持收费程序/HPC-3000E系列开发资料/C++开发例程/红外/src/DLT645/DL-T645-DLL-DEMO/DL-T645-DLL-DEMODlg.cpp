// DL-T645-DLL-DEMODlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DL-T645-DLL-DEMO.h"
#include "DL-T645-DLL-DEMODlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDialog *pDialog[4];
CDialog1 m_page1;
CDialog2 m_page2;
CDialog3 m_page3;
CDialog4 m_page4;

int m_CurSelTab;

// CDLT645DLLDEMODlg �Ի���

CDLT645DLLDEMODlg::CDLT645DLLDEMODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDLT645DLLDEMODlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDLT645DLLDEMODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_ctrTab);
}

BEGIN_MESSAGE_MAP(CDLT645DLLDEMODlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CDLT645DLLDEMODlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CDLT645DLLDEMODlg ��Ϣ�������

BOOL CDLT645DLLDEMODlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect rc0;
	GetClientRect(&rc0);
	rc0.top = 1;
	rc0.left = 0;
	rc0.right += 3;
	rc0.bottom += 25;
	MoveWindow(&rc0);

	//ΪTab Control��������ҳ��
	m_ctrTab.InsertItem(0, _T("����"));
	m_ctrTab.InsertItem(1, _T("2007-1"));
	m_ctrTab.InsertItem(2, _T("2007-2"));
	m_ctrTab.InsertItem(3, _T("1997"));
	m_ctrTab.SetActiveWindow();

	//���������Ի���
	m_page1.Create(IDD_DIALOG1, &m_ctrTab);
	m_page2.Create(IDD_DIALOG2, &m_ctrTab);
	m_page3.Create(IDD_DIALOG3, &m_ctrTab);
	m_page4.Create(IDD_DIALOG4, &m_ctrTab);

	//�趨��Tab����ʾ�ķ�Χ
	CRect rc;
	m_ctrTab.GetClientRect(&rc);
	rc.top += 22;
	rc.bottom -= 3;
	rc.left += 3;
	rc.right -= 3;
	m_page1.MoveWindow(&rc);
	m_page2.MoveWindow(&rc);
	m_page3.MoveWindow(&rc);
	m_page4.MoveWindow(&rc);

	//������ѶԻ������ָ�뱣������
	pDialog[0] = &m_page1;
	pDialog[1] = &m_page2;
	pDialog[2] = &m_page3;
	pDialog[3] = &m_page4;

	//��ʾ��ʼҳ��
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);
	pDialog[3]->ShowWindow(SW_HIDE);

	//���浱ǰѡ��
	m_CurSelTab = 0; 
	m_page1.m_ctrlCom.SetCurSel(1);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CDLT645DLLDEMODlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_DLT645DLLDEMO_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_DLT645DLLDEMO_DIALOG));
	}
}
#endif


void CDLT645DLLDEMODlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	m_CurSelTab = m_ctrTab.GetCurSel();
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW); 

	switch (m_CurSelTab)
	{
	case 0:
		m_page1.InitDialog();
		break;

	case 1:
		m_page2.InitDialog();
		break;

	case 2:
		m_page3.m_sAddress = m_page2.m_sAddress;
		m_page3.InitDialog();
		break;

	case 3:
		m_page4.InitDialog();
		break;

	default:
		break;
	}

	*pResult = 0;
}

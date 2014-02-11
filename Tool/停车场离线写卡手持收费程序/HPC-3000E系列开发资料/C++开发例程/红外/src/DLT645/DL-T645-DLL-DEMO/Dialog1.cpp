// Dialog1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DL-T645-DLL-DEMO.h"
#include "Dialog1.h"
#include "DLT645.h"

// CDialog1 �Ի���

IMPLEMENT_DYNAMIC(CDialog1, CDialog)

CDialog1::CDialog1(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog1::IDD, pParent)
	, m_nCom(0)
	, m_sDisplay(_T(""))
{

}

CDialog1::~CDialog1()
{
}

void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO1, m_nCom);
	DDX_Text(pDX, IDC_DISPLAY, m_sDisplay);
	DDX_Control(pDX, IDC_OPEN_PORT, m_ctrlOpenPort);
	DDX_Control(pDX, IDC_CLOSE_PORT, m_ctrlClosePort);
	DDX_Control(pDX, IDC_COMBO1, m_ctrlCom);
}


BEGIN_MESSAGE_MAP(CDialog1, CDialog)
	ON_BN_CLICKED(IDC_OPEN_PORT, &CDialog1::OnBnClickedOpenPort)
	ON_BN_CLICKED(IDC_CLOSE_PORT, &CDialog1::OnBnClickedClosePort)
END_MESSAGE_MAP()

void CDialog1::InitDialog()
{
	m_sDisplay= "";
}
// CDialog1 ��Ϣ�������

void CDialog1::OnBnClickedOpenPort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_sDisplay = _T("�򿪴���...\r\n");
	GetDlgItem(IDC_DISPLAY)->SetWindowText(m_sDisplay);
	UpdateData(TRUE);
	if (DLT645_OpenPort(m_nCom))
	{
		m_sDisplay = _T("�򿪴��ڳɹ���\r\n");
		UpdateData(FALSE);
	}
	else
	{
		m_sDisplay = _T("�򿪴���ʧ�ܣ�\r\n");
		UpdateData(FALSE);
		return;
	}
	
	m_ctrlClosePort.EnableWindow(TRUE);
	m_ctrlOpenPort.EnableWindow(FALSE);
	m_ctrlCom.EnableWindow(FALSE);
}

void CDialog1::OnBnClickedClosePort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (DLT645_ClosePort(m_nCom))
	{
		m_sDisplay += _T("�رմ��ڳɹ���\r\n");
		UpdateData(FALSE);
	}
	else
	{
		m_sDisplay += _T("�رմ���ʧ�ܣ�\r\n");
		UpdateData(FALSE);
		return;
	}
	m_ctrlClosePort.EnableWindow(FALSE);
	m_ctrlOpenPort.EnableWindow(TRUE);
	m_ctrlCom.EnableWindow(TRUE);
}

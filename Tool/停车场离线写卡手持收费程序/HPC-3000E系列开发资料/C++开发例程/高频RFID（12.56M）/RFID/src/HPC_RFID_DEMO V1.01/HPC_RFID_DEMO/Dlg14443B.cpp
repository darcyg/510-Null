// Dlg14443B.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HPC_RFID_DEMO.h"
#include "Dlg14443B.h"
#include "HPC_RFID_DLL.h"

// CDlg14443B �Ի���

IMPLEMENT_DYNAMIC(CDlg14443B, CDialog)

CDlg14443B::CDlg14443B(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg14443B::IDD, pParent)
	, m_sDisplay(_T(""))
{

}

CDlg14443B::~CDlg14443B()
{
}

void CDlg14443B::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_DISPLAY, m_sDisplay);
}


BEGIN_MESSAGE_MAP(CDlg14443B, CDialog)
	ON_BN_CLICKED(IDC_BTN_READ_SN, &CDlg14443B::OnBnClickedBtnReadSn)
	ON_BN_CLICKED(IDC_BTN_READ_SN2, &CDlg14443B::OnBnClickedBtnReadSn2)
	ON_BN_CLICKED(IDC_BTN_CLEAN, &CDlg14443B::OnBnClickedBtnClean)
END_MESSAGE_MAP()


// CDlg14443B ��Ϣ�������

void CDlg14443B::InitDialog(void)
{
}

void CDlg14443B::OnBnClickedBtnReadSn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BYTE i,ucCardSn[16];
	CString ss;

	if (RFID_STATUS_OK == ISO14443B_ReadCardSn(ucCardSn))
	{
		m_sDisplay += "OK!����14443B���ţ�\r\n";
		for (i=0; i<4; i++)
		{
			ss.Format(_T("%02X "),ucCardSn[i]);
			m_sDisplay += ss;
		}
		m_sDisplay += "\r\n";
	}
	else
	{
		m_sDisplay += "ERROR!��14443B����ʧ�ܣ�\r\n";
	}
	GetDlgItem(IDC_EDT_DISPLAY)->SetWindowText(m_sDisplay);
}

void CDlg14443B::OnBnClickedBtnReadSn2()
{
	BYTE i,ucCardSn[16];
	CString ss;

	if (RFID_STATUS_OK == ISO14443B_ReadSidCardSn(ucCardSn))
	{
		m_sDisplay += "OK!�����������֤���ţ�\r\n";
		for (i=0; i<8; i++)
		{
			ss.Format(_T("%02X "),ucCardSn[i]);
			m_sDisplay += ss;
		}
		m_sDisplay += "\r\n";
	}
	else
	{
		m_sDisplay += "ERROR!���������֤����ʧ�ܣ�\r\n";
	}
	GetDlgItem(IDC_EDT_DISPLAY)->SetWindowText(m_sDisplay);
}

void CDlg14443B::OnBnClickedBtnClean()
{
	m_sDisplay = "";
	UpdateData(FALSE);
}

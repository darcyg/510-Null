// Dlg15693.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HPC_RFID_DEMO.h"
#include "Dlg15693.h"
#include "HPC_RFID_DLL.h"
#include "MyString.h"

MyString MS3;

// CDlg15693 �Ի���

IMPLEMENT_DYNAMIC(CDlg15693, CDialog)

CDlg15693::CDlg15693(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg15693::IDD, pParent)
	, m_sDisplay(_T(""))
	, m_Block(0)
	, m_sData(_T(""))
{

}

CDlg15693::~CDlg15693()
{
}

void CDlg15693::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_DISPLAY, m_sDisplay);
	DDX_CBIndex(pDX, IDC_COM_BLOCK, m_Block);
	DDX_Text(pDX, IDC_EDT_DATA, m_sData);
}


BEGIN_MESSAGE_MAP(CDlg15693, CDialog)
	ON_BN_CLICKED(IDC_BTN_READ_SN, &CDlg15693::OnBnClickedBtnReadSn)
	ON_BN_CLICKED(IDC_BTN_READ_BLOCK, &CDlg15693::OnBnClickedBtnReadBlock)
	ON_BN_CLICKED(IDC_BTN_WRITE_BLOCK, &CDlg15693::OnBnClickedBtnWriteBlock)
	ON_BN_CLICKED(IDC_BTN_CLEAN, &CDlg15693::OnBnClickedBtnClean)
END_MESSAGE_MAP()


// CDlg15693 ��Ϣ�������

void CDlg15693::InitDialog(void)
{
	m_Block = 5;
	m_sData = (_T("12 34 56 78"));
	UpdateData(FALSE);
}

void CDlg15693::OnBnClickedBtnReadSn()
{
	BYTE i,ucCardSn[16];
	CString ss;

	if (RFID_STATUS_OK == ISO15693_ReadCardSn(ucCardSn))
	{
		m_sDisplay += "OK!����ISO15693���ţ�\r\n";
		for (i=0; i<8; i++)
		{
			ss.Format(_T("%02X "),ucCardSn[i]);
			m_sDisplay += ss;
		}
		m_sDisplay += "\r\n";
	}
	else
	{
		m_sDisplay += "ERROR!��ISO15693����ʧ�ܣ�\r\n";
	}
	GetDlgItem(IDC_EDT_DISPLAY)->SetWindowText(m_sDisplay);
}

void CDlg15693::OnBnClickedBtnReadBlock()
{
	BYTE i,ucData[16];
	CString ss;
	UpdateData(TRUE);
	if (RFID_STATUS_OK == ISO15693_ReadBlock(m_Block, ucData))
	{
		m_sDisplay += "OK!ISO15693����ɹ���\r\n";
		m_sDisplay += "����������Ϊ��\r\n";
		for (i=0; i<4; i++)
		{
			ss.Format(_T("%02X "),ucData[i]);
			m_sDisplay += ss;
		}
		m_sDisplay += "\r\n";
	}
	else
	{
		m_sDisplay += "ERROR!ISO15693����ʧ�ܣ�\r\n";
	}
	GetDlgItem(IDC_EDT_DISPLAY)->SetWindowText(m_sDisplay);
}

void CDlg15693::OnBnClickedBtnWriteBlock()
{
	BYTE i,ucData[16];
	CString ss;
	UpdateData(TRUE);
	MS3.StringToByte(m_sData, ucData, 4);
	if(m_Block < 5)
	{
		if (IDYES != MessageBox(_T("ѡ����С��5��������\n���ÿ飬ȷ��Ҫд�룿"), NULL, MB_YESNO))
		{
			return;
		}
	}
	if (RFID_STATUS_OK == ISO15693_WriteBlock(m_Block, ucData))
	{
		m_sDisplay += "OK!ISO15693д��ɹ���\r\n";
		m_sDisplay += "д�������Ϊ��\r\n";
		for (i=0; i<4; i++)
		{
			ss.Format(_T("%02X "),ucData[i]);
			m_sDisplay += ss;
		}
		m_sDisplay += "\r\n";
	}
	else
	{
		m_sDisplay += "ERROR!ISO15693д��ʧ�ܣ�\r\n";
	}
	GetDlgItem(IDC_EDT_DISPLAY)->SetWindowText(m_sDisplay);
}

void CDlg15693::OnBnClickedBtnClean()
{
	m_sDisplay = "";
	UpdateData(FALSE);
}

// DlgFeliCa.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HPC_RFID_DEMO.h"
#include "DlgFeliCa.h"
#include "HPC_RFID_DLL.h"

// CDlgFeliCa �Ի���

IMPLEMENT_DYNAMIC(CDlgFeliCa, CDialog)

CDlgFeliCa::CDlgFeliCa(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFeliCa::IDD, pParent)
	, m_sDisplay(_T(""))
{

}

CDlgFeliCa::~CDlgFeliCa()
{
}

void CDlgFeliCa::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_DISPLAY, m_sDisplay);
}


BEGIN_MESSAGE_MAP(CDlgFeliCa, CDialog)
	ON_BN_CLICKED(IDC_BTN_READ_FELICA_SN, &CDlgFeliCa::OnBnClickedBtnReadFelicaSn)
	ON_BN_CLICKED(IDC_BTN_CLEAN, &CDlgFeliCa::OnBnClickedBtnClean)
END_MESSAGE_MAP()


// CDlgFeliCa ��Ϣ�������

void CDlgFeliCa::InitDialog(void)
{
}

void CDlgFeliCa::OnBnClickedBtnReadFelicaSn()
{
	BYTE i,ucCardSn[16];
	CString ss;

	if (RFID_STATUS_OK == ISO18092_ReadFelicaSn(ucCardSn))
	{
		m_sDisplay += "OK!����Felica���ţ�\r\n";
		for (i=0; i<8; i++)
		{
			ss.Format(_T("%02X "),ucCardSn[i]);
			m_sDisplay += ss;
		}
		m_sDisplay += "\r\n";
	}
	else
	{
		m_sDisplay += "ERROR!��Felica����ʧ�ܣ�\r\n";
	}
	GetDlgItem(IDC_EDT_DISPLAY)->SetWindowText(m_sDisplay);
}

void CDlgFeliCa::OnBnClickedBtnClean()
{
	m_sDisplay = "";
	UpdateData(FALSE);
}

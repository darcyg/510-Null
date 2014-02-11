// DlgSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HPC_RFID_DEMO.h"
#include "DlgSetting.h"
#include "HPC_RFID_DLL.h"

// CDlgSetting �Ի���

IMPLEMENT_DYNAMIC(CDlgSetting, CDialog)

CDlgSetting::CDlgSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetting::IDD, pParent)
	, m_sDisplay(_T(""))
{

}

CDlgSetting::~CDlgSetting()
{
	RfidModulePowerOff();
}

void CDlgSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COM_COM, m_CtrCom);
	DDX_Text(pDX, IDC_EDT_DISPLAY, m_sDisplay);
	DDX_Control(pDX, IDC_BTN_CLOSE_PORT, m_ctrlClosePort);
	DDX_Control(pDX, IDC_BTN_OPEN_PORT, m_ctrlOpenPort);
}


BEGIN_MESSAGE_MAP(CDlgSetting, CDialog)
	ON_BN_CLICKED(IDC_BTN_OPEN_PORT, &CDlgSetting::OnBnClickedBtnOpenPort)
	ON_BN_CLICKED(IDC_BTN_CLOSE_PORT, &CDlgSetting::OnBnClickedBtnClosePort)
END_MESSAGE_MAP()


void CDlgSetting::InitDialog(void)
{
	//m_CtrCom.SetCurSel(0);
}

// CDlgSetting ��Ϣ�������

void CDlgSetting::OnBnClickedBtnOpenPort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BYTE com;
	CString ss;
	//UpdateData(FALSE);
	com = m_CtrCom.GetCurSel();
	ss.Format(_T("%X "),com+1);
	m_sDisplay = "COM";
	m_sDisplay += ss;
	if (RfidModuleOpenPort(com) == RFID_STATUS_OK)
	{
		m_sDisplay += "OK!�򿪴��ڳɹ���\r\n";
	}
	else
	{
		m_sDisplay += "ERROR!�򿪴���ʧ�ܣ�\r\n";
	}
	UpdateData(FALSE);
	RfidModulePowerOn();
	m_ctrlClosePort.EnableWindow(TRUE);
	m_ctrlOpenPort.EnableWindow(FALSE);
	m_CtrCom.EnableWindow(FALSE);
}

void CDlgSetting::OnBnClickedBtnClosePort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (RfidModuleClosePort() == RFID_STATUS_OK)
	{
		m_sDisplay += "OK!�رմ��ڳɹ���\r\n";
	}
	else
	{
		m_sDisplay += "ERROR!�رմ���ʧ�ܣ�\r\n";
	}
	UpdateData(FALSE);
	RfidModulePowerOff();
	m_ctrlClosePort.EnableWindow(FALSE);
	m_ctrlOpenPort.EnableWindow(TRUE);
	m_CtrCom.EnableWindow(TRUE);
}


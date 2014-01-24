// Dialog2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DL-T645-DLL-DEMO.h"
#include "Dialog2.h"
#include "DLT645.h"
#include "MyString.h"
#include "MyBeep.h"

// CDialog2 �Ի���
MyString MS1;
CMyBeep BP1;

IMPLEMENT_DYNAMIC(CDialog2, CDialog)

CDialog2::CDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog2::IDD, pParent)
	, m_sDataItem(_T(""))
	, m_sConsumer(_T(""))
	, m_sPassword(_T(""))
	, m_sData(_T(""))
	, m_sAddress(_T(""))
	, m_sTime(_T(""))
	, m_sDisplay(_T(""))
	, m_sAddressToWrite(_T(""))
{

}

CDialog2::~CDialog2()
{
}

void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DI, m_sDataItem);
	DDX_Text(pDX, IDC_C, m_sConsumer);
	DDX_Text(pDX, IDC_PW, m_sPassword);
	DDX_Text(pDX, IDC_DATA, m_sData);
	DDX_Text(pDX, IDC_ADDR, m_sAddress);
	DDX_Text(pDX, IDC_TIME, m_sTime);
	DDX_Text(pDX, IDC_DISPLAY, m_sDisplay);
	DDX_Text(pDX, IDC_ADDR2, m_sAddressToWrite);
}


BEGIN_MESSAGE_MAP(CDialog2, CDialog)
	ON_BN_CLICKED(IDC_READ_DATA, &CDialog2::OnBnClickedReadData)
	ON_BN_CLICKED(IDC_WRITE_DATA, &CDialog2::OnBnClickedWriteData)
	ON_BN_CLICKED(IDC_READ_ADDR, &CDialog2::OnBnClickedReadAddr)
	ON_BN_CLICKED(IDC_WRITE_TIME, &CDialog2::OnBnClickedWriteTime)
	ON_BN_CLICKED(IDC_WRITE_ADDR, &CDialog2::OnBnClickedWriteAddr)
END_MESSAGE_MAP()


// CDialog2 ��Ϣ�������
void CDialog2::InitDialog()
{
	m_sDataItem = _T("00 00 01 00");
	m_sConsumer = (_T("00 00 00 01"));
	m_sPassword = (_T("02 00 00 00"));
	m_sData = (_T("00 00 00 00 00 00"));
	//m_sAddress = (_T("00 00 00 00 00 00"));
	m_sAddressToWrite = (_T("11 22 33 44 55 66"));
	m_sTime = (_T("00 00 10 09 08 11"));
	m_sDisplay = (_T(""));
	UpdateData(FALSE);
}

void CDialog2::OnBnClickedReadData()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	BYTE Addr[6],DI[4],ReadBuff[255];
	CString sString;
	MS1.StringToByte(m_sAddress,Addr,6);
	MS1.StringToByte(m_sDataItem,DI,4);
	if (DLT645_2007_ReadData1(Addr, DI, ReadBuff))
	{
		MS1.ByteToString(&ReadBuff[6], &sString, ReadBuff[1]-4);
		m_sDisplay = _T("��ȡ�ɹ����������£�\r\n");
		m_sDisplay += sString;
		m_sDisplay += _T("\r\n");
		BP1.BeepOk();
	}
	else
	{
		m_sDisplay = _T("��ȡ����ʧ�ܣ�\r\n");
		BP1.BeepError();
	}
	UpdateData(FALSE);
}

void CDialog2::OnBnClickedWriteData()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	BYTE Addr[6],DI[4],WriteBuff[6],len,PassWord[4],Consumer[4];
	CString sString;
	MS1.StringToByte(m_sAddress,Addr,6);
	MS1.StringToByte(m_sDataItem,DI,4);
	MS1.StringToByte(m_sPassword,PassWord,4);
	MS1.StringToByte(m_sConsumer,Consumer,4);
	len = (BYTE) MS1.StringToByte(m_sData,WriteBuff,6);
	if (DLT645_2007_WriteData(Addr, DI, PassWord, Consumer, WriteBuff, len))
	{
		m_sDisplay = _T("д���ݳɹ���\r\n");
		BP1.BeepOk();
	}
	else
	{
		m_sDisplay = _T("д����ʧ�ܣ�\r\n");
		BP1.BeepError();
	}
	UpdateData(FALSE);
}

void CDialog2::OnBnClickedReadAddr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BYTE Addr[6];
	CString sString;
	if (DLT645_2007_ReadAddr(Addr))
	{
		m_sAddress = "";
		MS1.ByteToString(Addr, &sString, 6);
		MS1.ByteToString(Addr, &m_sAddress, 6);
		m_sDisplay = _T("��ͨ�ŵ�ַ�ɹ�����ַ���£�\r\n");
		m_sDisplay += sString;
		BP1.BeepOk();
	}
	else
	{
		m_sDisplay = _T("��ͨ�ŵ�ַʧ�ܣ�\r\n");
		BP1.BeepError();
	}
	UpdateData(FALSE);
}

void CDialog2::OnBnClickedWriteAddr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	BYTE Addr[6];
	MS1.StringToByte(m_sAddressToWrite,Addr,6);
	if (DLT645_2007_WriteAddr(Addr))
	{
		m_sDisplay = _T("дͨ�ŵ�ַ�ɹ���\r\n");
		BP1.BeepOk();
	}
	else
	{
		m_sDisplay = _T("дͨ�ŵ�ַʧ�ܣ�\r\n");
		BP1.BeepError();
	}
	UpdateData(FALSE);
}

void CDialog2::OnBnClickedWriteTime()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	BYTE Time[6];
	MS1.StringToByte(m_sTime,Time,6);
	if (DLT645_2007_BroadcastTime(Time))
	{
		m_sDisplay = _T("�㲥Уʱ��Ϣ�ѷ��ͣ�\r\n");
		BP1.BeepOk();
	}
	else
	{
		m_sDisplay = _T("�㲥Уʱ��Ϣ����ʧ�ܣ�\r\n");
		BP1.BeepError();
	}
	UpdateData(FALSE);
}


// ServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "CeCom.h"
#include "Cmd.h"
#include "tk.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CServerDlg �Ի���


UINT16 CRCCheckSum( BYTE* pucData, UINT32 uiLen);
CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
END_MESSAGE_MAP()


void CALLBACK  DisplayRcvData(void *pDlg, BYTE *pucBuf, DWORD dwRcvLen)
{	
	CRITICAL_SECTION  csDisp;
	CString str;
	CServerDlg	*p  = (CServerDlg *)pDlg;
	if(!(p && ::IsWindow(p->GetSafeHwnd())))
	{
		return;
	}
	byte buf[256];

	char show[256];

	InitializeCriticalSection(&csDisp);		                        //  ��ʼ���ٽ�������   
	EnterCriticalSection(&csDisp);		

	memcpy(show,pucBuf,dwRcvLen);
	show[dwRcvLen] = 0;
	str += L"received :";
	for(int i=0;i < dwRcvLen;i++)
	{
		CString tmp;
		tmp.Format(L" %02x",pucBuf[i]);
		str+=tmp;
	}
	//TK::Ansi2Unicode(wch,show);
	str += L"\r\n";

	memcpy(buf,show,dwRcvLen);
	reverse(buf,buf+dwRcvLen);

	Com_SendData(buf,dwRcvLen);


	str += L"send :";
	for(int i=0;i<dwRcvLen;i++)
	{
		CString tmp;
		tmp.Format(L" %02x",buf[i]);
		str+=tmp;
	}
	str += L"\r\n";

	p->AppendInfo(str);

	LeaveCriticalSection(&csDisp);			                        //  �˳��ٽ���  
	DeleteCriticalSection(&csDisp);			                        //  �ͷ��ٽ���������Դ
}

// CServerDlg ��Ϣ�������

BOOL CServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	Com_OpenPort(0);

	Com_Clear();

	Com_RcvDataTread(255, 100, (PFUN_COMRCV)DisplayRcvData, this);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CServerDlg::OnDestroy()
{
	CDialog::OnDestroy();

	Com_ClosePort();
}

void CServerDlg::AppendInfo(CString &str)
{

	CEdit * show= (CEdit*)GetDlgItem(IDC_SHOW);
	int pre=show->GetWindowTextLength();
	show->SetSel(show->GetWindowTextLength(),show->GetWindowTextLength());
	show->ReplaceSel(str);
	int now=show->GetWindowTextLength();
	show->SetSel(pre,now);
}

// EM1300ScanDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EM1300ScanDemo.h"
#include "EM1300ScanDemoDlg.h"
#include "EM1300DLL.h"
#include "epcBuzzerLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString strDisp = _T("");                                           /* ��ʼ��                       */

// CEM1300ScanDemoDlg �Ի���
UCHAR pattern[]={SCAN_INTERVAL,SCAN_PERCEIVE,SCAN_CONTINUE,SCAN_LAZYPERCEIVE,SCAN_SINGLE};

CEM1300ScanDemoDlg::CEM1300ScanDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEM1300ScanDemoDlg::IDD, pParent)
	, m_strDisp(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEM1300ScanDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CB_PATTERN, m_cbPattern);
	DDX_Control(pDX, IDC_BN_SETPATTERN, m_bnSetPattern);
	DDX_Control(pDX, IDC_BN_START, m_bnStart);
	DDX_Control(pDX, IDC_BN_END, m_bnEnd);
	DDX_Control(pDX, IDC_BN_VERSION, m_bnVersion);
	DDX_Control(pDX, IDC_BNCLEAR, m_bnClear);
}

BEGIN_MESSAGE_MAP(CEM1300ScanDemoDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BN_SETPATTERN, &CEM1300ScanDemoDlg::OnBnClickedBnSetpattern)
	ON_BN_CLICKED(IDC_BN_START, &CEM1300ScanDemoDlg::OnBnClickedBnStart)
	ON_BN_CLICKED(IDC_BN_END, &CEM1300ScanDemoDlg::OnBnClickedBnEnd)
	ON_BN_CLICKED(IDC_BN_VERSION, &CEM1300ScanDemoDlg::OnBnClickedBnVersion)
	ON_BN_CLICKED(IDC_BNCLEAR, &CEM1300ScanDemoDlg::OnBnClickedBnclear)
	ON_MESSAGE(WM_MYMESSAGE,OnMyMessage)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CEM1300ScanDemoDlg ��Ϣ�������

BOOL CEM1300ScanDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	::SetWindowPos(this->m_hWnd,HWND_TOPMOST,0,0,GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN), 0);
	m_cbPattern.AddString(L"���ɨ��");
	m_cbPattern.AddString(L"��Ӧɨ��");
	m_cbPattern.AddString(L"����ɨ��");
	m_cbPattern.AddString(L"�ӳٸ�Ӧɨ��");
	m_cbPattern.AddString(L"����ɨ��");
	m_cbPattern.SetCurSel(4);

	DWORD     dwThreadId;

	int ret = EM1300SerialInit(COM2);

	if( ret != INIT_OK) {
		CString str;
		str.Format(_T("%d"),ret);
		AfxMessageBox(_T("����ͨ��ʧ�ܣ�")+str);	
		::PostQuitMessage(0);
	}

	m_hExitThreadEvent = CreateEvent(NULL, TRUE, FALSE, NULL);            /*  �������ڽ����߳��˳��¼�  */

	m_Thread = CreateThread(NULL, 0, ThreadProc, this, 0, &dwThreadId);    /* �����߳�                 */

	/*
	*  �ж��߳��Ƿ񴴽��ɹ�
	*/
	if (!m_Thread) {
		CloseHandle(m_hExitThreadEvent);				                    /* �ر��߳��˳��¼����    */
		AfxMessageBox(_T("�����߳�ʧ�ܣ�"));

		::PostQuitMessage(0);
	}	
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CEM1300ScanDemoDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_EM1300SCANDEMO_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_EM1300SCANDEMO_DIALOG));
	}
}
#endif


/*********************************************************************************************************
** Function name:           ThreadProc
** Descriptions:            �̺߳���                        
** input parameters:        pArg                   ����ָ��			
** output parameters:       NONE                            
** 
** Returned value:          0(�߳̽���)
*********************************************************************************************************/
DWORD CEM1300ScanDemoDlg::ThreadProc(PVOID pArg)
{
	BYTE ReceiveBuf[MAXSIZE];
	BYTE ucCount = 0;
	BYTE i;
	CString strTmp;
	DWORD   ulState;

	/*
	*  ȡ��ʵʱ��ʾ��ľ��
	*/
	CEM1300ScanDemoDlg* pDlg = (CEM1300ScanDemoDlg*)pArg;                              
	
	while(TRUE) {

		/* 
		*  �ȴ��߳��˳��¼� 
		*/
		if (WaitForSingleObject(pDlg->m_hExitThreadEvent, 0) == WAIT_OBJECT_0)  {
			break;	
		}

		/*
		*  �жϽ��������Ƿ�ɹ�
		*/
		ulState = EM1300GetDecodeData(ReceiveBuf, &ucCount);
		if (ulState == RECEIVE_SUCCESS) {
			for (i = 0; i < ucCount; i++) {
				strTmp.Format(_T("%c"), ReceiveBuf[i]);   
				strDisp += strTmp; 
			}	
			::SendMessage(pDlg->m_hWnd,WM_MYMESSAGE,0,0);
			epcBuzzerOn(50);
			strDisp = _T("");                                           /* ��strDisp���                 */
		}
		Sleep(2);                                                       /* �߳�˯��2ms                   */
	}
	return 0;	
}

void CEM1300ScanDemoDlg::OnDestroy()
{
	CDialog::OnDestroy();
	if(!EM1300SerialTerminate())
	{
		AfxMessageBox(_T("��ֹͨ��ʧ��!"));
	}

	if (m_Thread != NULL) {	
		SetEvent(m_hExitThreadEvent);								    /*  ֪ͨ���ڽ����߳��˳�        */

		WaitForSingleObject(m_Thread, 500);		                        /*  �ȴ��߳��˳�                */
		CloseHandle(m_Thread);										    /*  �رս����߳̾��            */
		CloseHandle(m_hExitThreadEvent);				                /*  �ر��߳��˳��¼����        */		
		m_Thread = NULL;
	}
}

void CEM1300ScanDemoDlg::OnBnClickedBnSetpattern()
{
	int curPattern = m_cbPattern.GetCurSel();
	if(EM1300TriggerState(pattern[curPattern]) != SUCCESS_SETTING)
	{
		AfxMessageBox(_T("���ô���ģʽʧ��"));
		return;
	}
	if(curPattern == 4)
	{
		m_bnStart.EnableWindow();
		m_bnEnd.EnableWindow();
	}
	else
	{
		m_bnStart.EnableWindow(FALSE);
		m_bnEnd.EnableWindow(FALSE);
	}
}

void CEM1300ScanDemoDlg::OnBnClickedBnStart()
{
	if(EM1300DecodeState(TRUE) != SUCCESS_SETTING)
	{
		AfxMessageBox(_T("��������ʧ��!"));
	}
}

void CEM1300ScanDemoDlg::OnBnClickedBnEnd()
{
	if(EM1300DecodeState(FALSE) != SUCCESS_SETTING)
	{
		AfxMessageBox(_T("ֹͣ����ʧ��!"));
	}
}

void CEM1300ScanDemoDlg::OnBnClickedBnVersion()
{
	DWORD  ulState;
	ulState = EM1300GetVersion();
	CString str;
	str.Format(L"����汾 :V%.2lf!",ulState*1.0/100);
	AfxMessageBox(str);
}

void CEM1300ScanDemoDlg::OnBnClickedBnclear()
{
	CEdit * disp=(CEdit*)GetDlgItem(IDC_DISP);
	disp->SetSel(0,-1);
	disp->Clear();
	disp->SetFocus();
}

LRESULT CEM1300ScanDemoDlg::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CEdit *disp = (CEdit*)GetDlgItem(IDC_DISP);            /* ��ÿؼ����                 */

	int prev = disp->GetWindowTextLength();
	disp->SetSel(prev,prev);
	disp->ReplaceSel(strDisp + _T("\r\n��ȡ�ɹ���\r\n"));
	int next = disp->GetWindowTextLength();
	disp->SetSel(prev,next);
	disp->SetFocus();
	return 0;
}


volatile bool bContinue = false;
volatile bool bTimerset = false;
volatile bool bF20Uped	= false;
BOOL CEM1300ScanDemoDlg::PreTranslateMessage(MSG* pMsg)
{
	static DWORD pre = 0;
	if (pMsg->message == WM_KEYDOWN && bF20Uped == true && bContinue == true)
	{
		EM1300TriggerState(SCAN_SINGLE);
		bContinue = false;
	}
	else if (pMsg->message == WM_KEYDOWN && pMsg->wParam==VK_F20 && !bContinue)//���̶�Ӧ���ֻ�ASCII��    
	{
		if(!bTimerset)
			SetTimer(1,5000,NULL);
		bTimerset=true;
		DWORD now=GetTickCount();
		if(now-pre>300)
		{
			pre=now;
			int ret=EM1300DecodeState(TRUE);
			if (ret != SUCCESS_SETTING) 
			{
				AfxMessageBox(L"���ô���");
				return 0;
			}
		}
		bF20Uped = false;
	}
	else if (pMsg->message == WM_KEYUP && pMsg->wParam==VK_F20)
	{
		if(bTimerset)
			KillTimer(1);
		bTimerset=false;
		bF20Uped = true;
	}
	return CDialog::PreTranslateMessage(pMsg); 
}
void CEM1300ScanDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == 1)
	{
		bContinue=true;
		EM1300TriggerState(SCAN_CONTINUE);
		KillTimer(1);
		bTimerset=false;
	}

	CDialog::OnTimer(nIDEvent);

	CDialog::OnTimer(nIDEvent);
}

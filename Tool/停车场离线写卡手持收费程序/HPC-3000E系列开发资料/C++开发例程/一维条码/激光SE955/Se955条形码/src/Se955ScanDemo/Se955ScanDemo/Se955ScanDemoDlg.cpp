// Se955ScanDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Se955ScanDemo.h"
#include "Se955ScanDemoDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSe955ScanDemoDlg �Ի���

CSe955ScanDemoDlg::CSe955ScanDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSe955ScanDemoDlg::IDD, pParent)
	, m_strdisp(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Thread = NULL;
	m_hExitThreadEvent = NULL;
}

void CSe955ScanDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BAUD, m_comboBaud);
	DDX_Text(pDX, IDC_DISP, m_strdisp);
	DDX_Control(pDX, IDC_COM, m_comboCom);
}

BEGIN_MESSAGE_MAP(CSe955ScanDemoDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_START, &CSe955ScanDemoDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_TERMINATE, &CSe955ScanDemoDlg::OnBnClickedTerminate)
	ON_BN_CLICKED(IDC_STARTSCAN, &CSe955ScanDemoDlg::OnBnClickedStartscan)
	ON_BN_CLICKED(IDC_CLOSESCAN, &CSe955ScanDemoDlg::OnBnClickedClosescan)
	ON_BN_CLICKED(IDC_SOFTTRIG, &CSe955ScanDemoDlg::OnBnClickedSofttrig)
	ON_BN_CLICKED(IDC_CONTINUETRIG, &CSe955ScanDemoDlg::OnBnClickedContinuetrig)
	ON_BN_CLICKED(IDC_VERSION, &CSe955ScanDemoDlg::OnBnClickedVersion)
	ON_BN_CLICKED(IDC_CLR, &CSe955ScanDemoDlg::OnBnClickedClr)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CSe955ScanDemoDlg ��Ϣ�������

/*********************************************************************************************************
** Function name:           OnInitDialog
** Descriptions:            �Ի����ʼ������                        
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
BOOL CSe955ScanDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_comboCom.SetCurSel(0);                                            /* Ĭ��ѡ��COM2                  */
	m_comboBaud.SetCurSel(5);			                                /* Ĭ��ѡ��9600������            */
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CSe955ScanDemoDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_SE955SCANDEMO_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_SE955SCANDEMO_DIALOG));
	}
}
#endif



static UCHAR GucComNo = 0;


/*********************************************************************************************************
���ںű�
*********************************************************************************************************/
const UCHAR     GenPortTbl[5]   = {COM1, COM2, COM3, COM4, COM5};


/*********************************************************************************************************
�����ʱ�
*********************************************************************************************************/
const UCHAR     GenBaudTbl[8]   = {B_RATE300,  B_RATE600,   B_RATE1200, B_RATE2400, 
B_RATE4800, B_RATE9600, B_RATE19200, B_RATE38400};

/*********************************************************************************************************
ֹͣλ��
*********************************************************************************************************/
const UCHAR     GenStopTbl[2]   = {STOP_BITONE, STOP_BITTWO};


/*********************************************************************************************************
У��λ��
*********************************************************************************************************/
const UCHAR     GenParityTbl[5] = {DAT_ODD, DAT_EVEN, DAT_MARK, DAT_SPACE, DAT_NONE};
/*********************************************************************************************************



/*********************************************************************************************************
** Function name:           OnDestroy
** Descriptions:            ���ٴ���ʱ����                      
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnDestroy() 
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
	Se955SerialTerminate();	

	if (m_Thread != NULL) {	
		SetEvent(m_hExitThreadEvent);								    /*  ֪ͨ���ڽ����߳��˳�        */

		WaitForSingleObject(m_Thread, 500);		                        /*  �ȴ��߳��˳�                */
		CloseHandle(m_Thread);										    /*  �رս����߳̾��            */
		CloseHandle(m_hExitThreadEvent);				                /*  �ر��߳��˳��¼����        */		
		m_Thread = NULL;
	}
	
}



/*********************************************************************************************************
** Function name:           OnBnClickedStart
** Descriptions:            ����ͨ��                        
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	CButton   *pcbtnOpenClose;
	DWORD     dwThreadId;
    UCHAR     ucBaud;

    /* 
	 *  ȡ�ô��ڲ����ʡ�ֹͣλ����żУ��λ
	 */
	UpdateData(TRUE);
 	GucComNo = GenPortTbl[m_comboCom.GetCurSel()];
    
	/* 
	 *  ȡ�ô��ڲ����ʡ�ֹͣλ����żУ��λ
	 */
	GucComNo = GenPortTbl[m_comboCom.GetCurSel()];
    ucBaud   = GenBaudTbl[m_comboBaud.GetCurSel()];	
   
	/* 
	 *  ��ȡ���ں�����ͨ��
	 */	
	if(Se955SerialInit(GucComNo,ucBaud,STOP_BITONE,DAT_NONE) != INIT_OK) {
		AfxMessageBox(_T("����ͨ��ʧ�ܣ�"));	
		return;
	}

	m_hExitThreadEvent = CreateEvent(NULL, TRUE, FALSE, NULL);            /*  �������ڽ����߳��˳��¼�  */
	
	m_Thread = CreateThread(NULL, 0, ThreadProc, this, 0, &dwThreadId);    /* �����߳�                 */
	  
	/*
	 *  �ж��߳��Ƿ񴴽��ɹ�
	 */
	if (!m_Thread) {
		CloseHandle(m_hExitThreadEvent);				                    /* �ر��߳��˳��¼����    */
		AfxMessageBox(_T("�����߳�ʧ�ܣ�"));
		return;
	}	
	pcbtnOpenClose = (CButton *)GetDlgItem(IDC_START); 	                /* ����"����ͨ��"��ť��Ч         */
	pcbtnOpenClose->EnableWindow(FALSE);
    
	pcbtnOpenClose = (CButton *)GetDlgItem(IDC_TERMINATE); 	            /* ����"��ֹͨ��"��ť��Ч         */
	pcbtnOpenClose->EnableWindow(TRUE);

}


/*********************************************************************************************************
** Function name:           OnBnClickedTerminate
** Descriptions:            ��ֹͨ��                        
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnBnClickedTerminate()
{
	// TODO: Add your control notification handler code here
	CButton   *pcbtnOpenClose;

	/* 
	 *  �رմ���
	 */
	Se955SerialTerminate();

	if (m_Thread != NULL) {	
		SetEvent(m_hExitThreadEvent);								    /*  ֪ͨ���ڽ����߳��˳�        */

		WaitForSingleObject(m_Thread, 500);		                        /*  �ȴ��߳��˳�                */
		CloseHandle(m_Thread);										    /*  �رս����߳̾��            */
		CloseHandle(m_hExitThreadEvent);				                /*  �ر��߳��˳��¼����        */		
		m_Thread = NULL;
	}
   


    /* 
	 *  ����"����ͨ��"��ť��Ч�� ����"��ֹͨ��"��ť��Ч
	 */
	pcbtnOpenClose = (CButton *)GetDlgItem(IDC_START); 	
	pcbtnOpenClose->EnableWindow(TRUE);
    
	pcbtnOpenClose = (CButton *)GetDlgItem(IDC_TERMINATE); 	
	pcbtnOpenClose->EnableWindow(FALSE);	
}



/*********************************************************************************************************
** Function name:           OnBnClickedStartscan
** Descriptions:            ��ʼɨ��                        
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnBnClickedStartscan()
{
	// TODO: Add your control notification handler code here
	if (Se955DecodeState(TRUE) != SUCCESS_SETTING) {
		AfxMessageBox(_T("���ô���"));
	}

}

/*********************************************************************************************************
** Function name:           OnBnClickedClosescan
** Descriptions:            �ر�ɨ��                        
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnBnClickedClosescan()
{
	// TODO: Add your control notification handler code here
	if (Se955DecodeState(FALSE) != SUCCESS_SETTING) {
		AfxMessageBox(_T("���ô���"));
	}
}

/*********************************************************************************************************
** Function name:           OnBnClickedSofttrig
** Descriptions:            ����Ϊ���ɨ�跽ʽ                       
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnBnClickedSofttrig()
{
	// TODO: Add your control notification handler code here
	CButton   *pcbtnOpenClose;

	if (Se955TriggerState(SCAN_HOST) != SUCCESS_SETTING) {
		AfxMessageBox(_T("���ô���"));
	}

	pcbtnOpenClose = (CButton *)GetDlgItem(IDC_STARTSCAN); 	           /* ����"��ʼɨ��"��ť��Ч       */
	pcbtnOpenClose->EnableWindow(TRUE);

	pcbtnOpenClose = (CButton *)GetDlgItem(IDC_CLOSESCAN); 	           /* ����"�ر�ɨ��"��ť��Ч       */
	pcbtnOpenClose->EnableWindow(TRUE);
}

/*********************************************************************************************************
** Function name:           OnBnClickedContinuetrig
** Descriptions:            ����Ϊ����ɨ�跽ʽ                        
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnBnClickedContinuetrig()
{
	// TODO: Add your control notification handler code here	
	CButton   *pcbtnOpenClose;

	if (Se955TriggerState(SCAN_CONTINUE) != SUCCESS_SETTING) {
		AfxMessageBox(_T("���ô���"));
	}

	pcbtnOpenClose = (CButton *)GetDlgItem(IDC_STARTSCAN); 	           /* ����"��ʼɨ��"��ť��Ч         */
	pcbtnOpenClose->EnableWindow(FALSE);

	pcbtnOpenClose = (CButton *)GetDlgItem(IDC_CLOSESCAN); 	           /* ����"�ر�ɨ��"��ť��Ч         */
	pcbtnOpenClose->EnableWindow(FALSE);
}






/*********************************************************************************************************
** Function name:           ThreadProc
** Descriptions:            �̺߳���                        
** input parameters:        pArg                   ����ָ��			
** output parameters:       NONE                            
** 
** Returned value:          0(�߳̽���)
*********************************************************************************************************/
DWORD CSe955ScanDemoDlg::ThreadProc(PVOID pArg)
{
	BYTE ReceiveBuf[MAXSIZE];
	BYTE ucCount = 0;
	BYTE i;
	CString strTmp;
	CString strDisp = _T("");                                           /* ��ʼ��                       */
	DWORD   ulState;
	
	/*
	 *  ȡ��ʵʱ��ʾ��ľ��
	 */
	CSe955ScanDemoDlg* pDlg = (CSe955ScanDemoDlg*)pArg;                              
    CEdit *pceditRcv = (CEdit*)pDlg->GetDlgItem(IDC_DISP);            /* ��ÿؼ����                 */
	
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
		ulState = Se955GetDecodeData(ReceiveBuf, &ucCount);
		if (ulState == RECEIVE_SUCCESS) {
			for (i = 0; i < ucCount; i++) {
				strTmp.Format(_T("%c"), ReceiveBuf[i]);   
				strDisp += strTmp; 
			}	

			pDlg->m_strdisp += strDisp;
			pDlg->m_strdisp += _T("\r\n��ȡ�ɹ���\r\n");
			pceditRcv->SetWindowText(pDlg->m_strdisp);
			
			strDisp = _T("");                                           /* ��strDisp���                 */
		}
		Sleep(2);                                                       /* �߳�˯��2ms                   */
	}
	return 0;	
}




/*********************************************************************************************************
** Function name:           OnBnClickedVersion
** Descriptions:            ��ȡ������汾                       
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnBnClickedVersion()
{
	// TODO: Add your control notification handler code here
	DWORD  ulState;
	ulState = Se955GetVersion();
	switch (ulState)
	{
		case 100:
		AfxMessageBox(_T("����汾��V1.00��"));
		break;
		case 101:
		AfxMessageBox(_T("����汾��V1.01��"));
		break;
		default:
		break;
	}
}


/*********************************************************************************************************
** Function name:           OnBnClickedClr
** Descriptions:            �����ʾ��������                       
** input parameters:        NONE			
** output parameters:       NONE                            
** 
** Returned value:          NONE
*********************************************************************************************************/
void CSe955ScanDemoDlg::OnBnClickedClr()
{
	// TODO: Add your control notification handler code here
	m_strdisp = _T("");	
	UpdateData(FALSE);
}

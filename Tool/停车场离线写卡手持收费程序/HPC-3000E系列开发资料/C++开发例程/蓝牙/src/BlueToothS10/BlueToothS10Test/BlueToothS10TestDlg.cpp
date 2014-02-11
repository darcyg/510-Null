// BlueToothS10TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BlueToothS10Test.h"
#include "BlueToothS10TestDlg.h"
#include "BlueToothS10.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


bool AssertResult(int result)
{
	if(result != SUCCESS_SETTING)
	{
		CString str;
		str.Format(_T("Failed : %d"),result);
		AfxMessageBox(str);
		return false;
	}
	return true;
}
// CBlueToothS10TestDlg �Ի���

CBlueToothS10TestDlg::CBlueToothS10TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBlueToothS10TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
	
void CBlueToothS10TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABFUNC, m_Funcs);
}

BEGIN_MESSAGE_MAP(CBlueToothS10TestDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABFUNC, &CBlueToothS10TestDlg::OnTcnSelchangeTabfunc)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CBlueToothS10TestDlg ��Ϣ�������

BOOL CBlueToothS10TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	::SetWindowPos(m_hWnd,HWND_TOPMOST,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN),0);
	

	CSize size;
	size.cx=60;
	size.cy=30;
	size=m_Funcs.SetItemSize(size);
	m_Funcs.SetMinTabWidth(60);
	int index = 0;
	InsertTab(&m_ModuleDlg,CModule::IDD,index++,_T("Basic"));
	InsertTab(&m_SettingDlg,CSetting::IDD,index++,_T("Setting"));
	InsertTab(&m_SearchDlg,CSearch::IDD,index++,_T("Query"));
	InsertTab(&m_TransportDlg,CTransport::IDD,index++,_T("Transport"));
	m_Funcs.SetCurSel(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CBlueToothS10TestDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_BLUETOOTHS10TEST_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_BLUETOOTHS10TEST_DIALOG));
	}
}
#endif

void CBlueToothS10TestDlg::InsertTab( CDialog* pDlg, UINT nTemplate, int index, LPCTSTR lpszItem )
{
	if ( !pDlg )
		return;

	CRect rc;
	m_Funcs.GetWindowRect( &rc );
	ScreenToClient( &rc );
	rc.DeflateRect( 1, 30, 1, 2 );

	m_Funcs.InsertItem( index, lpszItem );
	pDlg->Create( nTemplate, &m_Funcs );
	pDlg->MoveWindow( &rc );
	pDlg->ShowWindow( SW_SHOW );
	m_pDlgs[index] = pDlg;
}
void CBlueToothS10TestDlg::OnTcnSelchangeTabfunc(NMHDR *pNMHDR, LRESULT *pResult)
{
	SelChangeTab();
	*pResult = 0;
}


void CBlueToothS10TestDlg::SelChangeTab()
{
	int sel = m_Funcs.GetCurSel();
	for ( int i = 0; i < DLG_NUM; ++i )
	{
		if ( !m_pDlgs[i] || m_pDlgs[i]->GetSafeHwnd() == NULL )
			continue;

		if ( sel == i )
		{
			m_pDlgs[i]->SetFocus();
			m_pDlgs[i]->ShowWindow( SW_SHOW );
		}
		else
		{
			m_pDlgs[i]->ShowWindow( SW_HIDE );
		}
	}
}
void CBlueToothS10TestDlg::OnDestroy()
{
	CDialog::OnDestroy();

	S10_Close();
}

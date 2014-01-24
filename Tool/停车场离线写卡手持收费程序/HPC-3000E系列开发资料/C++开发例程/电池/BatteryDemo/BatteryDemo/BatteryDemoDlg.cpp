// BatteryDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BatteryDemo.h"
#include "BatteryDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBatteryDemoDlg �Ի���

CBatteryDemoDlg::CBatteryDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBatteryDemoDlg::IDD, pParent)
    , m_szVoltage(_T(""))
    , m_szACStatus(_T(""))
    , m_szBattStatus(_T(""))
    , m_szBattCharging(_T(""))
    , m_szPercent(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBatteryDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_VOLATAGE, m_szVoltage);
    DDX_Text(pDX, IDC_STATIC_AC_STATUS, m_szACStatus);
    DDX_Text(pDX, IDC_STATIC_BATT_STATUS, m_szBattStatus);
    DDX_Text(pDX, IDC_STATIC_BATT_STATUS_CHARGING, m_szBattCharging);
    DDX_Text(pDX, IDC_EDIT_PERCENT, m_szPercent);
}

BEGIN_MESSAGE_MAP(CBatteryDemoDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
    ON_WM_TIMER()
END_MESSAGE_MAP()


// CBatteryDemoDlg ��Ϣ�������

BOOL CBatteryDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,100,NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CBatteryDemoDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_BATTERYDEMO_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_BATTERYDEMO_DIALOG));
	}
}
#endif


void CBatteryDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: Add your message handler code here and/or call default

    SYSTEM_POWER_STATUS_EX2 powerInfo;                                  /* ϵͳ��Դ״̬�ṹ��           */

    if ( GetSystemPowerStatusEx2( &powerInfo,
                                  sizeof(SYSTEM_POWER_STATUS_EX2),
                                  FALSE) != 0 ) {                       /* ��ȡϵͳ��Դ״̬��Ϣ         */

        m_szVoltage.Format(_T("��ѹ %dmV"),powerInfo.BatteryVoltage);   /* ��ʾ��ص�ѹ                 */
        m_szPercent.Format(_T("���� %d%%"),powerInfo.BatteryLifePercent);/* ��ʾ��ص����ٷֱ�           */

        /*
        *  ��������ʾ��س������ʹ��״̬�������ӳ������ϵͳʹ��
        *  ��������硣δ���ӳ����ʱʹ�õ�ع���
        */
        if (powerInfo.ACLineStatus == AC_LINE_UNKNOWN) {
            m_szACStatus = _T("δ֪��Դ");
        }else if ( (powerInfo.ACLineStatus&AC_LINE_ONLINE) == AC_LINE_ONLINE ) {
            m_szACStatus = _T("����ʹ���ⲿ��Դ");
        }else if ( (powerInfo.ACLineStatus&AC_LINE_OFFLINE) == AC_LINE_OFFLINE ) {
            m_szACStatus = _T("����ʹ�õ�ص�Դ");
        } else {
            m_szACStatus = _T("δ֪��Դ");
        }

        /*
        *  ��������ʾ��ؼ��𣬼���صĵ���״̬
        */
        if ( (powerInfo.BatteryFlag == BATTERY_FLAG_UNKNOWN) ) {
            m_szBattStatus = _T("δ֪�ĵ�ؼ���");
        } else if ( (powerInfo.BatteryFlag&BATTERY_FLAG_HIGH) == BATTERY_FLAG_HIGH ) {
            m_szBattStatus = _T("��ص�����");
        } else if ( (powerInfo.BatteryFlag&BATTERY_FLAG_LOW) == BATTERY_FLAG_LOW ) {
            m_szBattStatus = _T("��ص�������");
        } else if ( (powerInfo.BatteryFlag&BATTERY_FLAG_CRITICAL) == BATTERY_FLAG_CRITICAL ) {
            m_szBattStatus = _T("��ص������ز���");
        } else {
            m_szBattStatus = _T("δ֪�ĵ�ؼ���");
        } 

        /*
        *  ��������ʾ����Ƿ����ڳ��
        */
        if ( (powerInfo.BatteryFlag&BATTERY_FLAG_CHARGING) == BATTERY_FLAG_CHARGING ) {
            m_szBattCharging = _T("���ڳ��");
        } else {
            if (( powerInfo.ACLineStatus&AC_LINE_ONLINE) == AC_LINE_ONLINE ) {
                m_szBattCharging = _T("ʹ���ⲿ��Դ");
            } else {
                m_szBattCharging = _T("ʹ�õ��");
            }
        }



        UpdateData(FALSE);
    }

    CDialog::OnTimer(nIDEvent);
}

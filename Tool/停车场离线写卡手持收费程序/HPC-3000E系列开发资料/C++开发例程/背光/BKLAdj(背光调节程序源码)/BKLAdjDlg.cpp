// BKLAdjDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BKLAdj.h"
#include "BKLAdjDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBKLAdjDlg dialog

CBKLAdjDlg::CBKLAdjDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBKLAdjDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_hBackLight = INVALID_HANDLE_VALUE;
}

void CBKLAdjDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK_BATTER, m_ctlCheckBatteryAutoOff);
    DDX_Control(pDX, IDC_COMBO_BATT_TIME, m_ctlComboBatteryTime);
    DDX_Control(pDX, IDC_COMBO_AC_TIME, m_ctlComboACTime);
    DDX_Control(pDX, IDC_STATIC_BRIGHTNESS_PERCENT, m_ctlStaticBrightness);
    DDX_Control(pDX, IDC_SLIDER_VAL, m_ctlSliderBrightness);
    DDX_Control(pDX, IDC_CHECK_AC, m_ctlCheckACAutoOff);
}

BEGIN_MESSAGE_MAP(CBKLAdjDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_CHECK_BATTER, &CBKLAdjDlg::OnBnClickedCheckBatter)
    ON_BN_CLICKED(IDC_CHECK_AC, &CBKLAdjDlg::OnBnClickedCheckAc)
    ON_WM_HSCROLL()
    ON_CBN_SELCHANGE(IDC_COMBO_BATT_TIME, &CBKLAdjDlg::OnCbnSelchangeComboBattTime)
    ON_CBN_SELCHANGE(IDC_COMBO_AC_TIME, &CBKLAdjDlg::OnCbnSelchangeComboAcTime)
END_MESSAGE_MAP()
#define MAX_BATT_TABLE 5

/* ��ع���ʱ��ѡ�ĳ�ʱʱ��     */
const DWORD dwBattTimeTable[MAX_BATT_TABLE] = {15,30,60,120,300};
const WCHAR *wcszBattTimeName[MAX_BATT_TABLE] = 
{
    L"15��",
    L"30��",
    L"1����",
    L"2����",
    L"5����"
};

#define MAX_AC_TABLE 8
const DWORD dwAcTimeTable[MAX_AC_TABLE] = {15,30,60,120,300,600,900,1800};
const WCHAR *wcszACTimeName[MAX_AC_TABLE] = 
{
    L"15��",
    L"30��",
    L"1����",
    L"2����",
    L"5����",
    L"10����",
    L"15����",
    L"30����"
};

// CBKLAdjDlg message handlers
#define     MIN_BRIGHTNESS_PERCENT      2

void CBKLAdjDlg::GetBackLightDrvRegPath()
{
    HKEY        hEnumKey = NULL;
    LONG        lrEnum;
    WCHAR       cbEnumNames[MAX_PATH];
    DWORD       dwEnumLen;
    int         iEnumIndex =0;

    CString     strBklName = L"BKL1:";

    lrEnum = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
        L"Drivers\\Active",0,0,&hEnumKey);
    if (ERROR_SUCCESS != lrEnum)
    {
        return;
    }   
    do 
    {
        dwEnumLen = MAX_PATH;
        lrEnum = RegEnumKeyEx(hEnumKey,iEnumIndex,
            cbEnumNames,&dwEnumLen,NULL,NULL,NULL,NULL);
        cbEnumNames[dwEnumLen]=0;
        iEnumIndex ++;
        if (ERROR_SUCCESS == lrEnum)
        {
            CString     str;
            HKEY        hKey;
            DWORD       dwType;
            LONG        lrTmp;
            WCHAR       wszDrvName[16];
            DWORD       dwSize = sizeof(wszDrvName);

            str.Format(L"Drivers\\Active\\%s",cbEnumNames);
            lrTmp =  RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                str,0,0,&hKey);
            if (ERROR_SUCCESS == lrTmp)
            {
                lrTmp=RegQueryValueEx(hKey,L"Name",NULL,
                    &dwType,(BYTE *)wszDrvName,&dwSize);
                if (ERROR_SUCCESS== lrTmp && dwType == REG_SZ)
                {
                    wszDrvName[dwSize/sizeof(wszDrvName[0])]=0;
                    if (strBklName == wszDrvName)
                    {
                        WCHAR       szPath[MAX_PATH];
                        dwSize = sizeof(szPath);
                        lrTmp=RegQueryValueEx(hKey,L"Key",NULL,
                            &dwType,(BYTE *)szPath,&dwSize);
                        if (ERROR_SUCCESS== lrTmp && dwType == REG_SZ)
                        {
                            szPath[dwSize/sizeof(szPath[0])] = 0;
                            m_strBklDrvRegPath = szPath;
                            goto Exit;
                        }


                    }
                }
                RegCloseKey(hKey);
            }
        }

    } while (ERROR_SUCCESS == lrEnum);

Exit:
    //�ر�Ϊö��ע�����򿪵�Key
    RegCloseKey(hEnumKey);
    hEnumKey = NULL;
}

BOOL CBKLAdjDlg::OnInitDialog()
{
    int         i;
    CDialog::OnInitDialog();

    GetBackLightDrvRegPath();
    if (m_strBklDrvRegPath.IsEmpty())
    {
        MessageBox(L"��ȡ��������ע���·��ʧ��");
        PostMessage(WM_CLOSE);
        return FALSE;
    }
    

    m_hBackLight = CreateFile(_T("BKL1:"),
        GENERIC_READ | GENERIC_WRITE, 
        FILE_SHARE_WRITE, NULL,
        OPEN_EXISTING, 0, 0);
    if (INVALID_HANDLE_VALUE == m_hBackLight)
    {
        MessageBox(L"�򿪱�������ʧ��");
        PostMessage(WM_CLOSE);
        return FALSE;
    }

    //�趨�����б�ؼ�������
    for (i=0;i<MAX_BATT_TABLE;i++)
    {
        m_ctlComboBatteryTime.InsertString(i,wcszBattTimeName[i]);
    }
    for(i=0;i<MAX_AC_TABLE;i++)
    {
        m_ctlComboACTime.InsertString(i,wcszACTimeName[i]);
    }


    //��ȡ���������Ϣ
    BacklightGetRegSettings(&m_bklCtlInfo);

    //�趨����ʹ�õ�ص�Դʱ �����Զ��رյĿؼ�
    m_ctlCheckBatteryAutoOff.SetCheck(m_bklCtlInfo.fBatteryTapOn);
    //������ע���������ӽ��ĳ�ʱʱ��
    for (i=0;i<MAX_BATT_TABLE;i++)
    {
        if (dwBattTimeTable[i] < m_bklCtlInfo.dwBattTimeout)
        {
            continue;
        }
        break;
    }
    if (i==MAX_BATT_TABLE)
    {
        i= MAX_BATT_TABLE -1;
    }
    m_ctlComboBatteryTime.SetCurSel(i);
    m_ctlComboBatteryTime.EnableWindow(m_bklCtlInfo.fBatteryTapOn);

    //�趨����ʹ���ⲿ��Դʱ �����Զ��رյĿؼ�
    m_ctlCheckACAutoOff.SetCheck(m_bklCtlInfo.fExternalTapOn);
    //������ע���������ӽ��ĳ�ʱʱ��
    for (i=0;i<MAX_AC_TABLE;i++)
    {
        if (dwAcTimeTable[i] < m_bklCtlInfo.dwACTimeout)
        {
            continue;
        }
        break;
    }
    if (i==MAX_AC_TABLE)
    {
        i= MAX_AC_TABLE -1;
    }
    m_ctlComboACTime.SetCurSel(i);
    m_ctlComboACTime.EnableWindow(m_bklCtlInfo.fExternalTapOn);
  
    //��ʾ��ǰ����
    CString     str;
    if (m_bklCtlInfo.dwBrightnessPercent[0]>100)
    {
        m_bklCtlInfo.dwBrightnessPercent[0] = 100;
    }
    str.Format(L"%d%%",m_bklCtlInfo.dwBrightnessPercent[0]);
    m_ctlStaticBrightness.SetWindowText(str);

    //�趨�������ؼ�
    m_ctlSliderBrightness.SetRange(MIN_BRIGHTNESS_PERCENT,100,TRUE);
    i = m_bklCtlInfo.dwBrightnessPercent[0];
    if (i<MIN_BRIGHTNESS_PERCENT)
    {
        i= MIN_BRIGHTNESS_PERCENT;
    }
    m_ctlSliderBrightness.SetPos(i);
    m_ctlSliderBrightness.SetLineSize(1);
    m_ctlSliderBrightness.SetPageSize(7);
    m_dwBrightnessRuntime= m_bklCtlInfo.dwBrightnessPercent[0];


    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    // TODO: Add extra initialization here
    return TRUE;  // return TRUE  unless you set the focus to a control
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CBKLAdjDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_BKLADJ_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_BKLADJ_DIALOG));
	}
}
#endif


typedef struct
{
	BOOL                    fBatteryTapOn;          // reg setting - do we turn on when screen/button tapped?
	BOOL                    fExternalTapOn;         // reg setting - do we turn on when screen/button tapped? 
	DWORD                   dwBattTimeout;          // reg setting - we only want this to deal with special cases 
	DWORD                   dwACTimeout;
	DWORD                   dwBrightnessPercent[5]; //�������� �ٷ�֮���ֱ��Ӧ5����Դ�����������
} BKL_CTL_INFO;

void CBKLAdjDlg::BacklightGetRegSettings(BKL_CTL_INFO *pBKLinfo)
{
    DWORD   retCode;
    BYTE    ValueData[4];
    DWORD    dwType;
    void    *bData = ValueData;
    DWORD   cbData;
    HKEY    hKey;

    //���Ƚ�������ƽṹ�趨ΪĬ��ֵ
    pBKLinfo->dwBrightnessPercent[0] = 100;
    pBKLinfo->dwBrightnessPercent[1] = 100;
    pBKLinfo->dwBrightnessPercent[2] = 100;
    pBKLinfo->dwBrightnessPercent[3] = 100;
    pBKLinfo->dwBrightnessPercent[4] = 100;
    pBKLinfo->dwACTimeout = 15;
    pBKLinfo ->dwBattTimeout = 15;
    pBKLinfo->fBatteryTapOn = 1;
    pBKLinfo->fExternalTapOn = 1;

    retCode = RegOpenKeyEx (HKEY_CURRENT_USER, RK_CONTROLPANEL_BACKLIGHT, 0, KEY_ALL_ACCESS, &hKey);
    if (retCode == ERROR_SUCCESS)
    {
        //Battery Tap
        dwType=REG_DWORD;
        cbData = sizeof(DWORD);
        retCode = RegQueryValueEx(hKey, RV_BATBKL_ONTAP, NULL, &dwType, (LPBYTE) bData, (LPDWORD)&cbData);
        if (retCode == ERROR_SUCCESS)
        {
            pBKLinfo->fBatteryTapOn = (*(DWORD *)bData );
        }
        //External Tap
        dwType=REG_DWORD;
        cbData = sizeof(DWORD);
        retCode = RegQueryValueEx(hKey, RV_ACBKL_ONTAP, NULL, &dwType, (LPBYTE) bData, (LPDWORD)&cbData);
        if (retCode == ERROR_SUCCESS)
        {
            pBKLinfo->fExternalTapOn = (*(DWORD *)bData );
        }
        //Backlight on battery timeout (we may need to turn the backlight off)
        dwType=REG_DWORD;
        cbData = sizeof(DWORD);
        retCode = RegQueryValueEx(hKey, RV_BATTERYTIMEOUT, NULL, &dwType, (LPBYTE) bData, (LPDWORD)&cbData);
       
        if (retCode == ERROR_SUCCESS)
        {
            pBKLinfo->dwBattTimeout = (*(DWORD *)bData );
        }

        //Backlight on AC timeout
        dwType=REG_DWORD;
        cbData = sizeof(DWORD); 
        retCode = RegQueryValueEx(hKey, RV_ACTIMEOUT, NULL, &dwType, (LPBYTE) bData, (LPDWORD)&cbData);

        if (retCode == ERROR_SUCCESS)
        {
            pBKLinfo->dwACTimeout = (*(DWORD *)bData );
        }
        RegCloseKey(hKey);
        hKey = NULL;
    }

    //�򿪱���������ע�����ȡ���������
    retCode = RegOpenKeyEx(HKEY_LOCAL_MACHINE,m_strBklDrvRegPath,
        0,NULL,&hKey);
    if (ERROR_SUCCESS == retCode)
    {
        //��������
        dwType=REG_DWORD;
        WCHAR   szBrightness[64];
        cbData = sizeof(szBrightness); 
        retCode = RegQueryValueEx(hKey, RV_BACKLIGHT_BRIGHTNESS, NULL, &dwType, (LPBYTE) szBrightness, (LPDWORD)&cbData);

        if (retCode == ERROR_SUCCESS)
        {
            DWORD   dwLength = cbData/sizeof(szBrightness[0]);
            szBrightness[dwLength]=0;

            int     i=0,ir;
            UINT    uiData =0;
            WCHAR   *p =szBrightness;

            while(i<5)
            {
                ir = swscanf(p,L"%x",&uiData,&uiData);
                if (ir == 1)
                {
                    pBKLinfo->dwBrightnessPercent[i] =uiData;
                }

                //��ȡ��һ��λ��
                while(*p !=L'\0')
                {
                    p++;
                }
                p++;

                i++;
            }
        }

        RegCloseKey(hKey);
        hKey = NULL;
    }
}

void CBKLAdjDlg::OnBnClickedCheckBatter()
{
    if(m_bklCtlInfo.fBatteryTapOn)
    {
        m_bklCtlInfo.fBatteryTapOn = 0;
    }
    else
    {
        m_bklCtlInfo.fBatteryTapOn = 1;
    }
    m_ctlComboBatteryTime.EnableWindow(m_bklCtlInfo.fBatteryTapOn);
}

void CBKLAdjDlg::OnBnClickedCheckAc()
{
    if(m_bklCtlInfo.fExternalTapOn)
    {
        m_bklCtlInfo.fExternalTapOn = 0;
    }
    else
    {
        m_bklCtlInfo.fExternalTapOn = 1;
    }
    m_ctlComboACTime.EnableWindow(m_bklCtlInfo.fExternalTapOn);
}

#define     IOCTL_SET_LCD_BRIGHTNESS  2049
void CBKLAdjDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    
    DWORD pos = m_ctlSliderBrightness.GetPos();

    ::DeviceIoControl(m_hBackLight,IOCTL_SET_LCD_BRIGHTNESS,
        &pos,sizeof(pos),NULL,0,NULL,NULL);
    CString     str;
    str.Format(L"%d%%",pos);
    m_ctlStaticBrightness.SetWindowText(str);
    m_dwBrightnessRuntime = pos;
    CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBKLAdjDlg::OnCbnSelchangeComboBattTime()
{
    int     iSel;

    iSel = m_ctlComboBatteryTime.GetCurSel();
    m_bklCtlInfo.dwBattTimeout = dwBattTimeTable[iSel];
}

void CBKLAdjDlg::OnCbnSelchangeComboAcTime()
{
    int     iSel;

    iSel = m_ctlComboACTime.GetCurSel();
    m_bklCtlInfo.dwACTimeout = dwAcTimeTable[iSel];
}

void CBKLAdjDlg::OnCancel()
{
    DWORD pos = m_bklCtlInfo.dwBrightnessPercent[0];
    ::DeviceIoControl(m_hBackLight,IOCTL_SET_LCD_BRIGHTNESS,
        &pos,sizeof(pos),NULL,0,NULL,NULL);

    CDialog::OnCancel();
}

void CBKLAdjDlg::OnOK()
{
    m_bklCtlInfo.dwBrightnessPercent[0] = m_dwBrightnessRuntime;
    BacklightSetRegSettings(&m_bklCtlInfo);

    CDialog::OnOK();
}

void CBKLAdjDlg::BacklightSetRegSettings(BKL_CTL_INFO *pBKLinfo)
{
    DWORD   retCode;
    BYTE    ValueData[4];
    DWORD    dwType;
    void    *bData = ValueData;
    DWORD   cbData;
    HKEY    hKey;

    retCode = RegOpenKeyEx (HKEY_CURRENT_USER, RK_CONTROLPANEL_BACKLIGHT, 0, KEY_ALL_ACCESS, &hKey);
    if (retCode == ERROR_SUCCESS)
    {
        //Battery Tap
        dwType=REG_DWORD;
        cbData = sizeof(DWORD);
        (*(DWORD *)bData ) = pBKLinfo->fBatteryTapOn;
        retCode = RegSetValueEx(hKey, RV_BATBKL_ONTAP, NULL, dwType, (LPBYTE) bData, cbData);

        //External Tap
        dwType=REG_DWORD;
        cbData = sizeof(DWORD);
        (*(DWORD *)bData ) = pBKLinfo->fExternalTapOn;
        retCode = RegSetValueEx(hKey, RV_ACBKL_ONTAP, NULL, dwType, (LPBYTE) bData, cbData);

        //Backlight on battery timeout (we may need to turn the backlight off)
        dwType=REG_DWORD;
        cbData = sizeof(DWORD);
        (*(DWORD *)bData ) = pBKLinfo->dwBattTimeout;

        retCode = RegSetValueEx(hKey, RV_BATTERYTIMEOUT, 
            NULL, dwType, (LPBYTE) bData, cbData);    

        //Backlight on AC timeout
        dwType=REG_DWORD;
        cbData = sizeof(DWORD); 
        (*(DWORD *)bData ) = pBKLinfo->dwACTimeout;
        retCode = RegSetValueEx(hKey, RV_ACTIMEOUT, 
            NULL, dwType, (LPBYTE) bData, cbData);
        RegCloseKey(hKey);
        hKey = NULL;
    }

    //���ñ�������
    retCode = RegOpenKeyEx(HKEY_LOCAL_MACHINE,m_strBklDrvRegPath,
        0,NULL,&hKey);
    if (ERROR_SUCCESS == retCode)
    {
        //��������
        dwType=REG_DWORD;
        WCHAR   szBrightness[64];
        cbData = sizeof(szBrightness); 
        int     i=0,ir;
        UINT    uiData =0;
        WCHAR   *p =szBrightness;
        int     iSize =0;

        while(i<5)
        {
            uiData = pBKLinfo->dwBrightnessPercent[i];
            ir = swprintf(p,L"%x",uiData);
            ir++;
            p+=ir;
            iSize+=ir;
            i++;
        }
        p[0]=0;
        iSize++;



        dwType = REG_MULTI_SZ;
        cbData = iSize*sizeof(szBrightness[0]);
        retCode = RegSetValueEx(hKey, RV_BACKLIGHT_BRIGHTNESS,
            NULL, dwType, (LPBYTE) szBrightness, cbData);

        if (retCode == ERROR_SUCCESS)
        {
            DWORD   dwLength = cbData/sizeof(szBrightness[0]);
            szBrightness[dwLength]=0;

            int     i=0,ir;
            UINT    uiData =0;
            WCHAR   *p =szBrightness;

            while(i<5)
            {
                ir = swscanf(p,L"%x",&uiData,&uiData);
                if (ir == 1)
                {
                    pBKLinfo->dwBrightnessPercent[i] =uiData;
                }

                //��ȡ��һ��λ��
                while(*p !=L'\0')
                {
                    p++;
                }
                p++;

                i++;
            }
        }

        RegCloseKey(hKey);
        hKey = NULL;
    }


}
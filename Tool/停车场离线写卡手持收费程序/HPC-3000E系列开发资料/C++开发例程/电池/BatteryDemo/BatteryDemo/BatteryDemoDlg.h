// BatteryDemoDlg.h : ͷ�ļ�
//

#pragma once

// CBatteryDemoDlg �Ի���
class CBatteryDemoDlg : public CDialog
{
// ����
public:
	CBatteryDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BATTERYDEMO_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
    CString m_szVoltage;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    CString m_szACStatus;
    CString m_szBattStatus;
    CString m_szBattCharging;
    CString m_szPercent;
};

// ZigbeeComDlg.h : ͷ�ļ�
//

#pragma once
#include <vector>
using namespace std;

#define TimeoutTimer 1
#define TimeoutLimit 2000

#define AutoSearch 2
#define AutoSearchWait 500
// CZigbeeComDlg �Ի���
class CZigbeeComDlg : public CDialog
{
// ����
public:
	CZigbeeComDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ZIGBEECOM_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;


	int         m_com;
	int         m_baudRate;
	int         m_nAddr;
	int			m_Panid;
	vector<int> m_channels;
	vector<int> m_speeds;
	CString		m_ExePath;
	HANDLE		m_hReadThread;
	HANDLE		m_hReadEvent;
	HANDLE		m_hExitEvent;
	vector<WORD> m_Addrs;
	//HANDLE		m_hTimeoutEvent;

	static DWORD WINAPI ReadThreadProc( LPVOID lpram );
	void Show(CString &str);
	void AppendInfo(CString &str);

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBnsearch();
	afx_msg void OnCbnSelchangeDevices();
	afx_msg void OnBnClickedBnclear();
	afx_msg void OnBnClickedBnsend();
};

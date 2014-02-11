// Se955ScanDemoDlg.h : ͷ�ļ�
//

#pragma once


#include "Se955DLL.h"
#include "afxwin.h"

#define MAXSIZE    512
// CSe955ScanDemoDlg �Ի���
class CSe955ScanDemoDlg : public CDialog
{
// ����
public:
	CSe955ScanDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SE955SCANDEMO_DIALOG };


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
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedTerminate();
	afx_msg void OnBnClickedStartscan();
	afx_msg void OnBnClickedClosescan();
	afx_msg void OnBnClickedSofttrig();
	afx_msg void OnBnClickedContinuetrig();
	afx_msg void OnDestroy();
	CComboBox m_comboBaud;
	CString m_strdisp;
	CComboBox m_comboCom;
	afx_msg void OnBnClickedClr();
	afx_msg void OnBnClickedVersion();
	HANDLE  m_Thread;                                                   /*  �����߳̾��                */
    HANDLE  m_hExitThreadEvent;				                            /*  ���ڽ����߳��˳��¼�        */	
private:
	static DWORD ThreadProc(PVOID pArg);
};

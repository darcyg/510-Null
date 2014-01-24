#pragma once
#include "afxwin.h"


// CTransport �Ի���

class CTransport : public CDialog
{
	DECLARE_DYNAMIC(CTransport)

public:
	CTransport(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTransport();

	HANDLE m_hRecvThread;
	HANDLE m_hExitEvent;
	static DWORD RecvThreadProc(PVOID pArg);

// �Ի�������
	enum { IDD = IDD_DLG_TRANSPORT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnInclear();
	afx_msg void OnBnClickedBnOutclear();
	afx_msg void OnBnClickedBnSend();
	CButton m_ckInHex;
	CButton m_ckOutHex;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedCkInhex();
	afx_msg void OnBnClickedCkOuthex();
protected:
	virtual void OnOK();
	virtual void OnCancel();
};

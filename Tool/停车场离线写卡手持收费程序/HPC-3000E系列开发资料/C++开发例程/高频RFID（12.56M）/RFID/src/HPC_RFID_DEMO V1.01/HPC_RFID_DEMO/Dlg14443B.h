#pragma once
#include "afxwin.h"
#include "resource.h"

// CDlg14443B �Ի���

class CDlg14443B : public CDialog
{
	DECLARE_DYNAMIC(CDlg14443B)

public:
	CDlg14443B(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg14443B();

// �Ի�������
	enum { IDD = IDD_DLG_14443B };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void InitDialog(void);
	afx_msg void OnBnClickedBtnReadSn();
	afx_msg void OnBnClickedBtnReadSn2();
	CString m_sDisplay;
	afx_msg void OnBnClickedBtnClean();
};

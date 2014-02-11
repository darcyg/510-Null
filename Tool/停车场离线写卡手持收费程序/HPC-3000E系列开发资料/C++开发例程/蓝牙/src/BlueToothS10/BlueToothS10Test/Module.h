#pragma once
#include "afxwin.h"


// CModule �Ի���

class CModule : public CDialog
{
	DECLARE_DYNAMIC(CModule)

public:
	CModule(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModule();

// �Ի�������
	enum { IDD = IDD_DLG_MODULE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnInit();
	afx_msg void OnBnClickedBnClose();
	afx_msg void OnBnClickedBnOpermode();
	afx_msg void OnBnClickedBnVersion();
	afx_msg void OnBnClickedBnOrgl();
	afx_msg void OnBnClickedBnReboot();
	CComboBox m_Coms;
	CComboBox m_Modes;
protected:
	virtual void OnOK();
	virtual void OnCancel();
};

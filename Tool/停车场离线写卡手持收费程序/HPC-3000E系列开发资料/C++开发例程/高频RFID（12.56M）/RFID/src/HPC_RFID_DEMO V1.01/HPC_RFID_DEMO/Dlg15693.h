#pragma once
#include "afxwin.h"
#include "resource.h"

// CDlg15693 �Ի���

class CDlg15693 : public CDialog
{
	DECLARE_DYNAMIC(CDlg15693)

public:
	CDlg15693(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg15693();

// �Ի�������
	enum { IDD = IDD_DLG_15693 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void InitDialog(void);
	afx_msg void OnBnClickedBtnReadSn();
	afx_msg void OnBnClickedBtnReadBlock();
	afx_msg void OnBnClickedBtnWriteBlock();
	CString m_sDisplay;
	int m_Block;
	CString m_sData;
	afx_msg void OnBnClickedBtnClean();
};

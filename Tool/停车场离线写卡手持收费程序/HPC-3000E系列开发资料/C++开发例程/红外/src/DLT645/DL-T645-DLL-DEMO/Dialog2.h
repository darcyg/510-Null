#pragma once
#include "afxwin.h"
#include "resource.h"

// CDialog2 �Ի���

class CDialog2 : public CDialog
{
	DECLARE_DYNAMIC(CDialog2)

public:
	CDialog2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialog2();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void InitDialog();
	afx_msg void OnBnClickedReadData();
	afx_msg void OnBnClickedWriteData();
	afx_msg void OnBnClickedReadAddr();
	afx_msg void OnBnClickedWriteTime();
	//CComboBox m_ctrlDataItem;
	CString m_sDataItem;// = _T("00 00 01 00");
	CString m_sConsumer;
	CString m_sPassword;
	CString m_sData;
	CString m_sAddress;
	CString m_sTime;
	CString m_sDisplay;
	CString m_sAddressToWrite;
	afx_msg void OnBnClickedWriteAddr();
};

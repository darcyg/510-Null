#pragma once
#include "afxwin.h"
#include "resource.h"

// CDialog4 �Ի���

class CDialog4 : public CDialog
{
	DECLARE_DYNAMIC(CDialog4)

public:
	CDialog4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialog4();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void InitDialog();
	afx_msg void OnBnClickedReadData();
	afx_msg void OnBnClickedWriteData2();
	afx_msg void OnBnClickedSendTime();
	afx_msg void OnBnClickedWriteAddr2();
	afx_msg void OnBnClickedChangePw();
	afx_msg void OnBnClickedClean2();
	afx_msg void OnBnClickedChangeBrd2();
	CString m_sDataItem1;
	CString m_sDataItem2;
	CString m_sData;
	CString m_sTime;
	CString m_sAddress;
	CString m_sPassWordOld;
	CString m_sPassWordNew;
	int m_nBaundRate;
	CString m_sDisplay;
};

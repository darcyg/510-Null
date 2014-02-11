#pragma once
#include "afxwin.h"
#include "resource.h"

// CDlgSetting �Ի���

class CDlgSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgSetting)

public:
	CDlgSetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgSetting();

// �Ի�������
	enum { IDD = IDD_DLG_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOpenPort();
	CComboBox m_CtrCom;
	CString m_sDisplay;
	afx_msg void OnBnClickedBtnClosePort();
	CButton m_ctrlClosePort;
	CButton m_ctrlOpenPort;
	void InitDialog(void);
};

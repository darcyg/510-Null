#pragma once
#include "afxwin.h"
#include "resource.h"

// CDlgFeliCa �Ի���

class CDlgFeliCa : public CDialog
{
	DECLARE_DYNAMIC(CDlgFeliCa)

public:
	CDlgFeliCa(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgFeliCa();

// �Ի�������
	enum { IDD = IDD_DLG_FELICA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void InitDialog(void);
	CString m_sDisplay;
	afx_msg void OnBnClickedBtnReadFelicaSn();
	afx_msg void OnBnClickedBtnClean();
};

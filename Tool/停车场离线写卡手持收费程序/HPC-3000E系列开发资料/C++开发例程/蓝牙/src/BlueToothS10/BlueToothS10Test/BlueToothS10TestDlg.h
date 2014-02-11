// BlueToothS10TestDlg.h : ͷ�ļ�
//

#pragma once
#include "Module.h"
#include "Setting.h"
#include "Search.h"
#include "Transport.h"
#include "afxcmn.h"

#define DLG_NUM 4
// CBlueToothS10TestDlg �Ի���
class CBlueToothS10TestDlg : public CDialog
{
// ����
public:
	CBlueToothS10TestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BLUETOOTHS10TEST_DIALOG };

	CModule		m_ModuleDlg;
	CSetting	m_SettingDlg;
	CSearch		m_SearchDlg;
	CTransport	m_TransportDlg;
	CDialog *	m_pDlgs[DLG_NUM];

	void InsertTab( CDialog* pDlg, UINT nTemplate, int index, LPCTSTR lpszItem );
	void SelChangeTab();

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
	CTabCtrl m_Funcs;
	afx_msg void OnTcnSelchangeTabfunc(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
};

#pragma once
#include "afxwin.h"


// begindlg �Ի���

class begindlg : public CDialogEx
{
	DECLARE_DYNAMIC(begindlg)

public:
	begindlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~begindlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	BOOL begindlg::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static11;
	afx_msg void OnStnClickedStatic11();
	CStatic m_static13;
	CStatic m_static14;
	CStatic m_static15;
	afx_msg void OnStnClickedStatic13();
	afx_msg void OnStnClickedStatic14();
	afx_msg void OnStnClickedStatic15();
};

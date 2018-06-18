#pragma once
#include "afxwin.h"


// Choose 对话框

class Choose : public CDialogEx
{
	DECLARE_DYNAMIC(Choose)

public:
	Choose(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Choose();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HBRUSH Choose::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	BOOL Choose::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static6;
	CStatic m_static7;
	CStatic m_static8;
	afx_msg void OnStnClickedStatic6();
	afx_msg void OnStnClickedStatic7();
	afx_msg void OnStnClickedStatic8();
	CStatic m_static10;
	afx_msg void OnStnClickedStatic10();
};

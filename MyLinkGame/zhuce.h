#pragma once
#include "afxwin.h"


// zhuce 对话框

class zhuce : public CDialogEx
{
	DECLARE_DYNAMIC(zhuce)

public:
	zhuce(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~zhuce();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL zhuce::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit3;
	CEdit m_edit4;
	CStatic m_static21;
	CStatic m_static22;
	afx_msg void OnBnClickedOk();
};

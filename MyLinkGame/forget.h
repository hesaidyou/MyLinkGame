#pragma once
#include "afxwin.h"


// forget 对话框

class forget : public CDialogEx
{
	DECLARE_DYNAMIC(forget)

public:
	forget(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~forget();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL forget::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static23;
	CEdit m_edit5;
	afx_msg void OnBnClickedOk();
};

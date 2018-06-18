
// MyLinkGameDlg.h : 头文件
//

#pragma once
#include "afxwin.h"



// CMyLinkGameDlg 对话框
class CMyLinkGameDlg : public CDialogEx
{
// 构造
public:
	CMyLinkGameDlg(CWnd* pParent = NULL);	// 标准构造函数
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYLINKGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	



public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void CMyLinkGameDlg::OnStnClickedStatic1();
	void CMyLinkGameDlg::OnStnClickedStatic2();
	void CMyLinkGameDlg::OnStnClickedStatic3();
	CEdit m_edit;
	CEdit m_edit2;
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
};

#pragma once


// CLLKAddDlg 对话框

class CLLKAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLLKAddDlg)

public:
	CLLKAddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLLKAddDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LLKADDDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBaocun();
	afx_msg void OnBnClickedBubaocun();
	//将三个文本框关联到三个变量
	CString m_name;
	int m_score;
	int m_level;
	virtual BOOL OnInitDialog();
};

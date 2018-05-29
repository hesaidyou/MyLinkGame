#pragma once


// Rankdlg 对话框

class Rankdlg : public CDialog
{
	DECLARE_DYNAMIC(Rankdlg)

public:
	Rankdlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Rankdlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANKDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

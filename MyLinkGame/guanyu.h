#pragma once


// guanyu 对话框

class guanyu : public CDialogEx
{
	DECLARE_DYNAMIC(guanyu)

public:
	guanyu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~guanyu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL guanyu::OnInitDialog();
	DECLARE_MESSAGE_MAP()
};

#pragma once


// bangzhu 对话框

class bangzhu : public CDialogEx
{
	DECLARE_DYNAMIC(bangzhu)

public:
	bangzhu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~bangzhu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL bangzhu::OnInitDialog();
	DECLARE_MESSAGE_MAP()
};

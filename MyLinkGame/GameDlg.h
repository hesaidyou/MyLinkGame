#pragma once

//行、列
#define ROW 10+2
#define COLUMN 14+2

// GameDlg 对话框

class GameDlg : public CDialog
{
	DECLARE_DYNAMIC(GameDlg)

public:
	GameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~GameDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAMEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

	void CreatBlocks(int hardRate);

	bool CanRemove(int row1, int column1, int row2, int column2);

	void Remove(int row1, int column1, int row2, int column2);

	void Search(int row, int column);

	void Recreate();

	void ShowMap();

	//void ShowMap(int block[ROW][COLUMN]);


private:
	CPtrArray m_btnGroup; //Button 组

public:
	int block[ROW][COLUMN];
};

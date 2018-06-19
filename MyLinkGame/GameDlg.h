#pragma once
#ifndef  GAMEDLG_H
#define GAMEDLG_H
#include "afxcmn.h"
#include "MyProgress.h"
#include "afxwin.h"


//行、列
#define ROW 10+2
#define COLUMN 14+2
//连连看游戏区界面，按钮起始位置

//开始布置块的左上起点x坐标
#define XF 245
//#define XS 100
#define YF 120
//#define YS 70
//块长度
#define LBLOCK 65
//块高度
#define HBLOCK 60

#define PLAY_TIMER_ID 1


struct Point {
	int x;
	int y;
};

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
	

	void PlayMP3();

	void CreatBlocks(int hardRate);

	bool CanRemove(int row1, int column1, int row2, int column2);

	void Remove(int row1, int column1, int row2, int column2);

	void Search(int row, int column);

	void Recreate();

	void ShowMap();
	//画线
	void DrawLine();

	void DeleteLine();

	//void ShowMap(int block[ROW][COLUMN]);

//	static UINT TimeThread(LPVOID pParam);		//时间线程/时间条

	int m_score; //记录分数
	int m_time;
	int modal;
private:
	CPtrArray m_btnGroup; //Button 组
	BOOL m_bPlaying;
	BOOL m_pPause;
	MyProgress m_ctrlProgress;
	UINT_PTR timer;


public:
	int block[ROW][COLUMN];
	int countline;

	Point linkline[4];
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
//	afx_msg void OnBnClickedButtonrecreat();
//	afx_msg void OnBnClickedButtonhint();
	CStatic m_static4;
	CStatic m_static5;
	afx_msg void OnStnClickedStatic4();
	afx_msg void OnStnClickedStatic5();
	void ModalTwo();
	void SetModal(int modal);
	afx_msg void OnTimer(UINT_PTR nIDEvent);


//	afx_msg void OnBnClickedButtonpause();
	void OnPaintTime();



	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	CStatic m_static6;
	afx_msg void OnStnClickedStatic6();
	CStatic m_static12;
	afx_msg void OnStnClickedStatic12();
	BOOL IsWin();
	afx_msg void OnBnClickedButtontesting();
};



#endif // ! GAMEDLG_H
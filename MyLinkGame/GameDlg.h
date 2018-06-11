#pragma once
#include "afxcmn.h"

//�С���
#define ROW 10+2
#define COLUMN 14+2

// GameDlg �Ի���

class GameDlg : public CDialog
{
	DECLARE_DYNAMIC(GameDlg)

public:
	GameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~GameDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAMEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

	void CreatBlocks(int hardRate);

	bool CanRemove(int row1, int column1, int row2, int column2);

	void Remove(int row1, int column1, int row2, int column2);

	void Search(int row, int column);

	void Recreate();

	void ShowMap();

	BOOL IsWin(void);

	//void ShowMap(int block[ROW][COLUMN]);

//	static UINT TimeThread(LPVOID pParam);		//ʱ���߳�/ʱ����



private:
	CPtrArray m_btnGroup; //Button ��

public:
	int block[ROW][COLUMN];
	 CProgressCtrl m_ctrlProgress;
	UINT_PTR timer;
	UINT_PTR timer2;

	int m_time; //ʣ��ʱ��
	int m_score; //��¼����
	BOOL isThreadPause;
	CWinThread*  PlayerThread;

//	int progress;

	afx_msg
		void OnBnbegin();
	void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);






	afx_msg void OnBnClickedButton2();
};

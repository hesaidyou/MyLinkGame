#pragma once
#ifndef  GAMEDLG_H
#define GAMEDLG_H



//�С���
#define ROW 10+2
#define COLUMN 14+2
//��������Ϸ�����棬��ť��ʼλ��
#define XF 70
#define XS 70
#define YF 30
#define YS 70
#define LBLOCK 65
#define HBLOCK 60


struct Point {
	int x;
	int y;
};

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
	//����
	void DrawLine();

	//void ShowMap(int block[ROW][COLUMN]);


private:
	CPtrArray m_btnGroup; //Button ��

public:
	int block[ROW][COLUMN];

	Point linkline[4];
};



#endif // ! GAMEDLG_H
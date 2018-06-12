#pragma once
#ifndef BLOCKBUTTON_H
#define BLOCKBUTTON_H

#include "atltypes.h"
#include "block.h"

// CBlockButton

class CBlockButton : public CButton
{
	DECLARE_DYNAMIC(CBlockButton)

public:
	CBlockButton();
	virtual ~CBlockButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_ID; //按钮的类型，即按钮上图片的类型
	CPoint m_location; //按钮对应在map中的位置
	//Block m_block;
public:
	//重排
	//void Recreate();
	//提示
	//void Search(int row, int column);
	//判断是否可以消除
	//bool CanRemove(int row1, int column1, int row2, int column2);

	CBlockButton(int type, CPoint point);
	static CBlockButton* ms_firstBtn; //记录最终选择要消除的两个按钮
	static CBlockButton* ms_secondBtn;
	static CPoint ms_ptCross1;  //两个拐点的位置
	static CPoint ms_ptCross2;
	static GameDlg* parent;  //父窗口（游戏窗口）的指针
	//afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	void OnLButtonDown(UINT nFlags, CPoint point);

};



#endif
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
	int m_ID; //��ť�����ͣ�����ť��ͼƬ������
	CPoint m_location; //��ť��Ӧ��map�е�λ��
	//Block m_block;
public:
	//����
	//void Recreate();
	//��ʾ
	//void Search(int row, int column);
	//�ж��Ƿ��������
	//bool CanRemove(int row1, int column1, int row2, int column2);

	CBlockButton(int type, CPoint point);
	static CBlockButton* ms_firstBtn; //��¼����ѡ��Ҫ������������ť
	static CBlockButton* ms_secondBtn;
	static CPoint ms_ptCross1;  //�����յ��λ��
	static CPoint ms_ptCross2;
	static GameDlg* parent;  //�����ڣ���Ϸ���ڣ���ָ��
	//afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	void OnLButtonDown(UINT nFlags, CPoint point);

};



#endif
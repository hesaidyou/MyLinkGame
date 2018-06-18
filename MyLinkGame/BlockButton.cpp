// LLKanButton.cpp : implementation file
//
#include "stdafx.h"
#include <windows.h>
#include <mmsystem.h>
#include <windows.h>
#include <time.h>
#include <algorithm>
#pragma comment(lib, "WINMM.LIB")
#include "MyLinkGame.h"
#include "GameDlg.h"
#include "BlockButton.h"


//初始化全局变量
CBlockButton* CBlockButton::ms_firstBtn = NULL;
CBlockButton* CBlockButton::ms_secondBtn = NULL;
CPoint CBlockButton::ms_ptCross1(-1, -1);
CPoint CBlockButton::ms_ptCross2(-1, -1);
GameDlg* CBlockButton::parent = NULL;


IMPLEMENT_DYNAMIC(CBlockButton, CButton)

CBlockButton::CBlockButton()
	: m_ID(0)
	, m_location(0)
{

}

CBlockButton::~CBlockButton()
{
}


BEGIN_MESSAGE_MAP(CBlockButton, CButton)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



CBlockButton::CBlockButton(int type, CPoint point)
{
	m_location = point;
	m_ID = type;
}


//按钮按下的响应函数
void CBlockButton::OnLButtonDown(UINT nFlags, CPoint point){
	// TODO: Add your message handler code here and/or call default
	CString str;

	parent = (GameDlg *)GetParent();
	//初始化连接拐点
	ms_ptCross1.x = ms_ptCross1.y = -1;
	ms_ptCross2.x = ms_ptCross2.y = -1;

	//选中一个按钮时改变图片的样子
	if (CBlockButton::ms_firstBtn == NULL)
	{
		//ms_firstBtn记录了最终选中的第一个按钮
		//ms_secondBtn记录了最终选中的第二个按钮
		CBlockButton::ms_firstBtn = this;
		//将图片换成一张底色为红色的同类型的图片
		str.Format(_T("res\\%d.bmp"), (this->m_ID)+10);
		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		this->SetBitmap(m_fkBmp);
		this->ShowWindow(SW_SHOW);
		//点击按钮时的声音
		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	//换到另外一种类型的按钮
	else if (CBlockButton::ms_firstBtn->m_ID != this->m_ID)
	{
		str.Format(_T("res\\%d.bmp"), CBlockButton::ms_firstBtn->m_ID + 20);
		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		CBlockButton::ms_firstBtn->SetBitmap(m_fkBmp);
		CBlockButton::ms_firstBtn->ShowWindow(SW_SHOW);

		str.Format(_T("res\\%d.bmp"), (this->m_ID) + 10);
		m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		this->SetBitmap(m_fkBmp);
		this->ShowWindow(SW_SHOW);

		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);

		CBlockButton::ms_firstBtn = this;
	}
	//取消选中的按钮
	else if (CBlockButton::ms_firstBtn == this)
	{
		str.Format(_T("res\\%d.bmp"), CBlockButton::ms_firstBtn->m_ID + 20);
		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		CBlockButton::ms_firstBtn->SetBitmap(m_fkBmp);
		CBlockButton::ms_firstBtn->ShowWindow(SW_SHOW);
		CBlockButton::ms_firstBtn = NULL;
		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	//两个按钮可连接
	else if (parent->CanRemove(ms_firstBtn->m_location.x, ms_firstBtn->m_location.y, this->m_location.x, this->m_location.y)  )
	{
		parent->Remove(ms_firstBtn->m_location.x, ms_firstBtn->m_location.y, this->m_location.x, this->m_location.y);
		//记录最终选中的第二个按钮
		ms_secondBtn = this;
		//隐藏按钮
		ms_firstBtn->ShowWindow(SW_HIDE);
		ms_secondBtn->ShowWindow(SW_HIDE);
		//更新窗口，来调用对话框的onpain（）画路径
		parent->UpdateWindow();
		//消除一对图片后，剩余时间和分数都增加
		//parent->m_time += 5;
		//parent->m_score += 10;
		//改变按钮类型和map的值为0
		ms_firstBtn->m_ID = 0;
		ms_secondBtn->m_ID = 0;
		//parent->map[ms_firstBtn->m_location.x][ms_firstBtn->m_location.y] = 0;
		//parent->map[ms_secondBtn->m_location.x][ms_secondBtn->m_location.y] = 0;
		ms_firstBtn = ms_secondBtn = NULL;

		//画线
		parent->DrawLine();
		parent->UpdateWindow();
		PlaySound(_T("H:\\C++code\\LLKan\\res\\elec.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(200);
		parent->RedrawWindow();
		//关闭对话框parent->ShowWindow(FALSE);
		//parent->DeleteLine();
	}
	//两个同类型的按钮不可连接
	else
	{
		str.Format(_T("res\\%d.bmp"), CBlockButton::ms_firstBtn->m_ID + 20);
		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		CBlockButton::ms_firstBtn->SetBitmap(m_fkBmp);
		CBlockButton::ms_firstBtn->ShowWindow(SW_SHOW);

		str.Format(_T("res\\%d.bmp"), (this->m_ID) + 10);
		m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		this->SetBitmap(m_fkBmp);
		this->ShowWindow(SW_SHOW);

		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
		CBlockButton::ms_firstBtn = this;
	}
	CButton::OnLButtonDown(nFlags, point);
}

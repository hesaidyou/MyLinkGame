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


//��ʼ��ȫ�ֱ���
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


//��ť���µ���Ӧ����
void CBlockButton::OnLButtonDown(UINT nFlags, CPoint point){
	// TODO: Add your message handler code here and/or call default
	CString str;

	parent = (GameDlg *)GetParent();
	//��ʼ�����ӹյ�
	ms_ptCross1.x = ms_ptCross1.y = -1;
	ms_ptCross2.x = ms_ptCross2.y = -1;

	//ѡ��һ����ťʱ�ı�ͼƬ������
	if (CBlockButton::ms_firstBtn == NULL)
	{
		//ms_firstBtn��¼������ѡ�еĵ�һ����ť
		//ms_secondBtn��¼������ѡ�еĵڶ�����ť
		CBlockButton::ms_firstBtn = this;
		//��ͼƬ����һ�ŵ�ɫΪ��ɫ��ͬ���͵�ͼƬ
		str.Format(_T("res\\%d.bmp"), (this->m_ID)+10);
		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		this->SetBitmap(m_fkBmp);
		this->ShowWindow(SW_SHOW);
		//�����ťʱ������
		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	//��������һ�����͵İ�ť
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
	//ȡ��ѡ�еİ�ť
	else if (CBlockButton::ms_firstBtn == this)
	{
		str.Format(_T("res\\%d.bmp"), CBlockButton::ms_firstBtn->m_ID + 20);
		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		CBlockButton::ms_firstBtn->SetBitmap(m_fkBmp);
		CBlockButton::ms_firstBtn->ShowWindow(SW_SHOW);
		CBlockButton::ms_firstBtn = NULL;
		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	//������ť������
	else if (parent->CanRemove(ms_firstBtn->m_location.x, ms_firstBtn->m_location.y, this->m_location.x, this->m_location.y)  )
	{
		parent->Remove(ms_firstBtn->m_location.x, ms_firstBtn->m_location.y, this->m_location.x, this->m_location.y);
		//��¼����ѡ�еĵڶ�����ť
		ms_secondBtn = this;
		//���ذ�ť
		ms_firstBtn->ShowWindow(SW_HIDE);
		ms_secondBtn->ShowWindow(SW_HIDE);
		//���´��ڣ������öԻ����onpain������·��
		parent->UpdateWindow();
		//����һ��ͼƬ��ʣ��ʱ��ͷ���������
		//parent->m_time += 5;
		//parent->m_score += 10;
		//�ı䰴ť���ͺ�map��ֵΪ0
		ms_firstBtn->m_ID = 0;
		ms_secondBtn->m_ID = 0;
		//parent->map[ms_firstBtn->m_location.x][ms_firstBtn->m_location.y] = 0;
		//parent->map[ms_secondBtn->m_location.x][ms_secondBtn->m_location.y] = 0;
		ms_firstBtn = ms_secondBtn = NULL;

		//����
		parent->DrawLine();
		parent->UpdateWindow();
		PlaySound(_T("H:\\C++code\\LLKan\\res\\elec.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(200);
		parent->RedrawWindow();
		//�رնԻ���parent->ShowWindow(FALSE);
		//parent->DeleteLine();
	}
	//����ͬ���͵İ�ť��������
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

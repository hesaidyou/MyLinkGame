
// MyLinkGame.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyLinkGameApp: 
// �йش����ʵ�֣������ MyLinkGame.cpp
//

class CMyLinkGameApp : public CWinApp
{
public:
	CMyLinkGameApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyLinkGameApp theApp;
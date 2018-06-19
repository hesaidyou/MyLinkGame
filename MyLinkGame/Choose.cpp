// Choose.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "MyLinkGameDlg.h"
#include "Choose.h"
#include "afxdialogex.h"
#include "GameDlg.h"
#include <windows.h>
#include "begindlg.h"

// Choose 对话框

IMPLEMENT_DYNAMIC(Choose, CDialogEx)

Choose::Choose(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Choose::~Choose()
{
}

void Choose::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC6, m_static6);
	DDX_Control(pDX, IDC_STATIC7, m_static7);
	DDX_Control(pDX, IDC_STATIC8, m_static8);
	DDX_Control(pDX, IDC_STATIC10, m_static10);
}


BEGIN_MESSAGE_MAP(Choose, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC6, &Choose::OnStnClickedStatic6)
	ON_STN_CLICKED(IDC_STATIC7, &Choose::OnStnClickedStatic7)
	ON_STN_CLICKED(IDC_STATIC8, &Choose::OnStnClickedStatic8)
	ON_STN_CLICKED(IDC_STATIC10, &Choose::OnStnClickedStatic10)
END_MESSAGE_MAP()


// Choose 消息处理程序



BOOL Choose::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	///* 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作*/
	//SetIcon(m_hIcon, TRUE);			// 设置大图标
	//SetIcon(m_hIcon, FALSE);		// 设置小图标

									
	// TODO: 在此添加额外的初始化代码
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 1280, 1000, SWP_NOZORDER);
	CenterWindow();
	CDialogEx::SetBackgroundImage(IDB_BITMAP4);

	m_static6.SetWindowText(_T(""));
	m_static7.SetWindowText(_T(""));
	m_static8.SetWindowText(_T(""));
	m_static10.SetWindowText(_T(""));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}



//简单 无变化
void Choose::OnStnClickedStatic6()
{
	GameDlg gamedlg;
	gamedlg.DoModal();
	this->CloseWindow();
}

//向下
void Choose::OnStnClickedStatic7()
{
	GameDlg gamedlg;
	gamedlg.SetModal(2);
	gamedlg.DoModal();
	this->CloseWindow();
}


void Choose::OnStnClickedStatic8()
{
	GameDlg gamedlg;
	gamedlg.DoModal();
	this->CloseWindow();
}


void Choose::OnStnClickedStatic10()
{
	begindlg a;
	a.DoModal();
	this->CloseWindow();
}

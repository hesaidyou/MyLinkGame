// begindlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "begindlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include "GameDlg.h"
#include "Choose.h"
#include "bangzhu.h"
#include "guanyu.h"

// begindlg 对话框

IMPLEMENT_DYNAMIC(begindlg, CDialogEx)

begindlg::begindlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

begindlg::~begindlg()
{
}

void begindlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC11, m_static11);
	DDX_Control(pDX, IDC_STATIC13, m_static13);
	DDX_Control(pDX, IDC_STATIC14, m_static14);
	DDX_Control(pDX, IDC_STATIC15, m_static15);
}


BEGIN_MESSAGE_MAP(begindlg, CDialogEx)
	ON_STN_CLICKED(IDC_STATIC11, &begindlg::OnStnClickedStatic11)
	ON_STN_CLICKED(IDC_STATIC13, &begindlg::OnStnClickedStatic13)
	ON_STN_CLICKED(IDC_STATIC14, &begindlg::OnStnClickedStatic14)
	ON_STN_CLICKED(IDC_STATIC15, &begindlg::OnStnClickedStatic15)
END_MESSAGE_MAP()


// begindlg 消息处理程序

BOOL begindlg::OnInitDialog()
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
	CDialogEx::SetBackgroundImage(IDB_BITMAP5);

	m_static11.SetWindowText(_T(""));
	m_static13.SetWindowText(_T(""));
	m_static14.SetWindowText(_T(""));
	m_static15.SetWindowText(_T(""));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void begindlg::OnStnClickedStatic11()
{
	Choose  choose;
	choose.DoModal();
	this->CloseWindow();
}


void begindlg::OnStnClickedStatic13()
{
	bangzhu b;
	b.DoModal();
}


void begindlg::OnStnClickedStatic14()
{
	guanyu c;
	c.DoModal();
}


void begindlg::OnStnClickedStatic15()
{
	exit(0);
}

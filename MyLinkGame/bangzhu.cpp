// bangzhu.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "bangzhu.h"
#include "afxdialogex.h"


// bangzhu 对话框

IMPLEMENT_DYNAMIC(bangzhu, CDialogEx)

bangzhu::bangzhu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

bangzhu::~bangzhu()
{
}

void bangzhu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(bangzhu, CDialogEx)
END_MESSAGE_MAP()


// bangzhu 消息处理程序
BOOL bangzhu::OnInitDialog()
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
	CDialogEx::SetBackgroundImage(IDB_BITMAP6);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
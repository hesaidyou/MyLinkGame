
// MyLinkGameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "MyLinkGameDlg.h"
#include "afxdialogex.h"

#include "BlockButton.h"
#include "Block.h"

#define IDC_BLOCK 10000

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyLinkGameDlg 对话框



CMyLinkGameDlg::CMyLinkGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYLINKGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyLinkGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyLinkGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyLinkGameDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyLinkGameDlg 消息处理程序

BOOL CMyLinkGameDlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyLinkGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyLinkGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyLinkGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





//根据map构造按钮
void CMyLinkGameDlg::ShowMap(int block[ROW][COLUMN]){
	int i, j;
	CPoint p;
	CString str = _T("");
	////清除原有按钮
	//for (i = 0; i<m_btnGroup.GetSize(); i++)
	//	delete (CLLKanButton *)m_btnGroup.GetAt(i);
	//m_btnGroup.RemoveAll();
	//添加新按钮
	for (i = 1; i <= ROW - 2; i++)
		for (j = 1; j <= COLUMN - 2; j++)
		{
			p.x = i;
			p.y = j;
			//将按钮放入m_btnGroup指针数组中
			m_btnGroup.Add(new CBlockButton(block[i][j], p));
		}
	//显示按钮
	for (i = 0; i<(ROW - 2)*(COLUMN - 2); i++)
	{
		CBlockButton *btn = (CBlockButton *)m_btnGroup.GetAt(i);
		//构造按钮的大小和位置
		btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE,
			CRect(70 + (i % (COLUMN - 2)) * 50, 70 + (i / (ROW - 2)) * 50,
				120 + (i % (COLUMN - 2)) * 50, 120 + (i / (ROW - 2)) * 50), this,
			IDC_BLOCK + i);

		if (btn->m_ID)//如果为0则不显示
		{
			//尽量用绝对路径
			str.Format(_T("res\\%d.bmp"), btn->m_ID);
			HBITMAP m_fkBmp = (HBITMAP)::LoadImage
			(AfxGetInstanceHandle(),
				str, IMAGE_BITMAP, 0, 0,
				LR_CREATEDIBSECTION | LR_LOADFROMFILE);
			//加载图片
			if (m_fkBmp == NULL)
				if (MessageBox(_T(" 缺 少 图 片 资 源! "), _T(" 错 误"),
					MB_ICONERROR | MB_OK) == IDOK)
				{
					CDialog::OnCancel();
					return;
				}
			btn->SetBitmap(m_fkBmp);
			btn->ShowWindow(SW_SHOW);
		}
		else
			btn->ShowWindow(SW_HIDE);

	}
}

void CMyLinkGameDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Block b;
	b.CreatBlocks(1);
	ShowMap(b.block);
}

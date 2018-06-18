
// MyLinkGameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "begindlg.h"
#include "MyLinkGameDlg.h"
#include "afxdialogex.h"
#include "Choose.h"
#include "GameDlg.h"
#include "zhuce.h"
#include "forget.h"


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
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
}

BEGIN_MESSAGE_MAP(CMyLinkGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_STATIC1, &CMyLinkGameDlg::OnStnClickedStatic1)
	ON_STN_CLICKED(IDC_STATIC2, &CMyLinkGameDlg::OnStnClickedStatic2)
	ON_STN_CLICKED(IDC_STATIC3, &CMyLinkGameDlg::OnStnClickedStatic3)
END_MESSAGE_MAP()


// CMyLinkGameDlg 消息处理程序

BOOL CMyLinkGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	this->PlayMP3();

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
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 1280, 1000, SWP_NOZORDER);
	CenterWindow();
	CDialogEx::SetBackgroundImage(IDB_BITMAP2);

	static CFont font;
	font.DeleteObject();
	font.CreatePointFont(350, _T("楷体"));
	m_edit.SetFont(&font);//设置字体
	m_edit2.SetFont(&font);

	m_static1.SetWindowText(_T(""));
	m_static2.SetWindowText(_T(""));
	m_static3.SetWindowText(_T(""));
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


#define LEN sizeof(struct linkgame)   

struct linkgame
{
	char name[30];
	char password[30];
	char question[30];
	char answer[30];
	char game1[30];
	char game2[30];
	char game3[30];
	char score[30];
	struct linkgame *next;
};

void CMyLinkGameDlg::OnStnClickedStatic1()
{
	struct linkgame *shead = NULL;
	struct linkgame *phead;
	struct linkgame *p;
	p = (struct linkgame*) malloc(LEN);

	char a[30];
	char b[30];
	char e[30];
	char f[30];
	char g[30];
	char h[30];

	FILE *inFile;

	inFile = fopen("linkgame.txt", "r");
	if (inFile == NULL)
	{
		printf("\nFailed to open the file.\n");
		exit(1);
	}

	fscanf(inFile, "%s %s %s %s %s %s\n", a, b, e, f, g, h);
	strcpy(p->name, a);
	strcpy(p->password, b);
	strcpy(p->game1, e);
	strcpy(p->game2, f);
	strcpy(p->game3, g);
	strcpy(p->score, h);
	p->next = NULL;
	shead = p;
	phead = shead;

	while (fscanf(inFile, "%s %s %s %s %s %s\n", a, b, e, f, g, h) != EOF)
	{
		p = (struct linkgame*) malloc(LEN);
		strcpy(p->name, a);
		strcpy(p->password, b);
		strcpy(p->game1, e);
		strcpy(p->game2, f);
		strcpy(p->game3, g);
		strcpy(p->score, h);

		shead->next = p;
		shead->next->next = NULL;
		shead = shead->next;
	}

	CString name1, password1;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(name1);
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(password1);
	if (name1 == "" && password1 != "")AfxMessageBox(_T("请输入账号"));
	else if (password1 == "" && name1 != "")AfxMessageBox(_T("请输入密码"));
	else if (name1 == ""&&password1 == "")AfxMessageBox(_T("请输入账号和密码"));
	else
	{
		shead = phead;
		while (shead != NULL)
		{
			if (shead->name == name1)
			{
				if (shead->password == password1)
				{
					AfxMessageBox(_T("登录成功"));
					this->CloseWindow();
					begindlg a;
					a.DoModal();
				}
				else AfxMessageBox(_T("密码错误"));
				break;
			}
			else shead = shead->next;
		}
		if (shead == NULL) AfxMessageBox(_T("该账号不存在"));
	}
}


void CMyLinkGameDlg::OnStnClickedStatic2()
{
	zhuce d;
	d.DoModal();
}


void CMyLinkGameDlg::OnStnClickedStatic3()
{
	forget f;
	f.DoModal();
}

BOOL CMyLinkGameDlg::PreTranslateMessage(MSG* pMsg) //键盘事件处理
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN://按下回车
			OnStnClickedStatic1();
			return TRUE;
			break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CMyLinkGameDlg::PlayMP3()
{
	CString strFileName;
	strFileName.Format(_T("res\\游戏中背景音乐.mp3"));
	CString strCommond;
	strCommond.Format(_T("play %s repeat"), strFileName);
	mciSendString(strCommond, NULL, 0, NULL);
}


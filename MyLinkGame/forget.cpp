// forget.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "forget.h"
#include "afxdialogex.h"


// forget 对话框

IMPLEMENT_DYNAMIC(forget, CDialogEx)

forget::forget(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

forget::~forget()
{
}

void forget::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC23, m_static23);
	DDX_Control(pDX, IDC_EDIT1, m_edit5);
}


BEGIN_MESSAGE_MAP(forget, CDialogEx)
	ON_BN_CLICKED(IDOK, &forget::OnBnClickedOk)
END_MESSAGE_MAP()


// forget 消息处理程序
BOOL forget::OnInitDialog()
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
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 500, 300, SWP_NOZORDER);
	CenterWindow();
	CDialogEx::SetBackgroundImage(IDB_BITMAP8);


	static CFont font;
	font.DeleteObject();
	font.CreatePointFont(300, _T("楷体"));
	m_edit5.SetFont(&font);
	m_static23.SetFont(&font);
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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




void forget::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

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

	fclose(inFile);

	CString name1, password1;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(name1);
	if (name1 == "" && password1 != "")
	{
		AfxMessageBox(_T("请输入账号"));
		forget f;
		f.DoModal();
	}
	else
	{
		shead = phead;
		while (shead != NULL)
		{
			if (shead->name == name1)
			{
				password1 = shead->password;
				AfxMessageBox(password1);
				this->CloseWindow();
				break;
			}
			else shead = shead->next;
		}
		if (shead == NULL)
		{
			AfxMessageBox(_T("该账号不存在"));
			forget f;
			f.DoModal();
		}
	}
}


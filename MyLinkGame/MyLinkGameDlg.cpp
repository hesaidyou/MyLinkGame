
// MyLinkGameDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMyLinkGameDlg �Ի���



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


// CMyLinkGameDlg ��Ϣ�������

BOOL CMyLinkGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	this->PlayMP3();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 1280, 1000, SWP_NOZORDER);
	CenterWindow();
	CDialogEx::SetBackgroundImage(IDB_BITMAP2);

	static CFont font;
	font.DeleteObject();
	font.CreatePointFont(350, _T("����"));
	m_edit.SetFont(&font);//��������
	m_edit2.SetFont(&font);

	m_static1.SetWindowText(_T(""));
	m_static2.SetWindowText(_T(""));
	m_static3.SetWindowText(_T(""));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyLinkGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	if (name1 == "" && password1 != "")AfxMessageBox(_T("�������˺�"));
	else if (password1 == "" && name1 != "")AfxMessageBox(_T("����������"));
	else if (name1 == ""&&password1 == "")AfxMessageBox(_T("�������˺ź�����"));
	else
	{
		shead = phead;
		while (shead != NULL)
		{
			if (shead->name == name1)
			{
				if (shead->password == password1)
				{
					AfxMessageBox(_T("��¼�ɹ�"));
					this->CloseWindow();
					begindlg a;
					a.DoModal();
				}
				else AfxMessageBox(_T("�������"));
				break;
			}
			else shead = shead->next;
		}
		if (shead == NULL) AfxMessageBox(_T("���˺Ų�����"));
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

BOOL CMyLinkGameDlg::PreTranslateMessage(MSG* pMsg) //�����¼�����
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN://���»س�
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
	strFileName.Format(_T("res\\��Ϸ�б�������.mp3"));
	CString strCommond;
	strCommond.Format(_T("play %s repeat"), strFileName);
	mciSendString(strCommond, NULL, 0, NULL);
}


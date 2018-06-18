// zhuce.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "zhuce.h"
#include "afxdialogex.h"


// zhuce �Ի���

IMPLEMENT_DYNAMIC(zhuce, CDialogEx)

zhuce::zhuce(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

zhuce::~zhuce()
{
}

void zhuce::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit3);
	DDX_Control(pDX, IDC_EDIT2, m_edit4);
	DDX_Control(pDX, IDC_STATIC21, m_static21);
	DDX_Control(pDX, IDC_STATIC22, m_static22);
}


BEGIN_MESSAGE_MAP(zhuce, CDialogEx)
	ON_BN_CLICKED(IDOK, &zhuce::OnBnClickedOk)
END_MESSAGE_MAP()


// zhuce ��Ϣ�������
BOOL zhuce::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	///* ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���*/
	//SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	//SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 500, 400, SWP_NOZORDER);
	CenterWindow();
	CDialogEx::SetBackgroundImage(IDB_BITMAP8);


	static CFont font;
	font.DeleteObject();
	font.CreatePointFont(300, _T("����"));
	m_edit3.SetFont(&font);//��������
	m_edit4.SetFont(&font);
	m_static21.SetFont(&font);
	m_static22.SetFont(&font);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

void zhuce::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	CString a1, a2, a3, a4;
	a1 = _T("0");
	a2 = _T("0");
	a3 = _T("0");
	a4 = _T("0");

	GetDlgItem(IDC_EDIT1)->GetWindowTextW(name1);
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(password1);
	if (name1 == "" && password1 != "") 
	{
		AfxMessageBox(_T("�������˺�"));
		zhuce z;
		z.DoModal();
	}
	else if (password1 == "" && name1 != "") 
	{ 
		AfxMessageBox(_T("����������")); 	
		zhuce z;
		z.DoModal();
	}
	else if (name1 == ""&&password1 == "") 
	{ 
		AfxMessageBox(_T("�������˺ź�����")); 
		zhuce z;
		z.DoModal();
	}
	else
	{
		shead = phead;
		while (shead != NULL)
		{
			if (shead->name == name1)
			{
				AfxMessageBox(_T("���˺��ѱ�ע��"));
				zhuce z;
				z.DoModal(); 
				break;
			}
			else shead = shead->next;
		}
		if (shead == NULL)
		{ 
			AfxMessageBox(_T("ע��ɹ�"));
			
			p = phead;
			FILE *outFile;
			outFile = fopen("linkgame.txt", "a+");

			if (outFile == NULL)
			{
				printf("\nFailed to open the file.\n");
				exit(1);
			}

			
			fprintf(outFile, "\t\n%s %s %s %s %s %s", name1, password1, a1 , a2 , a3 , a4);

			fclose(outFile);
			this->CloseWindow();
		}
	}
}

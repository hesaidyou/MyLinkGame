
// MyLinkGameDlg.cpp : ʵ���ļ�
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
}

BEGIN_MESSAGE_MAP(CMyLinkGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyLinkGameDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyLinkGameDlg ��Ϣ�������

BOOL CMyLinkGameDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

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





//����map���찴ť
void CMyLinkGameDlg::ShowMap(int block[ROW][COLUMN]){
	int i, j;
	CPoint p;
	CString str = _T("");
	////���ԭ�а�ť
	//for (i = 0; i<m_btnGroup.GetSize(); i++)
	//	delete (CLLKanButton *)m_btnGroup.GetAt(i);
	//m_btnGroup.RemoveAll();
	//����°�ť
	for (i = 1; i <= ROW - 2; i++)
		for (j = 1; j <= COLUMN - 2; j++)
		{
			p.x = i;
			p.y = j;
			//����ť����m_btnGroupָ��������
			m_btnGroup.Add(new CBlockButton(block[i][j], p));
		}
	//��ʾ��ť
	for (i = 0; i<(ROW - 2)*(COLUMN - 2); i++)
	{
		CBlockButton *btn = (CBlockButton *)m_btnGroup.GetAt(i);
		//���찴ť�Ĵ�С��λ��
		btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE,
			CRect(70 + (i % (COLUMN - 2)) * 50, 70 + (i / (ROW - 2)) * 50,
				120 + (i % (COLUMN - 2)) * 50, 120 + (i / (ROW - 2)) * 50), this,
			IDC_BLOCK + i);

		if (btn->m_ID)//���Ϊ0����ʾ
		{
			//�����þ���·��
			str.Format(_T("res\\%d.bmp"), btn->m_ID);
			HBITMAP m_fkBmp = (HBITMAP)::LoadImage
			(AfxGetInstanceHandle(),
				str, IMAGE_BITMAP, 0, 0,
				LR_CREATEDIBSECTION | LR_LOADFROMFILE);
			//����ͼƬ
			if (m_fkBmp == NULL)
				if (MessageBox(_T(" ȱ �� ͼ Ƭ �� Դ! "), _T(" �� ��"),
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Block b;
	b.CreatBlocks(1);
	ShowMap(b.block);
}

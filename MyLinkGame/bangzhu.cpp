// bangzhu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "bangzhu.h"
#include "afxdialogex.h"


// bangzhu �Ի���

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


// bangzhu ��Ϣ�������
BOOL bangzhu::OnInitDialog()
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
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 1280, 1000, SWP_NOZORDER);
	CenterWindow();
	CDialogEx::SetBackgroundImage(IDB_BITMAP6);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}
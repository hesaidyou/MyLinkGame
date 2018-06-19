// PaiHangBang.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "PaiHangBang.h"
#include "afxdialogex.h"


// PaiHangBang �Ի���

IMPLEMENT_DYNAMIC(PaiHangBang, CDialogEx)

PaiHangBang::PaiHangBang(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PAIHANGBANG, pParent)
{

}

PaiHangBang::~PaiHangBang()
{
}

void PaiHangBang::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
}


BEGIN_MESSAGE_MAP(PaiHangBang, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, &PaiHangBang::OnItemchangedList)
	ON_BN_CLICKED(IDCANCEL, &PaiHangBang::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CLEAN, &PaiHangBang::OnBnClickedClean)
	ON_BN_CLICKED(IDOK, &PaiHangBang::OnBnClickedOk)
END_MESSAGE_MAP()


// PaiHangBang ��Ϣ�������

BOOL PaiHangBang::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	m_list.InsertColumn(0, _T(""), LVCFMT_CENTER, 40);
	m_list.InsertColumn(1, _T("����"), LVCFMT_CENTER, 100);
	m_list.InsertColumn(2, _T("����"), LVCFMT_CENTER, 70);
	m_list.InsertColumn(3, _T("�Ѷ�"), LVCFMT_CENTER, 70);

	//���б���ϱ��
	LONG lStyle = m_list.SendMessage(LVM_GETEXTENDEDLISTVIEWSTYLE);
	lStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP;
	m_list.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)lStyle);

	ReadRecord();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void PaiHangBang::OnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

//������¼
void PaiHangBang::ReadRecord(void)
{

	CStdioFile mFile;
	CFileException mExcept;
	CString readstr;
	CString IDstr;
	int i = 0;
	if (!mFile.Open(_T("record.txt"), CFile::modeRead, &mExcept))
		mFile.Open(_T("record.txt"), CFile::modeCreate | CFile::modeRead, &mExcept);

	//���ļ�����д���б�
	while (mFile.ReadString(readstr))
	{
		IDstr.Format(_T("%d"), (i + 1));
		m_list.InsertItem(i, IDstr);
		m_list.SetItemText(i, 1, readstr);
		mFile.ReadString(readstr);
		m_list.SetItemText(i, 2, readstr);
		mFile.ReadString(readstr);
		m_list.SetItemText(i, 3, readstr);
		i++;
	}
}


void PaiHangBang::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here

	PaiHangBang::OnCancel();
}

//ɾ����¼
void PaiHangBang::OnBnClickedClean()
{
	// TODO: Add your control notification handler code here
	if (AfxMessageBox(_T("ȷ��ɾ����ʷ��¼"), MB_OKCANCEL) == IDOK)
	{
		m_list.DeleteAllItems();
		//����ļ���¼�����´���һ��ͬ���ļ���
		CFile mFile;
		CFileException mExcept;
		mFile.Open(_T("record.txt"), CFile::modeCreate, &mExcept);
	}
}


void PaiHangBang::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

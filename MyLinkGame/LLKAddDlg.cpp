// LLKAddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "LLKAddDlg.h"
#include "afxdialogex.h"
#include "GameDlg.h"

// CLLKAddDlg �Ի���

IMPLEMENT_DYNAMIC(CLLKAddDlg, CDialogEx)

CLLKAddDlg::CLLKAddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LLKADDDLG, pParent)
{
	m_name = _T("");
	m_score = 0;
	m_level = 0;
}

CLLKAddDlg::~CLLKAddDlg()
{
}

void CLLKAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_nameADDEdit, m_name);
	DDX_Text(pDX, IDC_SCOREedit, m_score);
	DDX_Text(pDX, IDC_Leveledit, m_level);
}


BEGIN_MESSAGE_MAP(CLLKAddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Baocun, &CLLKAddDlg::OnBnClickedBaocun)
	ON_BN_CLICKED(IDC_Bubaocun, &CLLKAddDlg::OnBnClickedBubaocun)
END_MESSAGE_MAP()


// CLLKAddDlg ��Ϣ�������


void CLLKAddDlg::OnBnClickedBaocun()
{
	UpdateData(TRUE);

	if (m_name != _T(""))
	{
		CStdioFile mFile;
		CFileException mExcept;
		if (!mFile.Open(_T("record.txt"), CFile::modeWrite, &mExcept))
			mFile.Open(_T("record.txt"), CFile::modeCreate | CFile::modeWrite, &mExcept);
		CString str;
		mFile.SeekToEnd();
		//����¼д���ļ��������
		str.Format(_T("%s\n"), m_name);
		mFile.WriteString(str);
		str.Format(_T("%d\n"), m_score);
		mFile.WriteString(str);
		str.Format(_T("%d\n"), m_level);
		mFile.WriteString(str);
		CDialog::OnOK();
	}
	else
		AfxMessageBox(_T("����������!"));
	//CDialogEx::OnOK();}
}

void CLLKAddDlg::OnBnClickedBubaocun()
{
	CDialogEx::OnOK();
}


BOOL CLLKAddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	//ͨ�ظ�����ָ��parent����ȡ���� �� �ؿ�����m_typeNum-1��
	GameDlg *parent = (GameDlg *)GetParent();
	m_level = parent->hard_rate;
	m_score = parent->m_score;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE}

}


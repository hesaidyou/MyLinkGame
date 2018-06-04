// Rankdlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "Rankdlg.h"
#include "afxdialogex.h"


// Rankdlg 对话框

IMPLEMENT_DYNAMIC(Rankdlg, CDialog)

Rankdlg::Rankdlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_RANKDLG, pParent)
{

}

Rankdlg::~Rankdlg()
{
}

void Rankdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Rankdlg, CDialog)
END_MESSAGE_MAP()


// Rankdlg 消息处理程序

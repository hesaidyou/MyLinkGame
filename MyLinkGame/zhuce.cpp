// zhuce.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "zhuce.h"
#include "afxdialogex.h"


// zhuce 对话框

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
}


BEGIN_MESSAGE_MAP(zhuce, CDialogEx)
END_MESSAGE_MAP()


// zhuce 消息处理程序

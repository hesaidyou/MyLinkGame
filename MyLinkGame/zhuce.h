#pragma once
#include "afxwin.h"


// zhuce �Ի���

class zhuce : public CDialogEx
{
	DECLARE_DYNAMIC(zhuce)

public:
	zhuce(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~zhuce();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit3;
	CEdit m_edit4;
};

#pragma once
#include "afxwin.h"


// forget �Ի���

class forget : public CDialogEx
{
	DECLARE_DYNAMIC(forget)

public:
	forget(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~forget();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	BOOL forget::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static23;
	CEdit m_edit5;
	afx_msg void OnBnClickedOk();
};

#pragma once


// guanyu �Ի���

class guanyu : public CDialogEx
{
	DECLARE_DYNAMIC(guanyu)

public:
	guanyu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~guanyu();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	BOOL guanyu::OnInitDialog();
	DECLARE_MESSAGE_MAP()
};

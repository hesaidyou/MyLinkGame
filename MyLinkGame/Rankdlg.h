#pragma once


// Rankdlg �Ի���

class Rankdlg : public CDialog
{
	DECLARE_DYNAMIC(Rankdlg)

public:
	Rankdlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Rankdlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANKDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

#pragma once


// CLLKAddDlg �Ի���

class CLLKAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLLKAddDlg)

public:
	CLLKAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLLKAddDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LLKADDDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBaocun();
	afx_msg void OnBnClickedBubaocun();
	//�������ı����������������
	CString m_name;
	int m_score;
	int m_level;
	virtual BOOL OnInitDialog();
};

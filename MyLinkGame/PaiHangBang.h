#pragma once


// PaiHangBang �Ի���

class PaiHangBang : public CDialogEx
{
	DECLARE_DYNAMIC(PaiHangBang)

public:
	PaiHangBang(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PaiHangBang();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAIHANGBANG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	afx_msg void OnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult);
	void ReadRecord(void);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedClean();
	afx_msg void OnBnClickedOk();
};


// MyLinkGameDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"



// CMyLinkGameDlg �Ի���
class CMyLinkGameDlg : public CDialogEx
{
// ����
public:
	CMyLinkGameDlg(CWnd* pParent = NULL);	// ��׼���캯��
	
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYLINKGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	



public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit m_edit;
	CEdit m_edit2;

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedStatic1();
	afx_msg void OnStnClickedStatic3();
	afx_msg void OnStnClickedStatic4();
	afx_msg void OnStnClickedStatic5();
	CStatic m_static3;
	CStatic m_static4;
	CStatic m_static5;
};

#pragma once


// bangzhu �Ի���

class bangzhu : public CDialogEx
{
	DECLARE_DYNAMIC(bangzhu)

public:
	bangzhu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~bangzhu();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	BOOL bangzhu::OnInitDialog();
	DECLARE_MESSAGE_MAP()
};

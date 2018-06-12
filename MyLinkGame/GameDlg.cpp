// GameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include <time.h>
#include <algorithm>

#include "BlockButton.h"

#define IDC_BLOCK 10000

// GameDlg �Ի���

int progress = 0;

IMPLEMENT_DYNAMIC(GameDlg, CDialog)


GameDlg::GameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_GAMEDLG, pParent)
{
	//::SetBackgroundImage(IDB_BITMAP1);
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 1280, 1000, SWP_NOZORDER);


}

GameDlg::~GameDlg()
{
}

void GameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
}


BEGIN_MESSAGE_MAP(GameDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &GameDlg::OnBnClickedButton1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &GameDlg::OnNMCustomdrawProgress1)
	ON_BN_CLICKED(IDC_BUTTON2, &GameDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// GameDlg ��Ϣ�������


void GameDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	timer=SetTimer(1, 1000, NULL);//���ý���������ʱ��

	isThreadPause = false;
	m_time = 30;
	m_score = 0;
	m_ctrlProgress.SetRange32(1, 3000);

	OnBnbegin();
	CreatBlocks(2);
	ShowMap();

}

//������Ϸ
void GameDlg::CreatBlocks(int hardRate) {

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			block[i][j] = { 0 };
		}
	}

	int b[(ROW - 2)*(COLUMN - 2)] = { 0 };

	//�Ѷ�1,5��ͼƬ
	if (hardRate == 1) {
		for (int i = 0; i <(ROW - 2)*(COLUMN - 2); i += 28) {
			for (int x = 0; x < 28; x++) {
				b[i + x] = i / 28 + 1;
			}
		}
	}

	//�Ѷ�2,10��ͼƬ
	if (hardRate == 2) {
		for (int i = 0; i <(ROW - 2)*(COLUMN - 2); i += 14) {
			for (int x = 0; x < 14; x++) {
				b[i + x] = i / 14 + 1;
			}
		}
	}


	//�Ѷ�3,20��ͼƬ
	if (hardRate == 3) {
		for (int i = 0; i <(ROW - 2)*(COLUMN - 2); i += 7) {
			for (int x = 0; x < 7; x++) {
				b[i + x] = i / 7 + 1;
			}
		}
	}

	srand((unsigned)time(NULL));
	std::random_shuffle(b, b + (ROW - 2)*(COLUMN - 2));
	int k = 0;
	memset(block, 0, sizeof(block));

	for (int i = 1; i < ROW - 1; i++) {
		for (int j = 1; j < COLUMN - 1; j++) {
			block[i][j] = b[k];
			k++;
		}
	}

}

//��������ʼ��������ꡢĿ���������꣨��ɣ�
bool GameDlg::CanRemove(int row1, int column1, int row2, int column2) {
	//��row1,column1��ʼ������������ʽΪ����һ����ֱ�ӿ�ʼ�����ж��Ƿ���Լ�������
	int mytype = block[row1][column1];

	//������
	//��������
	for (int i = column1 + 1; i <= COLUMN; i++) {
		//ֻ������Ŀ��㲢��������ͬ��������������ͬ���͵�����Ŀ���������
		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
			return true;
		}
		//�������ʼ�����Ͳ�ͬ
		else if (block[row1][i] != mytype) {
			//ÿһ����������������������ǿ��������ͣ�break
			if (block[row1][i] != 0) {
				break;
			}
			//��������
			for (int j = row1 + 1; j <= ROW; j++) {
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					return true;
				}
				//�������ʼ�����Ͳ�ͬ
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}
					//��������
					for (int k = i + 1; k <= COLUMN; k++) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
					//��������
					for (int k = i - 1; k >= 0; k--) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
				}
			}

			//��������
			for (int j = row1 - 1; j >= 0; j--) {
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					return true;
				}
				//�������ʼ�����Ͳ�ͬ
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}
					//��������
					for (int k = i + 1; k <= COLUMN; k++) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
					//��������
					for (int k = i - 1; k >= 0; k--) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
				}
			}

		}
	}

	//��������
	for (int i = column1 - 1; i >= 0; i--) {
		//ֻ������Ŀ��㲢��������ͬ��������������ͬ���͵�����Ŀ���������
		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
			return true;
		}
		//�������ʼ�����Ͳ�ͬ
		else if (block[row1][i] != mytype) {
			//ÿһ����������������������ǿ��������ͣ�break
			if (block[row1][i] != 0) {
				break;
			}
			//��������
			for (int j = row1 + 1; j <= ROW; j++) {
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					return true;
				}
				//�������ʼ�����Ͳ�ͬ
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}
					//��������
					for (int k = i + 1; k <= COLUMN; k++) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
					//��������
					for (int k = i - 1; k >= 0; k--) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
				}
			}

			//��������
			for (int j = row1 - 1; j >= 0; j--) {
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					return true;
				}
				//�������ʼ�����Ͳ�ͬ
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}
					//��������
					for (int k = i + 1; k <= COLUMN; k++) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
					//��������
					for (int k = i - 1; k >= 0; k--) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
				}
			}

		}
	}

	//��������
	for (int i = row1 + 1; i <= ROW; i++) {
		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//��������
			for (int j = column1 + 1; j <= COLUMN; j++) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//��������
					for (int k = i + 1; k <= COLUMN; k++) {
						if (block[k][j] == mytype && k == row2 && j == column2) {
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}

					//��������
					for (int k = i - 1; k >= 0; k--) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[k][j] == mytype && k == row2 && j == column2) {
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}
				}
			}

			//������������
			for (int j = column1 + 1; j >= 0; j--) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//��������
					for (int k = i + 1; k <= COLUMN; k++) {
						if (block[k][j] == mytype && k == row2 && j == column2) {
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}

					//��������
					for (int k = i - 1; k >= 0; k--) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[k][j] == mytype && k == row2 && j == column2) {
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}
				}
			}
		}
	}

	//��������
	for (int i = row1 - 1; i >= 0; i--) {
		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//��������
			for (int j = column1 + 1; j <= COLUMN; j++) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//��������
					for (int k = i + 1; k <= COLUMN; k++) {
						if (block[k][j] == mytype && k == row2 && j == column2) {
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}

					//��������
					for (int k = i - 1; k >= 0; k--) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[k][j] == mytype && k == row2 && j == column2) {
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}
				}
			}

			//��������
			for (int j = column1 + 1; j >= 0; j--) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//��������
					for (int k = i + 1; k <= COLUMN; k++) {
						if (block[k][j] == mytype && k == row2 && j == column2) {
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}

					//��������
					for (int k = i - 1; k >= 0; k--) {
						//����ǿ�����������Ŀ��㣬��������
						if (block[k][j] == mytype && k == row2 && j == column2) {
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}
				}
			}
		}
	}

	return false;
}

//����
void GameDlg::Remove(int row1, int column1, int row2, int column2) {
	block[row1][column1] = 0;
	block[row2][column2] = 0;
}

//��ʾ���ܣ�������֮�������ĵ㣬�粻��������ʾ���ţ�δ��ɣ�
void GameDlg::Search(int row, int column) {
	//��������
	for (int i = 0; i < ROW - 1; i++) {
		for (int j = 0; j < COLUMN - 1; j++) {

		}
	}
}

//����
void GameDlg::Recreate() {

	srand((unsigned)time(NULL));

	int b[(ROW - 2)*(COLUMN - 2)] = { 0 };
	int i, j;
	int k = 0;
	int temp;

	for (int i = 1; i < ROW - 1; i++) {
		for (int j = 1; j < COLUMN - 1; j++) {
			b[k] = block[i][j];
			k++;
		}
	}
	srand((unsigned)time(NULL));
	for (i = 1; i<(ROW - 2)*(COLUMN - 2); i++) {
		if (b[i] == 0)
			continue;
		j = rand() % (i + 1);
		k = 2;
		while (b[j] == 0) {
			j = rand() % (i + k);
			k++;
		}
		temp = b[i];
		b[i] = b[j];
		b[j] = temp;
	}
	k = 0;
	for (int i = 1; i < ROW - 1; i++) {
		for (int j = 1; j < COLUMN - 1; j++) {
			block[i][j] = b[k];
			k++;
		}
	}
	for (int i = 1; i < ROW - 1; i++) {
		for (int j = 1; j < COLUMN - 1; j++) {
			if (block[i + 1][j + 1] != 0) {
				/*
				ɾ������ͼƬ��Ϣ��δ��ɣ�
				*/


			}
		}
	}
	/*
	Ȼ��������ͼ

	*/


	/*
	Ȼ�����CString�Ĳ���
	ÿѡ������һ�Σ����ֿ�ʮ�ֻ��߶��ٷ�

	*/
}

//����map���찴ť
void GameDlg::ShowMap() {
	int i, j;
	CPoint p;
	CString str = _T("");
	////���ԭ�а�ť
	for (i = 0; i<m_btnGroup.GetSize(); i++)
		delete (CBlockButton *)m_btnGroup.GetAt(i);
	m_btnGroup.RemoveAll();
	//����°�ť
	for (i = 1; i <= ROW - 2; i++)
		for (j = 1; j <= COLUMN - 2; j++)
		{
			p.x = i;
			p.y = j;
			//����ť����m_btnGroupָ��������
			m_btnGroup.Add(new CBlockButton(block[i][j], p));
		}
	//��ʾ��ť
	for (i = 0; i<(ROW - 2); i++) {
		for (int j = 0; j < (COLUMN - 2); j++) {
			CBlockButton *btn = (CBlockButton *)m_btnGroup.GetAt(i * (COLUMN - 2) + j);
			//���찴ť�Ĵ�С��λ�ã�720����
			btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE,
				CRect(70 + j * 65, 30 + i * 60,
					70 + 65 + j * 65, 30 + 60 + i * 60), this,
				IDC_BLOCK + i);
	
			if (btn->m_ID)//���Ϊ0����ʾ
			{
				//�����þ���·��
				str.Format(_T("res\\%d.bmp"), btn->m_ID + 10);
				HBITMAP m_fkBmp = (HBITMAP)::LoadImage
				(AfxGetInstanceHandle(),
					str, IMAGE_BITMAP, 0, 0,
					LR_CREATEDIBSECTION | LR_LOADFROMFILE);
				//����ͼƬ
				if (m_fkBmp == NULL)
					if (MessageBox(_T(" ȱ �� ͼ Ƭ �� Դ! "), _T(" �� ��"),
						MB_ICONERROR | MB_OK) == IDOK)
					{
						CDialog::OnCancel();
						return;
					}
				btn->SetBitmap(m_fkBmp);
				btn->ShowWindow(SW_SHOW);
			}
			else {
				btn->ShowWindow(SW_HIDE);
			}
		}
	}
	//��ʾ��ť
	//for (i = 0; i<(ROW - 2)*(COLUMN - 2); i++)
	//{
	//	CBlockButton *btn = (CBlockButton *)m_btnGroup.GetAt(i);
	//	//���찴ť�Ĵ�С��λ�ã�720����
	//	btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE,
	//		CRect(70 + (i % (COLUMN - 2)) * 65, 30 + (i / (ROW - 2)) * 60,
	//			135 + (i % (COLUMN - 2)) * 65, 90 + (i / (ROW - 2)) * 60), this,
	//		IDC_BLOCK + i);

	//	if (btn->m_ID)//���Ϊ0����ʾ
	//	{
	//		//�����þ���·��
	//		str.Format(_T("res\\%d.bmp"), btn->m_ID + 10);
	//		HBITMAP m_fkBmp = (HBITMAP)::LoadImage
	//		(AfxGetInstanceHandle(),
	//			str, IMAGE_BITMAP, 0, 0,
	//			LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	//		//����ͼƬ
	//		if (m_fkBmp == NULL)
	//			if (MessageBox(_T(" ȱ �� ͼ Ƭ �� Դ! "), _T(" �� ��"),
	//				MB_ICONERROR | MB_OK) == IDOK)
	//			{
	//				CDialog::OnCancel();
	//				return;
	//			}
	//		btn->SetBitmap(m_fkBmp);
	//		btn->ShowWindow(SW_SHOW);
	//	}
	//	else
	//		btn->ShowWindow(SW_HIDE);

	//}
}

UINT TimeThread(LPVOID p)
{
	CProgressCtrl *pw;
	pw = (CProgressCtrl*)p;
	int i;
	//������Խ��з�ʱ�Ĳ�����ͬʱ��ʾ����

	for (i = 0; i<10000; i++)
	{
		pw->SetPos(i);
		::Sleep(10);
	}

	return 0;

}


void GameDlg::OnBnbegin()
{

	PlayerThread=AfxBeginThread(TimeThread, &m_ctrlProgress);
}


void GameDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

BOOL GameDlg::IsWin(void)
{
	//ʱ�������û�й���
	if (m_time == 0)
	{
		KillTimer(1);
		MessageBox(_T("Game Over !"), _T("ʱ�����"));
		m_time = 30;
		//�������İ�ť
		for (int i = 0; i<m_btnGroup.GetSize(); i++)
			delete (CBlockButton *)m_btnGroup.GetAt(i);
		m_btnGroup.RemoveAll();
		//��¼����

	//	CLLKAddDlg addData;
	//	addData.DoModal();

		return FALSE;
	}

	for (int i = 1; i <  ROW - 1; i++)
		for (int j = 1; j < COLUMN-1; j++)
		{
			if (block[i][j] != 0)
				return FALSE;
		}
	//���غ�ֹͣ��ʱ
	KillTimer(1);



	return TRUE;

}


/*void GameDlg::OnTimer(UINT nIDEvent)
{
	
		m_ctrlProgress.SetPos(progress);
		if (progress == 100)
		{
			KillTimer(timer);
		}
	

	CDialog::OnTimer(nIDEvent);

}*/

/*
void GameDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	this->KillTimer(1);
	this->SetTimer(1, 10000, NULL);
	m_ctrlProgress.SetRange(1, 1000);
}
 */


//��ͣ
void GameDlg::OnBnClickedButton2()
{
	if (!isThreadPause) {

		PlayerThread->SuspendThread();     //������̣��൱����ͣ����
		isThreadPause = true;
	}
	else
	{
		PlayerThread->ResumeThread();
		isThreadPause = false;
	}
}

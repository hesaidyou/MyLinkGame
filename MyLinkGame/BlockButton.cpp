// LLKanButton.cpp : implementation file
//
#include "stdafx.h"
#include <windows.h>
#include <mmsystem.h>
#include <windows.h>
#include <time.h>
#include <algorithm>
#pragma comment(lib, "WINMM.LIB")
#include "MyLinkGame.h"
#include "MyLinkGameDlg.h"
#include "BlockButton.h"


//��ʼ��ȫ�ֱ���
CBlockButton* CBlockButton::ms_firstBtn = NULL;
CBlockButton* CBlockButton::ms_secondBtn = NULL;
CPoint CBlockButton::ms_ptCross1(-1, -1);
CPoint CBlockButton::ms_ptCross2(-1, -1);
CMyLinkGameDlg* CBlockButton::parent = NULL;


IMPLEMENT_DYNAMIC(CBlockButton, CButton)

CBlockButton::CBlockButton()
	: m_ID(0)
	, m_location(0)
{

}

CBlockButton::~CBlockButton()
{
}


BEGIN_MESSAGE_MAP(CBlockButton, CButton)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



CBlockButton::CBlockButton(int type, CPoint point)
{
	m_location = point;
	m_ID = type;

}



//void CBlockButton::Recreate() {
//
//	srand((unsigned)time(NULL));
//
//	int b[(ROW - 2)*(COLUMN - 2)] = { 0 };
//	int i, j;
//	int k = 0;
//	int temp;
//
//	for (int i = 1; i < ROW - 1; i++) {
//		for (int j = 1; j < COLUMN - 1; j++) {
//			b[k] = block[i][j];
//			k++;
//		}
//	}
//	srand((unsigned)time(NULL));
//	for (i = 1; i<(ROW - 2)*(COLUMN - 2); i++) {
//		if (b[i] == 0)
//			continue;
//		j = rand() % (i + 1);
//		k = 2;
//		while (b[j] == 0) {
//			j = rand() % (i + k);
//			k++;
//		}
//		temp = b[i];
//		b[i] = b[j];
//		b[j] = temp;
//	}
//	k = 0;
//	for (int i = 1; i < ROW - 1; i++) {
//		for (int j = 1; j < COLUMN - 1; j++) {
//			block[i][j] = b[k];
//			k++;
//		}
//	}
//	for (int i = 1; i < ROW - 1; i++) {
//		for (int j = 1; j < COLUMN - 1; j++) {
//			if (block[i + 1][j + 1] != 0) {
//				/*
//				ɾ������ͼƬ��Ϣ��δ��ɣ�
//				*/
//
//
//			}
//		}
//	}
//	/*
//	Ȼ��������ͼ
//
//	*/
//
//
//	/*
//	Ȼ�����CString�Ĳ���
//	ÿѡ������һ�Σ����ֿ�ʮ�ֻ��߶��ٷ�
//
//	*/
//}

//��ʾ���ܣ�������֮�������ĵ㣬�粻��������ʾ���ţ�δ��ɣ�
void CBlockButton::Search(int row, int column) {
	//��������
	for (int i = 0; i < ROW - 1; i++) {
		for (int j = 0; j < COLUMN - 1; j++) {

		}
	}
}

//��������ʼ��������ꡢĿ���������꣨��ɣ�
//bool CBlockButton::CanRemove(int row1, int column1, int row2, int column2) {
//	//��row1,column1��ʼ������������ʽΪ����һ����ֱ�ӿ�ʼ�����ж��Ƿ���Լ�������
//	int mytype = block[row1][column1];
//
//	//������
//	//��������
//	for (int i = column1 + 1; i <= COLUMN; i++) {
//		//ֻ������Ŀ��㲢��������ͬ��������������ͬ���͵�����Ŀ���������
//		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
//			return true;
//		}
//		//�������ʼ�����Ͳ�ͬ
//		else if (block[row1][i] != mytype) {
//			//ÿһ����������������������ǿ��������ͣ�break
//			if (block[row1][i] != 0) {
//				break;
//			}
//			//��������
//			for (int j = row1 + 1; j <= ROW; j++) {
//				//
//				if (block[j][i] == mytype && j == row2 && i == column2) {
//					return true;
//				}
//				//�������ʼ�����Ͳ�ͬ
//				else if (block[j][i] != mytype) {
//					if (block[j][i] != 0) {
//						break;
//					}
//					//��������
//					for (int k = i + 1; k <= COLUMN; k++) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//					//��������
//					for (int k = i - 1; k >= 0; k--) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//				}
//			}
//
//			//��������
//			for (int j = row1 - 1; j >= 0; j--) {
//				//
//				if (block[j][i] == mytype && j == row2 && i == column2) {
//					return true;
//				}
//				//�������ʼ�����Ͳ�ͬ
//				else if (block[j][i] != mytype) {
//					if (block[j][i] != 0) {
//						break;
//					}
//					//��������
//					for (int k = i + 1; k <= COLUMN; k++) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//					//��������
//					for (int k = i - 1; k >= 0; k--) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//				}
//			}
//
//		}
//	}
//
//	//��������
//	for (int i = column1 - 1; i >= 0; i--) {
//		//ֻ������Ŀ��㲢��������ͬ��������������ͬ���͵�����Ŀ���������
//		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
//			return true;
//		}
//		//�������ʼ�����Ͳ�ͬ
//		else if (block[row1][i] != mytype) {
//			//ÿһ����������������������ǿ��������ͣ�break
//			if (block[row1][i] != 0) {
//				break;
//			}
//			//��������
//			for (int j = row1 + 1; j <= ROW; j++) {
//				//
//				if (block[j][i] == mytype && j == row2 && i == column2) {
//					return true;
//				}
//				//�������ʼ�����Ͳ�ͬ
//				else if (block[j][i] != mytype) {
//					if (block[j][i] != 0) {
//						break;
//					}
//					//��������
//					for (int k = i + 1; k <= COLUMN; k++) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//					//��������
//					for (int k = i - 1; k >= 0; k--) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//				}
//			}
//
//			//��������
//			for (int j = row1 - 1; j >= 0; j--) {
//				//
//				if (block[j][i] == mytype && j == row2 && i == column2) {
//					return true;
//				}
//				//�������ʼ�����Ͳ�ͬ
//				else if (block[j][i] != mytype) {
//					if (block[j][i] != 0) {
//						break;
//					}
//					//��������
//					for (int k = i + 1; k <= COLUMN; k++) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//					//��������
//					for (int k = i - 1; k >= 0; k--) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//				}
//			}
//
//		}
//	}
//
//	//��������
//	for (int i = row1 + 1; i <= ROW; i++) {
//		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
//			return true;
//		}
//		else if (block[i][column1] != mytype) {
//			if (block[i][column1] != 0) {
//				break;
//			}
//			//��������
//			for (int j = column1 + 1; j <= COLUMN; j++) {
//				if (block[i][j] == mytype && i == row2 && j == column2) {
//					return true;
//				}
//				else if (block[i][j] != mytype) {
//					if (block[i][j] != 0) {
//						break;
//					}
//					//��������
//					for (int k = i + 1; k <= COLUMN; k++) {
//						if (block[k][j] == mytype && k == row2 && j == column2) {
//							return true;
//						}
//						else if (block[k][j] != mytype) {
//							if (block[k][j] != 0) {
//								break;
//							}
//						}
//					}
//
//					//��������
//					for (int k = i - 1; k >= 0; k--) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[k][j] == mytype && k == row2 && j == column2) {
//							return true;
//						}
//						else if (block[k][j] != mytype) {
//							if (block[k][j] != 0) {
//								break;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	//��������
//	for (int i = row1 - 1; i >= 0; i--) {
//		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
//			return true;
//		}
//		else if (block[i][column1] != mytype) {
//			if (block[i][column1] != 0) {
//				break;
//			}
//			//��������
//			for (int j = column1 + 1; j <= COLUMN; j++) {
//				if (block[i][j] == mytype && i == row2 && j == column2) {
//					return true;
//				}
//				else if (block[i][j] != mytype) {
//					if (block[i][j] != 0) {
//						break;
//					}
//					//��������
//					for (int k = i + 1; k <= COLUMN; k++) {
//						if (block[k][j] == mytype && k == row2 && j == column2) {
//							return true;
//						}
//						else if (block[k][j] != mytype) {
//							if (block[k][j] != 0) {
//								break;
//							}
//						}
//					}
//
//					//��������
//					for (int k = i - 1; k >= 0; k--) {
//						//����ǿ�����������Ŀ��㣬��������
//						if (block[k][j] == mytype && k == row2 && j == column2) {
//							return true;
//						}
//						else if (block[k][j] != mytype) {
//							if (block[k][j] != 0) {
//								break;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return false;
//}


//��ť���µ���Ӧ����
//void CBlockButton::OnLButtonDown(UINT nFlags, CPoint point){
//	// TODO: Add your message handler code here and/or call default
//	CString str;
//
//	parent = (CMyLinkGameDlg *)GetParent();
//	//��ʼ�����ӹյ�
//	ms_ptCross1.x = ms_ptCross1.y = -1;
//	ms_ptCross2.x = ms_ptCross2.y = -1;
//
//	//ѡ��һ����ťʱ�ı�ͼƬ������
//	if (CBlockButton::ms_firstBtn == NULL)
//	{
//		//ms_firstBtn��¼������ѡ�еĵ�һ����ť
//		//ms_secondBtn��¼������ѡ�еĵڶ�����ť
//		CBlockButton::ms_firstBtn = this;
//		//��ͼƬ����һ�ŵ�ɫΪ��ɫ��ͬ���͵�ͼƬ
//		str.Format(_T("res\\%d.bmp"), (this->m_ID) + 100);
//		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//		this->SetBitmap(m_fkBmp);
//		this->ShowWindow(SW_SHOW);
//		//�����ťʱ������
//		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	}
//	//��������һ�����͵İ�ť
//	else if (CBlockButton::ms_firstBtn->m_ID != this->m_ID)
//	{
//		str.Format(_T("res\\%d.bmp"), CBlockButton::ms_firstBtn->m_ID);
//		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//		CBlockButton::ms_firstBtn->SetBitmap(m_fkBmp);
//		CBlockButton::ms_firstBtn->ShowWindow(SW_SHOW);
//
//		str.Format(_T("res\\%d.bmp"), (this->m_ID) + 100);
//		m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//		this->SetBitmap(m_fkBmp);
//		this->ShowWindow(SW_SHOW);
//
//		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
//
//		CBlockButton::ms_firstBtn = this;
//	}
//	//ȡ��ѡ�еİ�ť
//	else if (CBlockButton::ms_firstBtn == this)
//	{
//		str.Format(_T("res\\%d.bmp"), CBlockButton::ms_firstBtn->m_ID);
//		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//		CBlockButton::ms_firstBtn->SetBitmap(m_fkBmp);
//		CBlockButton::ms_firstBtn->ShowWindow(SW_SHOW);
//		CBlockButton::ms_firstBtn = NULL;
//		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	}
//	//������ť������
//	else if (FindLine(ms_firstBtn->m_location, this->m_location) ||
//		FindOneConner(ms_firstBtn->m_location, this->m_location) ||
//		FindSide(ms_firstBtn->m_location, this->m_location) ||
//		FindTwoConner(ms_firstBtn->m_location, this->m_location))
//	{
//		//��¼����ѡ�еĵڶ�����ť
//		ms_secondBtn = this;
//		//���ذ�ť
//		ms_firstBtn->ShowWindow(SW_HIDE);
//		ms_secondBtn->ShowWindow(SW_HIDE);
//		//���´��ڣ������öԻ����onpain������·��
//		parent->UpdateWindow();
//		//����һ��ͼƬ��ʣ��ʱ��ͷ���������
//		parent->m_time += 5;
//		parent->m_score += 10;
//		//�ı䰴ť���ͺ�map��ֵΪ0
//		ms_firstBtn->m_ID = 0;
//		ms_secondBtn->m_ID = 0;
//		parent->map[ms_firstBtn->m_location.x][ms_firstBtn->m_location.y] = 0;
//		parent->map[ms_secondBtn->m_location.x][ms_secondBtn->m_location.y] = 0;
//		ms_firstBtn = ms_secondBtn = NULL;
//		PlaySound(_T("H:\\C++code\\LLKan\\res\\elec.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	}
//	//����ͬ���͵İ�ť��������
//	else
//	{
//		str.Format(_T("res\\%d.bmp"), CBlockButton::ms_firstBtn->m_ID);
//		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//		CBlockButton::ms_firstBtn->SetBitmap(m_fkBmp);
//		CBlockButton::ms_firstBtn->ShowWindow(SW_SHOW);
//
//		str.Format(_T("res\\%d.bmp"), (this->m_ID) + 100);
//		m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//		this->SetBitmap(m_fkBmp);
//		this->ShowWindow(SW_SHOW);
//
//		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
//		CBlockButton::ms_firstBtn = this;
//	}
//	CButton::OnLButtonDown(nFlags, point);
//}

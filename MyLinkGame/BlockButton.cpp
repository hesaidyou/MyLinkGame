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


//初始化全局变量
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
//				删除界面图片信息（未完成）
//				*/
//
//
//			}
//		}
//	}
//	/*
//	然后重新贴图
//
//	*/
//
//
//	/*
//	然后就是CString的操作
//	每选择重排一次，积分扣十分或者多少分
//
//	*/
//}

//提示功能，搜索与之可消除的点，如不存在则提示重排（未完成）
void CBlockButton::Search(int row, int column) {
	//向右搜索
	for (int i = 0; i < ROW - 1; i++) {
		for (int j = 0; j < COLUMN - 1; j++) {

		}
	}
}

//传进来起始点横纵坐标、目标点横纵坐标（完成）
//bool CBlockButton::CanRemove(int row1, int column1, int row2, int column2) {
//	//从row1,column1开始搜索，搜索方式为从下一个点直接开始，先判断是否可以继续搜索
//	int mytype = block[row1][column1];
//
//	//→↓→
//	//向右搜索
//	for (int i = column1 + 1; i <= COLUMN; i++) {
//		//只有遇到目标点并且类型相同才消除，如遇相同类型但不是目标点则跳过
//		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
//			return true;
//		}
//		//如果与起始点类型不同
//		else if (block[row1][i] != mytype) {
//			//每一步都向下搜索，如果遇到非空其他类型，break
//			if (block[row1][i] != 0) {
//				break;
//			}
//			//向下搜索
//			for (int j = row1 + 1; j <= ROW; j++) {
//				//
//				if (block[j][i] == mytype && j == row2 && i == column2) {
//					return true;
//				}
//				//如果与起始点类型不同
//				else if (block[j][i] != mytype) {
//					if (block[j][i] != 0) {
//						break;
//					}
//					//向右搜索
//					for (int k = i + 1; k <= COLUMN; k++) {
//						//如果是可消除但不是目标点，继续搜索
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//					//向左搜索
//					for (int k = i - 1; k >= 0; k--) {
//						//如果是可消除但不是目标点，继续搜索
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
//			//向上搜索
//			for (int j = row1 - 1; j >= 0; j--) {
//				//
//				if (block[j][i] == mytype && j == row2 && i == column2) {
//					return true;
//				}
//				//如果与起始点类型不同
//				else if (block[j][i] != mytype) {
//					if (block[j][i] != 0) {
//						break;
//					}
//					//向右搜索
//					for (int k = i + 1; k <= COLUMN; k++) {
//						//如果是可消除但不是目标点，继续搜索
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//					//向左搜索
//					for (int k = i - 1; k >= 0; k--) {
//						//如果是可消除但不是目标点，继续搜索
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
//	//向左搜索
//	for (int i = column1 - 1; i >= 0; i--) {
//		//只有遇到目标点并且类型相同才消除，如遇相同类型但不是目标点则跳过
//		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
//			return true;
//		}
//		//如果与起始点类型不同
//		else if (block[row1][i] != mytype) {
//			//每一步都向下搜索，如果遇到非空其他类型，break
//			if (block[row1][i] != 0) {
//				break;
//			}
//			//向下搜索
//			for (int j = row1 + 1; j <= ROW; j++) {
//				//
//				if (block[j][i] == mytype && j == row2 && i == column2) {
//					return true;
//				}
//				//如果与起始点类型不同
//				else if (block[j][i] != mytype) {
//					if (block[j][i] != 0) {
//						break;
//					}
//					//向右搜索
//					for (int k = i + 1; k <= COLUMN; k++) {
//						//如果是可消除但不是目标点，继续搜索
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//					//向左搜索
//					for (int k = i - 1; k >= 0; k--) {
//						//如果是可消除但不是目标点，继续搜索
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
//			//向上搜索
//			for (int j = row1 - 1; j >= 0; j--) {
//				//
//				if (block[j][i] == mytype && j == row2 && i == column2) {
//					return true;
//				}
//				//如果与起始点类型不同
//				else if (block[j][i] != mytype) {
//					if (block[j][i] != 0) {
//						break;
//					}
//					//向右搜索
//					for (int k = i + 1; k <= COLUMN; k++) {
//						//如果是可消除但不是目标点，继续搜索
//						if (block[j][k] == mytype && j == row2 && k == column2) {
//							return true;
//						}
//						else if (block[j][k] != mytype) {
//							if (block[j][k] != 0) {
//								break;
//							}
//						}
//					}
//					//向左搜索
//					for (int k = i - 1; k >= 0; k--) {
//						//如果是可消除但不是目标点，继续搜索
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
//	//向下搜索
//	for (int i = row1 + 1; i <= ROW; i++) {
//		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
//			return true;
//		}
//		else if (block[i][column1] != mytype) {
//			if (block[i][column1] != 0) {
//				break;
//			}
//			//向右搜索
//			for (int j = column1 + 1; j <= COLUMN; j++) {
//				if (block[i][j] == mytype && i == row2 && j == column2) {
//					return true;
//				}
//				else if (block[i][j] != mytype) {
//					if (block[i][j] != 0) {
//						break;
//					}
//					//向下搜索
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
//					//向上搜索
//					for (int k = i - 1; k >= 0; k--) {
//						//如果是可消除但不是目标点，继续搜索
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
//	//向上搜索
//	for (int i = row1 - 1; i >= 0; i--) {
//		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
//			return true;
//		}
//		else if (block[i][column1] != mytype) {
//			if (block[i][column1] != 0) {
//				break;
//			}
//			//向右搜索
//			for (int j = column1 + 1; j <= COLUMN; j++) {
//				if (block[i][j] == mytype && i == row2 && j == column2) {
//					return true;
//				}
//				else if (block[i][j] != mytype) {
//					if (block[i][j] != 0) {
//						break;
//					}
//					//向下搜索
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
//					//向上搜索
//					for (int k = i - 1; k >= 0; k--) {
//						//如果是可消除但不是目标点，继续搜索
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


//按钮按下的响应函数
//void CBlockButton::OnLButtonDown(UINT nFlags, CPoint point){
//	// TODO: Add your message handler code here and/or call default
//	CString str;
//
//	parent = (CMyLinkGameDlg *)GetParent();
//	//初始化连接拐点
//	ms_ptCross1.x = ms_ptCross1.y = -1;
//	ms_ptCross2.x = ms_ptCross2.y = -1;
//
//	//选中一个按钮时改变图片的样子
//	if (CBlockButton::ms_firstBtn == NULL)
//	{
//		//ms_firstBtn记录了最终选中的第一个按钮
//		//ms_secondBtn记录了最终选中的第二个按钮
//		CBlockButton::ms_firstBtn = this;
//		//将图片换成一张底色为红色的同类型的图片
//		str.Format(_T("res\\%d.bmp"), (this->m_ID) + 100);
//		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//		this->SetBitmap(m_fkBmp);
//		this->ShowWindow(SW_SHOW);
//		//点击按钮时的声音
//		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	}
//	//换到另外一种类型的按钮
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
//	//取消选中的按钮
//	else if (CBlockButton::ms_firstBtn == this)
//	{
//		str.Format(_T("res\\%d.bmp"), CBlockButton::ms_firstBtn->m_ID);
//		HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//		CBlockButton::ms_firstBtn->SetBitmap(m_fkBmp);
//		CBlockButton::ms_firstBtn->ShowWindow(SW_SHOW);
//		CBlockButton::ms_firstBtn = NULL;
//		PlaySound(_T("H:\\C++code\\LLKan\\res\\sel.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	}
//	//两个按钮可连接
//	else if (FindLine(ms_firstBtn->m_location, this->m_location) ||
//		FindOneConner(ms_firstBtn->m_location, this->m_location) ||
//		FindSide(ms_firstBtn->m_location, this->m_location) ||
//		FindTwoConner(ms_firstBtn->m_location, this->m_location))
//	{
//		//记录最终选中的第二个按钮
//		ms_secondBtn = this;
//		//隐藏按钮
//		ms_firstBtn->ShowWindow(SW_HIDE);
//		ms_secondBtn->ShowWindow(SW_HIDE);
//		//更新窗口，来调用对话框的onpain（）画路径
//		parent->UpdateWindow();
//		//消除一对图片后，剩余时间和分数都增加
//		parent->m_time += 5;
//		parent->m_score += 10;
//		//改变按钮类型和map的值为0
//		ms_firstBtn->m_ID = 0;
//		ms_secondBtn->m_ID = 0;
//		parent->map[ms_firstBtn->m_location.x][ms_firstBtn->m_location.y] = 0;
//		parent->map[ms_secondBtn->m_location.x][ms_secondBtn->m_location.y] = 0;
//		ms_firstBtn = ms_secondBtn = NULL;
//		PlaySound(_T("H:\\C++code\\LLKan\\res\\elec.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	}
//	//两个同类型的按钮不可连接
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

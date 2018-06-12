// GameDlg.cpp : 实现文件
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

// GameDlg 对话框

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


// GameDlg 消息处理程序


void GameDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	timer=SetTimer(1, 1000, NULL);//设置进度条更新时钟

	isThreadPause = false;
	m_time = 30;
	m_score = 0;
	m_ctrlProgress.SetRange32(1, 3000);

	OnBnbegin();
	CreatBlocks(2);
	ShowMap();

}

//创建游戏
void GameDlg::CreatBlocks(int hardRate) {

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			block[i][j] = { 0 };
		}
	}

	int b[(ROW - 2)*(COLUMN - 2)] = { 0 };

	//难度1,5种图片
	if (hardRate == 1) {
		for (int i = 0; i <(ROW - 2)*(COLUMN - 2); i += 28) {
			for (int x = 0; x < 28; x++) {
				b[i + x] = i / 28 + 1;
			}
		}
	}

	//难度2,10种图片
	if (hardRate == 2) {
		for (int i = 0; i <(ROW - 2)*(COLUMN - 2); i += 14) {
			for (int x = 0; x < 14; x++) {
				b[i + x] = i / 14 + 1;
			}
		}
	}


	//难度3,20种图片
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

//传进来起始点横纵坐标、目标点横纵坐标（完成）
bool GameDlg::CanRemove(int row1, int column1, int row2, int column2) {
	//从row1,column1开始搜索，搜索方式为从下一个点直接开始，先判断是否可以继续搜索
	int mytype = block[row1][column1];

	//→↓→
	//向右搜索
	for (int i = column1 + 1; i <= COLUMN; i++) {
		//只有遇到目标点并且类型相同才消除，如遇相同类型但不是目标点则跳过
		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
			return true;
		}
		//如果与起始点类型不同
		else if (block[row1][i] != mytype) {
			//每一步都向下搜索，如果遇到非空其他类型，break
			if (block[row1][i] != 0) {
				break;
			}
			//向下搜索
			for (int j = row1 + 1; j <= ROW; j++) {
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					return true;
				}
				//如果与起始点类型不同
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}
					//向右搜索
					for (int k = i + 1; k <= COLUMN; k++) {
						//如果是可消除但不是目标点，继续搜索
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
					//向左搜索
					for (int k = i - 1; k >= 0; k--) {
						//如果是可消除但不是目标点，继续搜索
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

			//向上搜索
			for (int j = row1 - 1; j >= 0; j--) {
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					return true;
				}
				//如果与起始点类型不同
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}
					//向右搜索
					for (int k = i + 1; k <= COLUMN; k++) {
						//如果是可消除但不是目标点，继续搜索
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
					//向左搜索
					for (int k = i - 1; k >= 0; k--) {
						//如果是可消除但不是目标点，继续搜索
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

	//向左搜索
	for (int i = column1 - 1; i >= 0; i--) {
		//只有遇到目标点并且类型相同才消除，如遇相同类型但不是目标点则跳过
		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
			return true;
		}
		//如果与起始点类型不同
		else if (block[row1][i] != mytype) {
			//每一步都向下搜索，如果遇到非空其他类型，break
			if (block[row1][i] != 0) {
				break;
			}
			//向下搜索
			for (int j = row1 + 1; j <= ROW; j++) {
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					return true;
				}
				//如果与起始点类型不同
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}
					//向右搜索
					for (int k = i + 1; k <= COLUMN; k++) {
						//如果是可消除但不是目标点，继续搜索
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
					//向左搜索
					for (int k = i - 1; k >= 0; k--) {
						//如果是可消除但不是目标点，继续搜索
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

			//向上搜索
			for (int j = row1 - 1; j >= 0; j--) {
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					return true;
				}
				//如果与起始点类型不同
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}
					//向右搜索
					for (int k = i + 1; k <= COLUMN; k++) {
						//如果是可消除但不是目标点，继续搜索
						if (block[j][k] == mytype && j == row2 && k == column2) {
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}
					//向左搜索
					for (int k = i - 1; k >= 0; k--) {
						//如果是可消除但不是目标点，继续搜索
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

	//向下搜索
	for (int i = row1 + 1; i <= ROW; i++) {
		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//向右搜索
			for (int j = column1 + 1; j <= COLUMN; j++) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//向下搜索
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

					//向上搜索
					for (int k = i - 1; k >= 0; k--) {
						//如果是可消除但不是目标点，继续搜索
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

			//向左搜索？？
			for (int j = column1 + 1; j >= 0; j--) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//向下搜索
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

					//向上搜索
					for (int k = i - 1; k >= 0; k--) {
						//如果是可消除但不是目标点，继续搜索
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

	//向上搜索
	for (int i = row1 - 1; i >= 0; i--) {
		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//向右搜索
			for (int j = column1 + 1; j <= COLUMN; j++) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//向下搜索
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

					//向上搜索
					for (int k = i - 1; k >= 0; k--) {
						//如果是可消除但不是目标点，继续搜索
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

			//向左搜索
			for (int j = column1 + 1; j >= 0; j--) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//向下搜索
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

					//向上搜索
					for (int k = i - 1; k >= 0; k--) {
						//如果是可消除但不是目标点，继续搜索
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

//消除
void GameDlg::Remove(int row1, int column1, int row2, int column2) {
	block[row1][column1] = 0;
	block[row2][column2] = 0;
}

//提示功能，搜索与之可消除的点，如不存在则提示重排（未完成）
void GameDlg::Search(int row, int column) {
	//向右搜索
	for (int i = 0; i < ROW - 1; i++) {
		for (int j = 0; j < COLUMN - 1; j++) {

		}
	}
}

//重排
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
				删除界面图片信息（未完成）
				*/


			}
		}
	}
	/*
	然后重新贴图

	*/


	/*
	然后就是CString的操作
	每选择重排一次，积分扣十分或者多少分

	*/
}

//根据map构造按钮
void GameDlg::ShowMap() {
	int i, j;
	CPoint p;
	CString str = _T("");
	////清除原有按钮
	for (i = 0; i<m_btnGroup.GetSize(); i++)
		delete (CBlockButton *)m_btnGroup.GetAt(i);
	m_btnGroup.RemoveAll();
	//添加新按钮
	for (i = 1; i <= ROW - 2; i++)
		for (j = 1; j <= COLUMN - 2; j++)
		{
			p.x = i;
			p.y = j;
			//将按钮放入m_btnGroup指针数组中
			m_btnGroup.Add(new CBlockButton(block[i][j], p));
		}
	//显示按钮
	for (i = 0; i<(ROW - 2); i++) {
		for (int j = 0; j < (COLUMN - 2); j++) {
			CBlockButton *btn = (CBlockButton *)m_btnGroup.GetAt(i * (COLUMN - 2) + j);
			//构造按钮的大小和位置（720，）
			btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE,
				CRect(70 + j * 65, 30 + i * 60,
					70 + 65 + j * 65, 30 + 60 + i * 60), this,
				IDC_BLOCK + i);
	
			if (btn->m_ID)//如果为0则不显示
			{
				//尽量用绝对路径
				str.Format(_T("res\\%d.bmp"), btn->m_ID + 10);
				HBITMAP m_fkBmp = (HBITMAP)::LoadImage
				(AfxGetInstanceHandle(),
					str, IMAGE_BITMAP, 0, 0,
					LR_CREATEDIBSECTION | LR_LOADFROMFILE);
				//加载图片
				if (m_fkBmp == NULL)
					if (MessageBox(_T(" 缺 少 图 片 资 源! "), _T(" 错 误"),
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
	//显示按钮
	//for (i = 0; i<(ROW - 2)*(COLUMN - 2); i++)
	//{
	//	CBlockButton *btn = (CBlockButton *)m_btnGroup.GetAt(i);
	//	//构造按钮的大小和位置（720，）
	//	btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE,
	//		CRect(70 + (i % (COLUMN - 2)) * 65, 30 + (i / (ROW - 2)) * 60,
	//			135 + (i % (COLUMN - 2)) * 65, 90 + (i / (ROW - 2)) * 60), this,
	//		IDC_BLOCK + i);

	//	if (btn->m_ID)//如果为0则不显示
	//	{
	//		//尽量用绝对路径
	//		str.Format(_T("res\\%d.bmp"), btn->m_ID + 10);
	//		HBITMAP m_fkBmp = (HBITMAP)::LoadImage
	//		(AfxGetInstanceHandle(),
	//			str, IMAGE_BITMAP, 0, 0,
	//			LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	//		//加载图片
	//		if (m_fkBmp == NULL)
	//			if (MessageBox(_T(" 缺 少 图 片 资 源! "), _T(" 错 误"),
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
	//这里可以进行费时的操作，同时显示进度

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
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

BOOL GameDlg::IsWin(void)
{
	//时间结束，没有过关
	if (m_time == 0)
	{
		KillTimer(1);
		MessageBox(_T("Game Over !"), _T("时间结束"));
		m_time = 30;
		//清除桌面的按钮
		for (int i = 0; i<m_btnGroup.GetSize(); i++)
			delete (CBlockButton *)m_btnGroup.GetAt(i);
		m_btnGroup.RemoveAll();
		//记录分数

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
	//过关后停止计时
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


//暂停
void GameDlg::OnBnClickedButton2()
{
	if (!isThreadPause) {

		PlayerThread->SuspendThread();     //挂起进程，相当于暂停播放
		isThreadPause = true;
	}
	else
	{
		PlayerThread->ResumeThread();
		isThreadPause = false;
	}
}

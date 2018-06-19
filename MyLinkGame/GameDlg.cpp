 // GameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLinkGame.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include "Choose.h"
#include <string>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <algorithm>

#include "LLKAddDlg.h"
#include "BlockButton.h"
#include "PaiHangBang.h"

#define IDC_BLOCK 10000

// GameDlg 对话框

IMPLEMENT_DYNAMIC(GameDlg, CDialog)

GameDlg::GameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_GAMEDLG, pParent)
{
	//::SetBackgroundImage(IDB_BITMAP1);
	//GameDlg::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 320, 240, SWP_NOZORDER);
	//GameDlg::SetWindowPos(NULL, 0, 0, 320, 240, SWP_NOZORDER | SWP_NOMOVE);


	//HBITMAP hbitmap;
	//hbitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), (WCHAR*)("res/GameDlg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	//初始化连线数组
	for (int i = 0; i < 4; i++) {
		linkline[i].x = -1;
		linkline[i].y = -1;
	}

}





GameDlg::~GameDlg()
{
}

void GameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_STATIC5, m_static5);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
	DDX_Control(pDX, IDC_STATIC6, m_static6);
	DDX_Control(pDX, IDC_STATIC12, m_static12);
}


BEGIN_MESSAGE_MAP(GameDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_STATIC4, &GameDlg::OnStnClickedStatic4)
	ON_STN_CLICKED(IDC_STATIC5, &GameDlg::OnStnClickedStatic5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &GameDlg::OnNMCustomdrawProgress1)
	ON_STN_CLICKED(IDC_STATIC6, &GameDlg::OnStnClickedStatic6)
	ON_STN_CLICKED(IDC_STATIC12, &GameDlg::OnStnClickedStatic12)
	ON_BN_CLICKED(IDC_BUTTONTESTING, &GameDlg::OnBnClickedButtontesting)
	ON_BN_CLICKED(IDC_PAHHANGCESHI, &GameDlg::OnBnClickedPahhangceshi)
	ON_BN_CLICKED(IDC_WinTest, &GameDlg::OnBnClickedWintest)
END_MESSAGE_MAP()


// GameDlg 消息处理程序



void GameDlg::PlayMP3()
{
	CString strFileName;
	strFileName.Format(_T("res\\地图背景音乐.mp3"));
	CString strCommond;
	strCommond.Format(_T("play %s repeat"), strFileName);
	mciSendString(strCommond, NULL, 0, NULL);
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


	//难度3,14种图片
	if (hardRate == 3) {
		for (int i = 0; i <(ROW - 2)*(COLUMN - 2); i += 7) {
			for (int x = 0; x < 10; x++) {
				b[i + x] = i / 10 + 1;
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

	//初始化连线数组
	for (int i = 0; i < 4; i++) {
		linkline[i].x = -1;
		linkline[i].y = -1;
	}
	countline = 0;
	//录入第一个点
	linkline[0].x = row1;
	linkline[0].y = column1;


	//→↓→
	//向右搜索  正版
	for (int i = column1 + 1; i <= COLUMN; i++) {

		//录入第二个点，如果继续下一步，则countline++
		linkline[1].x = row1;
		linkline[1].y = i;

		//只有遇到目标点并且类型相同才消除，如遇相同类型但不是目标点则跳过
		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
			countline = 1;
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
				linkline[2].x = j;
				linkline[2].y = i;

				if (block[j][i] == mytype && j == row2 && i == column2) {
					countline = 2;
					return true;
				}
				//如果与起始点类型不同
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}

					//向右搜索
					for (int k = i + 1; k <= COLUMN; k++) {
						linkline[3].x = j;
						linkline[3].y = k;

						//如果是可消除但不是目标点，继续搜索
						if (block[j][k] == mytype && j == row2 && k == column2) {
							countline = 3;
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}

					//如果向下移动两个才可以向左拐
					if (j - row1 > 1) {
						int can = 0;
						for (int c = row1 + 1; c < j; c++) {
							if (block[c][column1] != 0) {
								can = 1;
							}
						}

						if (can == 1) {
							//向左搜索
							for (int k = i - 1; k >= 0; k--) {
								linkline[3].x = j;
								linkline[3].y = k;

								//如果是可消除但不是目标点，继续搜索
								if (block[j][k] == mytype && j == row2 && k == column2) {
									countline = 3;
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

			//向上搜索
			for (int j = row1 - 1; j >= 0; j--) {
				linkline[2].x = j;
				linkline[2].y = i;
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					countline = 2;
					return true;
				}
				//如果与起始点类型不同
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}

					//向右搜索
					for (int k = i + 1; k <= COLUMN; k++) {
						linkline[3].x = j;
						linkline[3].y = k;

						//如果是可消除但不是目标点，继续搜索
						if (block[j][k] == mytype && j == row2 && k == column2) {
							countline = 3;
							return true;
						}
						else if (block[j][k] != mytype) {
							if (block[j][k] != 0) {
								break;
							}
						}
					}

					//拐三下限制
					if (row1 - j > 1) {
						int can = 0;
						for (int c = row1 - 1; c > j; c--) {
							if (block[c][column1] != 0) {
								can = 1;
							}
						}

						if (can == 1) {
							//向左搜索
							for (int k = i - 1; k >= 0; k--) {
								linkline[3].x = j;
								linkline[3].y = k;

								//如果是可消除但不是目标点，继续搜索
								if (block[j][k] == mytype && j == row2 && k == column2) {
									countline = 3;
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

		}
	}

	//向左搜索
	for (int i = column1 - 1; i >= 0; i--) {
		//录入第二个点，如果继续下一步，则countline++
		linkline[1].x = row1;
		linkline[1].y = i;

		//只有遇到目标点并且类型相同才消除，如遇相同类型但不是目标点则跳过
		if (block[row1][i] == mytype && row1 == row2 && i == column2) {
			countline = 1;
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
				//录入第二个点，如果继续下一步，则countline++
				linkline[2].x = j;
				linkline[2].y = i;
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					countline = 2;
					return true;
				}
				//如果与起始点类型不同
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}

					//限制
					if (j - row1 > 1) {
						int can = 0;
						for (int c = row1 + 1; c < j; c++) {
							if (block[c][column1] != 0) {
								can = 1;
							}
						}

						if (can == 1) {
							//向右搜索
							for (int k = i + 1; k <= COLUMN; k++) {
								linkline[3].x = j;
								linkline[3].y = k;

								//如果是可消除但不是目标点，继续搜索
								if (block[j][k] == mytype && j == row2 && k == column2) {
									countline = 3;
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

					//向左搜索
					for (int k = i - 1; k >= 0; k--) {
						linkline[3].x = j;
						linkline[3].y = k;

						//如果是可消除但不是目标点，继续搜索
						if (block[j][k] == mytype && j == row2 && k == column2) {
							countline = 3;
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
				linkline[2].x = j;
				linkline[2].y = i;
				//
				if (block[j][i] == mytype && j == row2 && i == column2) {
					countline = 2;
					return true;
				}
				//如果与起始点类型不同
				else if (block[j][i] != mytype) {
					if (block[j][i] != 0) {
						break;
					}

					if (row1 - j > 1) {
						int can = 0;
						for (int c = row1 - 1; c > j; c--) {
							if (block[c][column1] != 0) {
								can = 1;
							}
						}

						if (can == 1) {
							//向右搜索
							for (int k = i + 1; k <= COLUMN; k++) {
								linkline[3].x = j;
								linkline[3].y = k;

								//如果是可消除但不是目标点，继续搜索
								if (block[j][k] == mytype && j == row2 && k == column2) {
									countline = 3;
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

					//向左搜索
					for (int k = i - 1; k >= 0; k--) {
						linkline[3].x = j;
						linkline[3].y = k;

						//如果是可消除但不是目标点，继续搜索
						if (block[j][k] == mytype && j == row2 && k == column2) {
							countline = 3;
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
		linkline[1].x = i;
		linkline[1].y = column1;

		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			countline = 1;
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//向右搜索
			for (int j = column1 + 1; j <= COLUMN; j++) {
				linkline[2].x = i;
				linkline[2].y = j;

				if (block[i][j] == mytype && i == row2 && j == column2) {
					countline = 2;
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}

					//向下搜索
					for (int k = i + 1; k <= COLUMN; k++) {
						linkline[3].x = k;
						linkline[3].y = j;

						if (block[k][j] == mytype && k == row2 && j == column2) {
							countline = 3;
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}

					//xianzhi
					if (j - column1 > 1) {
						int can = 0;
						for (int c = column1 + 1; c < j; c++) {
							if (block[row1][c] != 0) {
								can = 1;
							}
						}

						if (can == 1) {
							//向上搜索
							for (int k = i - 1; k >= 0; k--) {
								linkline[3].x = k;
								linkline[3].y = j;

								//如果是可消除但不是目标点，继续搜索
								if (block[k][j] == mytype && k == row2 && j == column2) {
									countline = 3;
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

			//向左搜索
			for (int j = column1 - 1; j >= 0; j--) {
				linkline[2].x = i;
				linkline[2].y = j;

				if (block[i][j] == mytype && i == row2 && j == column2) {
					countline = 2;
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//向下搜索
					for (int k = i + 1; k <= COLUMN; k++) {
						linkline[3].x = k;
						linkline[3].y = j;

						if (block[k][j] == mytype && k == row2 && j == column2) {
							countline = 3;
							return true;
						}
						else if (block[k][j] != mytype) {
							if (block[k][j] != 0) {
								break;
							}
						}
					}

					//限制
					if (column1 - j > 1) {
						int can = 0;
						for (int c = column1 - 1; c > j; c--) {
							if (block[row1][c] != 0) {
								can = 1;
							}
						}

						if (can == 1) {

							//向上搜索
							for (int k = i - 1; k >= 0; k--) {
								linkline[3].x = k;
								linkline[3].y = j;

								//如果是可消除但不是目标点，继续搜索
								if (block[k][j] == mytype && k == row2 && j == column2) {
									countline = 3;
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
		}
	}

	//向上搜索
	for (int i = row1 - 1; i >= 0; i--) {
		linkline[1].x = i;
		linkline[1].y = column1;

		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			countline = 1;
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//向右搜索
			for (int j = column1 + 1; j <= COLUMN; j++) {
				linkline[2].x = i;
				linkline[2].y = j;

				if (block[i][j] == mytype && i == row2 && j == column2) {
					countline = 2;
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}

					//限制
					if (j - column1 > 1) {
						int can = 0;
						for (int c = column1 + 1; c < j; c++) {
							if (block[row1][c] != 0) {
								can = 1;
							}
						}

						if (can == 1) {
							//向下搜索
							for (int k = i + 1; k <= COLUMN; k++) {
								linkline[3].x = k;
								linkline[3].y = j;

								if (block[k][j] == mytype && k == row2 && j == column2) {
									countline = 3;
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

					//向上搜索
					for (int k = i - 1; k >= 0; k--) {
						linkline[3].x = k;
						linkline[3].y = j;
						
						//如果是可消除但不是目标点，继续搜索
						if (block[k][j] == mytype && k == row2 && j == column2) {
							countline = 3;
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
			for (int j = column1 - 1; j >= 0; j--) {
				linkline[2].x = i;
				linkline[2].y = j;

				if (block[i][j] == mytype && i == row2 && j == column2) {
					countline = 2;
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}

					//限制
					if (column1 - j > 1) {
						int can = 0;
						for (int c = column1 - 1; c > j; c--) {
							if (block[row1][c] != 0) {
								can = 1;
							}
						}

						if (can == 1) {

							//向下搜索
							for (int k = i + 1; k <= COLUMN; k++) {
								linkline[3].x = k;
								linkline[3].y = j;

								if (block[k][j] == mytype && k == row2 && j == column2) {
									countline = 3;
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


					//向上搜索
					for (int k = i - 1; k >= 0; k--) {
						linkline[3].x = k;
						linkline[3].y = j;

						//如果是可消除但不是目标点，继续搜索
						if (block[k][j] == mytype && k == row2 && j == column2) {
							countline = 3;
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

//1画线消除  2画线bug
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
	//for (int i = 1; i < ROW - 1; i++) {
	//	for (int j = 1; j < COLUMN - 1; j++) {
	//		if (block[i + 1][j + 1] != 0) {
	//			/*
	//			删除界面图片信息（未完成）
	//			*/


	//		}
	//	}
	//}
	/*
	然后重新贴图

	*/

	m_time = m_time - 10;
	m_ctrlProgress.OffsetPos(-10);

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
				CRect(XF + j * 65, YF + i * 60,
					XF + LBLOCK + j * 65, YF + HBLOCK + i * 60), this,
				IDC_BLOCK + i);
	
			if (btn->m_ID)//如果为0则不显示
			{
				//尽量用绝对路径
				str.Format(_T("res\\%d.bmp"), btn->m_ID + 20);
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

//画线
void GameDlg::DrawLine() {
	CDC* pDC = GetDC();
	for (int i = 0; i < countline; i++) {
		if (linkline[i].x != -1 && linkline[i+1].x!=-1) {
			//画图专用
			//pDC->SetDCPenColor(RGB(255, 255, 255));
			pDC->SetBkColor(RGB(255, 255, 255));
			pDC->MoveTo((XF + (linkline[i].y-1) * LBLOCK + LBLOCK/2), (YF + (linkline[i].x-1) * HBLOCK + HBLOCK/2));
			pDC->LineTo((XF + (linkline[i + 1].y-1) * LBLOCK + LBLOCK/2), (YF + (linkline[i + 1].x-1) * HBLOCK + HBLOCK/2));
		}
	}

}

//删除线
void GameDlg::DeleteLine() {
	CDC* pDC = GetDC();

}


HBRUSH GameDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	static CBrush gBr;
	static bool isInited = false;
	if (!isInited)
{
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);
		gBr.CreatePatternBrush(&bitmap);
		COLORREF clearColor = -1;
		bitmap.DeleteObject();
		isInited = true;
	}
	if (pWnd == this)
	{
		pDC->SetBkMode(TRANSPARENT);
		return gBr; //主窗口背景使用这个背景刷
	}
	else
		{
		pDC->SetBkMode(TRANSPARENT);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH); //其他控件使用透明背景
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
		}

BOOL GameDlg::OnInitDialog()
{

	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//更改对话框大小
	CRect temprect(0, 0, 1280, 1000);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	hard_rate = 2;
	m_score = 0;
	m_time = 150;

	m_bPlaying = true;
	m_pPause = false;
	m_ctrlProgress.SetRange(0, 450);
	m_ctrlProgress.SetStep(-3);
	m_ctrlProgress.SetPos(450);

	timer = SetTimer(1, 1000, NULL);//设置进度条更新时钟
									//	m_time = 30;
	

	CreatBlocks(2);
	ShowMap();
	
	m_static4.SetWindowText(_T(""));
	m_static5.SetWindowText(_T(""));
	m_static6.SetWindowText(_T(""));
	m_static12.SetWindowText(_T(""));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

	

////画线
//void GameDlg::DrawLine() {
//	for (int i = 0; i < 3; i++) {
//		if (linkline[i].x != -1 && linkline[i+1].x!=-1) {
//			//画图专用
//			CDC* pDC = GetDC();
//			pDC->MoveTo((XF + (linkline[i].y-1) * LBLOCK + LBLOCK/2), (YF + (linkline[i].x-1) * HBLOCK + HBLOCK/2));
//			pDC->LineTo((XF + (linkline[i + 1].y-1) * LBLOCK + LBLOCK/2), (YF + (linkline[i + 1].x-1) * HBLOCK + HBLOCK/2));
//		}
//	}
//}

void GameDlg::OnStnClickedStatic4()//提示
{
	for (int i = 1; i < (ROW - 1); i++) {
		for (int j = 1; j < (COLUMN - 1); j++) {
			if (block[i][j] != 0) {
				for (int p = 1; p < ROW - 1; p++) {
					for (int q = 1; q < COLUMN - 1; q++) {
						if (block[p][q] != 0) {
							if (CanRemove(i, j, p, q)) {
								CString str;
								str.Format(_T("res\\%d.bmp"), block[i][j]);
								HBITMAP m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
								CBlockButton *btn1 = (CBlockButton *)m_btnGroup.GetAt((i - 1) * (COLUMN - 2) + j - 1);//(CBlockButton *)
								btn1->SetBitmap(m_fkBmp);

								str.Format(_T("res\\%d.bmp"), block[p][q]);
								m_fkBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), str, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
								CBlockButton *btn2 = (CBlockButton *)m_btnGroup.GetAt((p - 1 ) * (COLUMN - 2) + q - 1);//(CBlockButton *)
								btn2->SetBitmap(m_fkBmp);
							//	btn2->ShowWindow(FALSE);
								this->ShowWindow(SW_SHOW);

								return;
							}
						}
					}
				}
			}
		}
	}

	m_time = m_time - 10;
	m_ctrlProgress.OffsetPos(-10);
}

void GameDlg::OnStnClickedStatic5() //重排
{
	Recreate();
	ShowMap();
}

void GameDlg::ModalTwo() {
	for (int i = 0; i < (ROW - 2); i++) {
		for (int j = 0; j < (COLUMN - 2); j++) {
			CBlockButton *btn = (CBlockButton *)m_btnGroup.GetAt(i * (COLUMN - 2) + j);
			if (btn->m_ID==0) {
				for (int p = i- 1; p >= 0; p--) {
					CBlockButton *btn1 = (CBlockButton *)m_btnGroup.GetAt(p * (COLUMN - 2) + j);
					btn1->m_location.x++;
					//btn1->m_location.y++;
					btn1->SetWindowPos(NULL, 0, 0, XF + btn1->m_location.y * 65, YF + btn1->m_location.x * 60, SWP_NOSIZE);
				}
			}
		}
	}
	//for (int i = 0; i < (ROW - 2); i++) {
	//	for (int j = 0; j < (COLUMN - 2); j++) {

	//	}
	//}
}

void GameDlg::SetModal(int modal) {
	this->modal = modal;
}

void GameDlg::OnStnClickedStatic12()//返回
{
	Choose  choose;
	choose.DoModal();
	this->CloseWindow();
}


////画线
//void GameDlg::DrawLine() {
//	for (int i = 0; i < 3; i++) {
//		if (linkline[i].x != -1 && linkline[i+1].x!=-1) {
//			//画图专用
//			CDC* pDC = GetDC();
//			pDC->MoveTo((XF + (linkline[i].y-1) * LBLOCK + LBLOCK/2), (YF + (linkline[i].x-1) * HBLOCK + HBLOCK/2));
//			pDC->LineTo((XF + (linkline[i + 1].y-1) * LBLOCK + LBLOCK/2), (YF + (linkline[i + 1].x-1) * HBLOCK + HBLOCK/2));
//		}
//	}
//}

void GameDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == PLAY_TIMER_ID && m_bPlaying && m_pPause == false)
	{
		m_ctrlProgress.SetPos(m_time * 3);

		m_ctrlProgress.StepIt();
	}
	
	m_time--;
	//调用重画函数

	this->OnPaintTime();

	IsWin();

	CDialog::OnTimer(nIDEvent);
}


//是否通关了
BOOL GameDlg::IsWin()
{
	//时间结束，没有过关
	if (m_time == 0)
	{
		KillTimer(1);
		MessageBox(_T("Game Over !"), _T("时间结束"));
		m_time = 150;
		//清除桌面的按钮
		for (int i = 0; i < m_btnGroup.GetSize(); i++)
			delete (CBlockButton *)m_btnGroup.GetAt(i);
		m_btnGroup.RemoveAll();
		//记录分数
		m_score += m_time;
		CLLKAddDlg addData;
		addData.DoModal();
		return FALSE;
	}

	else {
		int count = 0;
		for (int i = 1; i < ROW-1; i++) {
			for (int j = 1; j < COLUMN-1; j++)
			{
				if (block[i][j] != 0)
					return FALSE;
				else
					count++;
			}
		}

		if (count == 140) {
			//过关后停止计时
			KillTimer(1);
			//如果全部通关

			MessageBox(_T("恭喜你，已经全部通关"), _T("胜利"));

			m_score += m_time;

			for (int i = 0; i < m_btnGroup.GetSize(); i++)
				delete (CBlockButton *)m_btnGroup.GetAt(i);

			//记录分数
			CLLKAddDlg addData;
			addData.DoModal();
			return true;
		}
	}

	return false;
}


//void GameDlg::OnBnClickedButtonpause()
//{
//	if (m_bPlaying && !m_pPause) {
//		m_bPlaying = false;
//		m_pPause = true;
//	}
//	else {
//		m_pPause = false;
//		m_bPlaying = true;
//	}
//}

void GameDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


//暂停
void GameDlg::OnStnClickedStatic6()
{
	if (m_bPlaying && !m_pPause) {
		m_bPlaying = false;
		m_pPause = true;

		for (int i = 0; i < m_btnGroup.GetSize(); i++) {
			((CBlockButton *)m_btnGroup.GetAt(i))->ShowWindow(false);
		}
		KillTimer(1);
	}
	else {
		int b[140];
		int k = 0;
		for (int i = 1; i < ROW - 1; i++) {
			for (int j = 1; j < COLUMN - 1; j++)
			{
				b[k] = block[i][j];
				k++;
			}
		}
		for (int i = 0; i < m_btnGroup.GetSize(); i++) {
			if (b[i] != 0) {
				((CBlockButton *)m_btnGroup.GetAt(i))->ShowWindow(true);
			}
		}
		m_pPause = false;
		m_bPlaying = true;

		SetTimer(1, 1000, NULL);
	}


}

void GameDlg::OnPaintTime()
{
	CWindowDC dc(this);
	CPen lPen(PS_SOLID, 2, RGB(222, 211, 140));
	//设置字体颜色
	dc.SelectObject(&lPen);
	//选择画笔
	CFont font;
	CString str;
	str.Format(_T("剩余时间: %3d 秒"), m_time);
	//m_time 中存储剩余时间信息
	font.CreatePointFont(100, _T("宋体"));
	//设置字体
	dc.SelectObject(&font);
	dc.SetTextColor(RGB(222, 211, 140));
	dc.SetBkColor(TRANSPARENT);
	dc.TextOut(10, 40, str); //显示时间

	CWindowDC dc1(this);
	CPen lPen1(PS_SOLID, 2, RGB(222, 211, 140));
	//设置字体颜色
	dc1.SelectObject(&lPen);
	//选择画笔
	CFont font1;
	CString str1;
	if(!IsWin())
		str1.Format(_T("当前分数: %3d 分"), m_score);
	else
		str1.Format(_T("当前分数: %3d 分"), m_time+m_score);

	//m_time 中存储剩余时间信息
	font1.CreatePointFont(100, _T("宋体"));
	//设置字体
	dc1.SelectObject(&font1);
	dc1.SetTextColor(RGB(222, 211, 140));
	dc1.SetBkColor(TRANSPARENT);
	dc1.TextOut(150, 40, str1); //显示分数

}


//暂停测试用
void GameDlg::OnBnClickedButtontesting()
{

	if (m_bPlaying && !m_pPause) {
		m_bPlaying = false;
		m_pPause = true;

		for (int i = 0; i < m_btnGroup.GetSize(); i++) {
			((CBlockButton *)m_btnGroup.GetAt(i))->ShowWindow(false);
		}
		KillTimer(1);
	}
	else {
		int b[140];
		int k = 0;
		for (int i = 1; i < ROW - 1; i++) {
			for (int j = 1; j < COLUMN - 1; j++)
			{
				b[k] = block[i][j];
				k++;
			}
		}
		for (int i = 0; i < m_btnGroup.GetSize(); i++) {
			if (b[i] != 0) {
				((CBlockButton *)m_btnGroup.GetAt(i))->ShowWindow(true);
			}
		}
		m_pPause = false;
		m_bPlaying = true;

		SetTimer(1, 1000, NULL);

	}
}


void GameDlg::OnBnClickedPahhangceshi()
{
	PaiHangBang paihang;
	paihang.DoModal();
}


void GameDlg::OnBnClickedWintest()
{
	for (int i = 1; i < ROW - 1; i++) {
		for (int j = 1; j < COLUMN - 1; j++)
		{
			block[i][j] = 0;
		}
	}
}

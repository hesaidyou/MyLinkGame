#include <windows.h>
#include<time.h>
#include<algorithm>
#include<iostream>
#include "block.h"
//#include "stdafx.h"
using namespace std;

//初始化
Block::Block() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			block[i][j] = { 0 };
		}
	}
}

Block::~Block() {}

//创建难度为hardRate的游戏，随机排列（未完成）
void Block::CreatBlocks(int hardRate) {
	cout << "Create The Map" << endl;
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
	random_shuffle(b, b + (ROW - 2)*(COLUMN - 2));
	int k = 0;
	memset(block, 0, sizeof(block));

	for (int i = 1; i < ROW - 1; i++) {
		for (int j = 1; j < COLUMN - 1; j++) {
			block[i][j] = b[k];
			k++;
		}
	}
	block[1][1] = 1;
	block[2][3] = 1;

	block[2][2] = 2;
	block[1][3] = 2;

	block[3][1] = 1;
	block[3][2] = 2;
}

void Block::Recreate()
{
	cout << "Recreate the map" << endl;

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

//测试重拍
void Block::test_Recreate()
{
	for (int i = 1; i < ROW - 1; i++) {
		for (int j = 1; j < COLUMN - 1; j++) {
			if (block[i][j] == 5)
				block[i][j] = 0;
		}
	}




}

//测试用
void Block::print()
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << block[i][j] << "  ";

		}
		cout << endl;
	}
}

//提示功能，搜索与之可消除的点，如不存在则提示重排（未完成）
void Block::Search(int row, int column) {
	//向右搜索
	for (int i = 0; i < ROW - 1; i++) {
		for (int j = 0; j < COLUMN - 1; j++) {

		}
	}
}

//传进来起始点横纵坐标、目标点横纵坐标（完成）
bool Block::CanRemove(int row1, int column1, int row2, int column2) {
	//从row1,column1开始搜索，搜索方式为从下一个点直接开始，先判断是否可以继续搜索
	int mytype = block[row1][column1];

	//→↓→
	//向右搜索
	for (int i = column1 + 1; i < COLUMN; i++) {
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
			for (int j = row1 + 1; j < ROW; j++) {
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
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
			for (int j = row1 - 1; j > 0; j--) {
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
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
	for (int i = column1 - 1; i > 0; i--) {
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
			for (int j = row1 + 1; j < ROW; j++) {
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
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
			for (int j = row1 - 1; j > 0; j--) {
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
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
	for (int i = row1 + 1; i < ROW; i++) {
		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//向右搜索
			for (int j = column1 + 1; j < COLUMN; j++) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//向下搜索
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
	for (int i = row1 - 1; i > 0; i--) {
		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//向右搜索
			for (int j = column1 + 1; j < COLUMN; j++) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//向下搜索
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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

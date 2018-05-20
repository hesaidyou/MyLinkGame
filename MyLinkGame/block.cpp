#include <windows.h>
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
	for (int i = 0; i < ROW - 1; i++) {
		for (int j = 0; j < COLUMN - 1; j++) {

		}
	}
	block[1][1] = 1;
	block[2][3] = 1;

	block[2][2] = 2;
	block[1][3] = 2;

	block[3][1] = 1;
	block[3][2] = 2;
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

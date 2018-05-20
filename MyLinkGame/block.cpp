#include <windows.h>
#include "block.h"
//#include "stdafx.h"
using namespace std;

//��ʼ��
Block::Block() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			block[i][j] = { 0 };
		}
	}
}

Block::~Block() {}

//�����Ѷ�ΪhardRate����Ϸ��������У�δ��ɣ�
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

//��ʾ���ܣ�������֮�������ĵ㣬�粻��������ʾ���ţ�δ��ɣ�
void Block::Search(int row, int column) {
	//��������
	for (int i = 0; i < ROW - 1; i++) {
		for (int j = 0; j < COLUMN - 1; j++) {

		}
	}
}

//��������ʼ��������ꡢĿ���������꣨��ɣ�
bool Block::CanRemove(int row1, int column1, int row2, int column2) {
	//��row1,column1��ʼ������������ʽΪ����һ����ֱ�ӿ�ʼ�����ж��Ƿ���Լ�������
	int mytype = block[row1][column1];

	//������
	//��������
	for (int i = column1 + 1; i < COLUMN; i++) {
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
			for (int j = row1 + 1; j < ROW; j++) {
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
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
			for (int j = row1 - 1; j > 0; j--) {
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
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
	for (int i = column1 - 1; i > 0; i--) {
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
			for (int j = row1 + 1; j < ROW; j++) {
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
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
			for (int j = row1 - 1; j > 0; j--) {
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
					for (int k = i + 1; k < COLUMN; k++) {
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
					for (int k = i - 1; k > 0; k--) {
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
	for (int i = row1 + 1; i < ROW; i++) {
		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//��������
			for (int j = column1 + 1; j < COLUMN; j++) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//��������
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

					//��������
					for (int k = i - 1; k > 0; k--) {
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
	for (int i = row1 - 1; i > 0; i--) {
		if (block[i][column1] == mytype && i == row2 && column1 == column2) {
			return true;
		}
		else if (block[i][column1] != mytype) {
			if (block[i][column1] != 0) {
				break;
			}
			//��������
			for (int j = column1 + 1; j < COLUMN; j++) {
				if (block[i][j] == mytype && i == row2 && j == column2) {
					return true;
				}
				else if (block[i][j] != mytype) {
					if (block[i][j] != 0) {
						break;
					}
					//��������
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

					//��������
					for (int k = i - 1; k > 0; k--) {
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

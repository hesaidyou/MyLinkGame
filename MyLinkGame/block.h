#pragma once
#ifndef __BLOCK_H__
#define __BLOCK_H__
//��������������

//�С���
#define ROW 3+2
#define COLUMN 3+2

class Block
{
public:
	Block();
	~Block();
	//�����Ѷ�ΪhardRate������
	void CreatBlocks(int hardRate);
	void Search(int row, int column);
	bool CanRemove(int row1, int column1, int row2, int column2);

private:
	int block[ROW][COLUMN];
};

struct Point {
	int x;
	int y;
};


#endif // !1

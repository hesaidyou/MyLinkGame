#pragma once
#ifndef __BLOCK_H__
#define __BLOCK_H__
//��������������

//�С���
#define ROW 10+2
#define COLUMN 14+2

class Block
{
public:
	Block();
	~Block();
	//�����Ѷ�ΪhardRate������
	void CreatBlocks(int hardRate);

	int block[ROW][COLUMN];
};

struct Point {
	int x;
	int y;
};


#endif // !1

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
	//����
	void Recreate();
	//��ʾ
	void Search(int row, int column);
	//�ж��Ƿ��������
	bool CanRemove(int row1, int column1, int row2, int column2);

	//��������
	void test_Recreate();
	//����
	void print();
private:
	int block[ROW][COLUMN];
};

struct Point {
	int x;
	int y;
};


#endif // !1

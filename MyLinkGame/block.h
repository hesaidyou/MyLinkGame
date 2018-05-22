#pragma once
#ifndef __BLOCK_H__
#define __BLOCK_H__
//连连看消除块类

//行、列
#define ROW 10+2
#define COLUMN 14+2

class Block
{
public:
	Block();
	~Block();
	//创建难度为hardRate的排列
	void CreatBlocks(int hardRate);
	//重排
	void Recreate();
	//提示
	void Search(int row, int column);
	//判断是否可以消除
	bool CanRemove(int row1, int column1, int row2, int column2);

	//测试重排
	void test_Recreate();
	//测试
	void print();
private:
	int block[ROW][COLUMN];
};

struct Point {
	int x;
	int y;
};


#endif // !1

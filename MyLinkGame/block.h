#pragma once
#ifndef __BLOCK_H__
#define __BLOCK_H__
//连连看消除块类

//行、列
#define ROW 3+2
#define COLUMN 3+2

class Block
{
public:
	Block();
	~Block();
	//创建难度为hardRate的排列
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

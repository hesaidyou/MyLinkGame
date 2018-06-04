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

	int block[ROW][COLUMN];
};

struct Point {
	int x;
	int y;
};


#endif // !1

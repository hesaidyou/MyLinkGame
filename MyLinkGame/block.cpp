#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Block.h"

Block::Block() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			block[i][j] = { 0 };
		}
	}
}

Block::~Block() {}

void Block::CreatBlocks(int hardRate) {

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


	//难度3,20种图片
	if (hardRate == 3) {
		for (int i = 0; i <(ROW - 2)*(COLUMN - 2); i += 7) {
			for (int x = 0; x < 7; x++) {
				b[i + x] = i / 7 + 1;
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
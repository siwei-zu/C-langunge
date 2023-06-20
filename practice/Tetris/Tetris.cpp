#define _CRT_SECURE_NO_WARNINGS 1
#include "Tetris.h"



void InitInterface()
{
	setfillcolor(RGB(145, 14, 56));
	//四周边框
	solidrectangle(0, 0, 380, 10);
	solidrectangle(0, 0, 10, 420);
	solidrectangle(370, 0, 380, 420);
	solidrectangle(0, 410, 380, 420);


	//中间竖线
	solidrectangle(210, 0, 220, 420);
	//横线
	solidrectangle(220, 180, 380, 190);
}

char CreateBlock()
{
	int block_ = rand() % 7;
	return block[block_];
}
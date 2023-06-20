#define _CRT_SECURE_NO_WARNINGS 1
#include "Tetris.h"


int main()
{
	initgraph(380, 420);
	setbkcolor(BLACK);
	cleardevice();
	srand((unsigned)time(NULL));

	InitInterface();

	while (1);
	return 0;
}


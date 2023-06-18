#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"

int main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();

	init_interface();

	while (1);
	closegraph();
	return 0;
}
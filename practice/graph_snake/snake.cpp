#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"


void init_interface()
{
	setfillcolor(GREEN);
	//四周边框
	solidrectangle(0, 0, 640, 10);
	solidrectangle(0, 0, 10, 480);
	solidrectangle(630, 0, 640, 480);
	solidrectangle(0, 470, 640, 480);

	//中间竖线
	solidrectangle(470, 0, 480, 480);
	//横线
	solidrectangle(470, 200, 640, 210);

	//设置方格
	int i = 0;
	setlinecolor(BLACK);
	for (i = 10; i < 470; i+=20)//22*22
	{
		line(i, 10, i, 470);
		line(10, i, 470, i);
	}
}
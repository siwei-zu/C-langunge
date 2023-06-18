#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	initgraph(640, 480);

	setbkcolor(WHITE);
	cleardevice();

	setfillcolor(RED);
	setlinecolor(GREEN);
	setlinestyle(PS_SOLID, 1);

	settextcolor(GREEN);
	settextstyle(10, 0, "¿¬Ìå");
	setbkmode(TRANSPARENT);
	outtextxy(0, 0, "hello world");

	rectangle(0, 0, 640, 10);
	fillrectangle(0, 20, 640, 30);
	solidrectangle(0, 40, 640, 50);


	while (1);
	closegraph();
	return 0;
}
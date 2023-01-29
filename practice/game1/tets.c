#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("*******************\n");
	printf("***    1.play   ***\n");
	printf("***    0.exit   ***\n");
	printf("*******************\n");
}

void game()
{
	char qipan[ROW][COL] = { 0 };
	//初始化棋盘
	init_qipan(qipan,ROW,COL);
	//打印棋盘
	display_qipan(qipan, ROW, COL);
	//开始游戏
	qipan_play(qipan, ROW, COL);
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
			case 1:{
				game();
				break;
			}
			case 0:{
				printf("退出游戏\n");
				break;
			}
			default:{
				printf("输入有误，请重新输入。\n");
				break;
			}
		}
	} while (input);
	return 0;
}


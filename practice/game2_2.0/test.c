#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void geme()
{
	char board_display[ROW][COL] = { 0 };
	char board_ground[ROW][COL] = { 0 };
	//初始化棋盘
	init_board(board_display, ROW, COL);
	init_board(board_ground, ROW, COL);

	//打印棋盘
	//display_board(board_display, ROW, COL);
	//display_board(board_ground, ROW, COL);

	//布置雷
	set_boom(board_ground, ROW, COL);
	//display_board(board_ground, ROW, COL);
	display_board(board_display, ROW, COL);

	//扫雷
	board_play(board_display, board_ground, ROW, COL);
}


void menu()
{
	printf("*************************\n");
	printf("****     1. play     ****\n");
	printf("****     0. exit     ****\n");
	printf("*************************\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		system("cls");//清屏
		switch (input)
		{
		case 1:
		{
			geme();
			break;
		}
		case 0:
			break;
		default :
		{
			printf("输入错误！！请重新输入。\n");
			break;
		}
		}
	} while (input);
	return 0;
}
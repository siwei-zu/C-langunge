#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void menu()
{
	printf("*****************************\n");
	printf("**** 1. play     0. exit ****\n");
	printf("**** 2.rules of the game ****\n");
	printf("*****************************\n");
}

void game_rules()
{
	printf("*\n");
}

void game()
{
	Snake snake = { 0 };
	char interface[20][20] = { 0 };//游戏界面展示数组
	memset(interface, ' ', sizeof(char) * ((FACE_SZ - 2) * (FACE_SZ - 2)));
	snake_init(&snake);
	game_interface(interface, FACE_SZ);
}


int main()
{
	int input1 = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input1);
		switch (input1)
		{
		case 1:
			game();
			break;
		case 2:
		{
			int input2 = 0;
			game_rules();
			while(1)
			{
				printf("请选择:>");
				scanf("%d", &input2);
				if (input2 == 0)
					break;
				else
					printf("输入无效\n");
			}
			break;
		}
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input1);
	return 0;
}

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
	printf("    1).这个游戏设置的很粗略，玩家需要使用键盘上的‘w’‘a’‘s’‘d’\n");
	printf("来操作蛇的移动，没有胜利，只有无尽的吃下去，直到蛇到达边界，或者与\n");
	printf("自己的身体重合后游戏失败\n");
	printf("    2).如果在游戏过程中想暂停游戏，按下空格即可\n");
	printf("    要退出当前界面，请按数字0并回车确认\n");
}

void game()
{
	Snake snake = { 0 };
	char inter_face[FACE_SZ - 2][FACE_SZ - 2] = { 0 };//游戏界面展示数组
	memset(inter_face, ' ', sizeof(char) * ((FACE_SZ - 2) * (FACE_SZ - 2)));
	snake_init(&snake);
	//game_interface(inter_face, FACE_SZ);
	snake_body(&snake, inter_face);
	game_play(&snake, inter_face);
}


int main()
{
	srand((unsigned)time(NULL));
	int input1 = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input1);
		system("cls");
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
				{
					system("cls");
					break;
				}
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

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
	char qipan_display[ROW][COL] = { 0 };
	char qipan_ground[ROW][COL] = { 0 };
	init_qipan(qipan_display, ROW, COL);
	init_qipan(qipan_ground, ROW, COL);


	set_boom(qipan_ground, ROW, COL);

	//display_qipan(qipan_ground,ROW, COL);
	display_qipan(qipan_display, ROW, COL);
	qipan_play(qipan_display,qipan_ground, ROW, COL);
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
		case 1: {
			game();
			break;
		}
		case 0: {
			printf("退出游戏\n");
			break;
		}
		default: {
			printf("输入有误，请重新输入。\n");
			break;
		}
		}
	} while (input);
	return 0;
}
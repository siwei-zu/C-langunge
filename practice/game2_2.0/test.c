#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void geme()
{
	char board_display[ROW][COL] = { 0 };
	char board_ground[ROW][COL] = { 0 };
	//��ʼ������
	init_board(board_display, ROW, COL);
	init_board(board_ground, ROW, COL);

	//��ӡ����
	//display_board(board_display, ROW, COL);
	//display_board(board_ground, ROW, COL);

	//������
	set_boom(board_ground, ROW, COL);
	//display_board(board_ground, ROW, COL);
	display_board(board_display, ROW, COL);

	//ɨ��
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		system("cls");//����
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
			printf("������󣡣����������롣\n");
			break;
		}
		}
	} while (input);
	return 0;
}
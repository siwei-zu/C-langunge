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
	//��ʼ������
	init_qipan(qipan,ROW,COL);
	//��ӡ����
	display_qipan(qipan, ROW, COL);
	//��ʼ��Ϸ
	qipan_play(qipan, ROW, COL);
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
			case 1:{
				game();
				break;
			}
			case 0:{
				printf("�˳���Ϸ\n");
				break;
			}
			default:{
				printf("�����������������롣\n");
				break;
			}
		}
	} while (input);
	return 0;
}


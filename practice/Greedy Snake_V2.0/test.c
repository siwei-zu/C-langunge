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
	printf("    1).�����Ϸ���õĺܴ��ԣ������Ҫʹ�ü����ϵġ�w����a����s����d��\n");
	printf("�������ߵ��ƶ���û��ʤ����ֻ���޾��ĳ���ȥ��ֱ���ߵ���߽磬������\n");
	printf("�Լ��������غϺ���Ϸʧ��\n");
	printf("    2).�������Ϸ����������ͣ��Ϸ�����¿ո񼴿�\n");
	printf("    Ҫ�˳���ǰ���棬�밴����0���س�ȷ��\n");
}

void game()
{
	Snake snake = { 0 };
	char inter_face[FACE_SZ - 2][FACE_SZ - 2] = { 0 };//��Ϸ����չʾ����
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
		printf("��ѡ��:>");
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
				printf("��ѡ��:>");
				scanf("%d", &input2);
				if (input2 == 0)
				{
					system("cls");
					break;
				}
				else
					printf("������Ч\n");
			}
			break;
		}
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input1);
	return 0;
}

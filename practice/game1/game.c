#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void init_qipan(char qipan[ROW][COL], int row, int col)
{
	memset(qipan, ' ', row * col);
}

void display_qipan(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row ; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (j == col - 1)
			{
				printf(" %c ", *(*(qipan + i) + j));
			}
			else
			{
				printf(" %c |", *(*(qipan + i) + j));
			}
		}
		printf("\n");
		if(i!=row-1)
		{
			for (j = 0; j < col; j++)
			{
				if (j != col - 1)
				{
					printf("---|");
				}
				else
					printf("---");
			}
		}
		printf("\n");
	}
}

void qipan_play(char qipan[ROW][COL], int row, int col)
{
	while (1)
	{
		//�������
		int a = 0;
		int b = 0;
		while(1)
		{
			printf("�����������������:>");
			scanf("%d%d", &a, &b);
			if (a >= 1 && a <= row && b >= 1 && b <= col && qipan[a - 1][b - 1] == ' ')
			{
				qipan[a - 1][b - 1] = '*';
				break;
			}
			else
				printf("�����������������롣\n");
		}
		system("cls");
		display_qipan(qipan, ROW, COL);
		//�ж���Ӯ
		if (qipan_decide(qipan, ROW, COL) == '*')
		{
			printf("���Ӯ\n");
			break;
		}
		else if (qipan_decide(qipan, ROW, COL) == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
		//��������
		while(1)
		{
			int c = rand() % 3;
			int d = rand() % 3;
			if (qipan[c][d] == ' ')
			{
				qipan[c][d] = '#';
				break;
			}
		}
		system("cls");
		display_qipan(qipan, ROW, COL);
		//�ж���Ӯ
		if (qipan_decide(qipan, ROW, COL) == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		else if (qipan_decide(qipan, ROW, COL) == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
	}
}

char qipan_decide(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] == '*')
			return '*';
	}
	for (j = 0; j < col; j++)
	{
		if (qipan[0][j] == qipan[1][j] && qipan[1][j] == qipan[2][j] && qipan[1][j] == '*')
			return '*';
	}
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] == '*')
		return '*';
	if (qipan[0][2] == qipan[1][1] && qipan[1][1] == qipan[2][0] && qipan[1][1] == '*')
		return '*';
	
	
	for (i = 0; i < row; i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] == '#')
			return '#';
	}
	for (j = 0; j < col; j++)
	{
		if (qipan[0][j] == qipan[1][j] && qipan[1][j] == qipan[2][j] && qipan[1][j] == '#')
			return '#';
	}
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] == '#')
		return '#';
	if (qipan[0][2] == qipan[1][1] && qipan[1][1] == qipan[2][0] && qipan[1][1] == '#')
		return '#';
	int flag = 0;
	for (i = 0; i < row ; i++)
	{
		for(j = 0 ; j < col ; j++)
		{
			if (qipan[i][j] == ' ')
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
		return 'Q';
}



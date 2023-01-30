#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void init_qipan(char qipan[ROW][COL], int row, int col)
{
	memset(qipan, '*', row * col);
}

void display_qipan(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	int a = 1;
	for (i = 0; i <= col; i++)
	{
		if (i == 0)
			printf("%d", i);
		else 
			printf(" %d  ", i );
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%d", a++);
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
		if (i != row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if(j!=0)
				{
					if (j != col - 1)
					{
						printf("---|");
					}
					else
						printf("---");
				}
				else
				{
					if (j != col - 1)
					{
						printf(" ---|");
					}
					else
						printf(" ---");
				}
			}
		}
		printf("\n");
	}
}

void set_boom(char qipan_ground[ROW][COL], int row, int col)
{
	int boom = BOOM;
	while(boom)
	{
		while(1)
		{
			int a = rand() % row;
			int b = rand() % col;
			if (qipan_ground[a][b] == '*')
			{
				qipan_ground[a][b] = 'O';
				break;
			}
		}
		boom--;
	}

}


void qipan_play(char qipan_display[ROW][COL], char qipan_ground[ROW][COL], int row, int col)
{
	while (1)
	{
		int win = row * col - BOOM;
		int a = 0;
		int b = 0;
		while(1)
		{
			printf("��������������:>");
			scanf("%d%d", &a, &b);
			if (a >= 1 && a <= 9 && b >= 1 && b <= 9)
			{
				if (qipan_ground[a-1][b-1] == '*'|| qipan_ground[a - 1][b - 1] == '#')
				{
					qipan_ground[a-1][b-1] = '#';
					scan_boom(qipan_ground,qipan_display,ROW,COL,a-1,b-1);
					//display_qipan(qipan_ground, ROW, COL);
					win--;
					if (win == 0)
					{
						printf("��Ϸʤ��������\n");
						display_qipan(qipan_ground, ROW, COL);
						return 0;
					}
				}
				else if (qipan_ground[a-1][b-1] == 'O')
				{
					printf("�ŵ����ˣ���Ϸʧ�ܡ�\n");
					display_qipan(qipan_ground, ROW, COL);
					return 0;
				}
				else
				{
					printf("�ظ�����������������롣\n");
					continue;
				}

			}
			else
			{
				printf("�Ƿ����꣬���������롣\n");
				continue;
			}
		}
	}
}

int scan_boom(char qipan_ground[ROW][COL], char qipan_display[ROW][COL], int row, int col,int x,int y)
{
		int count = 0;
		if (x == 0)
		{
			//������Ͻ�
			if (y == 0)
			{
				if (qipan_ground[x + 1][y + 1] == 'O')
					count++;
				else
					qipan_ground[x + 1][y + 1] = '#';
				if (qipan_ground[x + 1][y] == 'O')
					count++;
				else
					qipan_ground[x + 1][y] = '#';
				if (qipan_ground[x][y + 1] == 'O')
					count++;
				else
					qipan_ground[x][y + 1] = '#';
			}
			//������Ͻ�
			else if (y == 8)
			{
				if (qipan_ground[x + 1][y - 1] == 'O')
					count++;
				else
					qipan_ground[x + 1][y - 1] = '#';
				if (qipan_ground[x + 1][y] == 'O')
					count++;
				else
					qipan_ground[x + 1][y] = '#';
				if (qipan_ground[x][y - 1] == 'O')
					count++;
				else
					qipan_ground[x][y - 1] = '#';
			}
			//����һ��
			else
			{
				if (qipan_ground[x][y - 1] == 'O')
					count++;
				else
					qipan_ground[x][y - 1] = '#';
				if (qipan_ground[x + 1][y - 1] == 'O')
					count++;
				else
					qipan_ground[x + 1][y - 1] = '#';
				if (qipan_ground[x + 1][y] == 'O')
					count++;
				else
					qipan_ground[x + 1][y] = '#';
				if (qipan_ground[x + 1][y + 1] == 'O')
					count++;
				else
					qipan_ground[x + 1][y + 1] = '#';
				if (qipan_ground[x][y + 1] == 'O')
					count++;
				else
					qipan_ground[x][y + 1] = '#';
			}
		}
		else if (x == 8)
		{
			//������½�
			if (y == 0)
			{
				if (qipan_ground[x - 1][y] == 'O')
					count++;
				else
					qipan_ground[x - 1][y] = '#';
				if (qipan_ground[x - 1][y + 1] == 'O')
					count++;
				else
					qipan_ground[x - 1][y + 1] = '#';
				if (qipan_ground[x][y + 1] == 'O')
					count++;
				else
					qipan_ground[x][y + 1] = '#';
			}
			//������½�
			else if (y == 8)
			{
				if (qipan_ground[x - 1][y])
					count++;
				else
					qipan_ground[x - 1][y] = '#';
				if (qipan_ground[x - 1][y - 1])
					count++;
				else
					qipan_ground[x - 1][y - 1] = '#';
				if (qipan_ground[x][y - 1])
					count++;
				else
					qipan_ground[x][y - 1] = '#';
			}
			//������һ��
			else
			{
				if (qipan_ground[x][y - 1])
					count++;
				else
					qipan_ground[x][y - 1] = '#';
				if (qipan_ground[x - 1][y - 1])
					count++;
				else
					qipan_ground[x - 1][y - 1] = '#';
				if (qipan_ground[x - 1][y])
					count++;
				else
					qipan_ground[x - 1][y] = '#';
				if (qipan_ground[x - 1][y + 1])
					count++;
				else
					qipan_ground[x - 1][y + 1] = '#';
				if (qipan_ground[x][y + 1])
					count++;
				else
					qipan_ground[x][y + 1] = '#';
			}
		}
		//����м䲿��
		else
		{
			//����һ��
			if (y == 0)
			{
				if (qipan_ground[x - 1][y] == 'O')
					count++;
				else
					qipan_ground[x - 1][y] = '#';
				if (qipan_ground[x - 1][y + 1] == 'O')
					count++;
				else
					qipan_ground[x - 1][y + 1] = '#';
				if (qipan_ground[x][y + 1] == 'O')
					count++;
				else
					qipan_ground[x][y + 1] = '#';
				if (qipan_ground[x + 1][y + 1] == 'O')
					count++;
				else
					qipan_ground[x + 1][y + 1] = '#';
				if (qipan_ground[x + 1][y] == 'O')
					count++;
				else
					qipan_ground[x + 1][y] = '#';
			}
			//���ڰ���
			else if (y == 8)
			{
				if (qipan_ground[x - 1][y] == 'O')
					count++;
				else
					qipan_ground[x - 1][y] = '#';
				if (qipan_ground[x - 1][y - 1] == 'O')
					count++;
				else
					qipan_ground[x - 1][y - 1] = '#';
				if (qipan_ground[x][y - 1] == 'O')
					count++;
				else
					qipan_ground[x][y - 1] = '#';
				if (qipan_ground[x + 1][y - 1] == 'O')
					count++;
				else
					qipan_ground[x + 1][y - 1] = '#';
				if (qipan_ground[x + 1][y] == 'O')
					count++;
				else
					qipan_ground[x + 1][y] = '#';
			}
			//����м䲿��
			else
			{
				int i = 0;
				for (i = -1; i < 2; i++)
				{
					if (qipan_ground[x - 1][y + i] == 'O')
						count++;
					else
						qipan_ground[x - 1][y + i] = '#';
				}
				if (qipan_ground[x][y - 1] == 'O')
					count++;
				else
					qipan_ground[x][y - 1] = '#';
				if (qipan_ground[x][y + 1] == 'O')
					count++;
				else
					qipan_ground[x][y + 1] = '#';
				for (i = -1; i < 2; i++)
				{
					if (qipan_ground[x + 1][y + i] == 'O')
						count++;
					else
						qipan_ground[x + 1][y + i] = '#';
				}
			}
		}
		if (count == 0)
		{
			qipan_display[x][y] = '0';
			//scan_boom(qipan_ground, qipan_display, row, col, x, y);
			system("cls");
			display_qipan(qipan_display, ROW, COL);

		}
		else
		{
			system("cls");
			qipan_display[x][y] = count + 48;
			display_qipan(qipan_display, ROW, COL);
		}
}




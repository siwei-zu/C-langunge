#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void init_board(char board[][COL], int row, int col)//���̳�ʼ��
{
	memset(board, '*', row * col);
}

void display_board(char board[][COL], int row, int col)//���̵Ĵ�ӡ
{
	int i = 0;
	for (i = 0; i <= col; i++)
	{
		if (i == 0)
			printf("%d ", i);
		else
			printf(" %d  ", i);
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%d ", i + 1);
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != col - 1)
				printf("|");
		}
		printf("\n");
		if(i != row - 1)
		{
			printf("  ");
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j != col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void set_boom(char board[][COL], int row, int col)//ʹ�������������
{
	int x = 0;
	int y = 0;
	int boom = BOOM;
	while (boom > 0)
	{
		x = rand() % 10;
		y = rand() % 10;
		if ((x >= 0 && x < row) && (y >= 0 && y < col) && board[x][y] == '*')
		{
			board[x][y] = '0';
			boom--;
		}
	}
}

int win = ROW * COL - BOOM;//ȫ�ֱ���win����win��Ϊ��ʱ˵�����з���λ�ö����Ų飬���ʤ��

int board_play(char board_display[][9], char board_ground[][9], int row, int col)//��Ϸ����
{
	char decide_board[ROW][COL] = { 0 };
	while (1)
	{
		int x = 0;
		int y = 0;
		while (1)
		{
			printf("����������Ӧ������:>");
			scanf("%d %d", &x, &y);
			if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
			{
				int a = x - 1, b = y - 1;
				if (board_ground[a][b] == '*' && decide_board[a][b] != ' ')
				{
					decide_board[a][b] = ' ';//��ֹ�ظ�����
					scan_boom(board_display, board_ground, ROW, COL, a, b);
					//display_board(board_ground, ROW, COL);//͸��
					system("cls");//�������ñ�ø����ۣ�ʹ��ͷ�ļ�<windows.h>
					display_board(board_display, ROW, COL);
					break;
				}
				else if (decide_board[a][b] == ' ')
				{
					printf("�ظ��������꣬����������\n");
				}
				else if (board_ground[a][b] == '0')
				{
					int i = 0;
					for (i = 0; i < row; i++)
					{
						int j = 0;
						for (j = 0; j < col; j++)
						{
							if (board_ground[i][j] == '0')
								board_display[i][j] = '0';
						}
					}
					printf("ɨ�����ˣ�����Ϸʧ�ܡ�\n");
					display_board(board_display, ROW, COL);
					return 0;
				}
			}
			else
			{
				printf("����Υ��������������\n");
			}
		}
		if (win == 0)
		{
			printf("��ϲ�㣬��Ϸʤ������\n");
		}
	}
}

const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };


int scan_boom(char board_display[][COL], char board_ground[][COL], int row, int col, int x, int y)//�����������
{
	COORD pos;
	win--;
		int i = 0;
		int count = 0;
		int mx = 0;
		int my = 0;
		for (i = 0; i < 8; i++)//ѭ���ж�����������Ա߰˸�λ��������
		{
			mx = x + dx[i], my = y + dy[i];
			if ((mx >= 0 && mx < row) && (my >= 0 && my < col) && board_ground[mx][my] == '0')
			{
				count++;
			}
		}
		if (count == 0)
		{
			board_display[x][y] = ' ';
			pos.X = y + 3 + y * 3;
			pos.Y = (x + 1) * 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			printf(" ");
			Sleep(20);
			for (i = 0; i < 8; i++)
			{
				mx = x + dx[i];
				my = y + dy[i];
				if ((mx >= 0 && mx < row) && (my >= 0 && my < col)&& board_ground[mx][my] != '#')//���������
				{
					board_ground[x][y] = '#';//ͬ��������ǵ����ã�
					scan_boom(board_display, board_ground, ROW, COL, mx, my);//����ݹ�Ե�ǰ�����Ա߰˸�λ�ý���ɨ��
				}
			}
		}
		else//���׵Ĵ����ĳ�#��Ϊ���ں����ݹ��е�ɨ�������ʱ����Ҫ�ٴ�ɨ�裬��ֹ���ݹ�
		{
			board_ground[x][y] = '#';
			board_display[x][y] = count + 48;
			pos.X = y + 3 + y * 3;
			pos.Y = (x + 1) * 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			printf("%d", count);
			Sleep(20);
		}
}

//int scan_boom(char board_display[][COL], char board_ground[][COL], int row, int col, int x, int y)//�����������
//{
//	int i = 0;
//	int count = 0;
//	int mx = 0;
//	int my = 0;
//	int l = 0;
//	int r = 0;
//	int que[ROW * COL][2] = { 0 };
//	for (i = 0; i < 8; i++)//�Ƚ���ѭ���ж��Ա߰˸��Ƿ�����
//	{
//		mx = x + dx[i];
//		my = y + dy[i];
//		if (mx >= 0 && mx < row && my >= 0 && my < col && board_ground[mx][my] == '0')
//			count++;
//	}
//
//	if(count == 0)//����
//	{
//		board_display[x][y] = ' ';//��Ϊ�����ף����԰���ʾ���̵ĵ�ǰ����任Ϊ�ո�
//		board_ground[x][y] = '#';//����Ǵ���ɨ���
//		win--;
//		for (i = 0; i < 8; i++)
//		{
//			mx = x + dx[i];
//			my = y + dy[i];
//			if (mx >= 0 && mx < row && my >= 0 && my < col && board_ground[mx][my] != '#')
//			{
//				que[r][0] = mx, que[r++][1] = my;
//			}//��¼��Χ�˸�λ�õ����꣬��r������ǰ��
//		}
//		while (l < r)
//
//		{
//			int currx = que[l][0];
//			int curry = que[l++][1];//l���ں��棬���l������r˵��ֹͣ��ɢ
//			count = 0;//��¼board_ground[currx][curry]�Ա��׵ĸ���
//			{
//				for (i = 0; i < 8; i++)
//				{
//					mx = currx + dx[i];
//					my = curry + dy[i];
//					if (mx >= 0 && mx < row && my >= 0 && my < col && board_ground[mx][my] == '0')
//						count++; //�ж�board_ground[currx][curry]�Ա��׵ĸ���
//				}
//				if (count == 0)//��ǰ��������
//				{
//					board_display[currx][curry] = ' ';
//					board_ground[x][y] = '#';//����Ƿ�ֹ�ٴ�ɨ��
//					win--;
//					for (i = 0; i < 8; i++)
//					{
//						mx = currx + dx[i];
//						my = curry + dy[i];
//						if (mx >= 0 && mx < row && my >= 0 && my < col && board_ground[mx][my] != '#')
//							board_ground[mx][my] = '#', que[r][0] = mx, que[r++][1] = my;//��Ϊɨ����������que������
//					}
//				}
//				else
//				{
//					board_display[currx][curry] = count + 48;
//					board_ground[currx][curry] = '#';
//					win--;
//				}
//			}
//		}
//	}
//	else//����
//	{
//		board_display[x][y] = count + 48;
//		board_ground[x][y] = '#';
//		win--;
//	}
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void init_board(char board[][COL], int row, int col)//棋盘初始化
{
	memset(board, '*', row * col);
}

void display_board(char board[][COL], int row, int col)//棋盘的打印
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

void set_boom(char board[][COL], int row, int col)//使用随机数设置雷
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

int win = ROW * COL - BOOM;//全局变量win，当win变为零时说明所有非雷位置都被排查，获得胜利

int board_play(char board_display[][9], char board_ground[][9], int row, int col)//游戏内容
{
	char decide_board[ROW][COL] = { 0 };
	while (1)
	{
		int x = 0;
		int y = 0;
		while (1)
		{
			printf("请玩家输入对应的坐标:>");
			scanf("%d %d", &x, &y);
			if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
			{
				int a = x - 1, b = y - 1;
				if (board_ground[a][b] == '*' && decide_board[a][b] != ' ')
				{
					decide_board[a][b] = ' ';//防止重复输入
					scan_boom(board_display, board_ground, ROW, COL, a, b);
					//display_board(board_ground, ROW, COL);//透视
					system("cls");//清屏，让变得更美观，使用头文件<windows.h>
					display_board(board_display, ROW, COL);
					break;
				}
				else if (decide_board[a][b] == ' ')
				{
					printf("重复输入坐标，请重新输入\n");
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
					printf("扫到雷了！！游戏失败。\n");
					display_board(board_display, ROW, COL);
					return 0;
				}
			}
			else
			{
				printf("坐标违法，请重新输入\n");
			}
		}
		if (win == 0)
		{
			printf("恭喜你，游戏胜利！！\n");
		}
	}
}

const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };


int scan_boom(char board_display[][COL], char board_ground[][COL], int row, int col, int x, int y)//深度优先搜索
{
	COORD pos;
	win--;
		int i = 0;
		int count = 0;
		int mx = 0;
		int my = 0;
		for (i = 0; i < 8; i++)//循环判断输入坐标的旁边八个位置有无雷
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
				if ((mx >= 0 && mx < row) && (my >= 0 && my < col)&& board_ground[mx][my] != '#')//标记起作用
				{
					board_ground[x][y] = '#';//同样是做标记的作用，
					scan_boom(board_display, board_ground, ROW, COL, mx, my);//进入递归对当前坐标旁边八个位置进行扫描
				}
			}
		}
		else//有雷的处理，改成#是为了在后续递归中当扫描这个点时不需要再次扫描，防止死递归
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

//int scan_boom(char board_display[][COL], char board_ground[][COL], int row, int col, int x, int y)//广度优先搜索
//{
//	int i = 0;
//	int count = 0;
//	int mx = 0;
//	int my = 0;
//	int l = 0;
//	int r = 0;
//	int que[ROW * COL][2] = { 0 };
//	for (i = 0; i < 8; i++)//先进入循环判断旁边八个是否有雷
//	{
//		mx = x + dx[i];
//		my = y + dy[i];
//		if (mx >= 0 && mx < row && my >= 0 && my < col && board_ground[mx][my] == '0')
//			count++;
//	}
//
//	if(count == 0)//无雷
//	{
//		board_display[x][y] = ' ';//因为是无雷，所以把显示棋盘的当前坐标变换为空格
//		board_ground[x][y] = '#';//做标记代表扫描过
//		win--;
//		for (i = 0; i < 8; i++)
//		{
//			mx = x + dx[i];
//			my = y + dy[i];
//			if (mx >= 0 && mx < row && my >= 0 && my < col && board_ground[mx][my] != '#')
//			{
//				que[r][0] = mx, que[r++][1] = my;
//			}//记录周围八个位置的坐标，用r来走在前面
//		}
//		while (l < r)
//
//		{
//			int currx = que[l][0];
//			int curry = que[l++][1];//l走在后面，如果l跟上了r说明停止扩散
//			count = 0;//记录board_ground[currx][curry]旁边雷的个数
//			{
//				for (i = 0; i < 8; i++)
//				{
//					mx = currx + dx[i];
//					my = curry + dy[i];
//					if (mx >= 0 && mx < row && my >= 0 && my < col && board_ground[mx][my] == '0')
//						count++; //判断board_ground[currx][curry]旁边雷的个数
//				}
//				if (count == 0)//当前坐标无雷
//				{
//					board_display[currx][curry] = ' ';
//					board_ground[x][y] = '#';//做标记防止再次扫描
//					win--;
//					for (i = 0; i < 8; i++)
//					{
//						mx = currx + dx[i];
//						my = curry + dy[i];
//						if (mx >= 0 && mx < row && my >= 0 && my < col && board_ground[mx][my] != '#')
//							board_ground[mx][my] = '#', que[r][0] = mx, que[r++][1] = my;//将为扫描的坐标加入que数组中
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
//	else//有雷
//	{
//		board_display[x][y] = count + 48;
//		board_ground[x][y] = '#';
//		win--;
//	}
//}


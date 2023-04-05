#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int boom_x = 0;
int boom_y = 0;

void snake_init(Snake* ps)
{
	int** tmp = (int**)malloc(sizeof(int*) * IN_S_LEN);
	if (tmp == NULL)
	{
		perror("tmp_malloc");
		return;
	}
	int i = 0;
	for (i = 0; i < IN_S_LEN; i++)
	{
		tmp[i] = (int*)malloc(sizeof(int) * 2);
		if (tmp[i] == NULL)
		{
			perror("tmp[i]_malloc");
			return;
		}
	}
	ps->body_coor = tmp;
	ps->len = IN_S_LEN;
}

void game_interface(char face [][FACE_SZ - 2], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (i == 0 || i == sz - 1)
		{
			printf(" ");
			int j = 0;
			for (j = 0; j < sz - 2; j++)
			{
				if(j != sz - 3)
				{
					printf("--");
				}
				else
				{
					printf("-");
				}
			}
			printf(" ");
		}
		else
		{
			printf("|");
			int j = 0;
			for (j = 0; j < sz - 2; j++)
			{
				if(j != sz - 3)
				{
					printf("%c ", face[i - 1][j]);
				}
				else
				{
					printf("%c", face[i - 1][j]);
				}
			}
			printf("|");
		}
		printf("\n");
	}
}

void snake_body(Snake* snake, char face[][FACE_SZ - 2])
{
	snake->body_coor[0][0] = (FACE_SZ - 2) / 2;
	snake->body_coor[0][1] = (FACE_SZ - 2) / 2;
	snake->body_coor[1][0] = (FACE_SZ - 2) / 2;
	snake->body_coor[1][1] = (FACE_SZ - 2) / 2 - 1;
	face[snake->body_coor[0][0]][snake->body_coor[0][1]] = '#';
	face[snake->body_coor[1][0]][snake->body_coor[1][1]] = '*';
}

void set_food(char face[][FACE_SZ - 2])
{
	while (1)
	{
		int x = rand() % (FACE_SZ - 2);
		int y = rand() % (FACE_SZ - 2);
		if (face[x][y] == ' ')
		{
			face[x][y] = '1';
			boom_x = x;
			boom_y = y;
			break;
		}
	}
}

void menu3()
{
	printf("*****************************\n");
	printf("**** 1. Continue the game****\n");
	printf("**** 0. Exit the game    ****\n");
	printf("*****************************\n");
}


int game_pause()
{
	int input = 0;
	do
	{
		menu3();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			return 1;
			break;
		case 0:
			return 0;
			break;
		default:
			printf("输入有误请重新输入\n");
			break;
		}
	} while (input);
}

int snake_move(Snake* snake, char face[][FACE_SZ - 2], char move)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int move_x = 0;
	int move_y = 0;
	if (move == 'w' || move == 'W')
	{
		move_x = -1;
		move_y = 0;
	}
	else if (move == 'a' || move == 'A')
	{
		move_x = 0;
		move_y = -1;
	}
	else if (move == 's' || move == 'S')
	{
		move_x = 1;
		move_y = 0;
	}
	else if (move == 'd' || move == 'D')
	{
		move_x = 0;
		move_y = 1;
	}
	//else if(move == ' ')
	//{
	//	//游戏暂停函数
	//	if (game_pause())
	//	{
	//		return 1;
	//	}
	//	{
	//		exit(0);
	//	}
	//}

	//判定蛇的身体不重合
	for (i = 1; i < snake->len; i++)
	{
		if (snake->body_coor[0][0] == snake->body_coor[i][0] && snake->body_coor[0][1] == snake->body_coor[i][1])
		{
			printf("游戏失败\n");
			free(snake->body_coor);
			snake->body_coor = NULL;
			exit(0);
		}
	}

	//判定撞墙
	if ((((snake->body_coor[0][0] + move_x < FACE_SZ - 2) && (snake->body_coor[0][0] + move_x >= 0)) &&
		((snake->body_coor[0][1] + move_y >= 0) && (snake->body_coor[0][1] + move_y < FACE_SZ - 2))) == 0)
	{
		free(snake->body_coor);
		snake->body_coor = NULL;
		printf("游戏失败\n");
		exit(0);
	}

	if(snake->body_coor[0][0] + move_x != snake->body_coor[1][0] || snake->body_coor[0][1] + move_y != snake->body_coor[1][1] && move != ' ')
	{
		for (i = 0; i < snake->len; i++)
		{
			if (i != snake->len - 1)
			{
				if (i != 0)
				{
					int x1 = snake->body_coor[i][0];
					int y1 = snake->body_coor[i][1];
					snake->body_coor[i][0] = x;
					snake->body_coor[i][1] = y;
					x = x1;
					y = y1;
				}		
				else
				{
					x = snake->body_coor[i][0];
					y = snake->body_coor[i][1];
					snake->body_coor[i][0] = snake->body_coor[i][0] + move_x;
					snake->body_coor[i][1] = snake->body_coor[i][1] + move_y;
				}
			}
			else
			{
				int x1 = snake->body_coor[i][0];
				int y1 = snake->body_coor[i][1];
				snake->body_coor[i][0] = x;
				snake->body_coor[i][1] = y;

				face[x1][y1] = ' ';
			}
		}
		for (i = 0; i < snake->len; i++)
		{
			if (i != 0)
			{
				face[snake->body_coor[i][0]][snake->body_coor[i][1]] = '*';
			}
			else
			{
				face[snake->body_coor[i][0]][snake->body_coor[i][1]] = '#';
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

char legal_move(Snake* snake, char move)
{
	int move_x = 0;
	int move_y = 0;
	if (move == 'w' || move == 'W')
	{
		move_x = -1;
		move_y = 0;
	}
	else if (move == 'a' || move == 'A')
	{
		move_x = 0;
		move_y = -1;
	}
	else if (move == 's' || move == 'S')
	{
		move_x = 1;
		move_y = 0;
	}
	else  if (move == 'd' || move == 'D')
	{
		move_x = 0;
		move_y = 1;
	}
	if (snake->body_coor[0][0] + move_x == snake->body_coor[1][0] && snake->body_coor[0][1] + move_y == snake->body_coor[1][1])
		return 'q';
	else
	{
		return move;
	}
}

void sanke_longer(Snake* snake, char face[][FACE_SZ - 2])//蛇吃到食物后身体变长的实现
{
	if (face[boom_x][boom_y] != '1')
	{
		int** tmp = (int**)realloc(snake->body_coor, (sizeof(int*) * (snake->len + 1)));
		if (tmp == NULL)
		{
			perror("longer_realloc");
			return;
		}
		tmp[snake->len] = (int*)malloc(sizeof(int) * 2);
		if (tmp[snake->len] == NULL)
		{
			perror("longer_malloc");
			return;
		}
		snake->body_coor = tmp;
		tmp = NULL;
		if (snake->body_coor[snake->len - 2][0] - snake->body_coor[snake->len - 1][0] == 0)
		{
			if (snake->body_coor[snake->len - 2][1] - snake->body_coor[snake->len - 1][1] == -1)
			{
				snake->body_coor[snake->len][0] = snake->body_coor[snake->len - 1][0];
				snake->body_coor[snake->len][1] = snake->body_coor[snake->len - 1][1] + 1;
				face[snake->body_coor[snake->len][0]][snake->body_coor[snake->len][1]] = '*';
			}
			else
			{
				snake->body_coor[snake->len][0] = snake->body_coor[snake->len - 1][0];
				snake->body_coor[snake->len][1] = snake->body_coor[snake->len - 1][1] - 1;
				face[snake->body_coor[snake->len][0]][snake->body_coor[snake->len][1]] = '*';
			}
		}
		else if(snake->body_coor[snake->len - 2][0] - snake->body_coor[snake->len - 1][0] == -1)
		{
			snake->body_coor[snake->len][0] = snake->body_coor[snake->len - 1][0] + 1;
			snake->body_coor[snake->len][1] = snake->body_coor[snake->len - 1][1];
			face[snake->body_coor[snake->len][0]][snake->body_coor[snake->len][1]] = '*';
		}
		else
		{
			snake->body_coor[snake->len][0] = snake->body_coor[snake->len - 1][0] - 1;
			snake->body_coor[snake->len][1] = snake->body_coor[snake->len - 1][1];
			face[snake->body_coor[snake->len][0]][snake->body_coor[snake->len][1]] = '*';
		}
		snake->len++;
		set_food(face);
	}
}

void game_play(Snake* snake, char face[][FACE_SZ - 2])
{
	int ret = 0;
	char decide = 0;
	set_food(face);
	game_interface(face, FACE_SZ);
	char move = 'w';
	while (1)
	{
		printf("输入合法方向键以启动游戏\n");
		move = _getch();
		decide = move;
		ret = move;
		if (move != 'a')
			break;
		else
		{
			printf("方向不合法\n");
		}
	}
	while (1)
	{
		if (_kbhit() == 0)
		{
				if (ret != 0)
				{
					ret = snake_move(snake, face, move);
					sanke_longer(snake, face);
					decide = move;
					system("cls");
					game_interface(face, FACE_SZ);
					Sleep(TIME_REFRESH);//时间控制刷新
				}
		}
		else
		{
			move = _getch();
			fflush(stdin);
			if(move !=decide)
			{
				ret = snake_move(snake, face, move);
				//system("cls");
				//sanke_longer(snake, face);
				//game_interface(face, FACE_SZ);
				if (move == ' ')//游戏暂停
				{
					if (game_pause() == 0)
					{
						free(snake->body_coor);
						snake->body_coor = NULL;
						exit(0);
					}
					//ret = snake_move(snake, face, move);
					while (1)
					{
						printf("输入合法方向键以启动游戏\n");
						move = _getch();
						if (legal_move(snake, move) == 'q')
						{
							printf("输入违法\n");
						}
						else
						{
							break;
						}
					}
					//ret = snake_move(snake, face, move);
					//sanke_longer(snake, face);
					//system("cls");
					//game_interface(face, FACE_SZ);
					//Sleep(TIME_REFRESH);//时间控制刷新
				}
				if (ret == 0)
				{
					move = decide;
					ret = 1;
				}
				else
				{
					ret = snake_move(snake, face, move);
					sanke_longer(snake, face);
					fflush(stdin);
					system("cls");
					game_interface(face, FACE_SZ);
					Sleep(TIME_REFRESH);//时间控制刷新
				}
			}
		}

	}
}

//void menu3()
//{
//	printf("*****************************\n");
//	printf("**** 1. Continue the game****\n");
//	printf("**** 2. Exit the game    ****\n");
//	printf("*****************************\n");
//}
//
//
//int game_pause()
//{
//	int input = 0;
//	do
//	{
//		menu3();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			return 1;
//			break;
//		case 0:
//			return 0;
//			break;
//		default:
//			printf("输入有误请重新输入\n");
//			break;
//		}
//	} while (input);
//}
//
//char snake_move(Snake* snake, char face[][FACE_SZ - 2], char move)
//{
//	int x = 0;
//	int y = 0;
//	int i = 0;
//	int move_x = 0;
//	int move_y = 0;
//	if (move == 'w' || move == 'W')
//	{
//		move_x = -1;
//		move_y = 0;
//	}
//	else if (move == 'a' || move == 'A')
//	{
//		move_x = 0;
//		move_y = -1;
//	}	
//	else if (move == 's' || move == 'S')
//	{
//		move_x = 1;
//		move_y = 0;
//	}	
//	else if (move == 'd' || move == 'D')
//	{
//		move_x = 0;
//		move_y = 1;
//	}
//	else
//	{
//		//游戏暂停函数
//		if (game_pause())
//		{
//			return ' ';
//		}
//		{
//			exit(0);
//		}
//	}
//
//
//	
//	//判定撞墙
//	if ((((snake->body_coor[0][0] + move_x < FACE_SZ - 2) && (snake->body_coor[0][0] + move_x >= 0)) &&
//		((snake->body_coor[0][1] + move_y >= 0) && (snake->body_coor[0][1] + move_y < FACE_SZ - 2))) == 0)
//	{
//		printf("游戏失败\n");
//		exit(0);
//	}
//
//	for (i = 0; i < snake->len; i++)
//	{
//		if (i != snake->len - 1)
//		{
//			if (i != 0)
//			{
//				x = snake->body_coor[i][0];
//				y = snake->body_coor[i][1];
//				snake->body_coor[i][0] = snake->body_coor[i - 1][0];
//				snake->body_coor[i][1] = snake->body_coor[i - 1][1];
//			}
//			else
//			{
//				x = snake->body_coor[i][0];
//				y = snake->body_coor[i][1];
//				snake->body_coor[i][0] = snake->body_coor[i][0] + move_x;
//				snake->body_coor[i][1] = snake->body_coor[i][1] + move_y;
//			}
//		}
//		else
//		{
//			int x1 = snake->body_coor[i][0];
//			int y1 = snake->body_coor[i][1];
//			snake->body_coor[i][0] = x;
//			snake->body_coor[i][1] = y;
//
//			face[x1][y1] = ' ';
//		}
//	}
//	for (i = 0; i < snake->len; i++)
//	{
//		if (i != 0)
//		{
//			face[snake->body_coor[i][0]][snake->body_coor[i][1]] = '*';
//		}
//		else
//		{
//			face[snake->body_coor[i][0]][snake->body_coor[i][1]] = '#';
//		}
//	}
//	return move;
//}
//
////移动合法
//char legal_move(Snake* snake, char move)
//{
//	int move_x = 0;
//	int move_y = 0;
//	if (move == 'w' || move == 'W')
//	{
//		move_x = -1;
//		move_y = 0;
//	}
//	else if (move == 'a' || move == 'A')
//	{
//		move_x = 0;
//		move_y = -1;
//	}
//	else if (move == 's' || move == 'S')
//	{
//		move_x = 1;
//		move_y = 0;
//	}
//	else  if(move == 'd' || move == 'D')
//	{
//		move_x = 0;
//		move_y = 1;
//	}
//	if (snake->body_coor[0][0] + move_x == snake->body_coor[1][0] && snake->body_coor[0][1] + move_y == snake->body_coor[1][1])
//		return 'q';
//	else
//	{
//		return move;
//	}
//}
//
//void game_play(Snake* snake, char face[][FACE_SZ - 2])
//{
//	char ret = 0;
//	char decide = 0;
//	set_food(face);
//	game_interface(face, FACE_SZ);
//	char move = 'w';
//	while(1)
//	{
//		printf("输入合法方向键以启动游戏\n");
//		move = _getch();
//		decide = move;
//		ret = move;
//		if (move != 'a')
//			break;
//		else
//		{
//			printf("方向不合法\n");
//		}
//	}
//	while (1)
//	{
//		if (_kbhit() == 0)
//		{
//				ret = snake_move(snake, face, move);
//				fflush(stdin);
//				decide = move;
//				system("cls");
//				game_interface(face, FACE_SZ);
//				Sleep(1000);
//		}
//		else
//		{
//			move = _getch();
//			ret = legal_move(snake, move);
//			if (move == ' ')
//			{
//				snake_move(snake, face, move);
//				fflush(stdin);
//				printf("输入合法方向键以启动游戏\n");
//				move = _getch();
//				snake_move(snake, face, move);
//				fflush(stdin);
//				system("cls");
//				game_interface(face, FACE_SZ);
//			}
//			if (ret == 'q')
//			{
//				move = decide;
//				ret = snake_move(snake, face, move);
//				fflush(stdin);
//				system("cls");
//				game_interface(face, FACE_SZ);
//				Sleep(1000);
//			}
//			ret = snake_move(snake, face, move);
//			fflush(stdin);
//			system("cls");
//			game_interface(face, FACE_SZ);
//			Sleep(1000);
//		}
//		
//	}
//}
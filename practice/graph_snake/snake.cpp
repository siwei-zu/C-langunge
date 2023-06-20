#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"

//全局变量食物坐标
int food_x;
int food_y;

void InitSnake(Sk* sk)
{
	int** tmp = (int**)malloc(sizeof(int*) * 2);
	if (tmp == NULL)
	{
		perror("init malloc fail");
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		tmp[i] = (int*)malloc(sizeof(int) * 2);
		if (tmp[i] == NULL)
		{
			perror("init malloc fail");
			return;
		}
	}
	sk->position = tmp;
	sk->len = 2;


	sk->position[0][0] = 12;
	sk->position[0][1] = 11;//头部

	sk->position[1][0] = 11;
	sk->position[1][1] = 11;//身体

	////试验
	//sk->position[0][0] = 0;
	//sk->position[0][1] = 2;//头部

	//sk->position[1][0] = 0;
	//sk->position[1][1] = 1;//身体
}

void InitInterface()
{
	setfillcolor(BLACK);
	//四周边框
	solidrectangle(0, 0, 640, 10);
	solidrectangle(0, 0, 10, 480);
	solidrectangle(630, 0, 640, 480);
	solidrectangle(0, 470, 640, 480);

	//中间竖线
	solidrectangle(470, 0, 480, 480);
	//横线
	solidrectangle(470, 200, 640, 210);

	//设置方格
	int i = 0;
	setlinecolor(BLACK);
	//for (i = 10; i < 470; i+=20)//22*22
	//{
	//	line(i, 10, i, 470);
	//	line(10, i, 470, i);
	//}

}



void FllushSnakeBody(Sk* sk)
{
	for (int i = 0; i < sk->len; i++)
	{
		int x = sk->position[i][0];
		int y = sk->position[i][1];
		clearrectangle(CoToPh(x) + 1, CoToPh(y) + 1, CoToPh(x) + 19, CoToPh(y) + 19);
		if (i != 0)
		{
			//蛇身
			setfillcolor(GREEN);
			solidroundrect(CoToPh(x)+1, CoToPh(y)+1, CoToPh(x) + 19, CoToPh(y) + 19, 5, 5);
		}
		else
		{
			//蛇头
			setfillcolor(RED);
			solidroundrect(CoToPh(x)+1, CoToPh(y)+1, CoToPh(x) + 19, CoToPh(y) + 19, 5, 5);
		}
	}
}

int CoToPh(int x)
{
	return x * 20 + 10;
}

int PhToCo(int x)
{
	return (x - 10) / 20;
}

void SetFood()
{
	while(1)
	{
		int x = rand() % 22 + 1;
		int y = rand() % 22 + 1;
		////试验
		//int x = 1;
		//int y = 2;
		if (getpixel(CoToPh(x) + 5, CoToPh(y) + 5) == WHITE)
		{
			//食物
			setfillcolor(BLACK);
			solidroundrect(CoToPh(x)+1, CoToPh(y)+1, CoToPh(x) + 19, CoToPh(y) + 19, 5, 5);
			////    试验
			//solidroundrect(CoToPh(x) + 1, CoToPh(y) + 1, CoToPh(x) + 19, CoToPh(y) + 19, 5, 5);
			food_x = CoToPh(x);
			food_y = CoToPh(y);
			break;
		}
	}
}

void SnakeMove(Sk* sk, char move)
{
	int move_x = 0;
	int move_y = 0;

	if (move == 'w' || 'W' == move)
	{
		move_x = 0;
		move_y = -1;
	}
	else if (move == 'a' || 'A' == move)
	{
		move_x = -1;
		move_y = 0;
	}
	else if (move == 's' || 'S' == move)
	{
		move_x = 0;
		move_y = 1;
	}
	else if(move == 'd' || 'D' == move)
	{
		move_x = 1;
		move_y = 0;
	}

	int tail_x = sk->position[sk->len - 1][0];
	int tail_y = sk->position[sk->len - 1][1];
	clearroundrect(CoToPh(tail_x) + 1, CoToPh(tail_y) + 1, CoToPh(tail_x) + 19, CoToPh(tail_y) + 19, 5, 5);

	int i = 0;
	for (i = sk->len - 1; i >= 0; i--)
	{
		if(i != 0)
		{
			sk->position[i][0] = sk->position[i - 1][0];
			sk->position[i][1] = sk->position[i - 1][1];
		}
		else
		{
			sk->position[i][0] = sk->position[i][0] + move_x;
			sk->position[i][1] = sk->position[i][1] + move_y;
		}
	}
}

bool LegalMove(Sk* sk, char move, int decide)
{
	int move_x = 0;
	int move_y = 0;

	if (move == 'w' || 'W' == move)
	{
		move_x = 0;
		move_y = -1;
	}
	else if (move == 'a' || 'A' == move)
	{
		move_x = -1;
		move_y = 0;
	}
	else if (move == 's' || 'S' == move)
	{
		move_x = 0;
		move_y = 1;
	}
	else if (move == 'd' || 'D' == move)
	{
		move_x = 1;
		move_y = 0;
	}

	int x0 = sk->position[0][0];
	int y0 = sk->position[0][1];
	int x1 = sk->position[1][0];
	int y1 = sk->position[1][1];
	if ((x0 + move_x == x1 && y0 + move_y == y1))
	{
		return false;
	}
	if (x0 + move_x == x1 + move_x * 2 && y0 + move_y == y1 + move_y * 2 && decide == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ExistFood()
{
	if (getpixel(food_x + 5, food_y + 5) != BLACK)
	{
		return true;
	}
	return false;
}

void ExtendSnake(Sk* sk, char trace)
{
	//蛇身体加长开辟内存存储坐标
	int** tmp = (int**)realloc(sk->position, (sizeof(int*) * (sk->len + 1)));
	if (tmp == NULL)
	{
		perror("longer_realloc");
		return;
	}
	tmp[sk->len] = (int*)malloc(sizeof(int) * 2);
	if (tmp[sk->len] == NULL)
	{
		perror("longer_malloc");
		return;
	}
	sk->position = tmp;
	tmp = NULL;

	int tail0x = sk->position[sk->len - 1][0];
	int tail0y = sk->position[sk->len - 1][1];
	int tail1x = sk->position[sk->len - 2][0];
	int tail1y = sk->position[sk->len - 2][1];

	sk->len++;

	//蛇身增长的控制台尾坐标
	int target_x = 0;
	int target_y = 0;

	if (tail1x - tail0x == 0)
	{
		if (tail1y - tail0y == -1)
		{
			target_x = tail0x;
			target_y = tail0y + 1;
		}
		else
		{
			target_x = tail0x;
			target_y = tail0y - 1;
		}
	}
	else if (tail1x - tail0x == -1)
	{
		target_x = tail0x + 1;
		target_y = tail0y;
	}
	else
	{
		target_x = tail0x - 1;
		target_y = tail0y;
	}

	//尾部新增节点转换后的图坐标
	int convert_x = CoToPh(target_x);
	int convert_y = CoToPh(target_y);

	if ((convert_x >= 10 && convert_x <= 450) && (convert_y >= 10 && convert_y <= 450))
	{
		sk->position[sk->len - 1][0] = target_x;
		sk->position[sk->len - 1][1] = target_y;
	}
	else//处理蛇的尾部增长时直接加长会溢出边界的情况
	{
		if (tail1x - tail0x == 0)
		{
			if (trace == 'a')
			{
				sk->position[sk->len - 1][0] = sk->position[sk->len - 2][0] + 1;
				sk->position[sk->len - 1][1] = sk->position[sk->len - 2][1];
			}
			else if (trace == 'd')
			{
				sk->position[sk->len - 1][0] = sk->position[sk->len - 2][0] - 1;
				sk->position[sk->len - 1][1] = sk->position[sk->len - 2][1];
			}
		}
		else if (tail1y - tail0y == 0)
		{
			if (trace == 'w')
			{
				sk->position[sk->len - 1][0] = sk->position[sk->len - 2][0];
				sk->position[sk->len - 1][1] = sk->position[sk->len - 2][1] + 1;
			}
			else if (trace == 's')
			{
				sk->position[sk->len - 1][0] = sk->position[sk->len - 2][0];
				sk->position[sk->len - 1][1] = sk->position[sk->len - 2][1] - 1;
			}
		}
	}
}

bool judge_fail(Sk* sk, char move)
{
	int move_x = 0;
	int move_y = 0;

	if (move == 'w' || 'W' == move)
	{
		move_x = 0;
		move_y = -1;
	}
	else if (move == 'a' || 'A' == move)
	{
		move_x = -1;
		move_y = 0;
	}
	else if (move == 's' || 'S' == move)
	{
		move_x = 0;
		move_y = 1;
	}
	else if (move == 'd' || 'D' == move)
	{
		move_x = 1;
		move_y = 0;
	}

	int i = 0;
	int x0 = sk->position[0][0];
	int y0 = sk->position[0][1];

	//1.接触到身体失败
	for (i = 1; i < sk->len; i++)
	{
		int x = sk->position[i][0];
		int y = sk->position[i][1];
		if (x0 + move_x == x && y0 + move_y == y)
			return true;
	}
	//2.触碰到边界失败
	int convert_x = CoToPh(x0 + move_x);
	int convert_y = CoToPh(y0 + move_y);
	if (((convert_x >= 10 && convert_x <= 450) && (convert_y >= 10 && convert_y <= 450)) == 0)
		return true;

	return false;
}

void Destroy(Sk* sk)
{
	for (int i = 0; i < sk->len; i++)
	{
		free(sk->position[i]);
	}
	free(sk->position);
	closegraph();
}

void ClearRT()
{
	clearrectangle(480, 10, 630, 200);
}

void AgainBotton()
{
	ClearRT();

	setfillcolor(YELLOW);
	setlinestyle(PS_SOLID, 3);
	//开始游戏
	fillroundrect(505, 45, 605, 85, 10, 10);
	//退出游戏
	fillroundrect(505, 125, 605, 165, 10, 10);

	char text1[] = "开始游戏";
	char text2[] = "退出游戏";

	int text1_w = textwidth(text1);
	int text1_h = textheight(text1);
	int text2_w = textwidth(text2);
	int text2_h = textheight(text2);

	settextcolor(BLACK);
	outtextxy(505 + (100 - text1_w) / 2, 45 + (40 - text1_h) / 2, text1);
	outtextxy(505 + (100 - text2_w) / 2, 125 + (40 - text2_h) / 2, text2);
}

void ContinueBotton()
{
	ClearRT();

	setfillcolor(YELLOW);
	setlinestyle(PS_SOLID, 3);
	//开始游戏
	fillroundrect(505, 45, 605, 85, 10, 10);
	//退出游戏
	fillroundrect(505, 125, 605, 165, 10, 10);

	char text1[] = "继续游戏";
	char text2[] = "退出游戏";

	int text1_w = textwidth(text1);
	int text1_h = textheight(text1);
	int text2_w = textwidth(text2);
	int text2_h = textheight(text2);

	settextcolor(BLACK);
	outtextxy(505 + (100 - text1_w) / 2, 45 + (40 - text1_h) / 2, text1);
	outtextxy(505 + (100 - text2_w) / 2, 125 + (40 - text2_h) / 2, text2);
}

void GameGuideline()
{
	IMAGE img;
	loadimage(&img, "./gedline.jpg", 150, 0);
	putimage(480, 260, &img);
}

void StartGame()
{
	ClearRT();
	settextcolor(BLACK);
	outtextxy(480,10,"请按合法方向键");
	outtextxy(480, 40, "以启动游戏");
}
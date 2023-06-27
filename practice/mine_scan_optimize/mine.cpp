#define _CRT_SECURE_NO_WARNINGS 1
#include "mine.h"

void InitStartInterface()
{
	setfillcolor(RGB(247, 255, 10));//按钮颜色
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 10);
	fillroundrect(250, 20, 650, 220, 50, 50);
	fillroundrect(250, 260, 650, 460, 50, 50);

	char start[] = "开始游戏";
	char end[] = "退出游戏";

	settextcolor(BLACK);//文字颜色
	settextstyle(60, 30, "");

	int start_w = textwidth(start);
	int start_h = textheight(start);
	int end_w = textwidth(end);
	int end_h = textheight(end);

	outtextxy(250 + (400 - start_w) / 2, 20 + (200 - start_h) / 2, start);
	outtextxy(250 + (400 - end_w) / 2, 260 + (200 - end_h) / 2, end);

}

void StartDiscolour()
{
	setfillcolor(RGB(215, 222, 10));//按钮变化后的颜色
	fillroundrect(250, 20, 650, 220, 50, 50);

	char start[] = "开始游戏";

	settextcolor(BLACK);
	settextstyle(60, 30, "");

	int start_w = textwidth(start);
	int start_h = textheight(start);

	outtextxy(250 + (400 - start_w) / 2, 20 + (200 - start_h) / 2, start);
}

void EndDiscolour()
{
	setfillcolor(RGB(215, 222, 10));//按钮变化后的颜色
	fillroundrect(250, 260, 650, 460, 50, 50);

	char end[] = "退出游戏";

	settextcolor(BLACK);
	settextstyle(60, 30, "");

	int end_w = textwidth(end);
	int end_h = textheight(end);

	outtextxy(250 + (400 - end_w) / 2, 260 + (200 - end_h) / 2, end);
}

void InitDifficultyOptFace()
{
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 10);

	setfillcolor(RGB(32, 255, 46));//简单难度按钮颜色
	fillroundrect(100, 190, 300, 290, 50, 50);
	char simple[] = "简单(9*9)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int simple_w = textwidth(simple);
	int simple_h = textheight(simple);

	outtextxy(100 + (200 - simple_w) / 2, 190 + (100 - simple_h) / 2, simple);


	setfillcolor(RGB(255, 180, 62));//困难难度按钮颜色
	fillroundrect(350, 190, 550, 290, 50, 50);
	char difficulty[] = "困难(16*16)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int difficulty_w = textwidth(difficulty);
	int difficulty_h = textheight(difficulty);

	outtextxy(350 + (200 - difficulty_w) / 2, 190 + (100 - difficulty_h) / 2, difficulty);

	setfillcolor(RGB(255, 28, 5));//地狱难度按钮颜色
	fillroundrect(600, 190, 800, 290, 50, 50);
	char hell[] = "地狱(30*16)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int hell_w = textwidth(hell);
	int hell_h = textheight(hell);

	outtextxy(600 + (200 - hell_w) / 2, 190 + (100 - hell_h) / 2, hell);
}

void SimpleDiscolour()
{
	setfillcolor(RGB(6, 179, 9));//简单按钮变化后的颜色
	fillroundrect(100, 190, 300, 290, 50, 50);

	char simple[] = "简单(9*9)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int simple_w = textwidth(simple);
	int simple_h = textheight(simple);

	outtextxy(100 + (200 - simple_w) / 2, 190 + (100 - simple_h) / 2, simple);
}

void difficultyDiscolour()
{
	setfillcolor(RGB(194, 137, 47));//困难按钮变化后的颜色
	fillroundrect(350, 190, 550, 290, 50, 50);

	char difficulty[] = "困难(16*16)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int difficulty_w = textwidth(difficulty);
	int difficulty_h = textheight(difficulty);

	outtextxy(350 + (200 - difficulty_w) / 2, 190 + (100 - difficulty_h) / 2, difficulty);
}

void HellDiscolour()
{
	setfillcolor(RGB(168, 48, 11));//地狱按钮变化后的颜色
	fillroundrect(600, 190, 800, 290, 50, 50);

	char hell[] = "地狱(30*16)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int hell_w = textwidth(hell);
	int hell_h = textheight(hell);

	outtextxy(600 + (200 - hell_w) / 2, 190 + (100 - hell_h) / 2, hell);
}

void GoBack()
{
	char back[] = "若要返回上一级请按：Esc(选择难度后未开始游戏也可返回上一级)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int back_w = textwidth(back);
	int back_h = textheight(back);

	outtextxy((900 - back_w) / 2, 350, back);
}

void SetMineSimple(char** simpleboard)
{
	int mine = 10;
	while (mine)
	{
		int x = rand() % 9;
		int y = rand() % 9;
		if (simpleboard[y][x] == '0')
		{
			simpleboard[y][x] = '*';
			mine--;
		}
	}
}

void InitSimpleBoard()
{
	//划线
	//setlinecolor(BLACK);
	//setlinestyle(PS_SOLID, 1);

	int i = 0;
	//for (i = 275; i < 675; i+=50)
	//{
	//	line(i, 0, i, 450);
	//}
	//for (i = 50; i < 450; i+=50)
	//{
	//	line(225, i, 675, i);
	//}

	//画方块
	setfillcolor(RGB(93, 78, 255));//方块颜色
	for (i = 0; i < 450; i += 50)//列
	{
		for (int j = 225; j < 675; j += 50)//行
		{
			solidroundrect(j + 1, i + 1, j + 49, i + 49, 5, 5);
		}
		Sleep(100);
	}
}

void InitSimpleBoard_()
{
	//划线
//setlinecolor(BLACK);
//setlinestyle(PS_SOLID, 1);

	int i = 0;
	//for (i = 275; i < 675; i+=50)
	//{
	//	line(i, 0, i, 450);
	//}
	//for (i = 50; i < 450; i+=50)
	//{
	//	line(225, i, 675, i);
	//}

	//画方块
	for (i = 0; i < 450; i += 50)//列
	{
		for (int j = 225; j < 675; j += 50)//行
		{
			if (getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				solidroundrect(j + 1, i + 1, j + 49, i + 49, 5, 5);
			}
		}
	}
}

void SimpleBlockDiscolour(int x, int y)
{
	setfillcolor(RGB(69, 58, 191));//方块变化后的颜色
	solidroundrect(x + 1, y + 1, x + 49, y + 49, 5, 5);

	int i = 0;
	for (i = 0; i < 450; i += 50)//列
	{
		for (int j = 225; j < 675; j += 50)//行
		{
			if ((j != x || i != y) && getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				setfillcolor(RGB(93, 78, 255));//方块颜色
				solidroundrect(j + 1, i + 1, j + 49, i + 49, 5, 5);
			}
		}
	}
}

void GameFail()
{
	setbkcolor(WHITE);
	cleardevice();//清屏

	char fail[] = "游戏失败!!!";
	settextcolor(BLACK);
	settextstyle(50, 25, "");

	int fail_w = textwidth(fail);
	int fail_h = textheight(fail);

	outtextxy((900 - fail_w) / 2, (480 - fail_h) / 2, fail);
}

void GameWin()
{
	setbkcolor(WHITE);
	cleardevice();//清屏

	char fail[] = "游戏胜利!!!";
	settextcolor(BLACK);
	settextstyle(50, 25, "");

	int fail_w = textwidth(fail);
	int fail_h = textheight(fail);

	outtextxy((900 - fail_w) / 2, (480 - fail_h) / 2, fail);
}

const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };


int minesimple = 71;
char simpleboard_[9][9] = { 0 };
void ScanSimple(char** simpleboard, int x, int y)
{
	minesimple--;
	if (minesimple == 0)
	{
		GameWin();
		Sleep(1000);
		for (int i = 0; i < 16; i++)
		{
			free(simpleboard[i]);
		}
		free(simpleboard);
		exit(0);
	}
	int i = 0;
	int count = 0;
	int mx = 0;
	int my = 0;
	for (i = 0; i < 8; i++)//循环判断输入坐标的旁边八个位置有无雷
	{
		my = y + dy[i], mx = x + dx[i];
		if ((mx >= 0 && mx < 9) && (my >= 0 && my < 9) && simpleboard[my][mx] == '*')
		{
			count++;
		}
	}
	if (count == 0)
	{
		setfillcolor(WHITE);
		setbkcolor(WHITE);
		clearroundrect(x * 50 + 225 + 1, y * 50 + 1, x * 50 + 225 + 49, y * 50 + 49, 5, 5);
		solidroundrect(x * 50 + 225 + 1, y * 50 + 1, x * 50 + 225 + 49, y * 50 + 49, 5, 5);
		Sleep(50);
		for (i = 0; i < 8; i++)
		{
			my = y + dy[i];
			mx = x + dx[i];
			if ((mx >= 0 && mx < 9) && (my >= 0 && my < 9) && simpleboard_[my][mx] != '#')//标记起作用
			{
				simpleboard_[y][x] = '#';//同样是做标记的作用，
				ScanSimple(simpleboard, mx, my);//进入递归对当前坐标旁边八个位置进行扫描
			}
		}
	}
	else//有雷的处理，改成#是为了在后续递归中当扫描这个点时不需要再次扫描，防止死递归
	{
		simpleboard_[y][x] = '#';
		simpleboard[y][x] = count + 48;
		setfillcolor(WHITE);
		setbkcolor(WHITE);
		clearroundrect(x * 50 + 225 + 1, y * 50 + 1, x * 50 + 225 + 49, y * 50 + 49, 5, 5);
		solidroundrect(x * 50 + 225 + 1, y * 50 + 1, x * 50 + 225 + 49, y * 50 + 49, 5, 5);
		char number = simpleboard[y][x];
		settextcolor(BLACK);
		settextstyle(20, 10, "");

		int number_w = textwidth(number);
		int number_h = textheight(number);

		outtextxy(x * 50 + 225 + (50 - number_w) / 2, y * 50 + (50 - number_h) / 2, number);
		Sleep(50);
	}
}





void SetMineDifficulty(char** difficultyboard)
{
	int mine = 40;
	while (mine)
	{
		int x = rand() % 16;
		int y = rand() % 16;
		if (difficultyboard[y][x] == '0')
		{
			difficultyboard[y][x] = '*';
			mine--;
		}
	}
}

void InitDifficultyBoard()
{
	//划线
//setlinecolor(BLACK);
//setlinestyle(PS_SOLID, 1);

	int i = 0;
	//for (i = 275; i < 675; i+=50)
	//{
	//	line(i, 0, i, 450);
	//}
	//for (i = 50; i < 450; i+=50)
	//{
	//	line(225, i, 675, i);
	//}

	//画方块
	setfillcolor(RGB(93, 78, 255));//方块颜色
	for (i = 0; i < 480; i += 40)//列
	{
		for (int j = 210; j < 690; j += 40)//行
		{
			solidroundrect(j + 1, i + 1, j + 39, i + 39, 5, 5);
		}
		Sleep(100);
	}
}

void DifficultyBlockDiscolour(int x, int y)
{
	setfillcolor(RGB(69, 58, 191));//方块变化后的颜色
	solidroundrect(x + 1, y + 1, x + 39, y + 39, 5, 5);

	int i = 0;
	for (i = 0; i < 480; i += 40)//列
	{
		for (int j = 210; j < 690; j += 40)//行
		{
			if ((j != x || i != y) && getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				setfillcolor(RGB(93, 78, 255));//方块颜色
				solidroundrect(j + 1, i + 1, j + 39, i + 39, 5, 5);
			}
		}
	}
}


void InitDifficultyBoard_()
{
	//划线
//setlinecolor(BLACK);
//setlinestyle(PS_SOLID, 1);

	int i = 0;
	//for (i = 275; i < 675; i+=50)
	//{
	//	line(i, 0, i, 450);
	//}
	//for (i = 50; i < 450; i+=50)
	//{
	//	line(225, i, 675, i);
	//}

	//画方块
	setfillcolor(RGB(93, 78, 255));//方块颜色
	for (i = 0; i < 480; i += 40)//列
	{
		for (int j = 210; j < 690; j += 40)//行
		{
			if (getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				solidroundrect(j + 1, i + 1, j + 39, i + 39, 5, 5);
			}
		}
	}
}


int minedifficulty = 256 - 40;
char difficultyboard_[16][16] = { 0 };
void ScanDifficulty(char** difficultyboard, int x, int y)
{
	minedifficulty--;
	if (minedifficulty == 0)
	{
		GameWin();
		Sleep(1000);
		for (int i = 0; i < 16; i++)
		{
			free(difficultyboard[i]);
		}
		free(difficultyboard);
		exit(0);
	}
	int i = 0;
	int count = 0;
	int mx = 0;
	int my = 0;
	for (i = 0; i < 8; i++)//循环判断输入坐标的旁边八个位置有无雷
	{
		my = y + dy[i], mx = x + dx[i];
		if ((mx >= 0 && mx < 16) && (my >= 0 && my < 16) && difficultyboard[my][mx] == '*')
		{
			count++;
		}
	}
	if (count == 0)
	{
		setfillcolor(WHITE);
		setbkcolor(WHITE);
		clearroundrect(x * 40 + 210 + 1, y * 40 + 1, x * 40 + 210 + 39, y * 40 + 39, 5, 5);
		solidroundrect(x * 40 + 210 + 1, y * 40 + 1, x * 40 + 210 + 39, y * 40 + 39, 5, 5);
		Sleep(50);
		for (i = 0; i < 8; i++)
		{
			my = y + dy[i];
			mx = x + dx[i];
			if ((mx >= 0 && mx < 16) && (my >= 0 && my < 16) && difficultyboard_[my][mx] != '#')//标记起作用
			{
				difficultyboard_[y][x] = '#';//同样是做标记的作用，
				ScanDifficulty(difficultyboard, mx, my);//进入递归对当前坐标旁边八个位置进行扫描
			}
		}
	}
	else//有雷的处理，改成#是为了在后续递归中当扫描这个点时不需要再次扫描，防止死递归
	{
		difficultyboard_[y][x] = '#';
		difficultyboard[y][x] = count + 48;
		setfillcolor(WHITE);
		setbkcolor(WHITE);
		clearroundrect(x * 40 + 210 + 1, y * 40 + 1, x * 40 + 210 + 39, y * 40 + 39, 5, 5);
		solidroundrect(x * 40 + 210 + 1, y * 40 + 1, x * 40 + 210 + 39, y * 40 + 39, 5, 5);
		char number = difficultyboard[y][x];
		settextcolor(BLACK);
		settextstyle(20, 10, "");

		int number_w = textwidth(number);
		int number_h = textheight(number);

		outtextxy(x * 40 + 210 + (40 - number_w) / 2, y * 40 + (40 - number_h) / 2, number);
		Sleep(50);
	}
}


void SetMineHell(char** hellboard)
{
	int mine = 99;
	while (mine)
	{
		int x = rand() % 30;
		int y = rand() % 16;
		if (hellboard[y][x] == '0')
		{
			hellboard[y][x] = '*';
			mine--;
		}
	}
}

void InitHellBoard()
{
	//划线
//setlinecolor(BLACK);
//setlinestyle(PS_SOLID, 1);

	int i = 0;
	//for (i = 275; i < 675; i+=50)
	//{
	//	line(i, 0, i, 450);
	//}
	//for (i = 50; i < 450; i+=50)
	//{
	//	line(225, i, 675, i);
	//}

	//画方块
	setfillcolor(RGB(93, 78, 255));//方块颜色
	for (i = 0; i < 480; i += 30)//列
	{
		for (int j = 0; j < 900; j += 30)//行
		{
			solidroundrect(j + 1, i + 1, j + 29, i + 29, 5, 5);
		}
		Sleep(100);
	}
}

void HellBlockDiscolour(int x, int y)
{
	setfillcolor(RGB(69, 58, 191));//方块变化后的颜色
	solidroundrect(x + 1, y + 1, x + 29, y + 29, 5, 5);

	int i = 0;
	for (i = 0; i < 480; i += 30)//列
	{
		for (int j = 0; j < 900; j += 30)//行
		{
			if ((j != x || i != y) && getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				setfillcolor(RGB(93, 78, 255));//方块颜色
				solidroundrect(j + 1, i + 1, j + 29, i + 29, 5, 5);
			}
		}
	}
}


void InitHellBoard_()
{
	//划线
//setlinecolor(BLACK);
//setlinestyle(PS_SOLID, 1);

	int i = 0;
	//for (i = 275; i < 675; i+=50)
	//{
	//	line(i, 0, i, 450);
	//}
	//for (i = 50; i < 450; i+=50)
	//{
	//	line(225, i, 675, i);
	//}

	//画方块
	setfillcolor(RGB(93, 78, 255));//方块颜色
	for (i = 0; i < 480; i += 30)//列
	{
		for (int j = 0; j < 900; j += 30)//行
		{
			if (getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				solidroundrect(j + 1, i + 1, j + 29, i + 29, 5, 5);
			}
		}
	}
}


int minehell = 16 * 30 - 99;
char hellboard_[16][30] = { 0 };
void ScanHell(char** hellboard, int x, int y)
{
	minehell--;
	if (minehell == 0)
	{
		GameWin();
		Sleep(1000);
		for (int i = 0; i < 16; i++)
		{
			free(hellboard[i]);
		}
		free(hellboard);
		exit(0);
	}
	int i = 0;
	int count = 0;
	int mx = 0;
	int my = 0;
	for (i = 0; i < 8; i++)//循环判断输入坐标的旁边八个位置有无雷
	{
		my = y + dy[i], mx = x + dx[i];
		if ((mx >= 0 && mx < 30) && (my >= 0 && my < 16) && hellboard[my][mx] == '*')
		{
			count++;
		}
	}
	if (count == 0)
	{
		setfillcolor(WHITE);
		setbkcolor(WHITE);
		clearroundrect(x * 30 + 1, y * 30 + 1, x * 30 + 29, y * 30 + 29, 5, 5);
		solidroundrect(x * 30 + 1, y * 30 + 1, x * 30 + 29, y * 30 + 29, 5, 5);
		Sleep(50);
		for (i = 0; i < 8; i++)
		{
			my = y + dy[i];
			mx = x + dx[i];
			if ((mx >= 0 && mx < 32) && (my >= 0 && my < 16) && hellboard_[my][mx] != '#')//标记起作用
			{
				hellboard_[y][x] = '#';//同样是做标记的作用，
				ScanHell(hellboard, mx, my);//进入递归对当前坐标旁边八个位置进行扫描
			}
		}
	}
	else//有雷的处理，改成#是为了在后续递归中当扫描这个点时不需要再次扫描，防止死递归
	{
		hellboard_[y][x] = '#';
		hellboard[y][x] = count + 48;
		setfillcolor(WHITE);
		setbkcolor(WHITE);
		clearroundrect(x * 30 + 1, y * 30 + 1, x * 30 + 29, y * 30 + 29, 5, 5);
		solidroundrect(x * 30 + 1, y * 30 + 1, x * 30 + 29, y * 30 + 29, 5, 5);
		char number = hellboard[y][x];
		settextcolor(BLACK);
		settextstyle(20, 10, "");

		int number_w = textwidth(number);
		int number_h = textheight(number);

		outtextxy(x * 30 + (30 - number_w) / 2, y * 30 + (30 - number_h) / 2, number);
		Sleep(50);
	}
}
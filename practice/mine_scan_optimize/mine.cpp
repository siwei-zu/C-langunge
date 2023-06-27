#define _CRT_SECURE_NO_WARNINGS 1
#include "mine.h"

void InitStartInterface()
{
	setfillcolor(RGB(247, 255, 10));//��ť��ɫ
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 10);
	fillroundrect(250, 20, 650, 220, 50, 50);
	fillroundrect(250, 260, 650, 460, 50, 50);

	char start[] = "��ʼ��Ϸ";
	char end[] = "�˳���Ϸ";

	settextcolor(BLACK);//������ɫ
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
	setfillcolor(RGB(215, 222, 10));//��ť�仯�����ɫ
	fillroundrect(250, 20, 650, 220, 50, 50);

	char start[] = "��ʼ��Ϸ";

	settextcolor(BLACK);
	settextstyle(60, 30, "");

	int start_w = textwidth(start);
	int start_h = textheight(start);

	outtextxy(250 + (400 - start_w) / 2, 20 + (200 - start_h) / 2, start);
}

void EndDiscolour()
{
	setfillcolor(RGB(215, 222, 10));//��ť�仯�����ɫ
	fillroundrect(250, 260, 650, 460, 50, 50);

	char end[] = "�˳���Ϸ";

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

	setfillcolor(RGB(32, 255, 46));//���ѶȰ�ť��ɫ
	fillroundrect(100, 190, 300, 290, 50, 50);
	char simple[] = "��(9*9)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int simple_w = textwidth(simple);
	int simple_h = textheight(simple);

	outtextxy(100 + (200 - simple_w) / 2, 190 + (100 - simple_h) / 2, simple);


	setfillcolor(RGB(255, 180, 62));//�����ѶȰ�ť��ɫ
	fillroundrect(350, 190, 550, 290, 50, 50);
	char difficulty[] = "����(16*16)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int difficulty_w = textwidth(difficulty);
	int difficulty_h = textheight(difficulty);

	outtextxy(350 + (200 - difficulty_w) / 2, 190 + (100 - difficulty_h) / 2, difficulty);

	setfillcolor(RGB(255, 28, 5));//�����ѶȰ�ť��ɫ
	fillroundrect(600, 190, 800, 290, 50, 50);
	char hell[] = "����(30*16)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int hell_w = textwidth(hell);
	int hell_h = textheight(hell);

	outtextxy(600 + (200 - hell_w) / 2, 190 + (100 - hell_h) / 2, hell);
}

void SimpleDiscolour()
{
	setfillcolor(RGB(6, 179, 9));//�򵥰�ť�仯�����ɫ
	fillroundrect(100, 190, 300, 290, 50, 50);

	char simple[] = "��(9*9)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int simple_w = textwidth(simple);
	int simple_h = textheight(simple);

	outtextxy(100 + (200 - simple_w) / 2, 190 + (100 - simple_h) / 2, simple);
}

void difficultyDiscolour()
{
	setfillcolor(RGB(194, 137, 47));//���Ѱ�ť�仯�����ɫ
	fillroundrect(350, 190, 550, 290, 50, 50);

	char difficulty[] = "����(16*16)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int difficulty_w = textwidth(difficulty);
	int difficulty_h = textheight(difficulty);

	outtextxy(350 + (200 - difficulty_w) / 2, 190 + (100 - difficulty_h) / 2, difficulty);
}

void HellDiscolour()
{
	setfillcolor(RGB(168, 48, 11));//������ť�仯�����ɫ
	fillroundrect(600, 190, 800, 290, 50, 50);

	char hell[] = "����(30*16)";
	settextcolor(BLACK);
	settextstyle(30, 15, "");

	int hell_w = textwidth(hell);
	int hell_h = textheight(hell);

	outtextxy(600 + (200 - hell_w) / 2, 190 + (100 - hell_h) / 2, hell);
}

void GoBack()
{
	char back[] = "��Ҫ������һ���밴��Esc(ѡ���ѶȺ�δ��ʼ��ϷҲ�ɷ�����һ��)";
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
	//����
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

	//������
	setfillcolor(RGB(93, 78, 255));//������ɫ
	for (i = 0; i < 450; i += 50)//��
	{
		for (int j = 225; j < 675; j += 50)//��
		{
			solidroundrect(j + 1, i + 1, j + 49, i + 49, 5, 5);
		}
		Sleep(100);
	}
}

void InitSimpleBoard_()
{
	//����
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

	//������
	for (i = 0; i < 450; i += 50)//��
	{
		for (int j = 225; j < 675; j += 50)//��
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
	setfillcolor(RGB(69, 58, 191));//����仯�����ɫ
	solidroundrect(x + 1, y + 1, x + 49, y + 49, 5, 5);

	int i = 0;
	for (i = 0; i < 450; i += 50)//��
	{
		for (int j = 225; j < 675; j += 50)//��
		{
			if ((j != x || i != y) && getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				setfillcolor(RGB(93, 78, 255));//������ɫ
				solidroundrect(j + 1, i + 1, j + 49, i + 49, 5, 5);
			}
		}
	}
}

void GameFail()
{
	setbkcolor(WHITE);
	cleardevice();//����

	char fail[] = "��Ϸʧ��!!!";
	settextcolor(BLACK);
	settextstyle(50, 25, "");

	int fail_w = textwidth(fail);
	int fail_h = textheight(fail);

	outtextxy((900 - fail_w) / 2, (480 - fail_h) / 2, fail);
}

void GameWin()
{
	setbkcolor(WHITE);
	cleardevice();//����

	char fail[] = "��Ϸʤ��!!!";
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
	for (i = 0; i < 8; i++)//ѭ���ж�����������Ա߰˸�λ��������
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
			if ((mx >= 0 && mx < 9) && (my >= 0 && my < 9) && simpleboard_[my][mx] != '#')//���������
			{
				simpleboard_[y][x] = '#';//ͬ��������ǵ����ã�
				ScanSimple(simpleboard, mx, my);//����ݹ�Ե�ǰ�����Ա߰˸�λ�ý���ɨ��
			}
		}
	}
	else//���׵Ĵ����ĳ�#��Ϊ���ں����ݹ��е�ɨ�������ʱ����Ҫ�ٴ�ɨ�裬��ֹ���ݹ�
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
	//����
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

	//������
	setfillcolor(RGB(93, 78, 255));//������ɫ
	for (i = 0; i < 480; i += 40)//��
	{
		for (int j = 210; j < 690; j += 40)//��
		{
			solidroundrect(j + 1, i + 1, j + 39, i + 39, 5, 5);
		}
		Sleep(100);
	}
}

void DifficultyBlockDiscolour(int x, int y)
{
	setfillcolor(RGB(69, 58, 191));//����仯�����ɫ
	solidroundrect(x + 1, y + 1, x + 39, y + 39, 5, 5);

	int i = 0;
	for (i = 0; i < 480; i += 40)//��
	{
		for (int j = 210; j < 690; j += 40)//��
		{
			if ((j != x || i != y) && getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				setfillcolor(RGB(93, 78, 255));//������ɫ
				solidroundrect(j + 1, i + 1, j + 39, i + 39, 5, 5);
			}
		}
	}
}


void InitDifficultyBoard_()
{
	//����
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

	//������
	setfillcolor(RGB(93, 78, 255));//������ɫ
	for (i = 0; i < 480; i += 40)//��
	{
		for (int j = 210; j < 690; j += 40)//��
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
	for (i = 0; i < 8; i++)//ѭ���ж�����������Ա߰˸�λ��������
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
			if ((mx >= 0 && mx < 16) && (my >= 0 && my < 16) && difficultyboard_[my][mx] != '#')//���������
			{
				difficultyboard_[y][x] = '#';//ͬ��������ǵ����ã�
				ScanDifficulty(difficultyboard, mx, my);//����ݹ�Ե�ǰ�����Ա߰˸�λ�ý���ɨ��
			}
		}
	}
	else//���׵Ĵ����ĳ�#��Ϊ���ں����ݹ��е�ɨ�������ʱ����Ҫ�ٴ�ɨ�裬��ֹ���ݹ�
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
	//����
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

	//������
	setfillcolor(RGB(93, 78, 255));//������ɫ
	for (i = 0; i < 480; i += 30)//��
	{
		for (int j = 0; j < 900; j += 30)//��
		{
			solidroundrect(j + 1, i + 1, j + 29, i + 29, 5, 5);
		}
		Sleep(100);
	}
}

void HellBlockDiscolour(int x, int y)
{
	setfillcolor(RGB(69, 58, 191));//����仯�����ɫ
	solidroundrect(x + 1, y + 1, x + 29, y + 29, 5, 5);

	int i = 0;
	for (i = 0; i < 480; i += 30)//��
	{
		for (int j = 0; j < 900; j += 30)//��
		{
			if ((j != x || i != y) && getpixel(j + 5, i + 5) == RGB(69, 58, 191))
			{
				setfillcolor(RGB(93, 78, 255));//������ɫ
				solidroundrect(j + 1, i + 1, j + 29, i + 29, 5, 5);
			}
		}
	}
}


void InitHellBoard_()
{
	//����
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

	//������
	setfillcolor(RGB(93, 78, 255));//������ɫ
	for (i = 0; i < 480; i += 30)//��
	{
		for (int j = 0; j < 900; j += 30)//��
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
	for (i = 0; i < 8; i++)//ѭ���ж�����������Ա߰˸�λ��������
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
			if ((mx >= 0 && mx < 32) && (my >= 0 && my < 16) && hellboard_[my][mx] != '#')//���������
			{
				hellboard_[y][x] = '#';//ͬ��������ǵ����ã�
				ScanHell(hellboard, mx, my);//����ݹ�Ե�ǰ�����Ա߰˸�λ�ý���ɨ��
			}
		}
	}
	else//���׵Ĵ����ĳ�#��Ϊ���ں����ݹ��е�ɨ�������ʱ����Ҫ�ٴ�ɨ�裬��ֹ���ݹ�
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
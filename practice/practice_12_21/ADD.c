#define _CRT_SECURE_NO_WARNINGS 1
#include "ADD.h"
int Add(int x, int y)
{
	int z = x + y;
	return z;
}

void chushihua(char arr[HANG][LIE], int hang, int lie)
{
	int i = 0;
	for (i = 0; i < hang; i++)
	{
		int j = 0;
		for (j = 0; j < lie; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void chushihua2(char arr1[HANG][LIE], int hang, int lie)
{
	int i = 0;
	for (i = 0; i < hang; i++)
	{

		int j = 0;
		for (j = 0; j < lie; j++)
		{
			if (j == lie - 1)
			{
				printf(" %c ", arr1[i][j]);
				break;
			}
			printf(" %c |", arr1[i][j]);

		}
		printf("\n");
		for (j = 0; j < lie; j++)
		{
			if (i == hang - 1)
			{
				break;
			}
			if (j == lie - 1)
			{
				printf("---");
				break;
			}
			printf("---|");
		}
		printf("\n");
	}
}

void neirong(char arr[HANG][LIE], int hang, int lie)
{
	char ch1 = '*';
	char ch2 = '/';
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	system("cls");//这个是清屏命令，使运行起来更简洁
	chushihua2(arr, hang, lie);
	while (1)
	{
		scanf("%d%d", &a, &b);
		arr[a][b] = ch1;
		system("cls");
		if ((arr[0][0] == '*' && arr[0][1] == '*' && arr[0][2] == '*') || (arr[1][0] == '*' && arr[1][1] == '*' && arr[1][2] == '*') || (arr[2][0] == '*' && arr[2][1] == '*' && arr[2][2] == '*') || (arr[0][0] == '*' && arr[1][0] == '*' && arr[2][0] == '*') || (arr[0][1] == '*' && arr[1][1] == '*' && arr[2][1] == '*') || (arr[0][2] == '*' && arr[1][2] == '*' && arr[2][2] == '*') || (arr[0][0] == '*' && arr[1][1] == '*' && arr[2][2] == '*') || (arr[0][2] == '*' && arr[1][1] == '*' && arr[2][0] == '*'))
		{
			chushihua2(arr, hang, lie);
			printf("恭喜你，获得本次游戏胜利！\n");
			return 0;
		}
		chushihua2(arr, hang, lie);
		while (1)//制造死循环使电脑能够实现下棋
		{
			srand((unsigned)time(NULL));//引用了时间戳产生随机数
			c = (rand() % 10) % 2;
			d = (rand() % 10) % 2;
			if ((c != a) && (c < 3) && (d != b) && (d < 3) && (arr[c][d] == ' '))
			{
				arr[c][d] = ch2;
				system("cls");
				chushihua2(arr, hang, lie);
				break;
			}
			if ((arr[0][0] == '/' && arr[0][1] == '/' && arr[0][2] == '/') || (arr[1][0] == '/' && arr[1][1] == '/' && arr[1][2] == '/') || (arr[2][0] == '/' && arr[2][1] == '/' && arr[2][2] == '/') || (arr[0][0] == '/' && arr[1][0] == '/' && arr[2][0] == '/') || (arr[0][1] == '/' && arr[1][1] == '/' && arr[2][1] == '/') || (arr[0][2] == '/' && arr[1][2] == '/' && arr[2][2] == '/') || (arr[0][0] == '/' && arr[1][1] == '/' && arr[2][2] == '/') || (arr[0][2] == '/' && arr[1][1] == '/' && arr[2][0] == '/'))
			{
				chushihua(arr, hang, lie);
				printf("不要灰心，再接再励。\n");
				return 0;
			}
		}
	}
}

void neirong1(char arr[HANG][LIE], char arr1[HANG][LIE], int hang, int lie)
{

	while (1)
	{
		int i = 0;
		int j = 0;
		int count = 0;
	kaishi:
		printf("请输入对应坐标：");
		scanf("%d%d", &i, &j);
		if ((i > 9 || i < 0) && (j > 9 || j < 0))
		{
			printf("输入错误\n");
			goto kaishi;
		}
		if (arr[i][j] == '*')
		{
			printf("踩到地雷了，游戏失败！！\n");
			return 0;
		}
		int a, b;
		switch (i)
		{
		case 0:
			switch (j)
			{
			case 0:
				if (arr[i + 1][j + 1] == '*')
					count++;
				if (arr[i + 1][j] == '*')
					count++;
				if (arr[i][j + 1] == '*')
					count++;
				break;
			case 9:
				if (arr[i + 1][j] == '*')
					count++;
				if (arr[i][j - 1] == '*')
					count++;
				if (arr[i + 1][j - 1] == '*')
					count++;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				if (arr[i][j - 1] == '*')
					count++;
				if (arr[i][j + 1] == '*')
					count++;
				if (arr[i + 1][j - 1] == '*')
					count++;
				if (arr[i + 1][j] == '*')
					count++;
				if (arr[i + 1][j + 1] == '*')
					count++;
				break;
			}
			break;
		case 9:
			switch (j)
			{
			case 0:
				if (arr[i - 1][j + 1] == '*')
					count++;
				if (arr[i - 1][j] == '*')
					count++;
				if (arr[i][j + 1] == '*')
					count++;
				break;
			case 9:
				if (arr[i - 1][j] == '*')
					count++;
				if (arr[i - 1][j - 1] == '*')
					count++;
				if (arr[i][j - 1] == '*')
					count++;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				if (arr[i][j - 1] == '*')
					count++;
				if (arr[i][j + 1] == '*')
					count++;
				if (arr[i - 1][j - 1] == '*')
					count++;
				if (arr[i - 1][j] == '*')
					count++;
				if (arr[i - 1][j + 1] == '*')
					count++;
				break;
			}
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			switch (j)
			{
			case 0:
				if (arr[i - 1][j] == '*')
					count++;
				if (arr[i - 1][j + 1] == '*')
					count++;
				if (arr[i][j + 1] == '*')
					count++;
				if (arr[i + 1][j + 1] == '*')
					count++;
				if (arr[i + 1][j] == '*')
					count++;
				break;
			case 9:
				if (arr[i - 1][j] == '*')
					count++;
				if (arr[i - 1][j - 1] == '*')
					count++;
				if (arr[i][j - 1] == '*')
					count++;
				if (arr[i + 1][j - 1] == '*')
					count++;
				if (arr[i + 1][j] == '*')
					count++;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				for (a = i - 1, b = j - 1; b <= j + 1; b++)
				{
					if (arr[a][b] == '*')
						count++;
				}
				if (arr[i][j - 1] == '*')
					count++;
				if (arr[i][j + 1] == '*')
					count++;
				for (a = i + 1, b = j - 1; b <= j + 1; b++)
				{
					if (arr[a][b] == '*')
						count++;
				}
				break;
			}
		}
		arr1[i][j] = count += 48;
		int count1 = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (arr[i][j] >= '0' && arr[i][j] <= '9')
					count1++;
			}
		}
		if (count1 == 85)
		{
			printf("恭喜你，扫除完所有的雷，游戏胜利！！\n");
			return 0;
		}
		system("cls");
		chushihua2(arr1, hang, lie);
	}
}

void chushihua3(char arr[HANG][LIE], int hang, int lie)
{
	int count = 0;
	int i, j;
	srand((unsigned)time(NULL));
	while (1)
	{
		i = rand() % 10;
		j = rand() % 10;//制造随机数，实现随机埋雷。
		if (arr[i][j] == ' ')
		{
			arr[i][j] = '*';
			count++;
		}
		if (count == 16)
			break;
	}
	system("cls");//清屏看起来更美观。
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int i = 1;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %-2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for(i=0;i<10;i++)
//	{
//		scanf("%d", arr + i);
//	}
//	int max = arr[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("这组数据中的最大值是:>%d\n", max);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	float sum = 0.0f;
//	int i = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		int n = i;
//		if (n % 2 == 0)
//			n = -n;
//		sum += 1.0 / n;
//	}
//	printf("%.4f\n", sum);
//	return 0;
//}

//#include <stdio.h>
//
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		int n = i;
//		while (n)
//		{
//			if (n % 10 == 9)
//				count++;
//			n /= 10;
//		}
//	}
//	printf("1~100中9的个数为:>%d\n", count);
//	return 0;
//}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
	printf("*****************\n");
	printf("**   1. play   **\n");
	printf("**   2. exit   **\n");
	printf("*****************\n");
}

void game()
{
	int n = 0;
	int x = 0;
	x = rand() % 100 + 1;
	while (1)
	{
		printf("请输入你猜到的数字:>");
		scanf("%d", &n);
		if (n > x)
			printf("猜大了\n");
		else if (n < x)
			printf("猜小了\n");
		else
		{
			printf("恭喜你，猜对了！！\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1: {
			game();
			break;
		}
		case 0: {
			printf("退出游戏\n");
			break;
		}
		default: {
			printf("输入有误\n");
			break;
		}
			
		}
	} while (input);
	return 0;
}
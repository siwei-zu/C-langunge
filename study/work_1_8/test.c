#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int tmp;
//	printf("请输入需要排序的三个数字:>");
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i = 100;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		int decide = 0;
//		for (j = 2; j <= (int)sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				decide = 1;
//				break;
//			}
//		}
//		if (decide == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((0 == i % 4 && i % 100 != 0) || (0 == i % 400))
//			printf("%d ", i);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入要操作的两个数:>");
//	scanf("%d%d", &a, &b);
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	int c = 0;
//	while (a % b != 0)
//	{
//		c = b;
//		b = a % b;
//		a = c;
//	}
//	printf("%d\n", b);
//	return 0;
//}
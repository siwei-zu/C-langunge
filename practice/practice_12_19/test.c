#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void maopao(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j;
//		int juld = 1;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//				juld = 0;
//			}
//		}
//		if (juld == 1)
//		{
//			break;
//		}
//	}
//}
//
//int main()//将数组里面的无序数字转换成有序数字。
//{
//	int i;
//	int arr[10] = { 2,2,4,1,6,8,8,9,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	maopao(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//void kuaile(int n)
//{
//	int result = 0;
//	int a = 0;
//	if (n == 1)
//	{
//		printf("true\n");
//		return 0;
//	}
//	while (result != EOF)//使循环能够持续进行
//	{
//		a = 0;//将a和result初始化成0
//		result = 0;
//		while (n >= 1)
//		{
//			a = n % 10;
//			result += a * a;
//			n = n / 10;
//		}
//		if (result == 16 || result == 4 || result == 37 || result == 58 || result == 89 || result == 145 || result == 42 || result == 20)
//		{
//			printf("false\n");//这儿的意思是如果落尽这几个数字里面则必不可能是快乐数。
//			break;
//		}
//		else if (result == 1)
//		{
//			printf("true\n");
//			break;
//		}
//		n = result;
//	}
//}
//
//int main()//快乐（循环方法）。
//{
//	int n;
//	scanf("%d", &n);
//	kuaile(n);
//	return 0;
//}
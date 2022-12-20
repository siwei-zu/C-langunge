#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//int main()
//{
//	int a[5][5];
//	int(*p)[4] = a[0];
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}


//int main()//»ØÎÄÊý¡£
//{
//	int x;
//	scanf("%d", &x);
//	int left = 0;
//	int right;
//	int i;
//	int arr[2 ^ 32 - 1] = { 0 };
//	if (x < 0 || x % 10 == 0)
//	{
//		printf("false");
//		return 0;
//	}
//	else
//	{
//		for (i = 0; x >= 1; i++)
//		{
//			int k = x % 10;
//			arr[i] = k;
//			x = x / 10;
//		}
//		right = i - 1;
//		while (left <= right)
//		{
//			if (arr[left] == arr[right])
//			{
//				left++;
//				right--;
//			}
//			else
//				printf("false");
//
//		}
//		printf("true");
//		return 0;
//	}
//}
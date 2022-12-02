#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX_P 30001

int main()
{
	int n, x;
	int arr[MAX_P] = { 0 };
	scanf("%d%d", &n, &x);
	int i = 0;
	int count = 0;
	int b[31];//输入书的价格
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		count += b[i];
	}
	int num = (count - x);//这里用总价格减去包邮条件后正好可以转化为01背包问题
	if (num > 30001)//这里分情况讨论是因为我使用的编译器好像用不了太大的数组，要不然会栈溢出，索性就过大的数据省略个位数
	{
		num /= 10;
		for (i = 1; i <= n; i++)
		{
			int j = 0;
			for (j = num; j >= 0; j--)
			{
				if (b[i] / 10 > j)
					arr[j] = 0;
				else
				{
					arr[j] = arr[j - b[i] / 10] + b[i] / 10 > arr[j] ? arr[j - b[i] / 10] + b[i] / 10 : arr[j];//这里用到了滚动数组和动态规划的思想
				}
			}
		}
		printf("%d", count - arr[num] * 10);
	}
	else if (num <= 30000)//另一个判断，内容一样
	{
		for (i = 1; i <= n; i++)
		{
			int j = 0;
			for (j = num; j >= 0; j--)
			{
				if (b[i] <= j)
					//	arr[j] = arr[j];
					//else
				{
					arr[j] = arr[j - b[i]] + b[i] > arr[j] ? arr[j - b[i]] + b[i] : arr[j];
				}
			}
		}
		printf("%d", count - arr[num]);
	}
	return 0;
}
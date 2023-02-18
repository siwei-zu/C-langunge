#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void bubble_sort(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		int flag = 0;
		for (j = 0; j < sz - 1; j++)//冒泡排序过程中，有可能没有进行完过程就已经排好序
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			break;
		}
		for (j = 0; j < i + 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()//冒泡排序
{
	int arr[] = {1,3,5,7,9,0,2,4,6,8};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubble_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

#include <stdio.h>

int leap_year(int n)
{
	if ((0 == n % 4 && n % 100 != 0) || (0 == n % 400))
		return 1;
	else
		return 0;
}

int main()//判断闰年
{
	int n = 0;
	scanf("%d", &n);
	if (leap_year(n) == 1)
		printf("%d年是闰年\n", n);
	else
		printf("%d年不是闰年\n", n);
	return 0;
}

#include <stdio.h>

float my_pow(int n, int k)//增加了k可能为负数的可能
{
	if (k == 0)
		return 1;
	else if (k > 0)
	{
		return n * my_pow(n, k - 1);
	}
	else
	{
		return 1.0 / my_pow(n, -k);
	}
}

int main()//n的k次幂
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	printf("%.2f", my_pow(n, k));
	return 0;
}

double* convertTemperature(double celsius, int* returnSize) {
    *returnSize = 2;
    double* ans = (double*)malloc(sizeof(double) * 2);
    ans[0] = celsius + 273.15;
    ans[1] = celsius * 1.80 + 32.00;
    return ans;
}
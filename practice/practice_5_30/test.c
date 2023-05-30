#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				a[end] = tmp;
				end--;
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;
	}
}

int main()
{
	int a[] = { 2,5,4,6,9,7,1,3,0,8 };
	int n = 10;
	InsertSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
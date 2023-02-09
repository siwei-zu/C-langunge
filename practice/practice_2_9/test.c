#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[] = { 0,1,2,4,5,6,8 };
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int i = 0;
	for (i = 1; i <= 7; i++)
	{
		int j = 0;
		for (j = 0; j < 7 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 6; i >= 1; i--)
	{
		int j = 0;
		for (j = 0; j < 7 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
	int i = 0;
	for (i = 1; i <= 100000; i++)
	{
		int n = i;
		int number = 0;
		while (n)
		{
			n /= 10;
			number++;
		}
		int j = 0;
		n = i;
		int sum = 0;
		for (j = 0; j < number; j++)
		{
			sum += pow(n % 10, number);
			n /= 10;
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int a = 0;
	scanf("%d", &a);
	int n = a;
	int i = 0;
	int sum = 0;
	for (i = 0; i < 5; i++)
	{
		sum += a;
		printf("%d ", a);
		a = a * 10 + n;
	}
	printf("%d", sum);
	return 0;
}
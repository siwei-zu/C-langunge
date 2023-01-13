#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//void multiplication_table(int n)
//{
//	int i=0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%-2d*%-2d=%-3d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	multiplication_table(n);
//	return 0;
//}
//#include <stdio.h>
//
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前：a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("交换后：a=%d,b=%d\n", a, b);
//	return 0;
//}
//#include <stdio.h>
//void leap_year(int n)
//{
//	if ((0 == n % 4 && n % 100 != 0) || (0 == n % 400))
//		printf("%d年是闰年", n);
//	else
//		printf("%d年不是闰年", n);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	leap_year(n);
//	return 0;
//}

//#include <stdio.h>
//
//int prime_number(int n)
//{
//	int i = 2;
//	for (i = 2; i < (int)sqrt(n); i += 2)
//	{
//		if (n % i == 0);
//		return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (prime_number(n))
//		printf("%d是素数\n", n);
//	else
//		printf("%d不是素数\n",n);
//	return 0;
//}
#include <stdio.h>
int main()
{
	int i = 0;
	int n = 3;
	int count = 0;
	for (i = 0; i <= n - 1; i++)
	{
		int j = 0;
		for (j = n; j > i; j--)
			count++;
	}
	printf("%d", count);
	return 0;
}
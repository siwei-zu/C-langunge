#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int my_compare(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int max = my_compare(a, b);
	printf("%max=%d", max);
	return 0;
}

#include <stdio.h>


int my_compare(int x, int y)
{
	return x > y ? x : y;
}


int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int max = my_compare(a, b);
	printf("%max=%d", max);
	return 0;
}

#include <stdio.h>


int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) { // 注意 while 处理多个 case
		if (a > b)
		{
			printf("%d>%d\n", a, b);
		}
		else if (a < b)
			printf("%d<%d\n", a, b);
		else
			printf("%d=%d\n", a, b);


	}
	return 0;
}

#include <stdio.h>


int main() {
	int a[10];
	int i = 0;
	while (scanf("%d", &a[i++]) != EOF);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#include <stdio.h>


int main() {
	int a[10];
	int i = 0;
	while (scanf("%d", &a[i++]) != EOF);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#include <stdio.h>


int main() {
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		while (n)
		{
			printf("*");
			n--;
		}
		printf("\n");
	}
}
#include <stdio.h>


int main() {
	int n = 0;
	float degree = 0;
	while (scanf("%d", &n) != EOF)
	{
		degree += n;
	}
	printf("%.1f\n", degree / 5.0);
	return 0;
}
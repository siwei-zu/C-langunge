#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>//求出最大字符串
#include <string.h>
int main()
{
	char a[5][100];
	char(*p)[100] = &a;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%s", *(a + i));
	}
	char(*max)[100]=&a;
	for (i = 0; i<5;i++)
	{
		if(strcmp(*(p + i), *(max))>=0)
			max=p+i;
	}
	printf("%s\n", max);
	return 0;
}
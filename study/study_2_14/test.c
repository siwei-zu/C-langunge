#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int decide_sys()
{
	int a = 1;
	return *(char*)&a;
}

int main()
{
	if (decide_sys() == 1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}
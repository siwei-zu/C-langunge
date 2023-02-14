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
		printf("Ð¡¶Ë\n");
	else
		printf("´ó¶Ë\n");
	return 0;
}
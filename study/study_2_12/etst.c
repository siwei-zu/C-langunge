#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (i = 9; i >= -16; i--)
	{
		arr[i] = 1;
		printf("hehe\n");
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int main()
{
	//COORD pos;
	//pos.X = 0;//设置x为5
	//pos.Y = 0;//设置y为5
	//printf("**********");
	//Sleep(1000);
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	//printf("\b");
	//printf("#");
	//return 0;
	char s[10] = "";
	scanf("%s", s);
	int a = 0;
	fflush(stdin);
	//rewind(stdin);
	scanf("%d", &a);
	return 0;
}
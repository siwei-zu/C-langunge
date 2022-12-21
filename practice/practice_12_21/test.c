#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include "ADD.h"
void menu()
{
	printf("**************************\n");
	printf("****  1.play  0.exit  ****\n");
	printf("**************************\n");

}
void game()
{
	char arr[HANG][LIE] = { 0 };
	char arr1[HANG][LIE] = { 0 };
	chushihua(arr1, HANG, LIE);//填充,这是表面的arr1，防止开始玩就知道雷在哪里。
	chushihua(arr, HANG, LIE);//填充，这是幕后的arr（雷就被埋到这里面）
	chushihua3(arr, HANG, LIE);//布雷，这里的雷埋在arr里面
	chushihua2(arr1, HANG, LIE);//棋盘
	neirong1(arr, arr1, HANG, LIE);
}
int main()//扫雷
{
	int input = 0;
	do//用do..while循环实现游戏
	{
		menu();//打印游戏开始界面
		printf("请选择：");
		scanf("%d", &input);
		switch (input)//这里实现选择
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入！！");
		}


	} while (input);//这里对应了上面的选择“1”为真“0”为假自动跳出循环
	return 0;
}
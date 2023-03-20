#define _CRT_SECURE_NO_WARNINGS 1
#pragma pack()//修改默认对齐数的预处理指令。括号里有数字将默认对齐数调整为那个数字，没有的话将回复环境对齐数
#include <stdio.h>
#include <stddef.h>
struct S
{
	char a;
	int c;
};

int main()
{
	printf("%d\n", offsetof(struct S, a));//计算偏移量的大小的函数，使用头文件<stddef.h>
	printf("%d\n", offsetof(struct S, c));
	return 0;
}

//1.结构体的第一个成员永远都放在0偏移处
//2.从第二个成员开始，以后每个成员都要对齐到某个对齐数的整数倍处
//这个对齐数是：成员自身大小和默认对其数的较小值
//VS 环境下，默认对齐数是8
//gcc环境下，没有默认对齐数
//没有默认对齐数时，对齐数就是自身成员大小
//3.当成员全部存进去之后
//结构体的总大小必须是所有成员对齐数中最大对齐数的整数倍，如果不够则浪费空间
//4.如果嵌套了结构体的情况，嵌套的结构体对齐到自身最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍

enum Sex
{	//枚举的可能取值，默认是从0开始，递增1的
	MALE,
	FEMALE,
	SECRET	
};

int main()
{
	return 0;
}
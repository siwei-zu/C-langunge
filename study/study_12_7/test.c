#define _CRT_SECURE_NO_WARNINGS 1

//在三十二位机器上有三十二根地址线，每根地址线有着高电平和低电平代表着1和0，
//那三十二根地址线组成的二进制序列总共有2^32种不同的组合，每个组合代表不同的地址。
//地址等又占据内存的各个单元，每个内存单元的大小是一个字节
//
#include <stdio.h>
//void test()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if ((*p) == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//}
//
////1.大端存储模式，是指数据的低位保存在内存的高地址中，而数据的高位保存在内存的低地址中。
////2.小段储存模式，是指数据的高位保存在内存的低地址中，而数据的高位保存在内存的高地址中。
//int main()
//{
//	test();
//	return 0;
//}

//关于static的再认识
//1.static修饰局部变量时：会改变局部变量的生命周期，使局部变量从存储到栈区，转移到静态区。
//2.static修饰全局变量和函数时，会改变两者的作用域，使得两者只能在自己的文件里使用，而无法通过 extern来在别的文件生命使用。

//#define定义宏

#define MAX(x,y) ((x)>(y))?(x):(y)
#define SUM(x,y) ((x)+(y))

int main()
{
	int a = 10;
	int b = 20;
	int max = MAX(a, b);
	int sum = SUM(a, b);
	printf("max=%d\n", max);
	printf("sum=%d\n", sum);
	return 0;
}
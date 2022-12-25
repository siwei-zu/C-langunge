#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()//数出一个整型中二进制位中一的个数。
{
	int num = 0;
	int count = 0;
	int i = 0;
	scanf("%d", &num);
	//第二种优化算法

	while (num)
	{
		count++;
		num = num & (num - 1);
	}

	//第一种方法
	//while (count<32&&num!=0)
	//{
	//	if ((num & 1) == 1)
	//		count++;
	//	num >>= 1;
	//	//if ((num % 2) == 1)//有缺陷，只能计算正数。
	//	//	count++;
	//	//num /= 2;
	//}
	printf("%d", count);
	return 0;
}

int main()//不调用第三个参数实现两个整形的交换。
{
	int a = 3;
	int b = 5;
	printf("交换前：%d,%d\n", a, b);
	//普通方法
	/*int tmp = a;
	a = b;
	b = tmp;*/
	//第二种（加减法）
	/*a = a + b;
	b = a - b;
	a = a - b;*/
	//第三种（按位异或）
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("交换后：%d,%d\n", a, b);
	return 0;
}
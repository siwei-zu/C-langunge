#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int* printNumbers(int n, int* returnSize) {
    int x = n;
    int num = 1;
    while (x)
    {
        num *= 10;
        x--;
    }
    int* arr = (int*)malloc(sizeof(int) * (num - 1));
    for (x = 0; x < num; x++)
    {
        arr[x] = x + 1;
    }
    *returnSize = (num - 1);
    return arr;
}

//4.	求下面算术表达式的值（先自己分析，再试着用程序求解，比较得到的结果是否一致）。
//⑴设x = 2，a = 7，y = 4，求表达式: x + a % 3 * x + y % 2 / 4 的值
//⑵设a = 2，b = 3，x = 3.5，y = 2.5，求表达式 : (float)(a + b) / 2 + (int)x % (int)y的值
//5.	写出下面表达式运算后a的值，设原来a = 10，n = 5。设a和n已定义成整型变量（先自己分析，再试着用程序求解，比较得到的结果是否一致）。
//⑴ a += a   ⑵ a -= 2   ⑶ a *= 2 + 3   ⑷ a /= a + a   ⑸ a %= (n %= 2)   ⑹ a += a -= a *= a
//6.	输入并运行第3章例3 - 3、例3 - 6中的程序，通过输出结果理解对应的格式说明。
//7.	输入并运行第3章例3 - 8、例3 - 10中的程序，注意输入数据的格式。
//8.	设计程序，输入一个圆柱体的半径r和高h，求圆柱体的底周长c、底面积s、侧面积s1、表面积s2和体积v。

//#define PI 3.141593
//int main()
//{
//	float r, h;
//	printf("请输入圆柱体的半径和高(如果是整数，输入格式为xx.0):>");
//	scanf("%f%f", &r, &h);
//	printf("圆柱体的底周长 c=%.2f\n", 2 * PI * r);
//	printf("圆柱体的底面积 s=%.2f\n", r * PI * r);
//	printf("圆柱体的侧面积 s1=%.2f\n", 2 * PI * r*h);
//	printf("圆柱体的表面积 s2=%.2f\n", r * PI * r * 2+ 2 * PI * r * h);
//	printf("圆柱体的体积 v=%.2f\n", r * PI * r * h);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int n = 5;
//	printf("%d\n", a += a);
//	printf("%d\n", a -= 2);
//	printf("%d\n", a *= 2 + 3);
//	printf("%d\n", a /= a + a);
//	printf("%d\n", a %= (n %= 2));
//	printf("%d\n", a += a -= a *= a);
//	return 0;
//}
//int main()
//{
//	int a = 2;
//	int b = 3;
//	float x = 3.5f;
//	float y = 2.5f;
//	printf("%.1f\n", (float)(a + b) / 2 + (int)x % (int)y);
//	return 0;
//}

//int main()
//{
//	int x = 2;
//	int a = 7;
//	int y = 4;
//	printf("%d\n", x + a % 3 * x + y % 2 / 4);
//	return 0;
//}
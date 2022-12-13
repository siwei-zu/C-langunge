#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()//乘法口诀表
//{
//	int i = 0;
//	int hangshu = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (hangshu = 1; hangshu <= i; hangshu++)
//		{
//			printf("%d*%d=%-2d ", i, hangshu, i * hangshu);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int count = 0;
//int arr[2 ^ 31 - 1] = { 0 };
//void kuaile(int x)
//{
//    if (x > 9)
//    {
//        kuaile(x / 10);
//        count++;
//        arr[count] = x % 10;
//    }
//    else
//    {
//        return *arr = x;
//    }
//}
//int main()//快乐数递归
//{
//    int n;
//    int i;
//    int sum = 0;
//    scanf("%d", &n);
//be:
//    kuaile(n);
//    for (i = 0; i <= count; i++)
//    {
//        sum += arr[i] * arr[i];
//    }
//    if (sum == 1)
//    {
//        printf("true\n");
//    }
//    else if (sum == 4 || sum == 16 || sum == 37 || sum == 58 || sum == 89 || sum == 145 || sum == 20)
//        printf("false\n");
//    else
//    {
//        n = sum;
//        sum = 0;
//        count = 0;
//        goto be;
//    }
//    return 0;
//}

//hannuo(int n, char A, char B, char C)
//{
//	static int count = 1;
//	if (n == 1)
//	{
//		printf("第%d步：将%c移动到%c上\n", count, A, C);
//		count++;
//	}
//	else
//	{
//		hannuo(n - 1, A, C, B);
//		printf("第%d步：将%c移动到%c上\n", count, A, C);
//		count++;
//		hannuo(n - 1, B, A, C);
//
//	}
//}
////将起始柱上的 n-1 个圆盘移动到辅助柱上；
////将起始柱上遗留的 1 个圆盘移动到目标柱上；
////将辅助柱上的所有圆盘移动到目标柱上
//int main()//汉诺塔问题
//{
//	int n;
//	scanf("%d", &n);
//	hannuo(n, 'A', 'B', 'C');
//	return 0;
//}


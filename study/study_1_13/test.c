#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void print(int a)
//{
//	//if (a < 10)
//	//	printf("%d ", a);
//	//else
//	//{
//	//	print(a / 10);
//	//	printf("%d ", a % 10);
//	//}
//
//	//¼ò»¯
//	if (a > 9)
//		print(a / 10);
//	printf("%d ", a % 10);
//}
//
//int main()
//{
//	int a = 1234;
//	print(a);
//}
//
//int fb(int n)
//{
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 2;
//	else
//		return fb(n - 1) + fb(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n",fb(n));
//	return 0;
//}

//int my_strlen(char* ch)
//{
//	if ((*ch) != '\0')
//		return 1 + my_strlen(ch + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char* ch = "abcdef";
//	printf("%d\n",my_strlen(ch));
//	return 0;
//}

int jiecheng(int n)
{
	if (n != 1)
		return n * jiecheng(n - 1);
	else
		return 1;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",jiecheng(n));
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int fb(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fb(n));
//	return 0;
//}
//#include <stdio.h>
//
//int mi(int n,int k)
//{
//	if (k == 0)
//		return 1;
//	else
//		return n * mi(n, k - 1);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n,&k);
//	printf("%d", mi(n,k));
//	return 0;
//}

//#include <stdio.h>
//
//int DigitSum(int n)
//{
//	if (n > 9)
//		return n % 10 + DigitSum(n / 10);
//	else
//		return n;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", DigitSum(n));
//	return 0;
//}

//#include <stdio.h>
//
//void reverse_string(char str[], int left, int  right)//法一。
//{
//	char tmp;
//	if ((left > right))
//	{
//		return 0;
//	}
//	else
//	{
//		tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		return reverse_string(str, left + 1, right - 1);
//	}
//}
//法二
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//void reverse_string(char* str)
//{
//	char tmp = *str;
//	int len = my_strlen(str);
//	*str = str[len - 1];
//	str[len - 1] = '\0';
//	if (my_strlen(str + 1) >= 2)
//		reverse_string(str + 1);
//	str[len - 1] = tmp;
//}
//
//int main()//编写一个函数，实现字符串逆序。
//{
//	char str[] = "abcdefghijk";
//	//int sz = my_strlen(str);
//	int i = 0;
//	reverse_string(str);
//	printf("%s", str);
//	/*for (i = 0; i < sz; i++)
//	{
//		printf("%c", str[i]);
//	}*/
//	printf("\n");
//	return 0;
//}
//#include <stdio.h>
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
//#include <stdio.h>
//int jiecheng(int n)
//{
//	if (n != 1)
//		return n * jiecheng(n - 1);
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", jiecheng(n));
//	return 0;
//}

#include <stdio.h>

void print(int a)
{
	//if (a < 10)
	//	printf("%d ", a);
	//else
	//{
	//	print(a / 10);
	//	printf("%d ", a % 10);
	//}

	//简化
	if (a > 9)
		print(a / 10);
	printf("%d ", a % 10);
}

int main()
{
	int a = 1234;
	print(a);
}
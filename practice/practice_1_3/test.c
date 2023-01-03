#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int digitsum(int m)
{
	if (m < 10)
		return m;
	else
		return m % 10 + digitsum(m / 10);
}

int main()//递归实现整形每一位之和
{
	int a = 0;
	scanf("%d", &a);
	int ret = digitsum(a);
	printf("%d\n", ret);
	return 0;
}

void reverse_string(char str[], int left, int  right)//法一。
{
	char tmp;
	if ((left > right))
	{
		return 0;
	}
	else
	{
		tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		return reverse_string(str, left + 1, right - 1);
	}
}
法二
int my_strlen(char* str)
{
	if (*str != '\0')
		return 1 + my_strlen(str + 1);
	else
		return 0;
}
void reverse_string(char* str)
{
	char tmp = *str;
	int len = my_strlen(str);
	*str = str[len - 1];
	str[len - 1] = '\0';
	if (my_strlen(str + 1) >= 2)
		reverse_string(str + 1);
	str[len - 1] = tmp;
}

int main()//编写一个函数，实现字符串逆序。
{
	char str[] = "abcdefghijk";
	int sz = my_strlen(str);
	int i = 0;
	reverse_string(str);
	for (i = 0; i < sz; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}
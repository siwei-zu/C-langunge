#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()//Ӣ�ĵ��ʴ�Сдת����
{
	char ch = 0;
	int tmp = 0;
	printf("������Ҫת������ĸ��");
	while (ch != '\n')
	{
		scanf("%c", &ch);
		tmp = ch;
		if (ch >= 'A' && ch <= 'Z')
		{
			tmp += 32;
			printf("%c", tmp);
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			tmp -= 32;
			printf("%c", tmp);
		}
	}
}
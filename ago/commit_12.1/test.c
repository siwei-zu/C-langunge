#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()//英文单词大小写转换。
{
	char ch = 0;
	int tmp = 0;
	printf("请输入要转换的字母：");
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
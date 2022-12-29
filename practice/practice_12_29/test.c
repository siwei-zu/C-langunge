#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>

void hanshu(char** word1, char** word2, int sz1, int sz2)
{
	int i = 0;
	for (i = 0; i < sz1 || i < sz2; i++)
	{
		if (**word1 == **word2)
		{
			*word1 += 1;
			*word2 += 1;
		}
		else
		{
			printf("false\n");
			return 0;
		}
	}
	printf("true\n");
	return 0;
}

int main()//比较两个字符串是否相同。
{
	char word1[][3] = { "abc","def","g" };
	char word2[][3] = { "ab","cd","efg" };
	int sz1 = sizeof(word1) / sizeof(**word1);
	int sz2 = sizeof(word2) / sizeof(**word2);
	hanshu(word1[3][2], word2[3][2], sz1, sz2);
	return 0;
}
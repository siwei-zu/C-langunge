#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//打开文件
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror(fopen);
		return 1;
	}

	//对文件内容操作

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}
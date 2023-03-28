#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");//写操作，会删除原有文件的数据，然后再输入数据到文件,若指定文件不存在，会创建一个新文件
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	////fputc，将一个字符打印到文件中
//	//fputc('a', pf);
//	//fclose(pf);
//	//pf = NULL;
//
//	//pf = fopen("test.txt", "r"); //为了输入数据，打开一个已经存在的文本文件,若指定文件不存在，则会报错
//	//if (pf == NULL)
//	//{
//	//	perror("fopen");
//	//	return 1;
//	//}
//	////fgetc
//	//int ch = fgetc(pf);
//	//printf("%c", ch);
//
//	//fputs,向目标文件打印字符串
//	fputs("张三", pf);
//	fclose(pf);
//	pf = NULL;
//
//	pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//fgets
//	char arr[20];
//	fgets(arr, 20, pf);
//	printf("%s", arr);
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

struct S
{
	int a;
	char c;
	char arr[20];
};

int main()
{
	struct S s = { 100, 'a', "张三" };
	//打开文件
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//按格式化写入文件
	fprintf(pf, "%d %c %s\n", s.a, s.c, s.arr);
	fclose(pf);
	pf = NULL;

	pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//按格式化导出文件
	struct S s1 = {0};
	fscanf(pf, "%d %c %s", &s1.a, &s1.c, s1.arr);
	fprintf(stdout, "%d %c %s\n", s1.a, s1.c, s1.arr);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}
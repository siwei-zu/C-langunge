#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");//д��������ɾ��ԭ���ļ������ݣ�Ȼ�����������ݵ��ļ�,��ָ���ļ������ڣ��ᴴ��һ�����ļ�
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	////fputc����һ���ַ���ӡ���ļ���
//	//fputc('a', pf);
//	//fclose(pf);
//	//pf = NULL;
//
//	//pf = fopen("test.txt", "r"); //Ϊ���������ݣ���һ���Ѿ����ڵ��ı��ļ�,��ָ���ļ������ڣ���ᱨ��
//	//if (pf == NULL)
//	//{
//	//	perror("fopen");
//	//	return 1;
//	//}
//	////fgetc
//	//int ch = fgetc(pf);
//	//printf("%c", ch);
//
//	//fputs,��Ŀ���ļ���ӡ�ַ���
//	fputs("����", pf);
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
//	//�ر��ļ�
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
	struct S s = { 100, 'a', "����" };
	//���ļ�
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//����ʽ��д���ļ�
	fprintf(pf, "%d %c %s\n", s.a, s.c, s.arr);
	fclose(pf);
	pf = NULL;

	pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//����ʽ�������ļ�
	struct S s1 = {0};
	fscanf(pf, "%d %c %s", &s1.a, &s1.c, s1.arr);
	fprintf(stdout, "%d %c %s\n", s1.a, s1.c, s1.arr);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
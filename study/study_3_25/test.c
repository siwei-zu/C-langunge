#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//ģ�����������������������������
//������ǵĴ�������һ���������õĺ����У������������˶����ڴ���䣬���������ṹ�巵�ظ�
//�û����û�����free�����ͷŽṹ�壬�����û�����֪������ṹ���ڵĳ�ԱҲ��Ҫfree��������
//����ָ���û�����������¡����ԣ�������ǰѽṹ����ڴ��Լ����ԱҪ���ڴ�һ���Է����
//�ˣ������ظ��û�һ���ṹ��ָ�룬�û���һ��free�Ϳ��԰����е��ڴ�Ҳ���ͷŵ���
//�ڶ����ô��ǣ����������ڷ����ٶ�.
//�������ڴ���������߷����ٶȣ�Ҳ�����ڼ����ڴ���Ƭ������ʵ���Ҹ��˾���Ҳû����ˣ�����
//���ܲ���Ҫ����ƫ�����ļӷ���Ѱַ��


//malloc������ �ڴ���Ƭ�ͻ���٣�free��������ά���ϼ�
//������ڴ�������

//��������

struct S
{
	int a;
	char c;
	int arr[];//int arr[0];
};

int main()
{
	//�ṹ����������
	struct S* ss = (struct S*)malloc(sizeof(struct S) + sizeof(int) * 10);
	if (ss == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//�ṹ���ʼ��
	int i = 0;
	ss->a = 100;
	ss->c = 'w';
	for (i = 0; i < 10; i++)
	{
		ss->arr[i] = i + 1;
	}
	//��ӡ
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ss->arr[i]);
	}
	//�ͷ�
	free(ss);
	ss = NULL;
	return 0;
}


//ģ����������

struct S
{
	int a;
	char c;
	int* arr;
};

int main()
{
	struct S* ss = (struct S*)malloc(sizeof(struct S));
	//�����Ƿ񿪱��ڴ�ɹ�
	if (ss == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	ss->a = 100;
	ss->c = 'w';
	int* tmp = (int*)malloc(sizeof(int) * 10);
	if (tmp == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		ss->arr = tmp;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ss->arr[i] = i + 1;
	}
	//��ӡ
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ss->arr[i]);
	}
	//�ͷ�
	free(ss->arr);
	ss->arr = NULL;
	free(ss);
	ss = NULL;
	return 0;
}


//malloc
//calloc
//realloc - ��������Ķ����ڴ�Ĵ�С��
//���䣺reallocҲ������mallocһ������ռ�
#include <stdio.h>

int main()
{
	realloc(NULL, 20);//malloc(20);
	return 0;
}

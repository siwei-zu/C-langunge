#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//模拟柔性数组与柔性数组的区别在于
//如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给
//用户。用户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你
//不能指望用户来发现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好
//了，并返回给用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。
//第二个好处是：这样有利于访问速度.
//连续的内存有益于提高访问速度，也有益于减少内存碎片。（其实，我个人觉得也没多高了，反正
//你跑不了要用做偏移量的加法来寻址）


//malloc次数少 内存碎片就会减少，free次数较少维护较简单
//提高了内存利用率

//柔性数组

struct S
{
	int a;
	char c;
	int arr[];//int arr[0];
};

int main()
{
	//结构体声明创建
	struct S* ss = (struct S*)malloc(sizeof(struct S) + sizeof(int) * 10);
	if (ss == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//结构体初始化
	int i = 0;
	ss->a = 100;
	ss->c = 'w';
	for (i = 0; i < 10; i++)
	{
		ss->arr[i] = i + 1;
	}
	//打印
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ss->arr[i]);
	}
	//释放
	free(ss);
	ss = NULL;
	return 0;
}


//模拟柔性数组

struct S
{
	int a;
	char c;
	int* arr;
};

int main()
{
	struct S* ss = (struct S*)malloc(sizeof(struct S));
	//检验是否开辟内存成功
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
	//打印
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ss->arr[i]);
	}
	//释放
	free(ss->arr);
	ss->arr = NULL;
	free(ss);
	ss = NULL;
	return 0;
}


//malloc
//calloc
//realloc - 调整申请的堆区内存的大小的
//补充：realloc也可以像malloc一样申请空间
#include <stdio.h>

int main()
{
	realloc(NULL, 20);//malloc(20);
	return 0;
}

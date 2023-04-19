#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);

	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 2);
	if (ps->a == NULL)
	{
		perror("Init malloc");
		return;
	}
	ps->capacity = 2;
	ps->size = 0;
}

void SeqListDestroy(SeqList* ps)
{
	ps->capacity = 0;
	ps->size = 0;
	free(ps->a);
}

void Seqcheckcap(SeqList* ps)
{
	if (ps->capacity == ps->size)
	{
		int* tmp = (int*)realloc(ps->a, sizeof(SLDateType) * (ps->capacity * 2));
		if (tmp == NULL)
		{
			perror("checkcap realloc");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

void SeqListPrint(SeqList* ps)
{
	int  i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	Seqcheckcap(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	//Seqcheckcap(ps);
	//int i = ps->size;
	//while (i > 0)
	//{
	//	ps->a[i] = ps->a[i - 1];
	//	i--;
	//}
	//ps->a[i] = x;
	SeqListInsert(ps, 0, x);
	//ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps->size);

	SeqListErase(ps, 0);
	//int i = 0;
	//while (i < ps->size - 1)
	//{
	//	ps->a[i] = ps->a[i + 1];
	//	i++;
	//}
	//ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps->size);
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{

	assert(pos >= 0 && pos < ps->size);
	Seqcheckcap(ps);
	int i = ps->size;
	while (i > pos)
	{
		ps->a[i] = ps->a[i - 1];
		i--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	int i = pos;
	while (i < ps->size - 1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}


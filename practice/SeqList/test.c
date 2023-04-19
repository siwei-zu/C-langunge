#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeq1()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	SeqListPrint(&s);
	SeqListDestroy(&s);
}

void TestSeq2()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	SeqListPushFront(&s, 6);
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 1);

	SeqListPrint(&s);
	SeqListDestroy(&s);
}

void TestSeq3()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	SeqListPushFront(&s, 6);
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 1);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);
	SeqListDestroy(&s);
}

void TestSeq4()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	SeqListPushFront(&s, 6);
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 1);

	SeqListInsert(&s, 6, 7);

	SeqListErase(&s, 6);

	printf("%d\n", SeqListFind(&s, 4));

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);
	SeqListDestroy(&s);
}

int main()
{
	TestSeq4();
	return 0;
}
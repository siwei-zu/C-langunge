#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void TestSlist1()
{
	SListNode* s = NULL;

	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushBack(&s, 6);

	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);

	printf("链表中节点数据为6的地址是：%p", SListFind(s, 6));
	SListInsertAfter(SListFind(s, 6), 7);



	SListPushFront(&s, 6);
	SListPushFront(&s, 5);
	SListPushFront(&s, 4);
	SListPushFront(&s, 3);
	SListPushFront(&s, 2);
	SListPushFront(&s, 1);

	//SListPopBack(&s);

	SListPrint(s);

}

void TestSlist3()
{
	SListNode* s = NULL;

	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushBack(&s, 6);

	SListPushFront(&s, 6);
	SListPushFront(&s, 5);
	SListPushFront(&s, 4);
	SListPushFront(&s, 3);
	SListPushFront(&s, 2);
	SListPushFront(&s, 1);

	//SListPopFront(&s);
	//SListPopFront(&s);
	//SListPopFront(&s);
	//SListPopFront(&s);
	//SListPopFront(&s);
	//SListPopFront(&s);

	printf("链表中节点数据为6的地址是：%p\n", SListFind(s, 6));


	SListInsertAfter(SListFind(s, 6), 7);
	SListEraseAfter(SListFind(s, 5));

	//SListPopBack(&s);

	SListPrint(s);
	SListDestroy(s);
	s = NULL;
}

int main()
{
	TestSlist3();
	return 0;
}
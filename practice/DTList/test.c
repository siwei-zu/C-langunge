#define _CRT_SECURE_NO_WARNINGS 1
#include "DTList.h"

void Test1()
{
	DTList* phead = DTListInit();
	DTListPushBack(phead, 1);
	DTListPushBack(phead, 2);
	DTListPushBack(phead, 3);
	DTListPushBack(phead, 4);
	DTListPrint(phead);
}

void Test2()
{
	DTList* phead = DTListInit();
	DTListPushFront(phead, 30);
	DTListPushBack(phead, 1);
	DTListPushBack(phead, 2);
	DTListPushBack(phead, 3);
	DTListPushBack(phead, 4);
	DTListPushFront(phead, 20);
	DTListPopBack(phead);
	DTListPopFront(phead);

	DTListPrint(phead);
	DTListdestroy(phead);
	phead = NULL;
}

int main()
{
	Test2();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include  "DTList.h"

DTList* BuyListNode(DataType x)
{
	DTList* NewNode = (DTList*)malloc(sizeof(DTList));
	if (NewNode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	NewNode->data = x;
	return NewNode;
}

DTList* DTListInit()
{
	DTList* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void DTListPrint(DTList* phead)
{
	assert(phead);

	DTList* cur = phead->next;

	printf("sentry<==>");
	while (cur != phead)
	{
		printf("%d<==>", cur->data);

		cur = cur->next;
	}
}


void DTListPushBack(DTList* phead , DataType x)
{
	assert(phead);

	DTList* NewNode = BuyListNode(x);
	DTList* prev = phead->prev;

	prev->next = NewNode;
	NewNode->prev = prev;
	phead->prev = NewNode;
	NewNode->next = phead;
}

void DTListPopBack(DTList* phead)
{
	assert(phead);
	assert(phead->next != phead);

	DTList* prev = phead->prev;
	phead->prev = prev->prev;
	prev->prev->next = phead;
	free(prev);
}

void DTListPushFront(DTList* phead, DataType x)
{
	assert(phead);

	DTList* NewNode = BuyListNode(x);
	DTList* next = phead->next;

	phead->next = NewNode;
	NewNode->prev = phead;
	NewNode->next = next;
	next->prev = NewNode;
}

void DTListPopFront(DTList* phead)
{
	assert(phead);
	assert(phead->next != phead);

	DTList* next = phead->next;

	phead->next = next->next;
	next->next->prev = phead;
	free(next);
}

DTList* DTListFind(DTList* phead, DataType x)
{
	assert(phead);

	DTList* cur = phead->next;

	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}




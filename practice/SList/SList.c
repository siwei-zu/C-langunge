#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (tmp == NULL)
	{
		perror("BuyNode malloc");
		return;
	}
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void SListPrint(SListNode* plist)
{
	SListNode* tail = plist;
	while (tail != NULL)
	{
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* tail = *pplist;
	if (tail == NULL)
	{
		*pplist = BuySListNode(x);
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuySListNode(x);
	}
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = *pplist;
	*pplist = tmp;
}

void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* tail = *pplist;
	*pplist = (*pplist)->next;
	free(tail);
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* tail = plist;
	while (tail != NULL)
	{
		if (tail->data == x)
			return tail;
		tail = tail->next;
	}
	return tail;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* tail = pos->next;
	pos->next = BuySListNode(x);
	pos->next->next = tail;
}

void SListEraseAfter(SListNode* pos)
{
	assert(NULL || pos->next);
	SListNode* tail = pos->next->next;
	free(pos->next);
	pos->next = tail;
}

void SListDestroy(SListNode* plist)
{
	if(plist->next != NULL)
	{
		SListDestroy(plist->next);
		free(plist);
	}
}







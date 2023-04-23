#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (tmp == NULL)
	{
		perror("BuyNode malloc");
		return NULL;
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
	assert(pplist);


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
	assert(pplist);

	SListNode* tmp = BuySListNode(x);
	tmp->next = *pplist;
	*pplist = tmp;
}

void SListPopBack(SListNode** pplist)
{
	assert(pplist);
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
	assert(pplist);
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

void SListInsert(SListNode** pplist, SListNode* pos, SLTDateType x)
{
	assert(pplist);
	assert(pos);

	if (*pplist == pos)
	{
		SListPushFront(pplist, x);
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != pos)
		{
			tail = tail->next;
		}
		SListNode* NewNode = BuySListNode(x);
		NewNode->next = pos;
		tail->next = NewNode;
	}
}


void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);

	SListNode* tail = pos->next->next;
	free(pos->next);
	pos->next = tail;
}

void SListErase(SListNode** pplist, SListNode* pos)
{
	assert(pplist);
	assert(pos);

	if (*pplist == pos)
	{
		SListNode* tail = (*pplist)->next;
		free(*pplist);
		*pplist = tail;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != pos)
		{
			tail = tail->next;
		}
		tail->next = pos->next;
		free(pos);
	}
}


void SListDestroy(SListNode* plist)
{
	if(plist->next != NULL)
	{
		SListDestroy(plist->next);
		free(plist);
	}
}







#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//void TestSlist1()
//{
//	SListNode* s = NULL;
//
//	SListPushBack(&s, 1);
//	SListPushBack(&s, 2);
//	SListPushBack(&s, 3);
//	SListPushBack(&s, 4);
//	SListPushBack(&s, 5);
//	SListPushBack(&s, 6);
//
//	SListPopFront(&s);
//	SListPopFront(&s);
//	SListPopFront(&s);
//	SListPopFront(&s);
//	SListPopFront(&s);
//	SListPopFront(&s);
//
//	printf("链表中节点数据为6的地址是：%p", SListFind(s, 6));
//	SListInsertAfter(SListFind(s, 6), 7);
//
//
//
//	SListPushFront(&s, 6);
//	SListPushFront(&s, 5);
//	SListPushFront(&s, 4);
//	SListPushFront(&s, 3);
//	SListPushFront(&s, 2);
//	SListPushFront(&s, 1);
//
//	//SListPopBack(&s);
//
//	SListPrint(s);
//
//}
//
//void TestSlist3()
//{
//	SListNode* s = NULL;
//
//	SListPushBack(&s, 1);
//	SListPushBack(&s, 2);
//	SListPushBack(&s, 3);
//	SListPushBack(&s, 4);
//	SListPushBack(&s, 5);
//	SListPushBack(&s, 6);
//
//	SListPushFront(&s, 6);
//	SListPushFront(&s, 5);
//	SListPushFront(&s, 4);
//	SListPushFront(&s, 3);
//	SListPushFront(&s, 2);
//	SListPushFront(&s, 1);
//
//	//SListPopFront(&s);
//	//SListPopFront(&s);
//	//SListPopFront(&s);
//	//SListPopFront(&s);
//	//SListPopFront(&s);
//	//SListPopFront(&s);
//
//	printf("链表中节点数据为6的地址是：%p\n", SListFind(s, 6));
//
//
//	SListInsertAfter(SListFind(s, 6), 7);
//	//SListEraseAfter(SListFind(s, 5));
//
//	//SListPopBack(&s);
//
//	SListInsert(&s, SListFind(s, 6), 20);
//	SListErase(&s, SListFind(s, 5));
//
//	SListPrint(s);
//	SListDestroy(s);
//	s = NULL;
//}
//
//int main()
//{
//	TestSlist3();
//	return 0;
//}

SListNode* partition(SListNode* pHead, int x) {
    SListNode* prev = (SListNode*)malloc(sizeof(SListNode));
    SListNode* tail = (SListNode*)malloc(sizeof(SListNode));
    prev = NULL;
    tail = NULL;
    SListNode* ret = (SListNode*)malloc(sizeof(SListNode));
    SListNode* flag = (SListNode*)malloc(sizeof(SListNode));
    ret = NULL;
    flag = NULL;
    SListNode* cur = pHead;
    while (cur)
    {
        SListNode* next = cur->next;
        if (cur->data < x)
        {
            if (prev == NULL)
            {
                prev = cur;
                ret = prev;
            }
            else
            {
                prev->next = cur;
                prev = prev->next;
            }
        }
        else
        {
            if (tail == NULL)
            {
                tail = cur;
                flag = tail;
            }
            else
            {
                tail->next = cur;
                tail = tail->next;
            }
        }
        cur = next;
    }
    if (ret && flag)
    {
        prev->next = flag;
        tail->next = NULL;
        return ret;
    }
    else if (ret || flag)
    {
        return pHead;
    }
    else
        return NULL;
}

void Test()
{
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 1);
	SListPushBack(&list, 1);
	SListPushBack(&list, 1);
	SListPushBack(&list, 1);

    SListPrint(partition(list, 2));
    SListDestroy(list);
}


int main()
{
	Test();
	return 0;
}
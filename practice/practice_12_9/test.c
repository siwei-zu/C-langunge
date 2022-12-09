#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
}list;

int main()
{
    list list1[] = { {1,&list1[1]},{2,&list1[2]},{4,&list1[3]},NULL };
    list list2[] = { {1,&list2[1]},{3,&list2[2]},{4,&list2[3]},NULL };
    struct ListNode* list3 = list1;   
    struct ListNode* list4 = list2;
    struct ListNode* s =  (struct ListNode*)malloc(sizeof(struct ListNode));//创建一个开头
    struct ListNode* head;
    if (list1 == NULL)
        return 0;
    if (list2 == NULL)
        return 0;
    if (list3->val < list4->val)
    {
        s = list3;
        list3 = list3->next;
        head = s;//存放开头

    }
    else
    {
        s = list4;
        list4 = list4->next;
        head = s;//存放开头

    }
    while (list3->next != NULL&&list4->next!=NULL )
    {
        if (list3->val < list4->val)
        {
            s->next = list3;
            list3 = list3->next;
            s = s->next;
        }
        else
        {
            s->next = list4;
            list4 = list4->next;
            s = s->next;
        }
    }
    if (list3 != NULL)
    {
        s->next = list3;
    }
    else
    {
        s->next = list4;
    }
    while (head->next != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    return 0;
}
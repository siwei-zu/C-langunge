#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


 struct Node {
     int val;
      struct Node *next;
      struct Node *random;
 };
 

struct Node* CopNode(struct Node* head)
{
    if (head)
    {
        struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
        *NewNode = *head;
        NewNode->next = CopNode(head->next);
        return NewNode;
    }
    else
        return NULL;
}

struct Node* copyRandomList(struct Node* head) {
    int i = 0;
    int site[1000];
    struct Node* cur = head;
    while (cur)
    {
        site[i] = (int)cur;
        i++;
        cur = cur->next;
    }
    struct Node* ret = CopNode(head);
    cur = head;
    struct Node* tail = ret;
    while (tail)
    {
        if (cur->random == NULL)
        {
            tail->random = NULL;
        }
        else
        {
            struct Node* next = ret;
            int k = 0;
            for (k = 0; k < i; k++)
            {
                if (site[k] == (int)(cur->random))
                    break;
            }
            while (k)
            {
                next = next->next;
                k--;
            }
            tail->random = next;
        }
        tail = tail->next;
        cur = cur->next;
    }
    return ret;
}


int main()
{
    struct Node s1[5] = { 0 };
    s1[0].val = 7, s1[0].next = &s1[1], s1[0].random = NULL;
    s1[1].val = 13, s1[1].next = &s1[2], s1[1].random = &s1[0];
    s1[2].val = 11, s1[2].next = &s1[3], s1[2].random = &s1[4];
    s1[3].val = 10, s1[3].next = &s1[4], s1[3].random = &s1[2];
    s1[4].val = 1, s1[4].next = NULL, s1[4].random = &s1[1];
    struct Node* head = &s1[0];
    struct Node* ret = copyRandomList(head);
	return 0;
}
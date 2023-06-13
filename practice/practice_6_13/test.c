#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int maxVowels(char* s, int k) {
//    int l = 0;
//    int r = 0;
//    int max = 0;
//    while (l < k)
//    {
//        if ((s[l] == 'a' || s[l] == 'i' || s[l] == 'e' || s[l] == 'o' || s[l] == 'u'))
//        {
//            max++;
//        }
//        l++;
//    }
//    r = l;
//    l = 0;
//    int len = strlen(s);
//    int count = max;
//    while (r < len)
//    {
//        if ((s[l] == 'a' || s[l] == 'i' || s[l] == 'e' || s[l] == 'o' || s[l] == 'u'))
//        {
//            count--;
//        }
//        l++;
//        if ((s[r] == 'a' || s[r] == 'i' || s[r] == 'e' || s[r] == 'o' || s[r] == 'u'))
//        {
//            count++;
//        }
//        r++;
//        if (max < count)
//            max = count;
//    }
//    return max;
//}
//
//int main()
//{
//    char s[] = "abciiidef";
//    int k = 3;
//    printf("%d", maxVowels(s, k));
//	return 0;
//}

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* BuySListNode(int x)
{
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));

    tmp->val = x;
    tmp->next = NULL;
    return tmp;
}

void SListPushBack(struct ListNode** pplist, int x)
{



    struct ListNode* tail = *pplist;
    if (tail == NULL)
    {
        *pplist = BuySListNode(x);
    }
    else
    {
        tail->next = BuySListNode(x);
    }
}

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL)
    {
        return head;
    }
    struct ListNode* cur = head;
    struct ListNode* Odd = NULL;
    struct ListNode* _Odd = NULL;
    struct ListNode* Even = NULL;
    struct ListNode* _Even = NULL;
    int i = 0;
    while (cur)
    {
        if (i % 2 == 0)
        {
            SListPushBack(&_Even, cur->val);
            if (Even == NULL)
            {
                Even = _Even;
            }
            if (_Even->next != NULL)
            {
                _Even = _Even->next;
            }
            i++;
        }
        else
        {
            SListPushBack(&_Odd, cur->val);
            if (Odd == NULL)
            {
                Odd = _Odd;
            }
            if (_Odd->next != NULL)
            {
                _Odd = _Odd->next;
            }
            i++;
        }
        cur = cur->next;
    }
    _Even->next = Odd;

    return Even;
}

int main()
{
    struct ListNode* node1 = BuySListNode(1);
    struct ListNode* node2 = BuySListNode(2);
    struct ListNode* node3 = BuySListNode(3);
    struct ListNode* node4 = BuySListNode(4);
    struct ListNode* node5 = BuySListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node1 = oddEvenList(node1);
    return 0;
}
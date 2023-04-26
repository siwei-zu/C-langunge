#define _CRT_SECURE_NO_WARNINGS 1
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

struct ListNode* FindMid(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* PushFront(struct ListNode* mid)
{
    struct ListNode* head = NULL;
    while (mid)
    {
        struct ListNode* next = mid->next;
        mid->next = head;
        head = mid;
        mid = next;
    }
    return head;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* mid = FindMid(head);
    struct ListNode* NewHead = PushFront(mid);
    while (NewHead)
    {
        if (NewHead->val != head->val)
            return false;
        NewHead = NewHead->next;
        head = head->next;
    }
    return true;
}


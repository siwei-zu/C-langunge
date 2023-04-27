#define _CRT_SECURE_NO_WARNINGS 1

//�������������еĽڵ�--����
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* prev = head;
    struct ListNode* cur = head;
    struct ListNode* next = head;
    struct ListNode* tail = NULL;
    while (next && next->next)
    {
        next = next->next->next;

        cur = prev->next;
        cur->next = prev;

        if (tail != NULL)
            tail->next = cur;
        else
            head = cur;
        tail = prev;
        prev = next;
    }
    if (tail != NULL)
    {
        if (prev == NULL)
            tail->next = NULL;
        else
            tail->next = prev;
    }
    return head;
}

//�������������еĽڵ�--�ݹ�
struct ListNode* swapPairs(struct ListNode* head) {
    if (head && head->next)
    {
        struct ListNode* tail = head->next;
        head->next = swapPairs(head->next->next);
        tail->next = head;
        return tail;
    }
    else
        return head;
}
#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* p = head;
    struct ListNode* pre = head;
    p = p->next;
    while (p)
    {
        p = p->next;
        pre = pre->next;
        if (p != NULL)
            p = p->next;
    }
    return pre;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0, dummy->next = head;
    struct ListNode* first = head;
    struct ListNode* second = dummy;
    for (int i = 0; i < n; ++i) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    first = dummy->next;
    free(dummy);
    return first;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    if (head->next == NULL)
        return NULL;
    int i = 0;
    for (i = 1; fast != NULL; i++)
    {
        if (i > n + 1)
        {
            slow = slow->next;
        }
        fast = fast->next;
    }
    if (i - 1 == n)
        return head->next;
    fast = slow;
    slow = slow->next;
    slow = slow->next;
    fast->next = slow;
    return head;
}
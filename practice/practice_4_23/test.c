#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));//创建一个开头
    struct ListNode* head;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (list1->val < list2->val)
    {
        s = list1;
        list1 = list1->next;
        head = s;//存放开头

    }
    else
    {
        s = list2;
        list2 = list2->next;
        head = s;//存放开头

    }
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            s->next = list1;
            list1 = list1->next;
            s = s->next;
        }
        else
        {
            s->next = list2;
            list2 = list2->next;
            s = s->next;
        }
    }
    if (list1 != NULL)
    {
        s->next = list1;
    }
    else
    {
        s->next = list2;
    }
    return head;
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

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* ret = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return ret;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head != NULL)
    {
        head->next = removeElements(head->next, val);
        if (head->val == val)
        {
            return head->next;
        }
    }
    return head;
}
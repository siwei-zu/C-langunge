#define _CRT_SECURE_NO_WARNINGS 1
typedef struct Lnode {
    int val;
    struct Lnode* next;
} Lnode, ListNode;

Lnode* halfList(Lnode* head)
{
    for (Lnode* fast = head; fast != NULL && fast->next != NULL; ) {
        fast = fast->next->next;
        if (fast != NULL)
            head = head->next;
    }

    return head;
}

//头插法反转链表
Lnode* reverseList(Lnode* head)
{
    if (head == NULL)
        return NULL;

    Lnode* p = head->next;
    head->next = NULL;

    for (Lnode* temp; p != NULL; p = temp) {
        temp = p->next;
        p->next = head;
        head = p;
    }

    return head;
}

bool isPalindrome(ListNode* head)
{
    Lnode* rear = halfList(head);
    rear = reverseList(rear->next);

    for (; rear != NULL; head = head->next, rear = rear->next) {
        if (head->val != rear->val)
            return false;
    }

    return true;
}
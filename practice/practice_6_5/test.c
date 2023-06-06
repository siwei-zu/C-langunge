#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head->next == NULL)
    {
        return NULL;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* pre = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
    }
    pre->next = pre->next->next;
    return head;
}
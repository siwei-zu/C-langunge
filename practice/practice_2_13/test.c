#define _CRT_SECURE_NO_WARNINGS 1
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
#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (fast != head)
            {
                fast = fast->next;
                head = head->next;
            }
            return head;
        }
    }
    return NULL;
}
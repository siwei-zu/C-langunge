#define _CRT_SECURE_NO_WARNINGS 1
//����ͷ��ķ��������ݽ��з�ת
struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode* rehead = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        struct ListNode* next = cur->next;

        cur->next = rehead;
        rehead = cur;

        cur = next;
    }
    return rehead;
}
//��ԭ����������޸�
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;

    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
        {
            n3 = n3->next;
        }
    }
    return n1;
}
//��ԭ����������޸ġ��������ݹ�
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
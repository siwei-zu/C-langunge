#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));//����һ����ͷ
    struct ListNode* head;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (list1->val < list2->val)
    {
        s = list1;
        list1 = list1->next;
        head = s;//��ſ�ͷ

    }
    else
    {
        s = list2;
        list2 = list2->next;
        head = s;//��ſ�ͷ

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
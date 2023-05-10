#define _CRT_SECURE_NO_WARNINGS 1
struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    while (cur)
    {
        struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
        NewNode->val = cur->val;
        NewNode->next = cur->next;
        cur->next = NewNode;
        cur = NewNode->next;
    }

    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    cur = head;
    struct Node* retHead = NULL, * retTail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        cur->next = copy->next;
        if (retTail == NULL)
        {
            copy->next = NULL;
            retHead = copy;
            retTail = retHead;
        }
        else
        {
            retTail->next = copy;
            copy->next = NULL;
            retTail = copy;
        }
        cur = next;
    }

    return retHead;

}
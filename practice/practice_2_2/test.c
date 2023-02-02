#define _CRT_SECURE_NO_WARNINGS 1

//删除排序链表中的重复元素
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return head;
    struct ListNode* l1 = head;
    struct ListNode* l2 = head;
    while (l2 != NULL)
    {
        if (l2->val != l1->val)
        {
            l1->next = l2;
            l1 = l1->next;
        }
        l2 = l2->next;
    }
    l1->next = NULL;
    return head;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* e1, const void* e2)
{
    return *(char*)e1 - *(char*)e2;
}

int main() {
    char arr[1001] = { 0 };
    scanf("%s", arr);
    qsort(arr, strlen(arr), sizeof(char), cmp);
    printf("%s", arr);
    return 0;
}


int pivotIndex(int* nums, int numsSize) {
    int i = 0;
    int told = 0;
    int sum = 0;
    for (i = 0; i < numsSize; i++)
    {
        told += nums[i];
    }
    for (i = 0; i < numsSize; i++)
    {
        if (i == numsSize - 1)
        {
            if (0 == told - nums[i])
                return numsSize - 1;
        }
        if (sum == told - nums[i] - sum)
        {
            return i;
        }
        sum += nums[i];
    }
    return -1;
}
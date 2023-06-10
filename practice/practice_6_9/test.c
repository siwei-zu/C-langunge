#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void revserse(char* s, int l, int r)
{
    while (l < r)
    {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

char* reverseWords(char* s) {
    int l = 0;
    int r = strlen(s) - 1;
    while (l < r)
    {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
    l = 0;
    char* ret = s;
    while (*ret == ' ')
    {
        l++;
        ret++;
    }

    for (; l < strlen(s);)
    {
        r = l;
        while (s[r + 1] != ' ' && s[r + 1] != '\0')
        {
            r++;
        }

        revserse(s, l, r);
        l = r + 1;
        while (s[l] == ' ')
        {
            l++;
        }

        if (l - r > 2)
        {
            int count = l - r;
            int k = l - count + 2;
            while (s[l] != ' ' && s[l] != '\0')
            {
                s[l - count + 2] = s[l];
                s[l] = ' ';
                l++;
            }
            l = k;
        }
    }

    r = strlen(s) - 1;
    while (s[r] == ' ')
    {
        s[r] = '\0';
        r--;
    }

    return ret;
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * (numsSize));
    *returnSize = numsSize;
    ret[0] = 1;
    int i = 0;
    int right = 1;
    for (i = 1; i < numsSize; i++)
    {
        ret[i] = ret[i - 1] * nums[i - 1];
    }
    for (i = numsSize - 2; i >= 0; i--)
    {
        right *= nums[i + 1];
        ret[i] = ret[i] * right;
    }
    return ret;
}

int main()
{
    int nums[] = { 1,2,3,4 };
    int returnSize = 0;
    int size = sizeof(nums) / sizeof(nums[0]);
    int* ret = productExceptSelf(nums, size, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ret[i]);
    }
    printf("\n");
    char s[] = "the sky is blue";
    printf("%s\n", reverseWords(s));
    free(ret);
    ret = NULL;
    return 0;
}
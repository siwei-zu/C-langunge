#define _CRT_SECURE_NO_WARNINGS 1


//合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int a = m + n - 1;
    while (a >= 0)
    {
        if (p1 == -1)
        {
            nums1[a] = nums2[p2];
            p2--;
            a--;
        }
        else if (p2 == -1)
        {
            nums1[a] = nums1[p1];
            p1--;
            a--;
        }
        else if (nums1[p1] > nums2[p2])
        {
            nums1[a] = nums1[p1];
            p1--;
            a--;
        }
        else
        {
            nums1[a] = nums2[p2];
            p2--;
            a--;
        }

    }
}

#include <stdio.h>

int main() {
    int arr[128] = { 0 };
    char s[501];
    scanf("%s", s);
    int i = 0;
    int sum = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (arr[s[i]] == 0)
        {
            arr[s[i]] = 1;
            sum += 1;
        }
    }
    printf("%d", sum);
}

int majorityElement(int* nums, int numsSize) {
    int count = 1;
    int a = nums[0];
    int i = 0;
    for (i = 1; i < numsSize; i++)
    {
        if (count == 0)
            a = nums[i];
        if (nums[i] == a)
            count++;
        else
            count--;
    }
    return a;
}


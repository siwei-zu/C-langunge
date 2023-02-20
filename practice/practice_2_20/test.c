#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target > nums[mid])
        {
            left = mid + 1;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    int mid = 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (target > nums[mid])
            left = mid + 1;
        else if (target < nums[mid])
            right = mid - 1;
        else if (nums[mid] == target)
            return mid;
    }
    if (target < nums[mid])
        return mid;
    else
        return mid + 1;
}
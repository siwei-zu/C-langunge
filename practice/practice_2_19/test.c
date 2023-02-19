#define _CRT_SECURE_NO_WARNINGS 1
int* buildArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int i = 0;
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++)
    {
        ans[i] = nums[nums[i]];
    }
    return ans;
}

int smallestEvenMultiple(int n) {
    if (n % 2 == 0)
        return n;
    else
        return 2 * n;
}
#define _CRT_SECURE_NO_WARNINGS 1
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2 * numsSize;
    int* arr = (int*)malloc(sizeof(int) * 2 * numsSize);
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        arr[i] = nums[i];
    }
    for (i; i < numsSize * 2; i++)
    {
        arr[i] = nums[i - (numsSize)];
    }
    return arr;
}
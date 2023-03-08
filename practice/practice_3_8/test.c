#define _CRT_SECURE_NO_WARNINGS 1
int minMoves(int* nums, int numsSize) {
    int i = 0;
    int min = nums[0];
    int sum = 0;
    for (i = 1; i < numsSize; i++)
    {
        min = min < nums[i] ? min : nums[i];
    }
    for (i = 0; i < numsSize; i++)
    {
        sum += nums[i] - min;
    }
    return sum;
}
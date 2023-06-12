#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    double count = 0.0;
    int i = 0;
    while (i < k)
    {
        count += nums[i];
        i++;
    }
    int l = 0;
    int r = --i;
    int max = count;
    while (r < numsSize - 1)
    {
        max -= nums[l];
        l++;
        r++;
        max += nums[r];
        if (max > count)
            count = max;
    }
    return count / k;
}

int largestAltitude(int* gain, int gainSize) {
    int maxgain = 0;
    int i = 0;
    int count = 0;

    for (i = 0; i < gainSize; i++)
    {
        count += gain[i];
        if (count > maxgain)
            maxgain = count;
    }
    return maxgain;
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

int main()
{
    int nums[] = { 0,4,0,3,2 };
    int sz = sizeof(nums) / sizeof(nums[0]);
    printf("%f\n", findMaxAverage(nums, sz, 1));
	return 0;
}
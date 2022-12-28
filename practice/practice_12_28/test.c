#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()//找到数组中消失的数字。
{
    int nums[] = { 1,1 };
    int nums2[99999] = { 0 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i = 0;
    int k = 0;
    for (i = 0; i < numsSize; i++)
    {
        nums2[nums[i] - 1] = nums[i];
    }
    for (i = 0; i < numsSize; i++)
    {

        if ((nums2[i] - (i + 1)) != 0)
        {
            nums[k] = i + 1;
            k++;
        }
    }
    int returnSize = k;
    for (i = 0; i < returnSize; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}
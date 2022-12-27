#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()//删除有序数组中的重复项
{
    int nums[] = { 0,0,1,1,1,2,2,2,3,3,3,4,4 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i = 0;
    int count = 0;
    for (i = 0; i < numsSize - count; )
    {
        if (nums[i] == nums[i + 1])
        {
            int j = 0;
            for (j = i + 1; j < numsSize; j++)
            {
                nums[j] = nums[j + 1];
            }
            count++;
        }
        else
        {
            i++;
            continue;
        }
    }
    printf("%d", count);
}

int main()
{
    int a = 11;
    a = a | (1 << 2);
    printf("%d\n", a);
    a = a & (~(1 << 2));
    printf("%d\n", a);
    return 0;
    //00000000000000000000000000001011
    //00000000000000000000000000000100

    //00000000000000000000000000001111
    //11111111111111111111111111111011

    //00000000000000000000000000001011
}
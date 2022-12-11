#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


//int main()
//{
//    int grid[2][3] = { {1,2,4},{3,3,1} };
//    int gridColSize = 3;
//    int gridSize = 2;
//    int i = 0;
//    int arr[50];
//    int max = 0;
//    int max1 = 0;
//    int count = 0;
//    int k = 0;
//    int xy[2];
//    for (k = 0; k < gridColSize; k++)
//    {
//        max1 = 0;
//        for (i = 0; i < gridSize; i++)
//        {
//            int j = 0;
//            max = 0;
//            for (j = 0; j < gridColSize; j++)
//            {
//                if (grid[i][j] > max)
//                {
//                    max = grid[i][j];
//                    xy[0] = i;
//                    xy[1] = j;
//                }
//            }
//            grid[xy[0]][xy[1]] = 0;
//            max1 = max1 > max ? max1 : max;
//        }
//        count += max1;
//    }
//    printf("%d\n", count);
//    return 0;
//}

int cmp(const void* x, const void* y)
{
    return *((int*)x) - *((int*)y);
}


int main()
{
    int nums[] = { 2,3,5,6,7 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int arr[100000] = { 0 };
    int* dp = (int*)malloc(sizeof(int) * (nums[numsSize - 1]+1));
    for (i = 0; i < nums[numsSize - 1]+1; i++)
    {
        *(dp+i) = 1;
    }
    arr[nums[0]] = nums[0];
    int max = 0;
    for (i = 1; i < numsSize; i++)
    {
        if ((int)sqrt(nums[i])* (int)sqrt(nums[i])==nums[i]&&(int)sqrt(nums[i]) == arr[(int)sqrt(nums[i])])
        {
            dp[nums[i]] = dp[(int)sqrt(nums[i])] + 1;
            max = dp[nums[i]] > max ? dp[nums[i]] : max;
            arr[nums[i]] = nums[i];
        }
        else
            arr[nums[i]] = nums[i];
    }
    if (max == 0)
        printf("%d", -1);
    else
        printf("%d", max);
    return 0;
}

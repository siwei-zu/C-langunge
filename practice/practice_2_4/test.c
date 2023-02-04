#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//杨辉三角
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int i = 0;
    int** arr = (int**)malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for (i = 0; i < numRows; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;;
        arr[i][0] = arr[i][i] = 1;
        int j = 0;
        for (j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    return arr;
}
//除自身以外数组的乘积
//空间复杂度O（2n）
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int* l = (int*)malloc(sizeof(int) * numsSize);
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    l[0] = 1;
    int* r = (int*)malloc(sizeof(int) * numsSize);
    r[numsSize - 1] = 1;
    for (i = 1; i < numsSize; i++)
    {
        l[i] = nums[i - 1] * l[i - 1];
        r[numsSize - i - 1] = nums[numsSize - i] * r[numsSize - i];
    }
    *returnSize = numsSize;
    for (i = 0; i < numsSize; i++)
    {
        ret[i] = l[i] * r[i];
    }
    return ret;
}
//空间复杂度O（1）
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

//自除数
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* arr = malloc(sizeof(int) * (right - left + 1));
    int k = 0;
    for (left; left <= right; left++)
    {
        int flag = 0;
        int num = left;
        while (num)
        {
            if (num % 10 == 0)
            {
                flag = 1;
                break;
            }
            if (left % (num % 10) != 0)
            {
                flag = 1;
                break;
            }
            num /= 10;
        }
        if (flag == 0)
        {
            arr[k] = left;
            k++;
        }
    }
    *returnSize = k;
    return arr;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * candiesSize);
    *returnSize = candiesSize;
    int i = 0;
    int max = 0;
    for (i = 0; i < candiesSize; i++)
    {
        max = max > candies[i] ? max : candies[i];
    }
    for (i = 0; i < candiesSize; i++)
    {
        if (candies[i] + extraCandies >= max)
        {
            ret[i] = 1;
        }
        else
        {
            ret[i] = 0;
        }
    }
    return ret;
}

int main()//拥有最多糖果的孩子
{
	int candies[] = { 2,3,5,1,3 };
	int candiesSize = sizeof(candies) / sizeof(candies[0]);
	int extraCandies = 3;
	int returnSize = 0;
	int* ret = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);
	int i = 0;
	for (i = 0; i < returnSize; i++)
	{
		printf("%d ", ret[i]);
	}
	return 0;
}
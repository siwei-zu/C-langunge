#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()//自幂数
{
	int n = 0;//打印出n位的自幂数
	scanf("%d", &n);
	int i = 1;//判断范围起始数值，在下面第一个循环计算出结果		
	int j = 0;//循环变量
	for (j = 1; j < n; j++)
	{
		i *= 10;//得到起始数值
	}
	int max = i * 10;//终止位置
	for (i; i < max; i++)
	{
		int sum = 0;//与每位的n次幂相加
		int count = i;//得到i的每一位
		int p = 1;//存储每一位的n次幂
		while (count)//count自身可以作为判断依据，和那个图里的t>0一样
		{
			p = 1;
			for (j = 0; j < n; j++)
			{
				p *= (count % 10);
			}
			count /= 10;
			sum += p;
		}
		if (sum == i)//判断
		{
			printf("%d ", i);
		}
	}
	return 0;
}

//杨辉三角（滚动数组）
int* getRow(int rowIndex, int* returnSize) {
	*returnSize = rowIndex + 1;
	int* arr = (int*)malloc(sizeof(int) * (rowIndex + 1));
	int i = 0;
	for (i = 0; i <= rowIndex; i++)
	{
		arr[0] = arr[i] = 1;
		int j = 0;
		for (j = i - 1; j >= 1; j--)
		{
			arr[j] = arr[j] + arr[j - 1];
		}
	}
	return arr;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int count = 0;
    for (i = 0; i < numsSize; i++)
    {
        nums[nums[i] % (numsSize + 1) - 1] += numsSize + 1;
    }
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] <= numsSize + 1)
            count++;
    }
    *returnSize = count;
    int* arr = (int*)malloc(sizeof(int) * count);
    int l = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] <= numsSize + 1)
        {
            arr[l] = i + 1;
            l++;
        }
    }
    return arr;
}
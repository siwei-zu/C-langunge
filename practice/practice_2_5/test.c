#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()//������
{
	int n = 0;//��ӡ��nλ��������
	scanf("%d", &n);
	int i = 1;//�жϷ�Χ��ʼ��ֵ���������һ��ѭ����������		
	int j = 0;//ѭ������
	for (j = 1; j < n; j++)
	{
		i *= 10;//�õ���ʼ��ֵ
	}
	int max = i * 10;//��ֹλ��
	for (i; i < max; i++)
	{
		int sum = 0;//��ÿλ��n�������
		int count = i;//�õ�i��ÿһλ
		int p = 1;//�洢ÿһλ��n����
		while (count)//count���������Ϊ�ж����ݣ����Ǹ�ͼ���t>0һ��
		{
			p = 1;
			for (j = 0; j < n; j++)
			{
				p *= (count % 10);
			}
			count /= 10;
			sum += p;
		}
		if (sum == i)//�ж�
		{
			printf("%d ", i);
		}
	}
	return 0;
}

//������ǣ��������飩
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
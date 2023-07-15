#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];

		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				a[end] = tmp;
				end--;
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int end = 0;
		for (int i = 0; i + gap < n; i++)
		{
			end = i;
			int tmp = a[end + gap];
			
			while(end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void OptionSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[mini] > a[i])
			{
				mini = i;
			}
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//建大堆
	int i = 0;
	for (i = n - 1; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}
	//向下调整排序
	for (i = n-1;  i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, 0, i);
	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

//前后指针法
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	while (cur <= end)
	{
		if (a[cur] < a[keyi])
		{
			++prev;
			Swap(&a[prev], &a[cur]);
		}
			
		++cur;
	}

	Swap(&a[keyi], &a[prev]);
	keyi = prev;

	return keyi;
}

//递归
//闭区间[begin, end]
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	int keyi = PartSort3(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}


void MergeSort(int* a, int left, int right)
{
	if (left == right)
		return;

	int mid = (left + right) / 2;
	MergeSort(a, left, mid);
	MergeSort(a, mid + 1, right);

	int p1 = left;
	int p2 = mid + 1;
	while (p2 <= right)
	{
		if (p1 == p2)
		{
			if (++p2 == right + 1)
				break;
		}
		

		if (a[p1] > a[p2])
		{
			Swap(&a[p1], a[p2]);
		}

		p1++;
	}
}


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

int MidI(int* a, int begin, int end)
{
	int midi = (end - begin) / 2;

	if (a[midi] > a[begin])
	{
		if (a[midi] < a[end])
			return midi;
		else
		{
			if (a[begin] > a[end])
				return begin;
			else
				return end;
		}
	}
	else
	{
		if (a[begin] < a[end])
			return begin;
		else
		{
			if (a[midi] > a[end])
				return midi;
			else
				return end;
		}
	}
}

//霍尔的方法
int PartSort1(int* a, int begin, int end)
{
	int midi = MidI(a, begin, end);
	Swap(&a[begin], &a[midi]);

	int keyi = begin;
	int left = begin;
	int right = end;

	while (left < right)
	{
		while(left < right && a[right] >= a[keyi])
		{
			right--;
		}

		while (left <right && a[left] <= a[keyi])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[keyi]);
	return left;
}

//挖坑法
int PartSort2(int* a, int begin, int end)
{
	int midi = MidI(a, begin, end);
	Swap(&a[begin], &a[midi]);

	int key = a[begin];
	int holei = begin;

	while (begin < end)
	{
		while (begin <end && a[end] >= key)
		{
			end--;
		}

		a[holei] = a[end];
		holei = end;
		

		while (begin < end && a[begin] <= key)
		{
			begin++;
		}

		
		a[holei] = a[begin];
		holei = begin;	
	}

	a[holei] = key;
	return holei;
}

//前后指针法
int PartSort3(int* a, int begin, int end)
{
	int midi = MidI(a, begin, end);
	Swap(&a[begin], &a[midi]);

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

//优化快速排序，从之前的分两路（ >=  和 <= ），改分三路（ > 和 == 和 < ）
void QuickSort_ThreeRoutes(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	//代码优化，小区间排序，插入排序
	if (end - begin < 10)
	{
		InsertSort(a + begin, (end - begin + 1));
		return;
	}

	int midi = MidI(a, begin, end);
	Swap(&a[begin], &a[midi]);

	int key = a[begin];
	int cur = begin + 1;
	int left = begin;
	int right = end;
	while (cur <= right)
	{
		if (a[cur] == key)
		{
			cur++;
		}
		else if (a[cur] > key)
		{
			Swap(&a[cur], &a[right]);
			right--;
		}
		else
		{
			Swap(&a[cur], &a[left]);
			left++;
			cur++;
		}
	}

	QuickSort_ThreeRoutes(a, begin, left - 1);
	QuickSort_ThreeRoutes(a, cur + 1, end);
}


//递归
//闭区间[begin, end]
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	//代码优化，小区间排序，插入排序
	if (end - begin < 10)
	{
		InsertSort(a + begin, (end - begin + 1));
		return;
	}

	int keyi = PartSort3(a, begin, end);
	//int keyi = PartSort1(a, begin, end);
	//int keyi = PartSort2(a, begin, end);

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, end);
	StackPush(&st, begin);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, left, right);

		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}
	}

	StackDestroy(&st);
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left == right)
		return;
	
	//代码优化，小区间排序，插入排序
	if (right - left < 10)
	{
		InsertSort(a + left, (right - left + 1));
		return;
	}

	int midi = (left + right) / 2;
	_MergeSort(a, tmp, left, midi);
	_MergeSort(a, tmp, midi + 1, right);

	int begin1 = left, end1 = midi;
	int begin2 = midi + 1, end2 = right;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i] = a[begin1];
			begin1++;
		}
		else
		{
			tmp[i] = a[begin2];
			begin2++;
		}
		i++;
	}

	while (begin1 <= end1)
	{
		tmp[i] = a[begin1];
		begin1++;
		i++;
	}

	while (begin2 <= end2)
	{
		tmp[i] = a[begin2];
		begin2++;
		i++;
	}

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
}


//法一->排一段复制一段
void MergeSortNonR(int* a, int n)
{
	assert(n > 0);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc file");
		return;
	}
	int gap = 1;

	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i += gap * 2)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;

			if (end1 >= n || begin2 >= n)
			{
				break;
			}

			// 修正
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j] = a[begin1];
					begin1++;
				}
				else
				{
					tmp[j] = a[begin2];
					begin2++;
				}
				j++;
			}

			while (begin1 <= end1)
			{
				tmp[j] = a[begin1];
				begin1++;
				j++;
			}

			while (begin2 <= end2)
			{
				tmp[j] = a[begin2];
				begin2++;
				j++;
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}

		gap *= 2;
	}
 
  free(tmp);
}

//法二，全部复制
//void MergeSortNonR(int* a, int n)
//{
//	assert(n > 0);
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc file");
//		return;
//	}
//	int gap = 1;
//
//	while (gap < n)
//	{
//		int j = 0;
//		for (int i = 0; i < n; i += gap * 2)
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + gap * 2 - 1;
//			while (begin1 < n && begin2 < n && begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[j] = a[begin1];
//					begin1++;
//				}
//				else
//				{
//					tmp[j] = a[begin2];
//					begin2++;
//				}
//				j++;
//			}
//
//			while (begin1 < n && begin1 <= end1)
//			{
//				tmp[j] = a[begin1];
//				begin1++;
//				j++;
//			}
//
//			while (begin2 < n && begin2 <= end2)
//			{
//				tmp[j] = a[begin2];
//				begin2++;
//				j++;
//			}
//		}
//
//		gap *= 2;
//		memcpy(a, tmp, sizeof(int) * n);
//	}
//
//	free(tmp);
//}

void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* arr = (int*)malloc(sizeof(int) * range);
	if (arr == NULL)
	{
		perror("malloc fail");
		return;
	}
	memset(arr, 0, sizeof(int) * range);

	for (int i = 0; i < n; i++)
	{
		arr[a[i] - min]++;
	}

	int k = 0;
	for (int i = 0; i < range; i++)
	{
		while (arr[i]--)
		{
			a[k] = i + min;
			k++;
		}
	}

	free(arr);
}
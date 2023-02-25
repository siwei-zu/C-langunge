#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//冒泡排序的优化  flag == 1 和falg == 0

//冒泡排序

void Print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubble_sort(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		int flag = 1;//这个标记的作用会减少排序所用的时间，如果在某一过程中，这个量没有变化，说明已经排好序，直接break
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 9,8,7,4,5,6,1,2,3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	Print(arr, sz);
	return 0;
}


//冒泡排序模拟实现qsort功能

int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void Swap(char* e1, char* e2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *(e1 + i);
		*(e1 + i) = *(e2 + i);
		*(e2 + i) = tmp;
	}
}

void bubble_sort(void* arr, size_t num, size_t width, int (*cmp)(const void*, const void*))
{
	size_t i = 0;
	for (i = 0; i < num - 1; i++)
	{
		size_t j = 0;
		int flag = 1;
		for (j = 0; j < num - i - 1; j++)
		{
			if (cmp((char*)arr + j * width, (char*)arr + (j + 1) * width) > 0)
			{
				flag = 0;
				Swap((char*)arr + j * width, (char*)arr + (j + 1) * width, width);
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}


int main()
{
	int arr[] = { 9,8,7,4,5,6,1,2,3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(int), cmp);
	Print(arr, sz);
	return 0;
}
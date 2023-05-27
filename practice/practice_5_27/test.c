#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

typedef int HeapData;
typedef struct Heap
{
	HeapData* data;
	int size;
	int capcity;
}Hp;

void Swap(HeapData* x, HeapData* y)
{
	HeapData tmp = *x;
	*x = *y;
	*y = tmp;
}


void AdjustUp(HeapData* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HeapData* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}

		if (a[parent] > a[child])
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

//void HeapSort(int* a, int sz)
//{
//	//构建堆
//	//1.向上调整构建
//	int i = 0;
//	for (i = 1; i < sz; i++)
//	{
//		AdjustUp(a, i);
//	}
//	//2.向下调整构建
//	//for (i = (sz - 1 - 1) / 2; i >= 0; i--)
//	//{
//	//	AdjustDown(a, sz, i);
//	//}
//
//	for (i = sz - 1; i >= 0; i--)
//	{
//		printf("%d\n", a[0]);
//		Swap(&a[0], &a[i]);
//		AdjustDown(a, i, 0);
//	}
//
//}
//
//int main()
//{
//	int a[] = { -96,-91,-90,-87,54,77,-85,-84,72,85};
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//	return 0;
//}

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	int* a = (int*)malloc(sizeof(int) * k);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}
	FILE* pf = fopen("data.txt", "r");
	int i = 0;
	for (i = 0; i < k; i++)
	{
		fscanf(pf, "%d", &a[i]);
	}
	for (i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, k, i);
	}
	while (!feof(pf))
	{
		int val;
		fscanf(pf, "%d", &val);
		if (val > a[0])
		{
			a[0] = val;
			AdjustDown(a, k, 0);
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d\n", a[i]);
	}
	free(a);
	a = NULL;
	fclose(pf);
	pf = NULL;

}

int main()
{
	//CreateNDate();
	PrintTopK(5);
	return 0;
}
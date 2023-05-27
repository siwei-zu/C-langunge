#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"


void TestHeap()
{
	Hp hp;
	HeapInit(&hp);

	HeapPush(&hp, 10);
	HeapPush(&hp, 30);
	HeapPush(&hp, 15);
	HeapPush(&hp, 70);
	HeapPush(&hp, 56);
	HeapPush(&hp, 25);

	while(!HeapEmpty(&hp))
	{
		printf("%d\n", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestory(&hp);
}

int main()
{
	TestHeap();
	return 0;
}

//void HeapSort(int* a, int sz)
//{
//	//构建堆
//	//1.向上调整构建
//	//升序大堆， 降序小堆
//	int i = 0;
//	//for (i = 1; i < sz; i++)
//	//{
//	//	AdjustUp(a, i);
//	//}
//	//2.向下调整构建
//	for (i = (sz - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, sz, i);
//	}
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
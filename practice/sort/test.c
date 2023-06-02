#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void TestInsert()
{
	int a[] = { 1,5,8,7,4,6,9,3,2,0 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	printf("InsertSort:");
	Print(a, n);
}

void TestShell()
{
	int a[] = { 1,5,8,7,4,6,9,3,2,0 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	printf("ShellSort:");
	Print(a, n);
}

void TestOption()
{
	int a[] = { 1,5,8,7,4,6,9,3,2,0 };
	int n = sizeof(a) / sizeof(a[0]);
	OptionSort(a, n);
	printf("OptionSort:");
	Print(a, n);
}

void TestHeap()
{
	int a[] = { 1,5,8,7,4,6,9,3,2,0 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
	printf("HeapSort:");
	Print(a, n);
}

void TestBubble()
{
	int a[] = { 1,5,8,7,4,6,9,3,2,0 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);
	printf("BubbleSort:");
	Print(a, n);
}

void TestEfficiency()
{
	//制造随机数
	srand((unsigned)time(NULL));
	int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	printf("InsertSort: %d\n", end1 - begin1);

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	printf("ShellSort: %d\n", end2 - begin2);

	int begin3 = clock();
	OptionSort(a3, N);
	int end3 = clock();
	printf("OptionSort: %d\n", end3 - begin3);

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	printf("HeapSort: %d\n", end4 - begin4);

	int begin5 = clock();
	BubbleSort(a5, N);
	int end5 = clock();
	printf("BubbleSort: %d\n", end5 - begin5);

	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();
	//printf("InsertSort: %d\n", end1 - begin1);

	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();
	//printf("InsertSort: %d\n", end1 - begin1);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

int main()
{

	//TestInsert();
	//TestShell();
	//TestOption();
	//TestHeap();
	//TestBubble();

	TestEfficiency();
	return 0;
}
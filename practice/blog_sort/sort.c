#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//��������
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//��ӡ����
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//��������
void InsertSort(int* a, int n)
{
	//for(int end = 1; end < n; end++)
	//{
	//	int key = a[end];
	//	int k = end - 1;
	//	while (k >= 0)
	//	{
	//		if (key > a[k])
	//		{
	//			break;
	//		}
	//		k--;
	//	}
	//	int tmp = end;
	//	while (tmp > k + 1)
	//	{
	//		Swap(&a[tmp], &a[tmp - 1]);
	//		tmp--;
	//	}
	//}

	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];

		while (end >= 0)
		{
			if (tmp < a[end])
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
//ϣ������
void ShellSort(int* a, int n);
//��������
void Swap(int* p1, int* p2);
//ѡ������
void OptionSort(int* a, int n);
//������
void HeapSort(int* a, int n);
//ð������
void BubbleSort(int* a, int n);
//��������
void QuickSort(int* a, int begin, int end);
//�ǵݹ����
void QuickSortNonR(int* a, int begin, int end);

//�鲢����--�ݹ�
void MergeSort(int* a, int n);
//�ǵݹ�
void MergeSortNonR(int* a, int n);

//��������
void CountSort(int* a, int n);



int main()
{
	int a[] = { 5,8,9,7,4,1,2,3,6,0 };
	int sz = sizeof(a) / sizeof(a[0]);
	InsertSort(a, sz);
	Print(a, sz);
	return 0;
}
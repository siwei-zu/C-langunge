#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void Print(int (*arr)[5], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			//printf("%d ", arr[i][j]);
//			printf("%d ", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6,},{3,4,5,6,7} };
//	Print(arr, 3, 5);
//	return 0;
//}

//int(*parr[10])[5];//parr是一个数组可以储存十个元素，每个元素的类型是int(*)[]这个类型是一个指针，该指针指向的类型是int [5],这是一个五个元素
////的整型数组


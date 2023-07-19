#pragma once
#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

//打印数组
void Print(int* a, int n);
//插入排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);
//交换函数
void Swap(int* p1, int* p2);
//选择排序
void OptionSort(int* a, int n);
//堆排序
void HeapSort(int* a, int n);
//冒泡排序
void BubbleSort(int* a, int n);
//快速排序
void QuickSort(int* a, int begin, int end);
//非递归快排
void QuickSortNonR(int* a, int begin, int end);

//归并排序--递归
void MergeSort(int* a, int n);
//非递归
void MergeSortNonR(int* a, int n);

//计数排序
void CountSort(int* a, int n);
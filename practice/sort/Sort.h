#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
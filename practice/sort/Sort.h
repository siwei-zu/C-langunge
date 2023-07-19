#pragma once
#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

//��ӡ����
void Print(int* a, int n);
//��������
void InsertSort(int* a, int n);
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
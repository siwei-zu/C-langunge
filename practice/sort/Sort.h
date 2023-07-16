#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//´òÓ¡Êı×é
void Print(int* a, int n);
//²åÈëÅÅĞò
void InsertSort(int* a, int n);
//Ï£¶ûÅÅĞò
void ShellSort(int* a, int n);
//½»»»º¯Êı
void Swap(int* p1, int* p2);
//Ñ¡ÔñÅÅĞò
void OptionSort(int* a, int n);
//¶ÑÅÅĞò
void HeapSort(int* a, int n);
//Ã°ÅİÅÅĞò
void BubbleSort(int* a, int n);
//¿ìËÙÅÅĞò
void QuickSort(int* a, int begin, int end);
//·Çµİ¹é¿ìÅÅ
void QuickSortNonR(int* a, int begin, int end);

//¹é²¢ÅÅĞò--µİ¹é
void MergeSort(int* a, int n);
//·Çµİ¹é
void MergeSortNonR(int* a, int begin, int end);
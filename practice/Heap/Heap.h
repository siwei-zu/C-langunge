#pragma once
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

//初始化堆
void HeapInit(Hp* hp);
//堆的插入
void HeapPush(Hp* hp, HeapData x);
//堆的销毁
void HeapDestory(Hp* hp);
//堆的删除
void HeapPop(Hp* hp);
// 取堆顶的数据
HeapData HeapTop(Hp* hp);
// 堆的数据个数
int HeapSize(Hp* hp);
// 堆的判空
int HeapEmpty(Hp* hp);
//向上调整
void AdjustUp(HeapData* a, int x);
//向下调整
void AdjustDown(HeapData* a, int n, int x);

void Swap(HeapData* x, HeapData* y);



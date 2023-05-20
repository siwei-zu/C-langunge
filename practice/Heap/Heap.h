#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HeapData;
typedef struct Heap
{
	HeapData* data;
	int size;
	int capcity;
}Hp;


void HeapInit(Hp* hp);
void HeapPush(Hp* hp, HeapData x);
void HeapDestory(Hp* hp);
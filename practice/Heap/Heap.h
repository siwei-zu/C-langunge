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

//��ʼ����
void HeapInit(Hp* hp);
//�ѵĲ���
void HeapPush(Hp* hp, HeapData x);
//�ѵ�����
void HeapDestory(Hp* hp);
//�ѵ�ɾ��
void HeapPop(Hp* hp);
// ȡ�Ѷ�������
HeapData HeapTop(Hp* hp);
// �ѵ����ݸ���
int HeapSize(Hp* hp);
// �ѵ��п�
int HeapEmpty(Hp* hp);
//���ϵ���
void AdjustUp(HeapData* a, int x);
//���µ���
void AdjustDown(HeapData* a, int n, int x);

void Swap(HeapData* x, HeapData* y);



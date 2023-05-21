#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct DTList {
	struct DTList* prev;
	DataType data;
	struct DTList* next;
}DTList;


//˫��������ʼ��
DTList* DTListInit();
//��ӡ
void DTListPrint(DTList* phead);
//����β��
void DTListPushBack(DTList* phead, DataType x);
//βɾ
void DTListPopBack(DTList* phead);
//ͷ��
void DTListPushFront(DTList* phead, DataType x);
//ͷɾ
void DTListPopFront(DTList* phead);
//����
DTList* DTListFind(DTList* phead, DataType x);
//ָ��λ�ò���
void DTListInsert(DTList* phead, DataType x);
//ָ��λ��ɾ��
void DTListErase(DTList* pos);
//����
void DTListdestroy(DTList* phead);
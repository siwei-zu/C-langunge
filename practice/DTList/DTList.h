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


//双向链表初始化
DTList* DTListInit();
//打印
void DTListPrint(DTList* phead);
//链表尾插
void DTListPushBack(DTList* phead, DataType x);
//尾删
void DTListPopBack(DTList* phead);
//头插
void DTListPushFront(DTList* phead, DataType x);
//头删
void DTListPopFront(DTList* phead);
//查找
DTList* DTListFind(DTList* phead, DataType x);
//指定位置插入
void DTListInsert(DTList* phead, DataType x);
//指定位置删除
void DTListErase(DTList* pos);
//销毁
void DTListdestroy(DTList* phead);
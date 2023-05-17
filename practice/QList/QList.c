#define _CRT_SECURE_NO_WARNINGS 1
#include "QList.h"

void QueueInit(Queue* q)
{
	assert(q);

	q->_front = NULL;
	q->_rear = NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode* NewData = (QNode*)malloc(sizeof(QNode));
	if (NewData == NULL)
	{
		perror("malloc fail");
		return;
	}
	NewData->data = data;
	NewData->next = NULL;
	if (q->_front == NULL)
	{
		q->_front = NewData;
		q->_rear = NewData;
	}
	else
	{
		q->_rear->next = NewData;
		q->_rear = NewData;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	if (q->_front->next == NULL)
	{
		free(q->_front);
		q->_front = NULL;
		q->_rear = NULL;
	}
	else
	{
		QNode* cur = q->_front;
		q->_front = q->_front->next;
		free(cur);
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->_front->data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->_rear->data;
}

int QueueSize(Queue* q)
{
	assert(q);

	QNode* cur = q->_front;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_front == NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->_front;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->_front = NULL;
	q->_rear = NULL;
}




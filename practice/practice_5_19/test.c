#define _CRT_SECURE_NO_WARNINGS 1
// 链式结构：表示队列 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);

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

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* MySt = (MyStack*)malloc(sizeof(MyStack));

	QueueInit(&(MySt->q1));
	QueueInit(&(MySt->q2));

	return MySt;
}

void myStackPush(MyStack* obj, int x) {
	Queue* real = &(obj->q1);
	if (QueueEmpty(&(obj->q1)))
	{
		real = &(obj->q2);
	}
	QueuePush(real, x);
}

int myStackPop(MyStack* obj) {
	Queue* real = &(obj->q1);
	Queue* empty = &(obj->q2);
	if (QueueEmpty(&(obj->q1)))
	{
		real = &(obj->q2);
		empty = &(obj->q1);
	}
	while (QueueSize(real) > 1)
	{
		QueuePush(empty, QueueFront(real));
		QueuePop(real);
	}
	int ret = QueueFront(real);
	QueuePop(real);
	return ret;
}

int myStackTop(MyStack* obj) {
	Queue* real = &(obj->q1);
	if (QueueEmpty(&(obj->q1)))
	{
		real = &(obj->q2);
	}
	return QueueBack(real);
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&(obj->q1));
	QueueDestroy(&(obj->q2));
	free(obj);
}
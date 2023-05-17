#define _CRT_SECURE_NO_WARNINGS 1
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// ջ��
	int capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ 
void StackPush(Stack* ps, STDataType data);
// ��ջ 
void StackPop(Stack* ps);
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);
// ����ջ 
void StackDestroy(Stack* ps);

void StackInit(Stack* ps)
{
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->capacity == ps->top)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

void StackDestroy(Stack* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

typedef struct {
	Stack st1;
	Stack st2;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* que = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&(que->st1));
	StackInit(&(que->st2));
	return que;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&(obj->st1), x);
}

int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&(obj->st2)))
	{
		while (!StackEmpty(&(obj->st1)))
		{
			StackPush(&(obj->st2), StackTop(&(obj->st1)));
			StackPop(&(obj->st1));
		}
	}
	int ret = StackTop(&(obj->st2));
	StackPop(&(obj->st2));
	return ret;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&(obj->st2)))
	{
		while (!StackEmpty(&(obj->st1)))
		{
			StackPush(&(obj->st2), StackTop(&(obj->st1)));
			StackPop(&(obj->st1));
		}
	}
	return (obj->st2).a[(obj->st2).top - 1];
}

bool myQueueEmpty(MyQueue* obj) {
	return (StackEmpty(&(obj->st1)) && StackEmpty(&(obj->st2)));
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&(obj->st1));
	StackDestroy(&(obj->st2));
}
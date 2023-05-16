#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

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






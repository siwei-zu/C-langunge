#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void TestStack()
{
	Stack st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);

	while (StackSize(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}


int main()
{
	TestStack();
	return 0;
}
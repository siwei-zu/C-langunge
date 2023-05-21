#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"


void HeapInit(Hp* hp)
{
	assert(hp);

	hp->capcity = hp->size = 0;
	hp->data = NULL;
}


void HeapPush(Hp* hp, HeapData x)
{
	assert(hp);

	if (hp->capcity == hp->size)
	{
		int Newcapcity = hp->capcity == 0 ? 4 : hp->capcity * 2;
		HeapData* tmp = (HeapData*)realloc(hp->data, Newcapcity * 2 * sizeof(HeapData));
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		hp->data = tmp;
		hp->capcity = Newcapcity;
	}
	hp->data[hp->size] = x;
	hp->size++;
	AdjustUp(hp->data, hp->size - 1);
}
void HeapDestory(Hp* hp)
{
	assert(hp);

	free(hp->data);
	hp->capcity = hp->size = 0;
}

void Swap(HeapData* x, HeapData* y)
{
	HeapData tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustUp(HeapData* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HeapData* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}

		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Hp* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	Swap(&hp->data[0], &hp->data[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->data, hp->size, 0);
}

HeapData HeapTop(Hp* hp)
{
	assert(hp);

	return hp->data[0];
}

int HeapSize(Hp* hp)
{
	assert(hp);

	return hp->size;
}

int HeapEmpty(Hp* hp)
{
	assert(hp);

	return hp->size == 0;
}


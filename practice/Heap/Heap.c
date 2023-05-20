#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"


void HeapInit(Hp* hp)
{
	hp->capcity = hp->size = 0;
	hp->data = NULL;
}


void HeapPush(Hp* hp, HeapData x)
{
	if (hp->capcity == hp->size)
	{
		int Newcapcity = hp->capcity == 0 ? 4 : hp->capcity * 2;
		HeapData* tmp = (HeapData*)realloc(hp->data, Newcapcity * 2);
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		hp->data = tmp;
		hp->capcity = Newcapcity;
	}
	hp->data[hp->size] = x;
	int i = hp->size;
	int j = hp->size / 2;
	while (hp->data[i] > hp->data[j])
	{
		HeapData tmp = hp->data[i];
		hp->data[i] = hp->data[j];
		hp->data[j] = tmp;
		i = j;
		j /= 2;
	}
	hp->size++;
}
void HeapDestory(Hp* hp)
{
	free(hp->data);
	hp->capcity = hp->size = 0;
}
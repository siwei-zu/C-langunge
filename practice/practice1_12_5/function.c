#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"

struct Stu {
	char name[20];
	char sex[5];
	int age;
};
void my_qsort(void* base, int num_t, int sz_t, int (*my_compare)(const void*, const void*))
{
	int i = 0;
	for (i = 0; i < num_t - 1; i++)
	{
		int j = 0;
		for (j = i + 1; j < num_t; j++)
		{
			//int ret = my_compare((struct Stu*)base + i, (struct Stu*)base + j);
			//int ret = my_compare((int*)base + i, (int*)base + j);
			int ret = my_compare((float*)base + i, (float*)base  + j);
			if (ret > 0)
			{
				//int tmp = *((int*)base + i);
				//*((int*)base + i) = *((int*)base + j);
				//*((int*)base + j) = tmp;
				//struct Stu tmp = *((struct Stu*)base + i);
				//*((struct Stu*)base + i) = *((struct Stu*)base  + j);
				//*((struct Stu*)base  + j) = tmp;
				float tmp = *((float*)base + i);
				*((float*)base + i) = *((float*)base + j);
				*((float*)base + j) = tmp;
			}
		}
	}
}

int my_compare(const void* e1, const void* e2)
{
	//return ((int*)e1)->age - ((int*)e2)->age;
	//return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
	return (int)(*((float*)e1) - *((float*)e2));
}
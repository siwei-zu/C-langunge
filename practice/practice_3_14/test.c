#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	while (num--)
	{
		*((char*)dest + num) = *((char*)src + num);
	}
	return ret;
}
//
//int main()//memcpy
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[20];
//	my_memcpy(arr2, arr1, sizeof(int) * 6);
//	int i = 0;
//	for (i = 0; i < 6; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}



#include <stdio.h>

void* my_memmove(void* dest, const void* src, size_t num)
{
	if (dest > src)
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	else
	{
		int i = 0;
		while (i < num)
		{
			*((char*)dest + i) = *((char*)src + i);
			i++;
		}
	}
}

int main()//memmove
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[20];
	my_memmove(arr2, arr1, sizeof(int) * 9);
	my_memmove(arr2, arr2 + 2, sizeof(int) * 5);
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	my_memcpy(arr2, arr1, sizeof(int) * 9);
	my_memmove(arr2 + 2, arr2, sizeof(int) * 5);
	for (i = 0; i < 9; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	my_memcpy(arr2, arr1, sizeof(int) * 9);
	my_memmove(arr2 + 3, arr2 , sizeof(int) * 3);
	for (i = 0; i < 9; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	return 0;
}
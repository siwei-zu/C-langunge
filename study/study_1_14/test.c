#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h>

//void maopao(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int a[] = { 2,5,4,1,3,6,8,9,7,0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(a + i));
//	}
//	printf("\n");
//	int sz = sizeof(a) / sizeof(a[0]);
//	maopao(a,sz);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(a + i));
//	}
//	printf("\n");
//	return 0;
//}

void swap(char e1, char e2)
{
	printf("%c->%c ", e1, e2);
}

void hannuota(int n,char pos1,char pos2,char pos3)
{
	if (n == 1)
		swap(pos1, pos2);
	else
	{
		hannuota(n - 1, pos1, pos3, pos2);
		swap(pos1, pos2);
		hannuota(n - 1, pos2, pos1, pos3);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	hannuota(n, 'A', 'B', 'C');
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void sort_num(int* arr, int sz)
{
	int l = 0;
	int r = sz - 1;
	while (l <= r)
	{
		if (arr[l] % 2 == 1 && arr[r] % 2 == 0)
		{
			int tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
		if (arr[r] % 2 == 1)
		{
			r--;
		}
		if (arr[l] % 2 == 0)
		{
			l++;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort_num(arr,sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* arr1, const char* arr2)
{
	char* ret = arr1;
	assert(arr1 && arr2);
	while (*(arr1++) = *(arr2++));
	return ret;
}

int main()
{
	char arr1[] = "************";
	char arr2[] = "hello world";
	printf("%s\n", my_strcpy(arr1,arr2));
	return 0;
}

#include <stdio.h>

unsigned int my_strlen(const char* arr)
{
	char* ret = arr;
	while (*arr)
	{
		arr++;
	}
	return arr - ret;
}

int main()
{
	char arr[] = "abcdef";
	printf("%d\n", my_strlen(arr));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int** arr = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * (i + 1));
        arr[i][0] = arr[i][i] = 1;
        int j = 0;
        for (j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
        j = 0;
        for (j = 0; j < i + 1; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
	return 0;
}

bool isIsomorphic(char* s, char* t) {
	int len = strlen(s);
	int i = 0;
	char* arr[128] = { 0 };
	char* arr1[128] = { 0 };
	for (i = 0; i < len; i++)
	{
		if (arr[s[i]] == 0 && arr1[t[i]] == 0)
		{
			arr1[t[i]] = s[i];
			arr[s[i]] = t[i];
		}
		else
		{
			if (t[i] != arr[s[i]] && arr1[t[i]] != s[i])
				return false;
		}
	}

	return true;
}
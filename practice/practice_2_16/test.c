#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int nums[] = { 1,3,2,1,3,2,2 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i = 0;
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0;
    answer[1] = numsSize;
    int* hash = (int*)malloc(sizeof(int) * 101);
    memset(hash, 0, sizeof(int) * 101);
    for (i = 0; i < numsSize; i++)
    {
        if (hash[nums[i]] == 0)
        {
            hash[nums[i]]++;
        }
        else
        {
            answer[0]++;
            answer[1] -= 2;
            hash[nums[i]] = 0;
        }
    }
	return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char arr[110] = {0};
    char arr1[110] = {0};
    gets(arr + 1);
    arr[0] = ' ';
    int len = strlen(arr + 1);
    arr[len+1] = ' ';
    int l = len ;
    int r = len ;
    int j = 0;
    while (l >= 0 && r >= 0)
    {
        while (arr[l] != ' ')
        {
            l--;
        }
        int k = l + 1;
        while (k <= r)
        {
            if (arr[k] != ' ')
            {
                arr1[j] = arr[k];
                j++;
            }
            k++;
        }
        arr1[j] = ' ';
        j++;
        r = l;
        l--;
    }
    printf("%s\n", arr1);
    return 0;
}

#include <stdio.h>
int count = 0;

int fib(int n)
{
	count++;
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 2;
	}
	else
		return fib(n - 1) + fib(n - 2);
}

int main()
{
	fib(8);
	printf("%d\n", count);
	return 0;
}

#include <stdio.h>
#include <string.h>

void reverse(char* l, char* r)
{
	while (l < r)
	{
		char tmp = *l;
		*l = *r;
		*r = tmp;
		l++;
		r--;
	}
}

int main()
{
	char arr[101] = { 0 };
	gets(arr);
	printf("%s\n", arr);
	int len = strlen(arr);
	reverse(arr,arr+len-1);
	char* cur = arr;
	while (*cur)
	{
		char* start = cur;
		while (*cur != ' ' && *cur != '\0')
		{
			*cur++;
		}
		reverse(start, cur - 1);
		if (*cur != '\0')
			cur++;
	}
	printf("%s\n", arr);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int l1 = strlen(a);
    int l2 = strlen(b);
    char* arr = (char*)malloc(sizeof(char) * (l1 + l2 + 1));
    memset(arr, '0', sizeof(char) * (l1 + l2 + 1));
    arr[l1 + l2] = '\0';
    int ind1 = l1 - 1;
    int ind2 = l2 - 1;
    if (l1 == l2 && l1 == 1 && a[0] == '0' && b[0] == '0')
        return arr + 1;
    int i = l1 + l2 - 1;
    for (i; i >= 1; i--)
    {
        if (ind1 == ind2 && ind1 == -1)
            break;
        else if (ind1 == -1)
        {
            arr[i] += b[ind2] % 2;
            ind2--;
        }
        else if (ind2 == -1)
        {
            arr[i] += a[ind1] % 2;
            ind1--;
        }
        else
        {
            arr[i] += a[ind1] % 2 + b[ind2] % 2;
            ind1--;
            ind2--;
        }
        if (arr[i] > '2')
        {
            arr[i - 1] += arr[i] % 2;
            arr[i] = arr[i] % 2 + 48;
        }
        else if (arr[i] == '2')
        {
            arr[i - 1] += 1;
            arr[i] = '0';
        }
    }
    while (*arr == '0')
    {
        arr++;
    }
    return arr;
}

int main()
{
    int x = -1;
    unsigned int y = 2;
    if (x > y)
    {
        printf("x is greater");
    }
    else
    {
        printf("y is greater");
    }
    return 0;
}

int main()
{
	int i = 1;
	sizeof(i++);
	printf("%d\n", i);
	return 0;
}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i = 0;
    int max = 0;
    int count = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            max = max > count ? max : count;
            count = 0;
        }
    }
    max = max > count ? max : count;
    return max;
}

int main() {
    int i = 0;
    int n = 0;
    int count = 0;
    int count_result = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        count = 0;
        int j = 1;
        for (j = 1; j < i / 2 + 1; j++)
        {
            if (i % j == 0)
                count += j;
        }
        if (count == i)
            count_result++;
    }
    printf("%d", count_result);
}
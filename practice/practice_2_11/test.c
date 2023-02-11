#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n == 0)
	{
		printf("%d", 0);
	}
	else
	{
		printf("%d", 2 * n - 1);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n = 0;
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    i = 0;
    int result = 0;
    for (i = 0; i < n; i++)
    {
        result ^= arr[i];
    }
    printf("%d", result);
}


int findPeakElement(int* nums, int numsLen) {
    int i = 0;
    if (numsLen == 1)
        return 0;
    for (i = 0; i < numsLen; i++)
    {
        if (i != 0 && i != numsLen - 1)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
        else if (i == 0)
        {
            if (nums[i] > nums[i + 1])
                return i;
        }
        else
        {
            if (nums[i] > nums[i - 1])
                return i;
        }
    }
    return -1;
}


int findPeakElement(int* nums, int numsLen) {
    int l = 0;
    int r = numsLen - 1;
    if (numsLen == 1)
    {
        return 0;
    }
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
        {
            return mid;
        }
        else if (nums[mid] > nums[mid + 1])
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return l;
}

static int cmp(const void* pa, const void* pb) {
    return *(int*)pa - *(int*)pb;
}

int fillCups(int* amount, int amountSize) {
    qsort(amount, amountSize, sizeof(int), cmp);
    if (amount[2] > amount[1] + amount[0]) {
        return amount[2];
    }
    return (amount[0] + amount[1] + amount[2] + 1) / 2;


}
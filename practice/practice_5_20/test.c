#define _CRT_SECURE_NO_WARNINGS 1
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[parent] < a[child])
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



int* sortArray(int* nums, int numsSize, int* returnSize) {
	int i = 0;
	for (i = (numsSize - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(nums, numsSize, i);
	}

	for (i = numsSize - 1; i >= 0; i--)
	{
		Swap(&nums[0], &nums[i]);
		AdjustDown(nums, i, 0);
	}
	*returnSize = numsSize;
	return nums;
}
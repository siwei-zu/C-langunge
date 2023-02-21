#define _CRT_SECURE_NO_WARNINGS 1
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    (*returnSize) = numsSize;
    int l = 0;
    int r = numsSize - 1;
    int k = numsSize - 1;
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    while (l <= r)
    {
        if (nums[l] * nums[l] > nums[r] * nums[r])
        {
            arr[k] = nums[l] * nums[l];
            l++;
        }
        else
        {
            arr[k] = nums[r] * nums[r];
            r--;
        }
        k--;
    }
    return arr;
}

void rotate(int* nums, int numsSize, int k) {
    int left = 0;
    int right = numsSize - 1;
    int tmp;
    int count = k % numsSize;
    for (left, right; left <= right; left++, right--)
    {
        tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
    for (left = 0, right = count - 1; left <= right; left++, right--)
    {
        tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
    for (left = count, right = numsSize - 1; left <= right; left++, right--)
    {
        tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
}
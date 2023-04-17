#define _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize) {
    int fast = 0;
    int slow = 0;
    for (slow = 1, fast = 1; fast < numsSize; fast++)
    {
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow++] = nums[fast];

        }
    }
    return slow;
}
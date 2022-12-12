#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//int majorityElement(int* nums, int numsSize) {//多数元素的两种解法，一种是排序，另一种是摩尔投票
//    int count = 1;
//    int a = nums[0];
//    int i = 0;
//    for (i = 1; i < numsSize; i++)
//    {
//        if (count == 0)
//            a = nums[i];
//        if (nums[i] == a)
//            count++;
//        else
//            count--;
//    }
//    return a;
//}
//
//int cmp(const void* x, const void* y)
//{
//    return *(int*)x - *(int*)y;
//}
//
//int majorityElement(int* nums, int numsSize) {
//    qsort(nums, numsSize, sizeof(int), cmp);
//    return nums[numsSize / 2];
//}

#include <stdio.h>

int main() {
    printf("%c%c%c%c%c%c%c%c%c%c%c%c\n", 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33);
    return 0;
}
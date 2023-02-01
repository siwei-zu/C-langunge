#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
//int main()
//{
//	char key[] = "the quick brown fox jumps over the lazy dog";
//	char message[] = "vkbs bs t suepuv";
//    char arr[123] = { 0 };
//    char arr1[123] = { 0 };
//    int len = strlen(key);
//    int left = 'a';
//    int i = 0;
//    for (i = 0; i <= len && left <= 'z'; i++)
//    {
//        if (arr[key[i]] == 0 && key[i] != ' ')
//        {
//            arr1[key[i]] = left;
//            left++;
//            arr[key[i]] = 1;
//        }
//    }
//    int len2 = strlen(message);
//    for (i = 0; i < len2; i++)
//    {
//        if (message[i] != ' ')
//        {
//            message[i] = arr1[message[i]];
//        }
//    }
//    printf("%s", message);
//    return 0;
//}
//用一个循环找到数组中最大的两个数
//int dominantIndex(int* nums, int numsSize) {
//    int i = 0;
//    int m1 = -1;
//    int m2 = -1;
//    int index = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > m1) {
//            m2 = m1;
//            m1 = nums[i];
//            index = i;
//        }
//        else if (nums[i] > m2) {
//            m2 = nums[i];
//        }
//    }
//    return m1 >= m2 * 2 ? index : -1;
//}
//两个数组的交集
//模拟，表
//int main()
//{
    //int nums1[] = {1,2,2,1};
    //int nums1Size = 4;
    //int nums2[] = { 2,2 };
    //int nums2Size = 2;
//    int arr1[1001] = { 0 };
//    int arr2[1001] = { 0 };
//    int arr3[1001] = { 0 };
//    int i = 0;
//    int k = 0;
//    int max = 0;
//    for (i = 0; i < nums1Size; i++)
//    {
//        arr1[nums1[i]]++;
//        max = max > nums1[i] ? max : nums1[i];
//    }
//    for (i = 0; i < nums2Size; i++)
//    {
//        arr2[nums2[i]]++;
//        max = max > nums2[i] ? max : nums2[i];
//    }
//    for (i = 0; i <= max; i++)
//    {
//        int count = arr1[i] < arr2[i] ? arr1[i] : arr2[i];
//        if (count != 0)
//            count = 1;
//        int j = 0;
//        for (j = 0; j < count; j++)
//        {
//            arr3[k] = i;
//            k++;
//        }
//    }
//    int* arr4 = (int*)malloc(sizeof(int) * k);
//    for (i = 0; i < k; i++)
//    {
//        arr4[i] = arr3[i];
//    }
//    for (i = 0; i < k; i++)
//    {
//        printf("%d ", arr4[i]);
//    }
//    //*returnSize = k;
//    return 0;
//}

//int cmp(const void* e1, const void* e2)
//{
//    return (*(int*)e1 - *(int*)e2);
//}
////两个数组的交集
////二分查找，双指针
//int main()
//{
//    int nums1[] = { 1,2,2,1 };
//    int nums1Size = 4;
//    int nums2[] = { 2,2 };
//    int nums2Size = 2;
//    qsort(nums1, nums1Size, sizeof(int), cmp);
//    qsort(nums2, nums2Size, sizeof(int), cmp);
//    int* arr = (int*)malloc(sizeof(int) * 1000);
//    int* arr1 = (int*)malloc(sizeof(int) * 1001);
//    memset(arr1, 0, sizeof(int) * 1001);
//    int i = 0;
//    int k = 0;
//    for (i = 0; i < nums1Size; i++)
//    {
//        int target = nums1[i];
//        int l = 0;
//        int r = nums2Size - 1;
//        while (l <= r)
//        {
//            int mid = (l + r) / 2;
//            if (nums2[mid] > target)
//                r = mid - 1;
//            else if (nums2[mid] < target)
//                l = mid + 1;
//            else
//            {
//                if (arr1[target] == 0)
//                {
//                    arr[k] = target;
//                    k++;
//                    arr1[target] = 1;
//                }
//                break;
//            }
//        }
//    }
//    int* arr2 = (int*)malloc(sizeof(int) * k);
//    for (i = 0; i < k; i++)
//    {
//        arr2[i] = arr[i];
//    }
//    //*returnSize = k;
//    free(arr);
//    free(arr1);
//    for (i = 0; i < k; i++)
//    {
//        printf("%d ", arr2[i]);
//    }
//    return 0;
//}
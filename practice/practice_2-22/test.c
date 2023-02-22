#define _CRT_SECURE_NO_WARNINGS 1
//void moveZeroes(int* nums, int numsSize) {
//    int slow = 0;
//    int fast = 0;
//    for (fast, slow; fast < numsSize; fast++)
//    {
//        if (nums[fast] != 0)
//        {
//            int tmp = nums[slow];
//            nums[slow++] = nums[fast];
//            nums[fast] = tmp;
//        }
//    }
//}
//
//int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
//    int left = 0;
//    int right = numbersSize - 1;
//    for (; left < numbersSize || right >= 0;)
//    {
//        if (numbers[left] + numbers[right] > target)
//            right--;
//        else if (numbers[left] + numbers[right] < target)
//            left++;
//        else
//        {
//            *returnSize = 2;
//            numbers[0] = left + 1;
//            numbers[1] = right + 1;
//            break;
//        }
//    }
//    return numbers;
//}


//Ğı×ªÊı×é
//×óĞı


//#include <stdio.h>
//#include <assert.h>
//int my_strlen(char* str)
//{
//	char* ret = str;
//	while (*ret)
//	{
//		ret++;
//	}
//	return ret - str;
//}
//
//char* revolve_array(char* arr, int k)
//{
//	assert(arr);
//	int len = my_strlen(arr);
//	int count = k % len;
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left++] = arr[right];
//		arr[right--] = tmp;
//	}
//	left = len - count;
//	right = len - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left++] = arr[right];
//		arr[right--] = tmp;
//	}
//	left = 0;
//	right = len - count - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left++] = arr[right];
//		arr[right--] = tmp;
//	}
//	return arr;
//}
//
//int main()
//{
//	char arr[] = "ABCDEF";//FEDCBA  FE  ABCD
//	int k = 0;
//	scanf("%d", &k);
//	printf("%s\n", arr);
//	printf("%s\n", revolve_array(arr, k));
//	return 0;
//}
////ÓÒĞı
//char* revolve_array(char* arr, int k)
//{
//	assert(arr);
//	int len = my_strlen(arr);
//	int count = k % len;
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left++] = arr[right];
//		arr[right--] = tmp;
//	}
//	left = 0;
//	right = count - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left++] = arr[right];
//		arr[right--] = tmp;
//	}
//	left = count;
//	right = len - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left++] = arr[right];
//		arr[right--] = tmp;
//	}
//	return arr;
//}
//
//int main()
//{
//	char arr[] = "ABCDEF";//FEDCBA  FE  ABCD
//	int k = 0;
//	scanf("%d", &k);
//	printf("%s\n", arr);
//	printf("%s\n", revolve_array(arr, k));
//	return 0;
//}

#include <stdio.h>

void generate_matrix(int m, int n)
{

}

void find_target_in_matrix(int m, int n, int target)
{

}


int main()
{
	int m = 0;
	int n = 0;
	int target = 0;
	scanf("%d %d %d", &m, &n, &target);


	find_target_in_matrix(m, n, target);
	return 0;
}
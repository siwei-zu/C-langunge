#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 0,2,4,6,8 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置

//#include <stdio.h>
//
//void Print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//}
//
//void Reverse(int* arr, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//void Init(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	Print(arr, sz);
//	Reverse(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	Init(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//
//void maopao(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int a[] = { 2,5,4,1,3,6,8,9,7,0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(a + i));
//	}
//	printf("\n");
//	int sz = sizeof(a) / sizeof(a[0]);
//	maopao(a,sz);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(a + i));
//	}
//	printf("\n");
//	return 0;
//}

//int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//    int* arr = (int*)malloc((sizeof(int) * (numsSize + 1)));
//    *returnSize = 2;
//    memset(arr, 0, sizeof(int) * (numsSize + 1));
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        arr[nums[i] - 1]++;
//        if (arr[nums[i] - 1] == 2)
//            ret[0] = nums[i];
//    }
//    for (i = 0; i < numsSize; i++)
//    {
//        if (arr[i] == 0)
//            ret[1] = i + 1;
//    }
//    return ret;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int* count = (int*)malloc(sizeof(int) * 101);//判断输出yes还是no
    memset(count, 0, sizeof(int) * 101);
    int* count1 = (int*)malloc(sizeof(int) * 3);//判断密码格式是否符合
    memset(count1, 0, sizeof(int) * 3);
    char* arr = (char*)malloc(sizeof(char) * 101);
    memset(arr, 0, sizeof(char) * 101);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr);
        if ((arr[0] >= '0' && arr[0] <= '9') == 0 && strlen(arr) >= 8)
        {
            int j = 0;
            int flag = 0;
            for (j = 0; arr[j] != '\0'; j++)
            {
                if (arr[j] >= 'a' && arr[j] <= 'z')
                    count1[0] = 1;
                else if (arr[j] >= 'A' && arr[j] <= 'Z')
                    count1[1] = 1;
                else if (arr[j] >= '0' && arr[j] <= '9')
                    count1[2] = 1;
            }
            if (count1[0] + count1[1] + count1[2] >= 2)
                count[i] = 1;
        }
        memset(count1, 0, sizeof(int) * 3);
        memset(arr, 0, sizeof(char) * 101);
    }
    for (i = 0; i < n; i++)
    {
        if (count[i] == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

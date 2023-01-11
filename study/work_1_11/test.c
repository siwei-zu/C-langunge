#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char s[] = "\\123456\123456\t";
//	printf("%d\n", strlen(s));
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int cmp(const void* x, const void* y)
//{
//    return *(int*)x - *(int*)y;
//}
//
//int main() {
//    int a = 0;
//    int* arr = (int*)malloc(sizeof(int) * 200);
//    memset(arr, 0, sizeof(int) * 200);
//    scanf("%d", &a);
//    int flag = a * a * a;
//    int i = 0;
//    int count = 0;
//    int left = a * a;
//    int right = a * a;
//    int count1 = 0;
//    for (i = 0; count != flag; i += 2)
//    {
//        if (a * a % 2 == 0 && i == 0)
//        {
//            left--;
//            right++;
//            count = left + right;
//            arr[i] = left;
//            arr[i + 1] = right;
//            i += 2;
//            count1 += 2;
//        }
//        else if (a * a % 2 != 0 && i == 0)
//        {
//            count += a * a;
//            arr[i] = a * a;
//            i++;
//            left -= 2; right += 2;
//            count += (left + right);
//            arr[i] = left;
//            arr[i + 1] = right;
//            i += 2;
//            count1 += 2;
//        }
//        if (count == flag)
//            break;
//        left -= 2;
//        right += 2;
//        count += (left + right);
//        arr[i] = left;
//        arr[i + 1] = right;
//        count1 += 2;
//    }
//    qsort(arr, count1, sizeof(int), cmp);
//    for (i = 0; i <= 200; i++)
//    {
//        if (arr[i + 1] == 0)
//        {
//            printf("%d", arr[i]);
//            break;
//        }
//        printf("%d+", arr[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int n = 0;  scanf("%d", &n);  n--;  int x = 2;  int sum = 2;
//    while (n)
//    {
//        x += 3;
//        n--;
//        sum += x;
//    }
//    printf("%d", sum);
//    return 0;
//}

//bool digitCount(char* num) {
//    int* arr = (int*)malloc(sizeof(int) * 10);
//    memset(arr, 0, sizeof(int) * 10);
//    int i = 0;
//    while (num[i])
//    {
//        arr[num[i] - 48]++;
//        i++;
//    }
//    for (i = 0; num[i] != '\0'; i++)
//    {
//        if (num[i] - 48 != arr[i])
//            return false;
//    }
//    return true;
//}
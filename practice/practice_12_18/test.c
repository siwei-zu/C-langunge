#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//int main()
//{
//	char words[100][100] = { "dcedceadceceaeddcedc","dddcebcedcdbaeaaaeab","eecbeddbddeadcbbbdbb","decbcbebbddceacdeadd","ccbddbaedcadedbcaaae","dddcaadaceaedcdceedd","bbeddbcbbccddcaceeea","bdabacbbdadabbbddaea" };
//	int wordsSize = 8;
//    int arr[123] = { 0 };
//    int i = 0;
//    int count = 0;
//    for (i = 0; i < wordsSize - 1; i++)
//    {
//        int j = 0;
//        for (j = 0; words[i][j] != '\0'; j++)
//        {
//            if (arr[words[i][j]] == 0)
//            {
//                arr[words[i][j]] += 1;
//            }
//        }
//        int k = 0;
//        int brr[123] = { 0 };
//        for (j = i + 1; j < wordsSize; j++)
//        {
//            for (k = 0; words[j][k] != '\0'; k++)
//            {
//                if (brr[words[j][k]] == 0)
//                    brr[words[j][k]]++;
//            }
//            int input = 0;
//            int x = 0;
//            for (x = 97; x <= 122; x++)
//            {
//                if (arr[x] != brr[x])
//                    input = 1;
//            }
//            if (input == 0)
//                count++;
//            memset(brr, 0, sizeof(int) * 123);
//        }
//        memset(arr, 0, sizeof(int) * 123);
//    }
//    printf("%d\n", count);
//    return 0;
//}

int main()
{
	int n = 16;
    int i = 0;
    for (i = (int)sqrt(n); i >1; i--)
    {
        if (n % i == 0)
        {
            n = i + (n / i);
            i = (int)sqrt(n)+1;
        }
    }
    printf("%d\n", n);
    return 0;
}

//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48--sizeof（数组名）求的是整个数组的大小
//	printf("%d\n", sizeof(a[0][0]));//4-第一行第一个元素的大小
//	printf("%d\n", sizeof(a[0]));//16--第一行数组的大小
//	printf("%d\n", sizeof(a[0] + 1));//4--地址，指向第一行第二个元素
//	printf("%d\n", sizeof(*(a[0] + 1)));//4--第一行第二个元素的大小
//	printf("%d\n", sizeof(a + 1));//4/8--第二行数组的地址
//	printf("%d\n", sizeof(*(a + 1))); //16--第二行整个数组的大小
//	printf("%d\n", sizeof(&a[0] + 1));//4/8--第二行数组的地址
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	printf("%d\n", sizeof(*a));//16
//	printf("%d\n",sizeof(a[3]));//16
//	//谨记，sizeof（数组名），这里的数组表示整个数组，计算的是整个数组的大小
//	//&数组名，这里的数组名表示整个数组，取出的是整个数组的地址
//	//除此之外所有的数组名都表示首元素地址。
//	return 0;
//}
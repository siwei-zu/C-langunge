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
//	//��ά����
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48--sizeof�����������������������Ĵ�С
//	printf("%d\n", sizeof(a[0][0]));//4-��һ�е�һ��Ԫ�صĴ�С
//	printf("%d\n", sizeof(a[0]));//16--��һ������Ĵ�С
//	printf("%d\n", sizeof(a[0] + 1));//4--��ַ��ָ���һ�еڶ���Ԫ��
//	printf("%d\n", sizeof(*(a[0] + 1)));//4--��һ�еڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(a + 1));//4/8--�ڶ�������ĵ�ַ
//	printf("%d\n", sizeof(*(a + 1))); //16--�ڶ�����������Ĵ�С
//	printf("%d\n", sizeof(&a[0] + 1));//4/8--�ڶ�������ĵ�ַ
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	printf("%d\n", sizeof(*a));//16
//	printf("%d\n",sizeof(a[3]));//16
//	//���ǣ�sizeof����������������������ʾ�������飬���������������Ĵ�С
//	//&���������������������ʾ�������飬ȡ��������������ĵ�ַ
//	//����֮�����е�����������ʾ��Ԫ�ص�ַ��
//	return 0;
//}
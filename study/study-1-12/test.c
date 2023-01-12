#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int is_leap_year(int x)
//{
//	if ((0 == x % 4 && x % 100 != 0) || (0 == x % 400))
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		//判断y是否为闰年
//		//如果是闰年返回1
//		//不是闰年返回0
//		if (is_leap_year(y))
//		{
//			printf("%d ", y);
//		}
//	}
//	return 0;
//}

//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int x = 0;
//    int count = 0;
//    float sum = 0.0f;
//    int count1 = 0;
//    while (n)
//    {
//        scanf("%d", &x);
//        n--;
//        if (x < 0)
//            count1++;
//        else if (x > 0)
//        {
//            count++;
//            sum += x;
//        }
//    }
//    printf("%d %.1f", count1, sum / count);
//    return  0;;
//}

//int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
//    int min = rotateArray[0];
//    int i = 0;
//    for (i = 1; i < rotateArrayLen; i++)
//    {
//        min = rotateArray[i] < min ? rotateArray[i] : min;
//    }
//    return min;
//}

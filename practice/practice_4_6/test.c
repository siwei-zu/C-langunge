#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int i = 0;
//    int n = 0;
//    scanf("%d", &n);
//    int count = 0;
//    int count1 = 0;
//    int* arr = (int*)calloc(n, sizeof(int));
//    while (i < n)
//    {
//        int tmp = 0;
//        scanf("%d", &tmp);
//        arr[tmp - 1]++;
//        i++;
//    }
//    i = 0;
//    while (i < n)
//    {
//        if (arr[i] == 1)
//        {
//            count++;
//            count1 += i + 1;
//        }
//        i++;
//    }
//    printf("%d %d", count, count1);
//    return 0;
//}

//long long ans = 0;
//int decide = 1;
//int flag = 1;
//while (1)
//{
//	if (*s == '-' || *s == '+' || (*s > '0' && *s <= '9'))
//	{
//		if ((flag == 0) && (*s == '-' || *s == '+'))
//			return 0;
//		break;
//	}
//	else if (*s == ' ' || *s == '0')
//	{
//		if (*s == '0')
//			flag = 0;
//		if (*s == ' ' && flag == 0)
//			return 0;
//		s++;
//	}
//	else
//	{
//		return (int)(ans);
//	}
//}
//if (*s == '-')
//{
//	decide = -1;
//	s++;
//}
//else if (*s == '+')
//{
//	s++;
//}
//while (*s)
//{
//	if (*s >= '0' && *s <= '9')
//	{
//		ans *= 10;
//		ans += *s - 48;
//		if ((ans >= INT_MIN && ans <= INT_MAX) == 0)
//		{
//			if (decide > 0)
//				return INT_MAX;
//			else
//				return INT_MIN;
//		}
//	}
//	else
//	{
//		if ((ans >= INT_MIN && ans <= INT_MAX) == 0)
//		{
//			if (decide > 0)
//				return INT_MAX;
//			else
//				return INT_MIN;
//		}
//		return (ans * decide);
//	}
//	s++;
//}
//if ((ans >= INT_MIN && ans <= INT_MAX) == 0)
//{
//	if (decide > 0)
//		return INT_MAX;
//	else
//		return INT_MIN;
//}
//return (ans * decide);
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int reverse(int x) {
    if (x == 0)
        return 0;
    int num = x;
    int i = 0;
    int sgn = 1;
    if (x < 0)
        sgn = -1;
    char zheng[] = "2147483647";
    char fu[] = "2147483648";
    char decide[11] = { 0 };
    while (num % 10 == 0)
    {
        num /= 10;
    }
    while (num)
    {
        decide[i] += abs(num % 10) + 48;
        i++;
        num /= 10;
    }
    int len = strlen(decide);
    if (len < 10)
        return atoi(decide) * sgn;
    else
    {
        if (x > 0)
        {
            if (strcmp(zheng, decide) > 0)
                return atoi(decide) * sgn;
            else if (strcmp(zheng, decide) == 0)
                return INT_MAX;
            else
                return 0;
        }
        else
        {
            if (strcmp(fu, decide) > 0)
                return atoi(decide) * sgn;
            else if (strcmp(fu, decide) == 0)
                return INT_MIN;
            else
                return 0;
        }
    }
}

int main()
{
	int x = 1534236469;
	printf("%d\n", reverse(x));
	return 0;
}
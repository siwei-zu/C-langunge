#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//    int grid[4][4] = { {2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2} };
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        int j = 0;
//        for (j = 0; j < 4; j++)
//        {
//            if ((i == j || i == (-1) * j + 4 - 1) && grid[i][j] == 0)
//            {
//                printf("false\n");
//                return 0;
//            }
//            else
//            {
//                if (grid[i][j] != 0)
//                {
//                    printf("false\n");
//                    return 0;
//                }
//            }
//        }
//    }
//    printf("true\n");
//    return 0;
//}
//
//
//int mySqrt(int x) {
//    int left = 0;
//    int right = x;
//    int ans = -1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if ((long long)mid * mid <= x)
//        {
//            left = mid + 1;
//            ans = mid;
//        }
//        else if ((long long)mid * mid > x)
//            right = mid - 1;
//    }
//    return ans;
//}

int decide(unsigned int C)
{
    int count = 0;
    while (C)
    {
        C &= (C - 1);
        count++;
    }
    return count;
}

int convertInteger(int A, int B) {
    int C = A ^ B;
    return decide(C);
}
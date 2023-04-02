#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int maxArea(int* height, int heightSize) {//Ë«Ö¸Õë
    int l = 0;
    int r = heightSize - 1;
    int max = 0;
    while (l < r)
    {
        int tmp = abs(r - l) * (height[l] > height[r] ? height[r] : height[l]);
        max = max > tmp ? max : tmp;
        if (height[l] >= height[r])
            r--;
        else
            l++;
    }
    return max;
}

//int maxArea(int* height, int heightSize)
//{
//    int i = 0;
//    int j = 0;
//    int max = 0;
//    for (i = 0; i < heightSize - 1; i++)
//    {
//        for (j = i + 1; j < heightSize; j++)
//        {
//            int tmp = ((j - i) * (height[i] > height[j] ? height[j] : height[i]));
//            max = max > tmp ? max : tmp;
//        }
//    }
//    return max;
//}

int main()
{
	int arr[] = { 1,8,6,2,5,4,8,3,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d", maxArea(arr, sz));
	return 0;
}
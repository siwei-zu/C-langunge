#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    int prev = -1;
    for (int i = 0; i < flowerbedSize; ++i) {
        if (flowerbed[i] == 1) {
            if (prev < 0) {
                count += i / 2;
            }
            else {
                count += (i - prev - 2) / 2;
            }
            prev = i;
        }
    }
    if (prev < 0) {
        count += (flowerbedSize + 1) / 2;
    }
    else {
        count += (flowerbedSize - prev - 1) / 2;
    }
    return count >= n;
}

//bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
//    int i = 0;
//    while (i < flowerbedSize)
//    {
//        if (flowerbed[i] == 0 && i + 2 < flowerbedSize && flowerbed[i + 2] == 0)
//        {
//            flowerbed[i + 1] = 1;
//            n--;
//        }
//        if (i == flowerbed[flowerbedSize - 2]
//            && flowerbed[flowerbedSize - 2] == 0
//            && flowerbed[flowerbedSize - 1] == 0)
//        {
//            flowerbed[i + 1] = 1;
//            n--;
//        }
//
//        i++;
//    }
//    if (n > 0)
//        return false;
//    else
//        return true;
//}

int main()
{
    int flowerbed[] = { 1,0,1,0,1,0,1 };
    int flowerbedSize = sizeof(flowerbed) / sizeof(flowerbed[0]);
    int n = 2;

    printf("%d\n", canPlaceFlowers(flowerbed, flowerbedSize, n));
	return 0;
}
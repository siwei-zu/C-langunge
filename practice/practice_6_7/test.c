#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (flowerbedSize == 1)
    {
        if (flowerbed[0] == 1)
        {
            if (n == 0)
                return true;
            else
                return false;
        }
        if (flowerbed[0] == 0)
        {
            if (n <= 1)
                return true;
            else
                return false;
        }
    }


    int i = 0;
    for (i = 0; i < flowerbedSize && n > 0; i++)
    {
        if (flowerbed[i] == 0)
        {
            if (i - 1 < 0)
            {
                if (flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (i + 1 == flowerbedSize)
            {
                if (flowerbed[i - 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
    }
    if (n == 0)
        return true;
    else
        return false;
}

char* reverseVowels(char* s) {
    int l = 0;
    int r = strlen(s) - 1;
    while (l < r)
    {
        if ((s[l] == 'a' || s[l] == 'i' || s[l] == 'e' || s[l] == 'o' || s[l] == 'u'
            || s[l] == 'A' || s[l] == 'I' || s[l] == 'E' || s[l] == 'O' || s[l] == 'U')
            && (s[r] == 'a' || s[r] == 'i' || s[r] == 'e' || s[r] == 'o' || s[r] == 'u'
                || s[r] == 'A' || s[r] == 'I' || s[r] == 'E' || s[r] == 'O' || s[r] == 'U'))
        {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
        if ((s[l] == 'a' || s[l] == 'i' || s[l] == 'e' || s[l] == 'o' || s[l] == 'u'
            || s[l] == 'A' || s[l] == 'I' || s[l] == 'E' || s[l] == 'O' || s[l] == 'U') == 0)
            l++;
        if ((s[r] == 'a' || s[r] == 'i' || s[r] == 'e' || s[r] == 'o' || s[r] == 'u'
            || s[r] == 'A' || s[r] == 'I' || s[r] == 'E' || s[r] == 'O' || s[r] == 'U') == 0)
            r--;
    }
    return s;
}

int main()
{
    char s[] = "leetcode";
    char* res = reverseVowels(s);
    int flowerbed[] = {1, 0, 0, 0, 1};
    int flowerbedSize = sizeof(flowerbed) / sizeof(flowerbed[0]);
    int returnSize = 0;
    int ret = canPlaceFlowers(flowerbed, flowerbedSize, &returnSize);
    return 0;
}
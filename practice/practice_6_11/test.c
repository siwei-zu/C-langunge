#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//void moveZeroes(int* nums, int numsSize) {
//    int slow = 0;
//    int fast = 0;
//    for (fast, slow; fast < numsSize; fast++)
//    {
//        if (nums[fast] != 0)
//        {
//            int tmp = nums[slow];
//            nums[slow++] = nums[fast];
//            nums[fast] = tmp;
//        }
//    }
//}

bool isSubsequence(char* s, char* t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    if (len1 > len2)
        return false;
    char* s1 = s;
    for (int j = 0; j < len2 && *s != '\0'; j++)
    {
        int i = 0;
        s1 = s;
        for (i = 0; i < len2 && *s1 != '\0'; i++)
        {
            if (*s1 == t[i])
            {
                s1++;
            }
        }
    }
    if (*s == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char s[] = "abc";
    char t[] = "ahbgdc";
    printf("%d", isSubsequence(s, t));
    return 0;
}
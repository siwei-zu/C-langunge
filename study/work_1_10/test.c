#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
//int main()
//{
//    int* printNumbers(int n, int* returnSize) {
//        int x = n;
//        int num = 1;
//        while (x)
//        {
//            num *= 10;
//            x--;
//        }
//        int* arr = (int*)malloc(sizeof(int) * (num - 1));
//        for (x = 0; x < num; x++)
//        {
//            arr[x] = x + 1;
//        }
//        *returnSize = (num - 1);
//        return arr;
//    }
//}

//int main()
//{
//	int y[5 + 3];
//	double x[5] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
//	char c2[] = { '\x10', '\xa', '\8' };
//	char c1[] = { '1','2','3','4','5' };
//	return 0;
//}

//#include <stdio.h>
//int main() {
//    int year; int yue;  int day;  int count = 0;
//    scanf("%d%d%d", &year, &yue, &day);   int x = yue;    yue--;
//    do {
//        switch (yue)
//        {
//        case 1:count += 31; break;   case 2:count += 28; break;  case 3:count += 31; break;
//        case 4:count += 30; break;   case 5:count += 31; break;  case 6:count += 30; break;
//        case 7:count += 31; break;   case 8:count += 31; break;  case 9:count += 30; break;
//        case 10:count += 31; break;  case 11:count += 30; break;
//        }
//    } while (yue--);
//    if (((0 == year % 4 && year % 100 != 0) || (0 == year % 400)) && x > 2)  count++;
//    printf("%d", count + day);
//    return 0;
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int main()无重复字符的最长子串
//{
//    int lengthOfLongestSubstring(char* s) {
//        int* map = malloc(sizeof(int) * 128);
//        memset(map, 0, sizeof(int) * 128);
//        int len = strlen(s);
//        if (len == 0)
//            return 0;
//        int left = 0;
//        int right = 0;
//        int max = 0;
//        int count = 0;
//        for (left = 0, right = 0; left < len && right < len; )
//        {
//            if (map[s[right]] == 0)
//            {
//                map[s[right]]++;
//                right++;
//            }
//            else
//            {
//                map[s[left]] = 0;
//                left++;
//            }
//            max = max > right - left ? max : right - left;
//        }
//
//        return max;
//    }
//}

//优化
int main()
{
    char s[] = "dvdf";
    int* map = malloc(sizeof(int) * 128);
    memset(map, 0, sizeof(int) * 128);
    int len = strlen(s);
    if (len == 0)
        return 0;
    int left = 0;
    int right = 0;
    int max = 0;
    int count = 0;
    for (left = 0, right = 0; left < len && right < len; )
    {
        if (map[s[right]] == 0)
        {
            map[s[right]]++;
            right++;
        }
        else
        {
            map[s[left]] = 0;
            left++;
        }
        max = max > right-left ? max : right - left;
    }
    printf("%d\n", max);
    return 0;
}
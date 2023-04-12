#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <string.h>
//回文子串

//int countSubstrings(char* s) {
//    int len = strlen(s);
//    int count = 0;
//    int dp[len][len];
//    int i = 0;
//    for (i = 0; i < len; i++)
//    {
//        dp[i][i] = 1;
//        count++;
//
//    }
//    int k = 0;
//    int j = 0;
//    for (k = 0; k < len; k++)
//    {
//        for (j = k + 1, i = 0; j < len && i < len; j++, i++)
//        {
//            {
//                if (s[i] != s[j])
//                    dp[i][j] = 0;
//                else
//                {
//                    if (j - i == 1)
//                    {
//                        dp[i][j] = 1;
//                        count++;
//                    }
//                    else
//                    {
//                        if (dp[i + 1][j - 1] == 1)
//                        {
//                            dp[i][j] = 1;
//                            count++;
//                        }
//                        else
//                            dp[i][j] = 0;
//                    }
//                }
//            }
//        }
//    }
//    return count;
//}

//中心扩展法
int countSubstrings(char* s) {
    int i = 0;
    int count = 0;
    int len = strlen(s);
    for (i = 0; i < 2 * len - 1; i++)
    {
        int j = i / 2;
        int k = i / 2 + i % 2;
        while (j >= 0 && k < len && s[j] == s[k])
        {
            j--;
            k++;
            count++;
        }
    }
    return count;
}

int main()
{
	char s[] = "aaa";
	printf("%d\n", countSubstrings(s));
	return 0;
}
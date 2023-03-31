#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* longestPalindrome(char* s)//自己的方法
//{
//    int len = strlen(s);
//    if (len == 1)
//    {
//        return s;
//    }
//    else if (len == 2)
//    {
//        if (s[0] == s[1])
//        {
//            return s;
//        }
//        else
//        {
//            char* arr = (char*)calloc(2, sizeof(char));
//            if (arr == NULL)
//            {
//                perror(arr);
//                return NULL;
//            }
//            arr[0] = s[0];
//            return arr;
//        }
//    }
//    int i = 0;
//    //char dp[len][len];
//    int dp[5][5] = { 0 };
//    for (i = 0; i < len; i++)
//    {
//        dp[i][i] = 1;
//    }
//    for (i = 0; i < len - 1; i++)
//    {
//        if (s[i] == s[i + 1])
//        {
//            dp[i][i + 1] = 1;
//        }
//        else
//        {
//            dp[i][i + 1] = 0;
//        }
//    }
//    int l = 0;
//    for (l=2;l<len;l++)
//    {
//        int j = l;
//        for (i=0;i<len && j < len;i++, j++)
//        {
//            if ((s[i] == s[j]) && dp[i + 1][j - 1] == 1)
//            {
//                dp[i][j] = 1;
//            }
//            else
//            {
//                dp[i][j] = 0;
//            }
//        }
//    }
//    int ans[2];
//    int max = 0;
//    for (i = 0; i < len; i++)
//    {
//        int j = 0;
//        for (j = 0; j < len; j++)
//        {
//            if (dp[i][j] == 1 && (j - i) >= max)
//            {
//                ans[0] = i;
//                ans[1] = j;
//                max = j - i;
//            }
//        }
//    }
//    char* ret = (char*)calloc((max + 2), sizeof(char));
//    if (ret == NULL)
//    {
//        perror(ret);
//        return NULL;
//    }
//    strncpy(ret, &s[ans[0]], max + 1);
//    return ret;
//}

char* longestPalindrome(char* s)//电脑的
{
    int len = strlen(s);
    if (len == 1)
    {
        return s;
    }
    else if (len == 2)
    {
        if (s[0] == s[1])
        {
            return s;
        }
        else
        {
            char* arr = (char*)calloc(2, sizeof(char));
            if (arr == NULL)
            {
                perror(arr);
                return NULL;
            }
            arr[0] = s[0];
            return arr;
        }
    }
    int i = 0;
    int maxLen = 1;
    int begin = 0;
    //char dp[len][len];
    int dp[5][5] = { 0 };
    for (i = 0; i < len; i++)
    {
        dp[i][i] = 1;
    }
    for (int L = 2; L <= len; L++) {
        // 枚举左边界，左边界的上限设置可以宽松一些
        for (int i = 0; i < len; i++) {
            // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
            int j = L + i - 1;
            // 如果右边界越界，就可以退出当前循环
            if (j >= len) {
                break;
            }

            if (s[i] != s[j]) {
                dp[i][j] = 0;
            }
            else {
                if (j - i < 3) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
            if (dp[i][j] && j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    char* ret = (char*)calloc(maxLen + 1, sizeof(char));
    if (ret == NULL)
    {
        perror(ret);
        return NULL;
    }
    strncpy(ret, &s[begin], maxLen);
    return ret;
}

int main()
{
    char s[] = "aaaaa";
    printf("%s\n", longestPalindrome(s));
    return 0;
}
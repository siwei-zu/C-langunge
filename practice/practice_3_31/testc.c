#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* longestPalindrome(char* s)//�Լ��ķ���
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

char* longestPalindrome(char* s)//���Ե�
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
        // ö����߽磬��߽���������ÿ��Կ���һЩ
        for (int i = 0; i < len; i++) {
            // �� L �� i ����ȷ���ұ߽磬�� j - i + 1 = L ��
            int j = L + i - 1;
            // ����ұ߽�Խ�磬�Ϳ����˳���ǰѭ��
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

            // ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
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
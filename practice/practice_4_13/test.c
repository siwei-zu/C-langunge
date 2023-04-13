#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//char* mergeAlternately(char* word1, char* word2) {
//    int len1 = strlen(word1);
//    int len2 = strlen(word2);
//    int l = 0;
//    int r = 0;
//    int k = 0;
//    char* ret = (char*)calloc((len1 + len2 + 1), sizeof(char));
//    while (l < len1 || r < len2)
//    {
//        if (l == len1)
//        {
//            ret[k++] = word2[r++];
//        }
//        else if (r == len2)
//        {
//            ret[k++] = word1[l++];
//        }
//        else if (l == r)
//        {
//            ret[k++] = word1[l++];
//        }
//        else
//        {
//            ret[k++] = word2[r++];
//        }
//    }
//    return ret;
//}
//
//int main()//½»ÌæºÏ²¢×Ö·û´®
//{
//    char word1[] = "abc";
//    char word2[] = "pqr";
//    printf("%s\n", mergeAlternately(word1, word2));
//	return 0;
//}

//char* gcdOfStrings(char* str1, char* str2) {
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//    char* tmp = NULL;
//    if (len2 > len1)
//    {
//        tmp = str1;
//        str1 = str2;
//        str2 = tmp;
//        int tmp2 = len1;
//        len1 = len2;
//        len2 = tmp2;
//    }
//    int l = len1 - 1;
//    int r = len2 - 1;
//    char* ret = (char*)calloc(len2 + 1, sizeof(char));
//    char* tmp2 = (char*)calloc(len2 + 1, sizeof(char));
//    strcpy(ret, str2);
//    while (*ret != 0)
//    {
//        len1 = strlen(str1);
//        len2 = strlen(str2);
//        l = len1 - 1;
//        r = len2 - 1;
//        while (r >= 0)
//        {
//            if ((str1[l] - str2[r]) != 0)
//            {
//                return "";
//            }
//            l--;
//            r--;
//        }
//        strncpy(tmp2, ret, len2);
//        strncpy(ret, str2, r);
//        strncpy(str2, str1, l);
//        strncpy(str1, tmp2, len2);
//    }
//    return tmp2;
//}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* tmp = NULL;
    if (len2 > len1)
    {
        tmp = str1;
        str1 = str2;
        str2 = tmp;
        int tmp2 = len1;
        len1 = len2;
        len2 = tmp2;
    }
    int count = len2;
    int l = len1 - 1;
    int r = len2 - 1;
    while (l>=0 && r>=0 /* && (l != r && r != -1)*/)
    {
        int tmp1 = r;
        while (r >= 0)
        {
            if ((str1[l] - str2[r]) != 0)
            {
                return "";
            }
            l--;
            r--;
        }
        if ((l >= 0 || r >= 0) == 0)
            break;
        if (l >= len2 - 1)
        {
            r = len2 - 1;
        }
        else
        {
            tmp = str1;
            str1 = str2;
            str2 = tmp;
            r = l;
            l = tmp1;
            count = r;
        }
    }
    char* ret = (char*)calloc(count, sizeof(char));
    if (ret == NULL)
    {
        perror("calloc");
        return NULL;
    }
    strncpy(ret, str1, count);
    return ret;
}

int main()
{
    //char str1[] = "TAUXXTAUXXTAUXXTAUXXTAUXX";
    //char str2[] = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
    char str1[] = "ABCABC";
    char str2[] = "ABC";
    printf("%s", gcdOfStrings(str1, str2));
	return 0;
}



#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char pattern[] = "syys";
    char s[] = "a abc abc a";
    char** arr = (char**)malloc(sizeof(char*) * 123);
    char* charr = (char*)malloc(sizeof(char) * 3001);
    memset(charr, '\0', sizeof(char) * 3001);
    int i = 0;
    for (i = 97; i <= 122; i++)
    {
        arr[i] = (char*)malloc(sizeof(char) * 3001);
        memset(arr[i], '\0', sizeof(char) * 3001);
    }
    int len = strlen(s);
    int len2 = strlen(pattern);
    int flag = 0;
    int pre1 = 0;
    int pre2 = 0;
    for (i = 0; i < len; i++)
    {
        if (pre2 == len2)
        {
            return 0;
        }
        pre1 = 0;
        while (s[i] != ' ' && i < len)
        {
            charr[pre1] = s[i];
            i++;
            pre1++;
        }
        charr[pre1] = '\0';
        if (arr[pattern[pre2]][0] == 0)
        {
            strcpy(arr[pattern[pre2]], charr);
            int k = 97;
            for (k = 97; k <= 122; k++)
            {
                if (arr[k][0] != '\0' && k != pattern[pre2])
                {
                    if (strcmp(arr[k], arr[pattern[pre2]]) == 0)
                    {
                        return 0;
                    }
                }
            }
            pre2++;
        }
        else
        {
            if (strcmp(arr[pattern[pre2]], charr) != 0)
            {
                return 0;
            }
            pre2++;
        }

    }
    if (i >= len)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int* masterMind(char* solution, char* guess, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0;
    answer[1] = 0;
    *returnSize = 2;
    int flags[4] = { 0 };
    int flagg[4] = { 0 };
    int i = 0;
    int j = 0;
    for (i = 0; i < 4; i++) {
        if (solution[i] == guess[i]) {
            answer[0]++;
            flags[i] = 1;
            flagg[i] = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (flags[i] == 1) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            if (i == j) {
                continue;
            }
            if (flagg[j] == 1) {
                continue;
            }
            if (solution[i] == guess[j]) {
                flags[i] = 1;
                flagg[j] = 1;
                answer[1]++;
                break;
            }
        }
    }
    return answer;

}

int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
    int* ptr = (int*)calloc(2, sizeof(int));
    for (int i = 0; i < numbersLen; i++)
    {
        if (numbers[i] > target + 10) continue;
        for (int j = i + 1; j < numbersLen; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                ptr[0] = i + 1;
                ptr[1] = j + 1;
                *returnSize = 2;
                return ptr;
            }
        }
    }
    *returnSize = 0;
    return 0;
}
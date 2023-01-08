#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    char words[4][9] = { "pay","attention","practice","attend" };
    int wordsSize = 4;
    char pref[] = "at";
    int count = 0;
    int i = 0;
    for (i = 0; i < wordsSize; i++)
    {
        int j = 0;
        int decide = 0;
        for (j == 0; pref[j] != '\0'; j++)
        {
            if (words[i][j] != pref[j])
            {
                decide = 1;
                break;
            }
        }
        if (decide == 0)
            count++;
    }
    printf("%d\n", count);
    return 0;
}
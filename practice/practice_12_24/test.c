#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()//ÓÐÐ§µÄÀ¨ºÅ¡£
{
    char s2[] = "([)]";
    int i = 0;
    int j = 0;
    char* s = s2;
    int sz = strlen(s);
    if (sz % 2 == 1)
    {
        printf("false\n");
        return 0;
    }
    else
    {
        for (i = 0; i < sz; i++)
        {
            if (s[i] == ' ')
                continue;
            for (j = i + 1; j < sz; j++)
            {
                if (s[j] == ' ')
                    continue;
                if (s[j] - s[i] == 1 || s[j] - s[i] == 2)
                {
                    s[i] = ' ';
                    s[j] = ' ';

                }
            }
        }
        for (i = 0; i < sz; i++)
        {
            if (s[i] != ' ')
            {
                printf("false\n");
                return 0;
            }
        }
        printf("true\n");
    }
    return 0;
}
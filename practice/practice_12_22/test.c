#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()//罗马数字转整数。
{
    char s1[] = "III";
    char* s = s1;
    int sum = 0;
    while (*s != '\0')
    {
        if (*s == 'I')
        {
            if (*(s + 1) == 'V')
            {
                sum += 4;
                s += 2;
            }
            else if (*(s + 1) == 'X')
            {
                sum += 9;
                s += 2;
            }
            else
            {
                sum += 1;
                s += 1;
            }
        }
        else if (*s == 'X')
        {
            if (*(s + 1) == 'L')
            {
                sum += 40;
                s += 2;
            }
            else if (*(s + 1) == 'C')
            {
                sum += 90;
                s += 2;
            }
            else
            {
                sum += 10;
                s += 1;
            }
        }
        else if (*s == 'C')
        {
            if (*(s + 1) == 'D')
            {
                sum += 400;
                s += 2;
            }
            else if (*(s + 1) == 'M')
            {
                sum += 900;
                s += 2;
            }
            else
            {
                sum += 100;
                s += 1;
            }
        }
        else if (*s == 'V')
        {
            sum += 5;
            s += 1;
        }
        else if (*s == 'L')
        {
            sum += 50;
            s += 1;
        }
        else if (*s == 'C')
        {
            sum += 100;
            s += 1;
        }
        else if (*s == 'D')
        {
            sum += 500;
            s += 1;
        }
        else if (*s += 'M')
        {
            sum += 1000;
            s += 1;
        }
        else if (*s == '\0')
            break;
    }
    printf("%d", sum);
    return 0;
}
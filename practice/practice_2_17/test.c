#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int finalValueAfterOperations(char** operations, int operationsSize) {
    int x = 0;
    int i = 0;
    for (i = 0; i < operationsSize; i++)
    {
        int j = 0;
        while (operations[i][j] != '\0')
        {
            if (operations[i][j] == '-')
                x--;
            else if (operations[i][j] == '+')
                x++;
            j++;
        }
    }
    return x / 2;
}

int finalValueAfterOperations(char** operations, int operationsSize) {
    int x = 0;
    int i = 0;
    for (i = 0; i < operationsSize; i++)
    {
        if (strcmp(*(operations + i), "++X") == 0 || strcmp(*(operations + i), "X++") == 0)
            x++;
        else
            x--;
    }
    return x;
}
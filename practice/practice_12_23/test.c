#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


    char* main()//求最长公共前缀。
    {
        char strs[][10] = { "flow","flower","flight" };
        int strsSize = 3;
        int i = 0;
        int j = 0;
        int k = 0;
        int n = 0;
        int s = 0;
        char a[200] = "0";
        int count[3] = { 0,0,0 };
        if (strsSize == 1)
            return "";
        for (i = 0; i < strsSize; i++)
        {
            for (k = 1; i + k < strsSize; k++)
            {
                count[0] = 0;
                for (j = 0; strs[i][j] != '\0' && strs[i + k][j] != '\0'; j++)
                {
                    int z = 0;
                    z = strs[i][j] - strs[i + k][j];
                    if (z == 0)
                    {
                        count[0]++;
                    }
                    else
                        break;
                }
                if (k == 1)
                {
                    count[1] = count[0];
                }
                else if (k != 1)
                {
                    if (count[0] <= count[1])
                        count[1] = count[0];
                }
            }
            if (count[0] == 0)
                printf("1");
            if (i == 0)
            {
                count[2] = count[1];
            }
            else
            {
                if (count[2] >= count[1])
                {
                    count[2] = count[1];
                    n = i;
                }
            }
        }
        if (count[2] == 0)
        {
            return "";
        }
        else
        {
            i = 0;
            while (i < count[2])
            {
                strs[0][i] = strs[n][i];
                i++;
            }
            strs[0][i] = '\0';
            printf("%s", strs[0]);
        }
    }
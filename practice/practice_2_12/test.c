#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char target[] = "leet";
    int len = strlen(target);
    int i = 0;
    int j = 0;
    int k = 0;
    char arr[26][2];
    char* result = (char*)malloc(sizeof(char) * 10 * len + 1);
    memset(result, '\0', sizeof(char) * 10 * len + 1);
    for (i = 0; i < 26; i++)
    {
        if (j == 5)
        {
            j = 0;
            k++;
        }
        if (i != 25)
        {
            arr[i][0] = k;
            arr[i][1] = j;
            j++;
        }
        else
        {
            arr[i][0] = 5;
            arr[i][1] = 0;
        }
    }
    i = 0;
    k = 0;
    int move_x = 0;
    int move_y = 0;
    for (i = 0; i < len; i++)
    {
        int result_x = arr[target[i] - 97][1];
        int result_y = arr[target[i] - 97][0];
        if (move_x != 0 && move_y != 5) {
            if (result_x - move_x > 0)
            {
                j = 0;
                while (j < result_x - move_x)
                {
                    result[k] = 'R';
                    k++;
                    j++;
                }
            }
            else if (result_x - move_x < 0)
            {
                j = 0;
                while (j < move_x - result_x)
                {
                    result[k] = 'L';
                    k++;
                    j++;
                }
            }
            if (result_y - move_y > 0)
            {
                j = 0;
                while (j < result_y - move_y)
                {
                    result[k] = 'D';
                    k++;
                    j++;
                }
            }
            else if (result_y - move_y < 0)
            {
                j = 0;
                while (j < move_y - result_y)
                {
                    result[k] = 'U';
                    k++;
                    j++;
                }
            }
        }
        else
        {
            if (result_y - move_y > 0)
            {
                j = 0;
                while (j < result_y - move_y)
                {
                    result[k] = 'D';
                    k++;
                    j++;
                }
            }
            else if (result_y - move_y < 0)
            {
                j = 0;
                while (j < move_y - result_y)
                {
                    result[k] = 'U';
                    k++;
                    j++;
                }
            }
            if (result_x - move_x > 0)
            {
                j = 0;
                while (j < result_x - move_x)
                {
                    result[k] = 'R';
                    k++;
                    j++;
                }
            }
            else if (result_x - move_x < 0)
            {
                j = 0;
                while (j < move_x - result_x)
                {
                    result[k] = 'L';
                    k++;
                    j++;
                }
            }
        }
        result[k] = '!';
        k++;
        move_x = arr[target[i] - 97][1];
        move_y = arr[target[i] - 97][0];
    }
	return 0;
}


#include <stdio.h>

int main() {
    long n, k = 0;
    long count = 0;
    while (~scanf("%ld %ld", &n, &k))
    {
        if (k == 0)
        {
            printf("%ld\n", n * n);
            continue;
        }
        for (long j = k + 1; j <= n; j++)
        {
            long help = n % j < k ? 0 : (n % j) - k + 1;
            count += (j - k) * (n / j) + help;
        }
        printf("%ld\n", count);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n = 0;
    char* arr = (char*)malloc(sizeof(char) * 1001);
    char* arr1 = (char*)malloc(sizeof(char) * 1001);
    memset(arr, '\0', sizeof(char) * 1001);
    memset(arr1, '\0', sizeof(char) * 1001);
    scanf("%s", arr);
    scanf("%d", &n);
    strncpy(arr1, arr, n);
    printf("%s", arr1);
    return 0;
}
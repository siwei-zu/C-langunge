#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() {
    char arr[10000] = { 0 };
    gets(arr + 1);
    arr[0] = ' ';
    int len = strlen(arr);
    int i = 0;
    int left = len - 1;
    int right = len - 1;
    for (i = 0; i < len; i++)
    {
        if (((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z')) == 0)
        {
            arr[i] = ' ';
        }
    }
    while (left > 0 && right > 0)
    {
        while (arr[right] == ' ')
        {
            right--;
        }
        left = right;
        while (arr[left] != ' ')
        {
            left--;
        }
        if (left < 0 || right < 0)
            break;
        int j = left + 1;
        while (j <= right)
        {
            printf("%c", arr[j]);
            j++;
        }
        printf(" ");
        right = left;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    int* narr = (int*)malloc(sizeof(int) * n);
    int* marr = (int*)malloc(sizeof(int) * m);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &narr[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &marr[i]);
    }
    int ln = 0;
    int lm = 0;
    for (i = 0; i < m + n; i++)
    {
        if (ln == n)
        {
            while (lm < m)
            {
                printf("%d ", marr[lm]);
                lm++;
            }
            return 0;
        }
        if (lm == m)
        {
            while (ln < n)
            {
                printf("%d ", narr[ln]);
                ln++;
            }
            return 0;
        }
        if (narr[ln] < marr[lm])
        {
            printf("%d ", narr[ln]);
            ln++;
        }
        else
        {
            printf("%d ", marr[lm]);
            lm++;
        }
    }
    return 0;
}

#include <stdio.h>

int main() {
    int i = 10000;
    for (i = 1461; i < 100000; i++)
    {
        if ((/*((i % 10000) * i / 10000)
            +*/ ((i % 1000) * i / 1000)
            + ((i % 100) * i / 100)
            + ((i % 10) * i / 10)) == i)
        {
            printf("%d ", i);
        }
    }
    return 0;
}

bool isPalindrome(char* s) {

    int left = 0;
    int right = strlen(s) - 1;
    while (left <= right)
    {
        if (s[left] >= 'A' && s[left] <= 'Z')
        {
            s[left] += 32;
        }
        if (s[right] >= 'A' && s[right] <= 'Z')
        {
            s[right] += 32;
        }
        if (((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= '0' && s[left] <= '9')) == 0)
        {
            left++;
        }
        if (((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= '0' && s[right] <= '9')) == 0)
        {
            right--;
        }
        if (((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= '0' && s[left] <= '9'))
            && ((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= '0' && s[right] <= '9')))
        {
            if (s[left] != s[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }

    }
    return true;
}


#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("%d", 1);
    }
    else if (n == 2)
    {
        printf("%d", 1);
    }
    else
    {
        int a = 1;
        int b = 1;
        int k = 0;
        int z = 0;
        for (k = 3; k <= n; k++)
        {
            z = a + b;
            a = b;
            b = z;
        }
        printf("%d", z);
    }
}

#include <stdio.h>
#include <math.h>

int main()
{
    double n = 0.00;
    int m = 0;

    while (~scanf("%lf %d", &n, &m))
    {
        double sum = 0.00;//这里不能用float，只能用double
        for (int i = 0; i < m; i++)//控制m次
        {
            sum += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", sum);
    }

    return 0;
}
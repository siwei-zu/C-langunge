#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m = 0;
    int n = 0;
    scanf("%d %d", &n, &m);
    int** arr1 = (int**)malloc(sizeof(int*) * n);
    int** arr2 = (int**)malloc(sizeof(int*) * n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        arr1[i] = (int*)malloc(sizeof(int) * m);
        arr2[i] = (int*)malloc(sizeof(int) * m);
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                free(arr1);
                free(arr2);
                printf("No\n");
                return 0;
            }
        }
    }
    free(arr1);
    free(arr2);
    printf("Yes\n");
    return 0;
}

#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int arr[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int target = 0;
    scanf("%d", &target);
    for (i = 0; i < n; i++)
    {
        if (arr[i] != target)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}

#include<stdio.h>
int main() {
    int year, month, day;
    while (scanf("%d %d", &year, &month) != EOF) {
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31\n");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30\n");
            break;
        case 2: {   //2月平年28天，闰年29天
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                printf("29\n");
            else
                printf("28\n");
        }
        }
    }
    return 0;
}

#include<stdio.h>

int main()
{
    double price = 0.0;
    int month = 0;
    int day = 0;
    int flag = 0;

    scanf("%lf %d %d %d", &price, &month, &day, &flag);
    if (month == 11 && day == 11)
    {
        price = price * 0.7 - 50.0 * flag;
    }
    else if (month == 12 && day == 12)
    {
        price = price * 0.8 - 50 * flag;
    }
    if (price < 0)
    {
        printf("0.00\n");
    }
    else
    {
        printf("%.2lf\n", price);
    }

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//void bubble_sort(char** ret, int begin, int end)
//{
//    int i = 0;
//    for (i = begin; i < end - 1; i++)
//    {
//        int j = 0;
//        for (j = begin; j < end - 1 - i + begin; j++)
//        {
//            if (ret[j][0] > ret[j + 1][0])
//            {
//                char tmp1 = ret[j][0];
//                char tmp2 = ret[j][1];
//                ret[j][0] = ret[j + 1][0];
//                ret[j][1] = ret[j + 1][1];
//                ret[j + 1][0] = tmp1;
//                ret[j + 1][1] = tmp2;
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    int n = 0;
//    scanf("%d\n", &n);
//    char** arr = (char**)malloc(sizeof(char*) * n);
//    char** ret = (char**)malloc(sizeof(char*) * n);
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        arr[i] = (char*)calloc(3, sizeof(char));
//        ret[i] = (char*)calloc(3, sizeof(char));
//        scanf("%s", arr[i]);
//    }
//    int k = 0;
//    for (i = 0; i < n; i++)
//    {
//        if (arr[i][1] == 'B')
//        {
//            strcpy(ret[k], arr[i]);
//            k++;
//        }
//    }
//    bubble_sort(ret, 0, k);
//    int tmp = k;
//    for (i = 0; i < n; i++)
//    {
//        if (arr[i][1] == 'C')
//        {
//            strcpy(ret[k], arr[i]);
//            k++;
//        }
//    }
//    bubble_sort(ret, tmp, k);
//    tmp = k;
//    for (i = 0; i < n; i++)
//    {
//        if (arr[i][1] == 'D')
//        {
//            strcpy(ret[k], arr[i]);
//            k++;
//        }
//    }
//    bubble_sort(ret, tmp, n);
//    for (i = 0; i < n; i++)
//    {
//        printf("%s ", ret[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//    int k = 0;
//    scanf("%d", &k);
//    char* arr1 = (char*)calloc(k+1, sizeof(char));
//    char* arr2 = (char*)calloc(k+1, sizeof(char));
//    char* arr3 = (char*)calloc(k+1, sizeof(char));
//    scanf("%s", arr1);
//    scanf("%s", arr2);
//    scanf("%s", arr3);
//    int hash[26] = { 0 };
//    int i = 0;
//    int count = 0;
//    for (i = 0; i < k; i++)
//    {
//        hash[arr1[i] - 97]++;
//        hash[arr2[i] - 97]++;
//        hash[arr3[i] - 97]++;
//        char max = 'a';
//        int j = 0;
//        int flag = 0;
//        int max1 = 0;
//        for (j = 0; j < 26; j++)
//        {
//            if (max1 < hash[j])
//            {
//                max1 = hash[j];
//                flag = j;
//            }
//        }
//        max = flag + 97;
//        if (arr1[i] != max)
//        {
//            arr1[i] = max;
//            count++;
//
//        }
//        if (arr2[i] != max)
//        {
//            arr2[i] = max;
//            count++;
//        }
//        if (arr3[i] != max)
//        {
//            arr3[i] = max;
//            count++;
//        }
//        memset(hash, 0, sizeof(int) * 26);
//    }
//    printf("%d", count);
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int n = 0;
//    int x = 0;
//    scanf("%d %d", &n, &x);
//    int i = 0;
//    int* arr = (int*)malloc(sizeof(int) * n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", arr + i);
//    }
//    int l = 0;
//    int r = 0;
//    int min = 1000000;
//    long long sub = arr[0];
//    while (r < n && l<=r)
//    {
//
//        if (sub >= x)
//        {
//            min = min < (r - l + 1) ? min : r - l + 1;
//            sub /= arr[l];
//            l++;
//        }
//        else
//        {
//            r++;
//            sub *= arr[r];
//        }
//    }
//    if (min == 1000000)
//    {
//        printf("-1");
//        return 0;
//    }
//    printf("%d", min);
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int* arr = (int*)malloc(sizeof(int) * n);
//    int* zheng = (int*)malloc(sizeof(int) * n);
//    int* fu = (int*)malloc(sizeof(int) * n);
//    zheng[n - 1] = 0;
//    fu[n - 1] = 0;
//    int i = 0;
//    int count = 0;
//    int count1 = 0;
//    int count2 = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    for (i = n - 2; i >= 0; i--)
//    {
//        if (arr[i + 1] >= 0)
//        {
//            zheng[i] = zheng[i + 1] + 1;
//        }
//        else
//        {
//            fu[i] = fu[i + 1] + 1;
//        }
//    }
//    for (i = 0; i < n - 1; i++)
//    {
//        if (arr[i] >= 0)
//        {
//            count += zheng[i];
//        }
//        else
//        {
//            count += fu[i];
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 1 ^ 5;
//	return 0;
//}

#include <stdio.h>

int main()
{
    int n = 0;
    int t = 0;
    scanf("%d %d", &n, &t);
    int sc[20] = { 0 };
    int ti[20] = { 0 };
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &sc[i], &ti[i]);
    }
    int dp[11] = { 0 };
    int count = 0;
    if (ti[0] <= t)
    {
        for (i = 0; i < 11; i++)
        {
            dp[i] = sc[0];
        }
        count += sc[0];
    }
    for (i = 1; i < n; i++)
    {
        int j = 0;
        for (j = t; j > 0; j--)
        {
            if (j >= ti[i])
            {
                dp[j] = dp[j] > dp[j - ti[i]] + sc[i] ? dp[j] : dp[j - ti[i]] + sc[i];
            }
        }
    }
    printf("%d", dp[t]);
    return 0;
}
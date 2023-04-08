#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//    long long n = 0;
//    int i = 3;
//    int k = 12;
//    char ret[14] = { 0 };
//    scanf("%lld", &n);
//    long long num = n;
//    while (num)
//    {
//        if (i != 0)
//        {
//            ret[k] = (num % 10) + 48;
//            i--;
//            num /= 10;
//        }
//        else
//        {
//            ret[k] = ',';
//            i = 3;
//        }
//        k--;
//    }
//    for (i = 0; ret[i] == 0; i++)
//    {
//        ;
//    }
//    if (ret[i] == ',')
//        i++;
//    printf("%s ", &ret[i]);
//    return 0;
//}

#include <stdio.h>

int main()
{
    int hash[128] = { 0 };
    char str1[101] = { 0 };
    char str2[101] = { 0 };
    char ret[101] = { 0 };
    scanf("%s", str1);
    scanf("%s", str2);
    int i = 0;
    int k = 0;
    for (i = 0; str2[i] != '\0'; i++)
    {
        hash[str2[i]] = 1;
    }
    for (i = 0; str1[i] != '\0'; i++)
    {
        if (hash[str1[i]] != 1)
        {
            ret[k] = str1[i];
            k++;
        }
    }
    printf("%s", ret);
    return 0;
}
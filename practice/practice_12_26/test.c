#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char* c[] = { "ENTER","NEW","POINT","FORST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp+3);
	printf("%s\n", *cpp[-2]+3);
	printf("%s\n", cpp[-1][-1]+1);
	return 0;
}

int main()//爬楼梯（斐波那契数列）循环
{
    int n = 0;
    scanf("%d", &n);
    int z = 0;
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    {
        int i = 1;
        int j = 2;
        int k = 0;
        for (i = 1, j = 2; k < n - 2; k++)
        {
            z = i + j;
            i = j;
            j = z;
        }
        printf("%d", z);
    }
}
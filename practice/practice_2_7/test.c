#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    char arr[10000] = { 0 };
    gets(arr);
    int len = strlen(arr);
    int i = 0;
    int flag = 0;
    for (i = len - 1; i >= 0; i--)
    {
        if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
        {
            printf("%c", arr[i]);
            flag = 1;
        }
        else if (flag == 1)
        {
            printf(" ");
            flag = 0;
        }
    }
}

//int main()
//{
//    char columnTitle[] = "ZY";
//    int len = strlen(columnTitle);
//    int i = 0;
//    int wei = len - 1;
//    int count = 0;
//    for (i = 0; i < len; i++)
//    {
//        count += (columnTitle[i] - 64) * (int)pow(26.0, (double)wei);
//        wei--;
//    }
//    return count;
//}


//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("a=%d,b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a=%d,b=%d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 31;
//	//偶数位
//	printf("偶数位:\n");
//	while (i>=1)
//	{
//		printf("%d ",(n >> i) & 1);
//		i -= 2;
//	}
//	printf("\n");
//	printf("奇数位:\n");
//	i = 30;
//	while (i >= 0)
//	{
//		printf("%d ", (n >> i) & 1);
//		i -= 2;
//	}
//	printf("\n");
//	return 0;
//}
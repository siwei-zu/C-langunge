#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int sum(int a)
//{
//    int c = 0;
//    static int b = 3;
//    c += 1;
//    b += 2;
//    return (a + b + c);
//}
//int main()
//{
//    int i;
//    int a = 2;
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d,", sum(a));
//    }
//}
//#include <stdio.h>
//
//
//int main() {
//    int n = 0;
//    int count = 2;
//    scanf("%d", &n);
//    while (n >= 12)
//    {
//        n -= 12;
//        count += 4;
//    }
//    printf("%d\n", count);
//    return 0;
//}
//#include <stdio.h>
//
//
//int main() {
//    int a = 0;
//    int max = 0;
//    while (scanf("%d", &a) != EOF) {
//        max = a > max ? a : max;
//    }
//    printf("%d\n", max);
//    return 0;
//}
//#include <stdio.h>
//
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    if (n >= 90 && n <= 100)
//        printf("%c", 'A');
//    else if (n >= 80 && n <= 89)
//        printf("%c", 'B');
//    else if (n >= 70 && n <= 79)
//        printf("%c", 'C');
//    else if (n >= 60 && n <= 69)
//        printf("%c", 'D');
//    else if (n >= 0 && n <= 59)
//        printf("%c", 'E');
//    else
//        printf("%c", 'F');
//    return 0;
//}
//#include <stdio.h>
//
//
//int main() {
//    printf("%c%c%c%c%c%c%c%c%c%c%c%c\n", 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33);
//
//
//    return 0;
//}
//#include <stdio.h>
//
//
//int main() {
//    int a = 0;
//    int b = 0;
//    int ret = 0;
//    while (scanf("%d", &ret) != EOF)
//    {
//        if (ret > 0)
//            a++;
//        else if (ret < 0)
//            b++;
//    }
//    printf("positive:%d\n", a);
//    printf("negative:%d\n", b);
//    return 0;
//}
//#include <stdio.h>
//
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int ret = 0;
//    scanf("%d", &ret);
//    int max = ret;
//    int min = ret;
//
//    while (scanf("%d", &ret) != EOF)
//    {
//        max = ret > max ? ret : max;
//        min = ret < min ? ret : min;
//    }
//    printf("%d", max - min);
//    return 0;
//}
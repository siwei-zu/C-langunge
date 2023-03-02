#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//char* printBin(double num) {
//    char count = 0;
//    int i = 2;
//    char* ret = (char*)malloc(sizeof(char) * 33);
//    memset(ret, '\0', sizeof(char) * 33);
//    ret[0] = '0';
//    ret[1] = '.';
//    while (num != 0 && i <= 32)
//    {
//        num *= 2;
//        count = (char)(num);
//        num -= (int)num;
//        ret[i] = count + 48;
//        i++;
//    }
//    if (num == 0.0)
//    {
//        return ret;
//    }
//    else
//    {
//        return "ERROR";
//    }
//}
//
//int main()
//{
//	double num = 0.72;
//	int count = (int)num;
//    printf("%s", printBin(0.625));
//	return 0;
//}


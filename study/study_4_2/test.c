#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��#define֪ʶ�����ڶԲ�������ʱҪ�ǵ�ȫ�����ţ����������
// ��#�����������ǵ�ǰ����ת��Ϊ��Ӧ���ַ���
// "##" �����������������ֶ����ǵĽ����һ���Ѷ���Ĳ�����

#define MAX(x, y) ( (x) > (y) ? (x) : (y) )

int main()
{
	printf("%d\n", MAX(3, 5));
	return 0;
}

//#define PRINT_FORMAT(num, format) printf("the value of "#num" is "format, num, num);
//
//int main()
//{
//	int a = 10;
//	PRINT_FORMAT(a, "%d\n");
//	int b = 100;
//	PRINT_FORMAT(b, "%d\n");
//	float f = 3.14f;
//	PRINT_FORMAT(f, "%f\n");
//	return 0;
//}
//
// int Class110 = 2023;
//
// #define CAT(x,y) x##y
// //Class110
// int main()
// {
//     printf("%d\n", CAT(Class, 110));
//
//     return 0;
// }

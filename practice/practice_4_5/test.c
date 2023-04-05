#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//offsetofºêµÄÊµÏÖ

#define my_offsetof(type, number)  ((size_t)&(((type*)0)->number))

struct S
{
	int age;
	char name;
	int tele;
	int id;
};

int main()
{
	struct S s;
	printf("%d\n", my_offsetof(struct S, id));
	return 0;
}

//#include <stdio.h>
//
//#define SWAP(n) n = ((((n) & 0xaaaaaa)>>1) + (((n) & 0x555555) << 1))
//
//int main()
//{
//	int n = 5;
//	printf("%d\n", SWAP(n));
//	return 0;
//}

#include <stdio.h>
//#define MUL(x, y) ((x) * (y))
//
//int main()
//{
//	printf("%d\n", MUL(5 + 2, 3));
//	printf("%d\n", 5 + 2 * 3);
//	return 0;
//}

//#define VALUE(num) printf("the value of " #num " is %d", num)
//
//int main()
//{
//	int num = 5;
//	VALUE(num);
//	return 0;
//}

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

 //int Class110 = 2023;

 //#define CAT(x,y) x##y
 ////Class110
 //int main()
 //{
 //    printf("%d\n", CAT(Class, 110));

 //    return 0;
 //}
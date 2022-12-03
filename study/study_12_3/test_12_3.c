#define _CRT_SECURE_NO_WARNINGS 1
//转义字符\ddd中ddd表示1到3个八进制数字，\xdd中dd表示1到2个十六进制数字格式为x12.
#include <stdio.h>
extern int a;
int main()
{
	int b = 120;
	printf("%d\n", b);
	printf("%d\n", a);
	return 0;
}
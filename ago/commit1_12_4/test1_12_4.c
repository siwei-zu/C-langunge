#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()//编码代码实现，模拟用户登录情景，并且只能登陆三次。
{
	char arr[20] = { 0 };
	int i = 0;
	int a = 0;
	for (i = 0; i < 3; )
	{
		printf("请输入登录密码：");
		scanf("%s", arr);
		if ((strcmp(arr, "123456") == 0))//不能用==来比较字符串相等，应该使用一个库函数-strcmp-头文件为<string.h>
		{
			printf("登陆成功\n");//strcmp规定左边大于右边返回正数，左边等于右边返回零，左边小于右边返回负数。
			break;
		}
		else
		{
			a = 2 - i;
			if (a == 0)
			{
				i++;
				break;
			}
			printf("登陆失败，密码错误，你还有%d次机会。\n", a);
			i++;
		}
	}
	if (i == 3)
	{
		printf("登陆失败，请退出程序。\n");
	}
	return 0;
}
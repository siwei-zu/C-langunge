#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)//这里为假下面的if不进入下面的判断语句故不输出
//		if (b == 2)
//		{
//			printf("hehe\n");
//		}
//		else
//			printf("haha\n");//else和最近的if相匹配
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

int main()
{
	char arr[20] = { 0 };
	scanf("%[^\n]", arr);//这个代码的意思是scand只有碰见 \n 才会停下来
	printf("%s\n", arr);
	return 0;
}
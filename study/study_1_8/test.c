#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)//����Ϊ�������if������������ж����ʲ����
//		if (b == 2)
//		{
//			printf("hehe\n");
//		}
//		else
//			printf("haha\n");//else�������if��ƥ��
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
	scanf("%[^\n]", arr);//����������˼��scandֻ������ \n �Ż�ͣ����
	printf("%s\n", arr);
	return 0;
}
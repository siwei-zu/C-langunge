#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()//����һ�������ж�����λ��һ�ĸ�����
{
	int num = 0;
	int count = 0;
	int i = 0;
	scanf("%d", &num);
	//�ڶ����Ż��㷨

	while (num)
	{
		count++;
		num = num & (num - 1);
	}

	//��һ�ַ���
	//while (count<32&&num!=0)
	//{
	//	if ((num & 1) == 1)
	//		count++;
	//	num >>= 1;
	//	//if ((num % 2) == 1)//��ȱ�ݣ�ֻ�ܼ���������
	//	//	count++;
	//	//num /= 2;
	//}
	printf("%d", count);
	return 0;
}

int main()//�����õ���������ʵ���������εĽ�����
{
	int a = 3;
	int b = 5;
	printf("����ǰ��%d,%d\n", a, b);
	//��ͨ����
	/*int tmp = a;
	a = b;
	b = tmp;*/
	//�ڶ��֣��Ӽ�����
	/*a = a + b;
	b = a - b;
	a = a - b;*/
	//�����֣���λ���
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("������%d,%d\n", a, b);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()//�˷��ھ���
//{
//	int i = 0;
//	int hangshu = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (hangshu = 1; hangshu <= i; hangshu++)
//		{
//			printf("%d*%d=%-2d ", i, hangshu, i * hangshu);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int count = 0;
//int arr[2 ^ 31 - 1] = { 0 };
//void kuaile(int x)
//{
//    if (x > 9)
//    {
//        kuaile(x / 10);
//        count++;
//        arr[count] = x % 10;
//    }
//    else
//    {
//        return *arr = x;
//    }
//}
//int main()//�������ݹ�
//{
//    int n;
//    int i;
//    int sum = 0;
//    scanf("%d", &n);
//be:
//    kuaile(n);
//    for (i = 0; i <= count; i++)
//    {
//        sum += arr[i] * arr[i];
//    }
//    if (sum == 1)
//    {
//        printf("true\n");
//    }
//    else if (sum == 4 || sum == 16 || sum == 37 || sum == 58 || sum == 89 || sum == 145 || sum == 20)
//        printf("false\n");
//    else
//    {
//        n = sum;
//        sum = 0;
//        count = 0;
//        goto be;
//    }
//    return 0;
//}

//hannuo(int n, char A, char B, char C)
//{
//	static int count = 1;
//	if (n == 1)
//	{
//		printf("��%d������%c�ƶ���%c��\n", count, A, C);
//		count++;
//	}
//	else
//	{
//		hannuo(n - 1, A, C, B);
//		printf("��%d������%c�ƶ���%c��\n", count, A, C);
//		count++;
//		hannuo(n - 1, B, A, C);
//
//	}
//}
////����ʼ���ϵ� n-1 ��Բ���ƶ����������ϣ�
////����ʼ���������� 1 ��Բ���ƶ���Ŀ�����ϣ�
////���������ϵ�����Բ���ƶ���Ŀ������
//int main()//��ŵ������
//{
//	int n;
//	scanf("%d", &n);
//	hannuo(n, 'A', 'B', 'C');
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX_P 30001

int main()
{
	int n, x;
	int arr[MAX_P] = { 0 };
	scanf("%d%d", &n, &x);
	int i = 0;
	int count = 0;
	int b[31];//������ļ۸�
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		count += b[i];
	}
	int num = (count - x);//�������ܼ۸��ȥ�������������ÿ���ת��Ϊ01��������
	if (num > 30001)//����������������Ϊ��ʹ�õı����������ò���̫������飬Ҫ��Ȼ��ջ��������Ծ͹��������ʡ�Ը�λ��
	{
		num /= 10;
		for (i = 1; i <= n; i++)
		{
			int j = 0;
			for (j = num; j >= 0; j--)
			{
				if (b[i] / 10 > j)
					arr[j] = 0;
				else
				{
					arr[j] = arr[j - b[i] / 10] + b[i] / 10 > arr[j] ? arr[j - b[i] / 10] + b[i] / 10 : arr[j];//�����õ��˹�������Ͷ�̬�滮��˼��
				}
			}
		}
		printf("%d", count - arr[num] * 10);
	}
	else if (num <= 30000)//��һ���жϣ�����һ��
	{
		for (i = 1; i <= n; i++)
		{
			int j = 0;
			for (j = num; j >= 0; j--)
			{
				if (b[i] <= j)
					//	arr[j] = arr[j];
					//else
				{
					arr[j] = arr[j - b[i]] + b[i] > arr[j] ? arr[j - b[i]] + b[i] : arr[j];
				}
			}
		}
		printf("%d", count - arr[num]);
	}
	return 0;
}
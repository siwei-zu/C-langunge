#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()//�������ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�½���Ρ�
{
	char arr[20] = { 0 };
	int i = 0;
	int a = 0;
	for (i = 0; i < 3; )
	{
		printf("�������¼���룺");
		scanf("%s", arr);
		if ((strcmp(arr, "123456") == 0))//������==���Ƚ��ַ�����ȣ�Ӧ��ʹ��һ���⺯��-strcmp-ͷ�ļ�Ϊ<string.h>
		{
			printf("��½�ɹ�\n");//strcmp�涨��ߴ����ұ߷�����������ߵ����ұ߷����㣬���С���ұ߷��ظ�����
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
			printf("��½ʧ�ܣ���������㻹��%d�λ��ᡣ\n", a);
			i++;
		}
	}
	if (i == 3)
	{
		printf("��½ʧ�ܣ����˳�����\n");
	}
	return 0;
}
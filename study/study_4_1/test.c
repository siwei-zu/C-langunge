#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//���ļ�
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror(fopen);
		return 1;
	}

	//���ļ����ݲ���

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <Windows.h>
int main()//��д���룬��ʾ����ַ��������ƶ������м��ۡ�
{
	char arr1[] = "hello world!!!!!!!!";
	char arr2[] = "###################";
	int right = strlen(arr1) - 1;
	int left = 0;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");
		left++;
		right--;
	}
	printf("%s\n", arr1);
	return 0;
}
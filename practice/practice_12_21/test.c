#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include "ADD.h"
void menu()
{
	printf("**************************\n");
	printf("****  1.play  0.exit  ****\n");
	printf("**************************\n");

}
void game()
{
	char arr[HANG][LIE] = { 0 };
	char arr1[HANG][LIE] = { 0 };
	chushihua(arr1, HANG, LIE);//���,���Ǳ����arr1����ֹ��ʼ���֪���������
	chushihua(arr, HANG, LIE);//��䣬����Ļ���arr���׾ͱ��������棩
	chushihua3(arr, HANG, LIE);//���ף������������arr����
	chushihua2(arr1, HANG, LIE);//����
	neirong1(arr, arr1, HANG, LIE);
}
int main()//ɨ��
{
	int input = 0;
	do//��do..whileѭ��ʵ����Ϸ
	{
		menu();//��ӡ��Ϸ��ʼ����
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)//����ʵ��ѡ��
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("����������������룡��");
		}


	} while (input);//�����Ӧ�������ѡ��1��Ϊ�桰0��Ϊ���Զ�����ѭ��
	return 0;
}
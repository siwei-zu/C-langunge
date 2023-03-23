#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//ʵ��һ��ͨѶ¼��
//
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//
//�ṩ������
//
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��


void menu()
{
	printf("************************************\n");
	printf("****    1. add      2. del      ****\n");
	printf("****    3. search   4. modify   ****\n");
	printf("****    5. show     6. all_clear****\n");
	printf("****    7. sort     8. exit     ****\n");
	printf("************************************\n");
}

enum S
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	ALL_CLEAR,
	SORT
};

int main()
{
	Contact contact = {0};
	contact_init(&contact);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			contact_add(&contact);
			break;
		case DEL:
			contact_del(&contact);
			break;
		case SEARCH:
			contact_search(&contact);
			break;
		case MODIFY:
			contact_modify(&contact);
			break;
		case SHOW:
			contact_show(&contact);
			break;
		case ALL_CLEAR:
			contact_clear(&contact);
			break;
		case SORT:
			contact_sort(&contact);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}while (input);
	return 0;
}

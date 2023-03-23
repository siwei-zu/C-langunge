#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 20
#define	MAX_SEX 5
#define	MAX_TELE 12
#define	MAX_ADDRESS 30
#define MAX_NUM 100


typedef struct Peoinfor
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}Peoinfor;

typedef struct Contact
{
	Peoinfor num[MAX_NUM];
	int sz;
}Contact;
//��ʼ��ͨѶ¼
void contact_init(Contact* contact);
//����ͨѶ¼��ϵ��
void contact_add(Contact* contact);
//ɾ��ͨѶ¼��ϵ��
void contact_del(Contact* contact);
//����ͨѶ¼��ϵ��
void contact_search(Contact* contact);
//�޸�ͨѶ¼��ϵ��
void contact_modify(Contact* contact);
//��ʾ������ϵ��
void contact_show(Contact* contact);
//���ͨѶ¼������ϵ��
void contact_clear(Contact* contact);
//����ͨѶ¼��������
void contact_sort(Contact* contact);








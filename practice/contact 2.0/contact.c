#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void contact_init(Contact* contact)
{
	contact->num = (Peoinfor*)malloc(sizeof(Peoinfor) * MAX_INI);
	memset(contact->num, 0, sizeof(Peoinfor) * MAX_INI);
	contact->capacity = MAX_INI;
	contact->sz = 0;
}


//����ͨѶ¼
int contact_dila(Contact* contact)
{
	Peoinfor* ptr = (Peoinfor*)realloc(contact->num, (contact->capacity + MAX_AD));
	if (ptr == NULL)
	{
		return 0;
	}
	else
	{
		contact->num = ptr;
		contact->capacity += MAX_AD;
	}
}


void contact_add(Contact* contact)
{
	if (contact->sz == contact->capacity)
	{
		//����
		if (contact_dila(contact) == 0)
		{
			printf("����ʧ��\n");
			return;
		}
		else
		{
			printf("���ݳɹ�����ǰ������%d", contact->capacity);
		}
	}
		printf("����������:>");
		scanf("%s", (contact->num)[contact->sz].name);
		printf("�������Ա�:>");
		scanf("%s", (contact->num)[contact->sz].sex);
		printf("����������:>");
		scanf("%d", &(contact->num)[contact->sz].age);
		printf("������绰:>");
		scanf("%s", (contact->num)[contact->sz].tele);
		printf("������סַ:>");
		scanf("%s", (contact->num)[contact->sz].address);
		printf("��ӳɹ�\n");
		contact->sz++;
}

void contact_del(Contact* contact)
{
	if(contact->sz > 0)
	{
		char name[MAX_NAME] = {0};
		printf("�����뱻ɾ����ϵ������:>");
		scanf("%s", name);
		int  i = 0;
		int flag = 0;
		while (i < contact->sz)
		{
			if (strcmp((contact->num)[i].name, name) == 0)
			{
				for (i; i < contact->sz - 1; i++)
				{
					contact->num[i] = contact->num[i + 1];
				}
				flag = 1;
				printf("ɾ���ɹ�\n");
				contact->sz--;
			}
			i++;
		}
		if (flag == 0)
		{
			printf("ͨѶ¼��û�ж�Ӧ��ϵ��\n");
		}
	}
	else
	{
		printf("ͨѶ¼������ϵ��\n");
	}
}

void contact_print(Peoinfor* peo)
{
	printf("%-10s %-5s %-4d %-12s %-20s\n", peo->name, peo->sex, peo->age, peo->tele, peo->address);
}


void contact_search(Contact* contact)
{
	if (contact->sz > 0)
	{
		char name[MAX_NAME] = { 0 };
		printf("�����뱻������ϵ������:>");
		scanf("%s", name);
		int  i = 0;
		int flag = 0;
		while (i < contact->sz)
		{
			if (strcmp((contact->num)[i].name, name) == 0)
			{
				printf("%-10s %-5s %-3s %-12s %-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
				contact_print(&((contact->num)[i]));
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			printf("ͨѶ¼��û�ж�Ӧ��ϵ��\n");
		}
	}
	else
	{
		printf("ͨѶ¼������ϵ�ˣ��޷�����\n");
	}
}

void contact_modify(Contact* contact)
{
	if (contact->sz > 0)
	{
		char name[MAX_NAME] = { 0 };
		printf("�����뱻������ϵ������:>");
		scanf("%s", name);
		int  i = 0;
		int flag = 0;
		while (i < contact->sz)
		{
			if (strcmp((contact->num)[i].name, name) == 0)
			{
				printf("����������:>");
				scanf("%s", (contact->num)[i].name);
				printf("�������Ա�:>");
				scanf("%s", (contact->num)[i].sex);
				printf("����������:>");
				scanf("%d", &(contact->num)[i].age);
				printf("������绰:>");
				scanf("%s", (contact->num)[i].tele);
				printf("������סַ:>");
				scanf("%s", (contact->num)[i].address);
				printf("�޸ĳɹ�\n");
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			printf("ͨѶ¼��û�ж�Ӧ��ϵ��,�޷��޸�\n");
		}
	}
	else
	{
		printf("ͨѶ¼������ϵ�ˣ��޷��޸�\n");
	}
}

void contact_show(Contact* contact)
{
	if(contact->sz>0)
	{
		printf("%-10s %-5s %-3s %-12s %-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		int i = 0;
		for (i = 0; i < contact->sz; i++)
		{
			contact_print(&((contact->num)[i]));
		}
	}
	else
	{
		printf("ͨѶ¼������ϵ��\n");
	}

}

void contact_clear(Contact* contact)
{
	memset(contact->num, 0, sizeof(int) * MAX_NUM);
	contact->sz = 0;
	printf("����ɹ�\n");
}

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((Peoinfor*)(e1))->name, ((Peoinfor*)(e2))->name);
}

void contact_sort(Contact* contact)
{
	if(contact->sz > 0)
	{
		qsort(contact->num, contact->sz, sizeof(contact->num[0]), cmp_by_name);
		printf("����ɹ�\n");
	}
	else
	{
		printf("ͨѶ¼������ϵ�ˣ��޷�����\n");
	}
}







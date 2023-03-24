#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void contact_init(Contact* contact)
{
	contact->num = (Peoinfor*)malloc(sizeof(Peoinfor) * MAX_INI);
	memset(contact->num, 0, sizeof(Peoinfor) * MAX_INI);
	contact->capacity = MAX_INI;
	contact->sz = 0;
}


//扩容通讯录
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
		//扩容
		if (contact_dila(contact) == 0)
		{
			printf("扩容失败\n");
			return;
		}
		else
		{
			printf("扩容成功，当前容量：%d", contact->capacity);
		}
	}
		printf("请输入姓名:>");
		scanf("%s", (contact->num)[contact->sz].name);
		printf("请输入性别:>");
		scanf("%s", (contact->num)[contact->sz].sex);
		printf("请输入年龄:>");
		scanf("%d", &(contact->num)[contact->sz].age);
		printf("请输入电话:>");
		scanf("%s", (contact->num)[contact->sz].tele);
		printf("请输入住址:>");
		scanf("%s", (contact->num)[contact->sz].address);
		printf("添加成功\n");
		contact->sz++;
}

void contact_del(Contact* contact)
{
	if(contact->sz > 0)
	{
		char name[MAX_NAME] = {0};
		printf("请输入被删除联系人姓名:>");
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
				printf("删除成功\n");
				contact->sz--;
			}
			i++;
		}
		if (flag == 0)
		{
			printf("通讯录中没有对应联系人\n");
		}
	}
	else
	{
		printf("通讯录中无联系人\n");
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
		printf("请输入被查找联系人姓名:>");
		scanf("%s", name);
		int  i = 0;
		int flag = 0;
		while (i < contact->sz)
		{
			if (strcmp((contact->num)[i].name, name) == 0)
			{
				printf("%-10s %-5s %-3s %-12s %-20s\n", "姓名", "性别", "年龄", "电话", "地址");
				contact_print(&((contact->num)[i]));
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			printf("通讯录中没有对应联系人\n");
		}
	}
	else
	{
		printf("通讯录中无联系人，无法查找\n");
	}
}

void contact_modify(Contact* contact)
{
	if (contact->sz > 0)
	{
		char name[MAX_NAME] = { 0 };
		printf("请输入被查找联系人姓名:>");
		scanf("%s", name);
		int  i = 0;
		int flag = 0;
		while (i < contact->sz)
		{
			if (strcmp((contact->num)[i].name, name) == 0)
			{
				printf("请输入姓名:>");
				scanf("%s", (contact->num)[i].name);
				printf("请输入性别:>");
				scanf("%s", (contact->num)[i].sex);
				printf("请输入年龄:>");
				scanf("%d", &(contact->num)[i].age);
				printf("请输入电话:>");
				scanf("%s", (contact->num)[i].tele);
				printf("请输入住址:>");
				scanf("%s", (contact->num)[i].address);
				printf("修改成功\n");
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			printf("通讯录中没有对应联系人,无法修改\n");
		}
	}
	else
	{
		printf("通讯录中无联系人，无法修改\n");
	}
}

void contact_show(Contact* contact)
{
	if(contact->sz>0)
	{
		printf("%-10s %-5s %-3s %-12s %-20s\n", "姓名", "性别", "年龄", "电话", "地址");
		int i = 0;
		for (i = 0; i < contact->sz; i++)
		{
			contact_print(&((contact->num)[i]));
		}
	}
	else
	{
		printf("通讯录中无联系人\n");
	}

}

void contact_clear(Contact* contact)
{
	memset(contact->num, 0, sizeof(int) * MAX_NUM);
	contact->sz = 0;
	printf("清除成功\n");
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
		printf("排序成功\n");
	}
	else
	{
		printf("通讯录中无联系人，无法排序\n");
	}
}







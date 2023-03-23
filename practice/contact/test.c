#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//实现一个通讯录；
//
//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//
//提供方法：
//
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人


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
		printf("请选择:>");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}while (input);
	return 0;
}

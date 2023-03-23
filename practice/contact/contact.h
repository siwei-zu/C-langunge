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
//初始化通讯录
void contact_init(Contact* contact);
//增加通讯录联系人
void contact_add(Contact* contact);
//删除通讯录联系人
void contact_del(Contact* contact);
//搜索通讯录联系人
void contact_search(Contact* contact);
//修改通讯录联系人
void contact_modify(Contact* contact);
//显示所有联系人
void contact_show(Contact* contact);
//清除通讯录所有联系人
void contact_clear(Contact* contact);
//排序通讯录，按名字
void contact_sort(Contact* contact);








#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

typedef struct Stu {
	char name[20];
	char id[15];
	int age;
	char sex[5];
}Stu;

int my_cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int my_cmp_float(const void* e1, const void* e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}

int my_cmp_Stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int my_cmp_Stu_by_name(const void* e1, const void* e2)
{
	return  strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

void swap(char* ele1, char* ele2,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		char tmp = *ele1;
		*ele1 = *ele2;
		*ele2 = tmp;
		ele1++;
		ele2++;
	}
}

void my_qsort(void* base, int num, int sz, int (*cmp)(const void*, const void*))
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		int j = 0;
		for (j = 0; j < num - i ; j++)
		{
			if (cmp((char*)base + (i)*sz, (char*)base + (i + j) * sz) > 0)//这里强制类型转换为char*之后保证了指针可以移动，sz保证了指针移动所需要相应类型的不足
			{
				swap((char*)base + (i ) * sz, (char*)base + (i + j) * sz, sz);//同理
			}
		}
	}
}

int main()//qsort函数的自我实现
{
	int i = 0;
	int arr[] = {1,3,5,7,9,0,2,4,6,8};
	Stu s[3] = { {"张三","2022004444",21,"男"},{"李四","2022005555",23,"男"},{"王五","2022001111",20,"男"} };
	float frr[] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0.0 };
	int arr_num = sizeof(arr) / sizeof(arr[0]);
	int arr_sz = sizeof(arr[0]);
	my_qsort(arr, arr_num, arr_sz, my_cmp_int);
	for (i = 0; i < arr_num; i++)
		printf("%d ", arr[i]);
	printf("\n");
	int frr_num = sizeof(frr) / sizeof(frr[0]);
	int frr_sz = sizeof(frr[0]);
	my_qsort(frr, frr_num, frr_sz, my_cmp_float);
	my_qsort(arr, arr_num, arr_sz, my_cmp_int);
	for (i = 0; i < frr_num; i++)
		printf("%.1f ", frr[i]);
	printf("\n");
	int s_num = sizeof(s) / sizeof(s[0]);
	int s_sz = sizeof(s[0]);
	my_qsort(s,  s_num, s_sz, my_cmp_Stu_by_age);
	for (i = 0; i <s_num; i++)
	{
		printf("%s %s %d %s\n", (s + i)->name, (s + i)->id, (s + i)->age, (s + i)->sex);
	}
	my_qsort(s, s_num, s_sz, my_cmp_Stu_by_name);
	for (i = 0; i < s_num; i++)
	{
		printf("%s %s %d %s\n", (s + i)->name, (s + i)->id, (s + i)->age, (s + i)->sex);
	}
	return 0;
}

//int main()
//{
//	char a[] = "啊";
//	char b[] = "啊";
//	int ret = strcmp(a, b);
//	printf("%d", ret);
//}
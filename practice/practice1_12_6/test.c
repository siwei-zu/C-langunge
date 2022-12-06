#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "function.h"
struct Stu {
	char name[20];
	char sex[5];
	int age;
};



int main()
{
	int i = 0;
	int arr[] = { 0,2,4,6,8,1,3,5,7,9 };
	float frr[] = { 1.0,3.0,5.0,7.0,9.0,2.0,4.0,6.0,8.0,0.0 };
	int num_arr = sizeof(arr) / sizeof(arr[0]);
	int sz_arr = sizeof(arr[0]);
	struct Stu pStu[3] = { {"张三","男",33},{"李四","男",32},{"王五","男",35} };
	//for (i = 0; i < 10; i++)//排序int类型的数字
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	//my_qsort(arr, num_arr, sz_arr, my_compare);
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	int num_Stu = sizeof(pStu) / sizeof(pStu[0]);
	int sz_Stu = sizeof(pStu[0]);
	struct Stu(*ppStu) = pStu;
	//for (i = 0; i < 3; i++)
	//{
	//	printf("%s ", pStu[i].name);
	//	printf("%s ", pStu[i].sex);
	//	printf("%d ", pStu[i].age);
	//	printf("\n");
	//}
	//printf("\n");
	//my_qsort(ppStu, num_Stu, sz_Stu, my_compare);
	//for (i = 0; i < 3; i++)
	//{
	//	 printf("%s ", pStu[i].name);
	//	 printf("%s ", pStu[i].sex);
	//	 printf("%d ", pStu[i].age);
	//	 printf("\n");
	//}
	//printf("\n");
	int num_flo = sizeof(frr) / sizeof(frr[0]);
	int sz_flo = sizeof(frr[0]);
	for (i = 0; i < 10; i++)
	{
		printf("%.1f ", frr[i]);
	}
	printf("\n");
	my_qsort(frr, num_flo, sz_flo, my_compare);
	for (i = 0; i < 10; i++)
	{
		printf("%.1f ", frr[i]);
	}
	printf("\n");
	return 0;
}
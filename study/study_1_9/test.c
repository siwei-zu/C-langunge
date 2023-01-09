#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int sum = 1;
//	int count = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum = 1;
//		for (j = 1; j <= i; j++)
//		{
//			sum *= j;
//		}
//		count += sum;
//	}
//	printf("%d\n", count);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int n = 0;
//	int count = 0;
//	int sum = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//		count += sum;
//	}
//	printf("%d\n", count);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int left = 0;
//	int target = 21;
//	int right = sizeof(arr) / sizeof(arr[0])-1;
//	while (left <= right)
//	{
//		//int mid = (left + right) / 2;//可能会溢出
//		//优化
//		int mid = (right - left) / 2 + left;
//		if (arr[mid] < target)
//			left = mid + 1;
//		if (arr[mid] > target)
//			right = mid - 1;
//		if (arr[mid] == target)
//		{
//			printf("%d的下标为%d\n", target, mid);
//			return 0;
//		}
//	}
//	printf("找不到对应数字的下标\n");
//	return 0;
//}

#include <windows.h>
#include <string.h>
//int main()
//{
//	char ch1[] = "hello world";
//	char ch2[] = "###########";
//	int left = 0;
//	int right = strlen(ch1) - 1;
//	while (left <= right)
//	{
//		ch2[left] = ch1[left];
//		ch2[right] = ch1[right];
//		printf("%s\n", ch2);
//		left++;
//		right--;
//		Sleep(1000);
//		system("cls");
//	}
//	printf("%s\n", ch1);
//	getchar();
//	getchar();
//	return 0;
//}

//int main()
//{
//	char arr1[] = "123456";
//	char arr[20] = { 0 };
//	int i = 3;
//	while (i)
//	{
//		scanf("%s", arr);
//		if(strcmp(arr1, arr)==0)
//		{
//			printf("输入正确，登陆成功\n");
//			return 0;
//		}
//		else
//		{
//			i--;
//			if (i == 0)
//				break;
//			printf("输入错误，你还有%d次机会\n", i);
//			
//		}
//	}
//	printf("三次全部输入错误，请退出程序。");
//	return 0;
//}


#include <stdio.h>


int  main()
{
	int i = 0;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flag * 1.0 / i;
		flag = -flag;
	}
	printf("%lf\n", sum);
	return 0;
}

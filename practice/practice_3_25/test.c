#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//int* test(int* str, int n, int* returnSize)
//{
//	*returnSize = 2;
//	int* ans = (int*)calloc(2, sizeof(int));
//	if (ans == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return NULL;
//	}
//	int i = 0;
//	int tmp = 0;
//	for (i = 0; i < n; i++)
//	{
//		tmp ^= str[i];
//	}
//	int x = tmp & (-tmp);
//	for (i = 0; i < n; i++)
//	{
//		if (((str[i] & (-str[i])) ^ x) == 0)
//		{
//			ans[0] ^= str[i];
//		}
//		else
//		{
//			ans[1] ^= str[i];
//		}
//	}
//	return ans;
//}
//
//
//int main()
//{
//	//实现输入数组
//	int n = 0;//数组的元素的个数
//	scanf("%d", &n);
//	int* str = (int*)malloc(sizeof(int) * n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", str + i);
//	}
//
//	//解题
//	int returnSize = 0;
//	int* ans = test(str, n, &returnSize);
//	for (i = 0; i < returnSize; i++)
//	{
//		printf("%d ", ans[i]);
//	}
//
//	//释放
//	free(ans);
//	ans = NULL;
//	free(str);
//	str = NULL;
//	return 0;
//}


//模拟实现strncpy

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncpy(char* str2, const char* str1, size_t n)
//{
//	assert(str2 && str1);
//	char* ans = str2;
//	while ((*str2++ = *str1++) && (--n))
//	{
//		;
//	}
//	return ans;
//}
//
//int main()
//{
//	char str1[] = "abcdef";
//	char str2[20] = { 0 };
//	printf("%s", my_strncpy(str2, str1, 3));
//	return 0;
//}

//模式实现strncat

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncat(char* str2, const char* str1, size_t n)
//{
//	assert(str2 && str1);
//	char* ans = str2;
//	while (*str2)
//	{
//		str2++;
//	}
//	while ((*str2++ = *str1++) && (--n))
//	{
//		;
//	}
//	*str2 = '\0';
//	return ans;
//}
//
//int main()
//{
//	char str1[] = "abcdef";
//	char str2[20] = "qwer";
//	printf("%s", my_strncat(str2, str1, 6));
//	return 0;
//}

//模拟实现atoi

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	printf("%d", atoi(""));
//	return 0;
//}

#include <stdio.h>
#include <assert.h>
#include <math.h>

int my_atoi(const char* str)
{
	assert(str);
	long long ans = 0;
	int decide = 1;
	int flag = 1;
	while (1)
	{
		if (*str == '-' || *str == '+' || (*str > '0' && *str <= '9'))
		{
			if ((flag == 0) && (*str == '-' || *str == '+'))
				return 0;
			break;
		}
		else if (*str == ' ' || *str == '0')
		{
			if (*str == '0')
				flag = 0;
			if (*str == ' ' && flag == 0)
				return 0;
			str++;
		}
		else
		{
			return (int)(ans);
		}
	}
	if (*str == '-')
	{
		decide = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			ans *= 10;
			ans += *str - 48;
			//if (abs(ans) > 100000000 && ans % 100 / 10 != (*(str - 1) - 48))
			//{
			//	if (decide > 0)
			//		return INT_MAX;
			//	else
			//	{
			//		return INT_MIN;
			//	}
			//}
			if ((ans >= INT_MIN && ans <= INT_MAX) == 0)
			{
				if (decide > 0)
					return INT_MAX;
				else
					return INT_MIN;
			}
		}
		else
		{
			if ((ans >= INT_MIN && ans <= INT_MAX) == 0)
			{
				if (decide > 0)
					return INT_MAX;
				else
					return INT_MIN;
			}
			return (ans * decide);
		}
		str++;
	}
	if ((ans >= INT_MIN && ans <= INT_MAX) == 0)
	{
		if (decide > 0)
			return INT_MAX;
		else
			return INT_MIN;
	}
	return (ans * decide);
}

int main()
{
	char str[20] = { 0 };
	scanf("%s", str);
	int val = my_atoi(str);
	printf("%d", val);
	return 0;
}


//int my_atoi(const char* str)
//{
//	assert(str);
//	int ans = 0;
//	int decide = 1;
//	while (1)
//	{
//		if (*str == '-' || *str == '+' || (*str > '0' && *str <= '9'))
//			break;
//		else if (*str == ' ' || *str == '0')
//		{
//			str++;
//		}
//		else
//		{
//			return (int)(ans * 10);
//		}
//	}
//	if (*str == '-')
//	{
//		decide = -1;
//		str++;
//	}
//	else if (*str == '+')
//	{
//		str++;
//	}
//	while (*str)
//	{
//		if (*str >= '0' && *str <= '9')
//		{
//			ans *= 10;
//			ans += *str - 48;
//		}
//		else
//		{
//			return (ans * decide);
//		}
//		str++;
//	}
//	return (ans * decide);
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fine_target_in_matrix(int** arr, int row, int col, int target)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (arr[i][col - 1] > target)
		{
			int j = 0;
			for (j = col - 1; j >= 0; j--)
			{
				if (arr[i][j] == target)
					return 1;
			}
		}
		else if (target == arr[i][col - 1])
			return 1;
	}
	return 0;
}

int main()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	scanf("%d %d", &m, &n);
	int target = 0;
	scanf("%d", &target);
	int** arr = (int**)malloc(sizeof(int*) * m);
	//生成矩阵
	for (i = 0; i < m; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
		memset(arr[i], 0, sizeof(int) * n);
	}
	for (i = 0; i < n; i++)
	{
		arr[0][i] = i;
	}
	for (i = 1; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][j] = arr[i - 1][j] + 1;
		}
	}

	//打印矩阵
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	if (fine_target_in_matrix(arr, m, n, target) == 1)
	{
		printf("可以在该矩阵中找到目标值\n");
	}
	else
	{
		printf("不可以在该矩阵中找到目标值\n");
	}
	return 0;
}


void reverseString(char* s, int sSize) {
	int left = 0;
	int right = sSize - 1;
	char tmp;
	while (left < right)
	{
		tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
		left++;
		right--;
	}
}

void fun_reversal(char* left, char* right)
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}


int main()
{
    char s[] = "Let's take LeetCode contest";
    char* left = s;
    char* right = s;
    int len = strlen(s) - 1;
    while (right <= s + len)
    {
        char* start = left;
        while ((*start != ' ') && (*start != '\0'))
        {
            start++;
        }
        fun_reversal(left, start - 1);
        left = start + 1;
        right = start + 1;
    }
    printf("%s\n", s);
}

#include <stdio.h>
#include <assert.h>

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int my_strlen(char* str)
{
	char* ret = str;
	while (*ret)
	{
		ret++;
	}
	return ret - str;
}

char* revolve_array(char* arr, int k)
{
	assert(arr);
	int len = my_strlen(arr);
	int count = k % len;
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		char tmp = arr[left];
		arr[left++] = arr[right];
		arr[right--] = tmp;
	}
	left = len - count;
	right = len - 1;
	while (left < right)
	{
		char tmp = arr[left];
		arr[left++] = arr[right];
		arr[right--] = tmp;
	}
	left = 0;
	right = len - count - 1;
	while (left < right)
	{
		char tmp = arr[left];
		arr[left++] = arr[right];
		arr[right--] = tmp;
	}
	return arr;
}

int my_strcmp_revolve_str(char* s1, char* s2)
{
	assert(s1 && s2);
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);
	if (len1 != len2)
		return 0;
	int i = 0;
	for (i = 0; i < len1; i++)
	{

		if (my_strcmp(revolve_array(s1, 1), s2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char s1[1000] = { 0 };
	char s2[1000] = { 0 };
	scanf("%s", s1);
	scanf("%s", s2);
	if (my_strcmp_revolve_str(s1, s2) == 1)
	{
		printf("s1是s2旋转之后得到的字符串\n");
	}
	else
	{
		printf("s1不是s2旋转之后得到的字符串\n");
	}
	return 0;
}
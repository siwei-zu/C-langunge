#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//模拟strlen函数

//int my_strlen(const char* str1)
//{
//	assert(str1);
//	char* ret = (char*)str1;
//	while (*str1)
//	{
//		str1++;
//	}
//	return str1 - ret;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}



//模拟strcpy函数

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = { 0 };
//	printf("%s\n", my_strcpy(arr2, arr1));
//	return 0;
//}



//模拟实现strcat函数

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = "qwer";
//	printf("%s\n", my_strcat(arr2, arr1));
//	return 0;
//}
//
//
//#include <stdio.h>
//#include <assert.h>
//
////strcmp
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//
//int main()
//{
//	char arr1[] = "qwers";
//	char arr2[20] = "qwer";
//	printf("%d\n", my_strcmp(arr1, arr2));
//	return 0;
//}
// 
//
////strstr//1.先找头，再找身//KMP算法
//
#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* s1 = NULL;
	char* s2 = NULL;
	char* cp = (char*)str1;
	while (*cp)
	{
		s1 = cp;
		s2 = (char*)str2;
		while (s1 && s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cp;
		}
		cp++;
	}
	return NULL;
}

int main()
{
	char arr1[] = "abcddddefghigklmn";
	char arr2[20] = "def";
	if (my_strstr(arr1, arr2) == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%s\n", my_strstr(arr1, arr2));
	}
	return 0;
}

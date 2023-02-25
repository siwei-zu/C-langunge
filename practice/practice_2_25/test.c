#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool checkInclusion(char* s1, char* s2) {
    int l = 0;
    int r = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2)
        return false;
    char* map = (char*)malloc(sizeof(char) * 27);
    char* decide = (char*)malloc(sizeof(char) * 27);
    memset(map, '0', sizeof(char) * 27);
    memset(decide, '0', sizeof(char) * 27);
    map[26] = decide[26] = '\0';
    while (s1[r] != '\0')
    {
        map[s1[r] - 97] += 1;
        decide[s2[r] - 97] += 1;
        r++;
    }
    //r -= 1;
    while (s2[r] != '\0')
    {
        if (strcmp(map, decide) == 0)
        {
            free(map);
            free(decide);
            return true;
        }
        decide[s2[l] - 97] -= 1;
        l++;
        //r++;
        decide[s2[r] - 97] += 1;
        r++;
    }
    if (strcmp(map, decide) == 0)
    {
        return true;
    }
    free(map);
    free(decide);
    return false;
}

int lengthOfLongestSubstring(char* s) {
    int* map = malloc(sizeof(int) * 128);
    memset(map, 0, sizeof(int) * 128);
    int len = strlen(s);
    if (len == 0)
        return 0;
    int left = 0;
    int right = 0;
    int max = 0;
    int count = 0;
    for (left = 0, right = 0; left < len && right < len; )
    {
        if (map[s[right]] == 0)
        {
            map[s[right]]++;
            right++;
        }
        else
        {
            map[s[left]] = 0;
            left++;
        }
        max = max > right - left ? max : right - left;
    }

    return max;
}

struct Stu {
	char name[20];
	int age;
};

int cmp_Stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int cmp_Stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void test3()
{
	struct Stu arr[3] = { {"zhangsan",25},{"lisi",20},{"wangwu",15} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_Stu_by_name);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s %d\n", (arr + i)->name, (arr+i)->age);
	}
	printf("\n");
	qsort(arr, sz, sizeof(arr[0]), cmp_Stu_by_age);
	for (i = 0; i < sz; i++)
	{
		printf("%s %d\n", (arr + i)->name, (arr + i)->age);
	}
	printf("\n");
}

int cmp_float(const void* e1, const void* e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}

void test2()//浮点型
{
	float arr[] = { 9.0,8.0,7.0,4.0,5.0,6.0,1.0,3.0,2.0,1.0, 0.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(float), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%.1f ", arr[i]);
	}
	printf("\n");
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void test1()//整形
{
	int arr[] = { 9,8,7,4,5,6,1,2,3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(int), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	test1();//整形
	test2();//浮点型
	test3();//结构体
	return 0;
}
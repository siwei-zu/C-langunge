#define _CRT_SECURE_NO_WARNINGS 1
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

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cp = (char*)str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = (char*)str2;
//		while (s1 && s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "abcddddefghigklmn";
//	char arr2[20] = "def";
//	if (my_strstr(arr1, arr2) == NULL)
//	{
//		printf("’“≤ªµΩ\n");
//	}
//	else
//	{
//		printf("%s\n", my_strstr(arr1, arr2));
//	}
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

int main()
{
    struct ListNode* l11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l1 = l11;
    struct ListNode* l2 = l22;
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &l11->val);
		l11->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(i != 2)
        {
            l11 = l11->next;
        }
        //l11->next = NULL;
	}
    l11->next = NULL;
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &l22->val);
		l22->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(i != 2)
        {
            l22 = l22->next;
        }
        //l22->next = NULL;
	}
    l22->next = NULL;
    struct ListNode* rail = (struct ListNode*)malloc(sizeof(struct ListNode*));
    rail->val = 0;
    rail->next = NULL;
    struct ListNode* head = rail;
    int sum = 0;
    while (l1 || l2)
    {
        if (l1 == NULL && l2 != NULL)
        {
            rail->val += (l2->val + sum) % 10;
            sum = (l2->val + sum) / 10;
            l2 = l1->next;
            //rail->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
            //rail = rail->next;
            //rail->val = 0;
            //rail->next = NULL;
        }
        else if (l1 != NULL && l2 == NULL)
        {
            rail->val += (l1->val + sum) % 10;
            sum = (l1->val + sum) / 10;
            l1 = l1->next;
            //rail->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
            //rail = rail->next;
            //rail->val = 0;
            //rail->next = NULL;
        }
        else
        {
            rail->val += (l1->val + sum + l2->val) % 10;
            sum = (l1->val + sum + l2->val) / 10;
            l1 = l1->next;
            l2 = l2->next;
            //rail->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
            //rail = rail->next;
            //rail->val = 0;
            //rail->next = NULL;
        }
        if(l1 != NULL  || l2 != NULL)
        {
            rail->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
            rail = rail->next;
            rail->val = 0;
            rail->next = NULL;
        }
    }
    if (sum != 0)
    {
        rail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        rail = rail->next;
        rail->val = sum;
        rail->next = NULL;
    }
    //return head;
	return 0;
}
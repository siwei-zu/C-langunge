#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>

///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    if (headA == NULL || headB == NULL) {
//        return NULL;
//    }
//    struct ListNode* pA = headA, * pB = headB;
//    while (pA != pB) {
//        pA = pA == NULL ? headB : pA->next;
//        pB = pB == NULL ? headA : pB->next;
//    }
//    return pA;
//}

void game()//��������Ϸ
{
	int input2 = 0;
	int ret = 0;
	srand((unsigned)time(NULL));//�����NULL��һ����ָ����˼��
	ret = rand() % 100 + 1;
	while (1)
	{
		printf("������µ����֣�");
		scanf("%d", &input2);
		if (input2 < ret)
		{
			printf("��С��\n");
		}
		if (input2 > ret)
		{
			printf("�´���\n");
		}
		if (input2 == ret)
		{
			printf("��ϲ�㣬�¶��ˣ���\n");
			break;
		}
		if (input2 == 0)
		{
			break;
		}
	}
}

void  menu()
{
	printf("******************************\n");
	printf("*****   1.play  2.exit   *****\n");
	printf("******************************\n");
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			break;
		default:
			break;

		}
	} while (input);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
int* reversePrint(struct ListNode* head, int* returnSize) {
	int len = 10000;
	int* ret = (int*)malloc(sizeof(int) * len);
	struct ListNode* p = head;
	while (p) {
		ret[--len] = p->val;
		p = p->next;
	}
	*returnSize = 10000 - len;
	return ret + len;
}


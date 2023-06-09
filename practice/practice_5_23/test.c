#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "QList.h"

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(int x)
{
	BTNode* TreeNode = (BTNode*)malloc(sizeof(BTNode));
	if (TreeNode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	TreeNode->data = x;
	TreeNode->left = NULL;
	TreeNode->right = NULL;
	return TreeNode;
}

//ǰ�򴴽�����������
//BTNode* BuyNode(char x)
//{
//	BTNode* TreeNode = (BTNode*)malloc(sizeof(BTNode));
//	if (TreeNode == NULL)
//	{
//		perror("malloc fail");
//		return NULL;
//	}
//	TreeNode->data = x;
//	TreeNode->left = NULL;
//	TreeNode->right = NULL;
//	return TreeNode;
//}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode * node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(8);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->left = node7;
	node7->left = node8;

	return node1;
}

// ������ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//void PreOrder(BTNode* Creat)
//{
//	if (Creat == NULL)
//	{
//		printf("#");
//		return;
//	}
//	printf("%c", Creat->data);
//	PreOrder(Creat->left);
//	PreOrder(Creat->right);
//}
// �������������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
// �������������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left)
		 + BinaryTreeSize(root->right)
		 + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//����������ֵΪx�Ľڵ�
BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;

	if (root->data == x)
	{
		return root;
	}
	if (ret = BTreeFind(root->left, x))
		return ret;
	if (ret = BTreeFind(root->right, x))
		return ret;
	return ret;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	assert(root);

	if ((*root) == NULL)
		return;

	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	(*root)->left = NULL;
	(*root)->right = NULL;
	free(*root);
	*root = NULL;
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueEmpty(&qu))
	{
		BTNode* front = QueueFront(&qu);
		printf("%d ", front->data);
		if (front->left)
		{
			QueuePush(&qu, front->left);
		}
		if (front->right)
		{
			QueuePush(&qu, front->right);
		}
		QueuePop(&qu);
	}
	QueueDestroy(&qu);
}
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueEmpty(&qu))
	{
		BTNode* front = QueueFront(&qu);
		QueuePop(&qu);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&qu, front->left);
		QueuePush(&qu, front->right);
	}

	while (!QueueEmpty(&qu))
	{
		BTNode* front = QueueFront(&qu);
		if (front)
		{
			QueueDestroy(&qu);
			return false;
		}
	}

	QueueDestroy(&qu);
	return true;
}

//��������������
int maxDepth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	return left > right ? left + 1 : right + 1;
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if(*pi < n)
	{
		if (*(a + *pi) == '#')
		{
			++(*pi);
			return NULL;
		}

		BTNode* node = BuyNode(*(a + *pi));
		++(*pi);
		node->left = BinaryTreeCreate(a, n, pi);
		node->right = BinaryTreeCreate(a, n, pi);
		return node;
	}
}

int main()
{
	BTNode* root = CreatBinaryTree();

	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root, 4));
	printf("%d\n", maxDepth(root));

	printf("maxDepth:BTreeFind:%p\n", BTreeFind(root, 6));

	if (BinaryTreeComplete(root))
		printf("True\n");
	else
		printf("False\n");


	/*char a[] = "abc##de#g##F###";
	int sz = strlen(a);
	int i = 0;
	BTNode* Creat = BinaryTreeCreate(a, sz, &i);
	PreOrder(Creat);
	InOrder(Creat);
	printf("\n");
	BinaryTreeDestory(&root);*/
	//BinaryTreeDestory(&Creat);
	return 0;
}


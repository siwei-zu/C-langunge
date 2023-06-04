#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char BTDataType;
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

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
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

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("N ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

int main() {
	char arr[1000] = { 0 };

	scanf("%s", arr);

	int n = strlen(arr);

	int i = 0;
	BTNode* root = BinaryTreeCreate(arr, n, &i);

	InOrder(root);

}


int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;
}


bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;

    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
        return false;

    return isBalanced(root->left)
        && isBalanced(root->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (q == NULL && p == NULL)
		return true;

	if (q == NULL || p == NULL)
		return false;

	if (q->val != p->val)
		return false;

	return isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {

	if (isSameTree(root, subRoot))
		return true;

	if (root)
		return isSubtree(root->left, subRoot)
		|| isSubtree(root->right, subRoot);

	return false;
}

bool _isSymmetric(struct TreeNode* pl, struct TreeNode* pr)
{
	if (pl == NULL && pr == NULL)
		return true;

	if (pl == NULL || pr == NULL)
		return false;


	if (pl->val != pr->val)
		return false;

	return _isSymmetric(pl->left, pr->right)
		&& _isSymmetric(pl->right, pr->left);


}

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;

	return _isSymmetric(root->left, root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
	if (root == NULL)
	{
		return NULL;
	}

	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	invertTree(root->left);
	invertTree(root->right);

	return root;
}

int BinaryTreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left)
		+ BinaryTreeSize(root->right)
		+ 1;
}


void _preorderTraversal(struct TreeNode* root, int* ret, int* i)
{
	if (root == NULL)
		return;

	ret[*i] = root->val;
	(*i)++;
	_preorderTraversal(root->left, ret, i);
	_preorderTraversal(root->right, ret, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int n = BinaryTreeSize(root);
	int* ret = (int*)malloc(sizeof(int) * n);
	*returnSize = n;
	int i = 0;
	_preorderTraversal(root, ret, &i);
	return ret;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (q == NULL && p == NULL)
		return true;

	if (q == NULL || p == NULL)
		return false;

	if (q->val != p->val)
		return false;

	return isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}
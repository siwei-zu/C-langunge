#define _CRT_SECURE_NO_WARNINGS 1
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;
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

bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;

    if (root->left && root->left->val != root->val)
        return false;
    if (root->right && root->right->val != root->val)
        return false;


    return isUnivalTree(root->left)
        && isUnivalTree(root->right);
}
#define _CRT_SECURE_NO_WARNINGS 1
int* constructArr(int* a, int aSize, int* returnSize) {
    *returnSize = aSize;
    if (aSize == 0)
        return -1;
    int i = 0;
    int* ans = (int*)malloc(sizeof(int) * aSize);
    ans[0] = 1;
    for (i = 1; i < aSize; i++)
    {
        ans[i] = ans[i - 1] * a[i - 1];
    }
    int r = 1;
    for (i = aSize - 1; i >= 0; i--)
    {
        ans[i] = ans[i] * r;
        r *= a[i];
    }
    return ans;
}

int* leftRigthDifference(int* nums, int numsSize, int* returnSize) {
    int rightsum = 0;
    *returnSize = numsSize;
    int* answer = (int*)malloc(sizeof(int) * numsSize);
    int leftsum = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        rightsum += nums[i];
    }
    for (i = 0; i < numsSize; i++)
    {
        rightsum -= nums[i];
        answer[i] = leftsum > rightsum ? leftsum - rightsum : rightsum - leftsum;
        leftsum += nums[i];
    }
    return answer;
}

bool checkTree(struct TreeNode* root) {
    return root->val == root->left->val + root->right->val;
}
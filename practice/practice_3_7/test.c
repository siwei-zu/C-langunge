#define _CRT_SECURE_NO_WARNINGS 1
struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(int ikey) {
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (it == NULL) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    }
    else {
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int cmp(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* ret = (int*)malloc(sizeof(int) * 2);
    int i = 0;
    ret[0] = 0;
    ret[1] = numsSize - 1;
    int* nums2 = (int*)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++)
    {
        nums2[i] = nums[i];
    }
    qsort(nums2, numsSize, sizeof(int), cmp);
    while (ret[0] < ret[1])
    {
        if (nums2[ret[0]] + nums2[ret[1]] > target)
            ret[1]--;
        else if (nums2[ret[0]] + nums2[ret[1]] < target)
            ret[0]++;
        else
            break;
    }
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == nums2[ret[0]])
        {
            ret[0] = i;
            break;
        }
    }
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == nums2[ret[1]] && i != ret[0])
        {
            ret[1] = i;
            break;
        }
    }
    return ret;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int a = m + n - 1;
    while (a >= 0)
    {
        if (p1 == -1)
        {
            nums1[a] = nums2[p2];
            p2--;
            a--;
        }
        else if (p2 == -1)
        {
            nums1[a] = nums1[p1];
            p1--;
            a--;
        }
        else if (nums1[p1] > nums2[p2])
        {
            nums1[a] = nums1[p1];
            p1--;
            a--;
        }
        else
        {
            nums1[a] = nums2[p2];
            p2--;
            a--;
        }

    }
}
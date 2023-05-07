#define _CRT_SECURE_NO_WARNINGS 1
struct HashEntry {
    int key;
    int val;
    UT_hash_handle hh;
};

void hashAddItem(struct HashEntry** obj, int key, int val) {
    struct HashEntry* pEntry;
    pEntry = malloc(sizeof(struct HashEntry));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
}

struct HashEntry* hashFindItem(const struct HashEntry** obj, int key)
{
    struct HashEntry* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

void hashEraseItem(struct HashEntry** obj, int key)
{
    struct HashEntry* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (NULL != pEntry) {
        HASH_DEL(*obj, pEntry);
        free(pEntry);
    }
}

void hashFreeAll(struct HashEntry** obj)
{
    struct HashEntry* curr, * next;
    HASH_ITER(hh, *obj, curr, next)
    {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct HashEntry* cnt = NULL;
    for (int i = 0; i < numsSize; i++) {
        if (i > k) {
            hashEraseItem(&cnt, nums[i - k - 1]);
        }
        struct HashEntry* pEntry = hashFindItem(&cnt, nums[i]);
        if (NULL != pEntry) {
            return true;
        }
        hashAddItem(&cnt, nums[i], 1);
    }
    hashFreeAll(&cnt);
    return false;
}

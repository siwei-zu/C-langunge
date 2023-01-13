#define _CRT_SECURE_NO_WARNINGS 1
int rearrangeCharacters(char* s, char* target) {
    int* arr = (int*)malloc(sizeof(int) * 129);
    memset(arr, 0, sizeof(int) * 129);
    int i = 0;
    int count = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        arr[s[i]]++;
    }
    while (1)
    {
        for (i = 0; target[i] != '\0'; i++)
        {
            if (arr[target[i]] == 0)
                goto ret;
            arr[target[i]]--;
        }
        count++;
    }
ret:
    return count;
}
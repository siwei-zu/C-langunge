#define _CRT_SECURE_NO_WARNINGS 1
int strStr(char* haystack, char* needle) {
    int len1 = strlen(needle);
    int len2 = strlen(haystack) - 1;
    int i = 0;
    while (i + len1 - 1 <= len2)
    {
        if (strncmp(needle, haystack + i, len1) == 0)
        {
            return i;
        }
        i++;
    }
    return -1;
}
#define _CRT_SECURE_NO_WARNINGS 1
char* reverseLeftWords(char* s, int n) {
    int k = n % strlen(s);
    int l = 0;
    int r = strlen(s) - 1;
    while (l < r)
    {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
    l = 0;
    r = strlen(s) - 1 - k;
    while (l < r)
    {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
    l = strlen(s) - k;
    r = strlen(s) - 1;
    while (l < r)
    {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
    return  s;
}
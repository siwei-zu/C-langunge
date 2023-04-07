#define _CRT_SECURE_NO_WARNINGS 1
int countAsterisks(char* s) {
    bool valid = true;
    int res = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '|') {
            valid = !valid;
        }
        else if (c == '*' && valid) {
            res++;
        }
    }
    return res;

}
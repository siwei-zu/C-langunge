#define _CRT_SECURE_NO_WARNINGS 1
bool isPowerOfTwo(int n) {
    return n > 0 && (n & -n) == n;
}
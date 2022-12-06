#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void my_qsort(void* base, int num_t, int sz_t, int (*my_compare)(const void*, const void*));
int my_compare(const void* e1, const void* e2);
#define _CRT_SECURE_NO_WARNINGS 1
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d%d", &n, &m);
	int i = 0;
	int* arr = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	long long* crr = malloc(sizeof(long long) * n);
	crr[0] = 1;
	for (i = 1; i <= n; i++)
	{
		crr[i] = arr[i - 1] * crr[i - 1];
	}
	int* brr = malloc(sizeof(int) * n);
	test(arr, crr, brr, n, m);
	return 0;
}
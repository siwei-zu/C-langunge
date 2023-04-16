#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF) {
//		printf("%d\n", n * (1 + n) / 2);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int move_x[4] = { 0,1,-1,0 };
//int move_y[4] = { 1, 0,0,-1 };
//int a = 2;
//void tern(int** arr, int n, int x, int y, int move_x1, int move_y1)
//{
//	if (x < n && y < n && a<=n*n)
//	{
//		arr[x][y] = a;
//		a++;
//		if ((x + move_x1 < n && y + move_y1 < n) && arr[x + move_x1][y + move_y1] == 0)
//		{
//			tern(arr, n, x + move_x1, y + move_y1, move_x1, move_y1);
//		}
//		else
//		{
//			if (move_x1 == 0 && move_y1 == 1)
//			{
//				tern(arr, n, x + 1, y, move_x[1], move_y[1]);
//			}
//			else if (move_x1 == 1 && move_y1 == 0)
//			{
//				tern(arr, n, x, y - 1, move_x[3], move_y[3]);
//			}
//			else if (move_x1 == -1 && move_y1 == 0)
//			{
//				tern(arr, n, x, y+1, move_x[0], move_y[0]);
//			}
//			else if (move_x1 == 0 && move_y1 == -1)
//			{
//				tern(arr, n, x-1, y, move_x[2], move_y[2]);
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int** arr = (int**)calloc(n, sizeof(int*));
//
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		arr[i] = (int*)calloc(n, sizeof(int));
//	}
//	arr[0][0] = 1;
//	tern(arr, n, 0, 1, move_x[0], move_y[0]);
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()//A
//{
//	int n, m, k;
//	int i = 0;
//	scanf("%d %d %d", &n, &m, &k);
//	char ret[10001] = { 0 };
//	memset(ret, '0', sizeof(char) * n);
//	if (n - m < m - k)
//	{
//		printf("NO\n");
//		return 0;
//	}
//	else
//	{
//		int x = k;
//		while (m > 0 && x > 0)
//		{
//			ret[i] = '1';
//			i++;
//			m--;
//			x--;
//
//		}
//		if (i < n)
//		{
//			ret[i] = '0';
//			i++;
//		}
//		int l = 0;
//		while (m > 0)
//		{
//			if (i < n && l<=k)
//			{
//				ret[i] = '1';
//				l++;
//				m--;
//			}
//			else if (i < n && l > k)
//			{
//				ret[i] = '0';
//				l=0;
//			}
//			else if(i==n)
//			{
//				break;
//			}
//			i++;
//		}
//	}
//	printf("YES\n");
//	printf("%s", ret);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//int main()//I
//{
//	char ret[1001] = { 0 };
//	scanf("%s", ret);
//	if (strstr(ret, "eat") == NULL)
//	{
//		printf("What does it mean?\n");
//	}
//	else
//	{
//		printf("eeffQAQ\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//	//int a = 0;
//	//int b = 0;
//	//scanf("%d %d", &a, &b);
//	char arr1[11] = {0};
//	char arr2[11] = {0};
//	char ret[11] = {0};
//	//int num = a;
//
//	scanf("%s %s", arr1, arr2);
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	int i = (len1 > len2 ? len1 : len2)-1;
//	int k = i+1;
//	int sum = 0;
//	while (i >= 0)
//	{
//		if (arr1[i] == 0)
//		{
//			ret[k] = ((arr2[i] - 48) + sum) + 48;
//			sum = 0;
//		}
//		else if (arr2[i] == 0)
//		{
//			ret[k] = ((arr1[i] - 48) + sum) + 48;
//			sum = 0;
//		}
//		else
//		{
//			ret[k] += ((((arr1[i] + arr2[i]) - (2 * 48)) + sum) % 10) + 48;
//			sum = ((((arr1[i] + arr2[i]) - (2 * 48)) + sum)) / 10;
//		}
//		k--;
//		i--;
//	}
//	ret[k] += sum + 48;
//	//while (a > 0)
//	//{
//	//	arr1[i] = num % 10;
//	//}
//	if(ret[0] != 0)
//	{
//		int a = atoi(ret);
//		printf("%d", a);
//	}
//	else
//	{
//		int a = atoi(ret + 1);
//		printf("%d", a);
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()//B
//{
//	int n = 0;
//	scanf("%d", &n);
//	char* arr = (int*)calloc(n+1, sizeof(char));
//	scanf("%s", arr);
//	int i = 0;
//	int count = 0;
//	int k = n-1;
//	while (k >= 0)
//	{
//		if (arr[k] == 'C')
//		{
//			break;
//		}
//		k--;
//	}
//	while(i<n)
//	{
//		if (arr[i] == 'B')
//		{
//			count++;
//		}
//		else if (arr[i] == 'C' && i != k)
//		{
//			count++;
//		}
//		else if (arr[i] == 'C' && i == k)
//		{
//			if (count > 0)
//			{
//				count--;
//				printf("%d\n", count);
//				break;
//			}
//			else
//			{
//				printf("draw\n");
//				break;
//			}
//		}
//		i++;
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()//G
//{
//	int n = 0;
//	scanf("%d", &n);
//	char* arr = (char*)calloc(n + 1, sizeof(char));
//	scanf("%s", arr);
//	int l = 0;
//	int r = n - 1;
//	while (l <= r)
//	{
//		if (l != r)
//		{
//			if (arr[l] != arr[r])
//			{
//				if (arr[l] > arr[r])
//				{
//					arr[l] = arr[r];
//					break;
//				}
//				else
//				{
//					arr[r] = arr[l];
//					break;
//				}
//			}
//		}
//		else
//		{
//			if(arr[l] != 'a')
//			{
//				arr[l] = 'a';
//			}
//			else
//			{
//				arr[l] = 'b';
//			}
//		}
//		l++;
//		r--;
//	}
//	printf("%s\n", arr);
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main()//C
//{
//	int n = 0;
//	int q = 0;
//	scanf("%d %d", &n, &q);
//	int* arr = (int*)calloc(n + 1, sizeof(int));
//	int i = 0;
//	int count = 0;
//	int count_x = 0;
//	int count_y = 0;
//	for (i = 1; i <= q; i++)
//	{
//		int x = 0;
//		int y = 0;
//		scanf("%d %d", &x, &y);
//		count_x += x;
//		count_y += y;
//	}
//	for (i = 1; i <= q; i++)
//	{
//			arr[i] += count_y - abs(count_x - q*i) > 0 ? count_y - abs(count_x - q*i) : 0;
//	}
//	for (i = 1; i <= n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//	return -(*(int*)e1 - *(int*)e2);
//}
//
//int main()//D
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[100001] = { 0 };
//	int l[100001] = { 0 };
//	int r[100001] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 1; i < n; i++)
//	{
//		l[i] = l[i - 1] | arr[i - 1];
//	}
//	for (i = n-2; i >=0; i--)
//	{
//		r[i] = r[i + 1] | arr[i + 1];
//	}
//	for (i = 0; i < n; i++)
//	{
//		l[i] = l[i] | r[i];
//	}
//	qsort(l, n, sizeof(int), cmp);
//	printf("%d", l[0]);
//	return 0;
//}


//#include <stdio.h>
//
//int main()//H
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[30];
//	int i = 0;
//	int decide = 0;
//	int count = n;
//	for (i = 0; i < n; i++)
//	{
//		arr[i] = i + 1;
//	}
//	while(count>0)
//	{
//		int j = 0;
//		int x = 0;
//		int index = 0;
//		for (j = 0; j < n; j++)
//		{
//			int sum = 0;
//			if(arr[j] != 0)
//			{
//				int k = 0;
//				for (k = 1; k <= arr[j]; k++)
//				{
//					if (arr[j] % k == 0 && arr[k-1] != 0)
//					{
//						sum++;
//					}
//				}
//			}
//			if (sum > x)
//			{
//				//x = sum;
//				index = j;
//			}
//		}
//		for (j = 1; j <= arr[index]; j++)
//		{
//			if (arr[index] % j == 0)
//			{
//				if (arr[j - 1] != 0)
//				{
//					arr[j - 1] = 0;
//					count--;
//				}
//			}
//		}
//		if(decide==0)
//		{
//			decide = 1;
//		}
//		else
//		{
//			decide = 0;
//		}
//	}
//	if (decide == 1)
//	{
//		printf("Bob\n");
//	}
//	else
//	{
//		printf("Alice\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()//L
//{
//	int n = 0;
//	scanf("%d", &n);
//	int** arr = (int**)malloc(sizeof(int*) * n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		arr[i] = (int*)calloc(3, sizeof(int));
//	}
//	for (i = 0; i < n; i++)
//	{
//			scanf("%d", &arr[i][0]);
//			scanf("%d", &arr[i][1]);
//			scanf("%d", &arr[i][2]);
//			int k = 0;
//			int min = 0;
//			for (k = 1; k < 3; k++)
//			{
//				if (arr[i][0] > arr[i][k])
//				{
//					arr[i][0] = arr[i][k];
//				}
//			}
//	}
//	int* dp = (int*)calloc(n, sizeof(int));
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = n - 1; j >= 0; j--)
//		{
//			dp[j] = arr[i][0];
//			if (j > arr[i][0])
//			{
//				dp[j] = dp[j] < dp[j - arr[i][0]] + arr[i][0] ? dp[j] : dp[j - arr[i][0]] + arr[i][0];
//			}
//		}
//	}
//	printf("%d", dp[n-1]);
//	return 0;
//}


//#include <stdio.h>
//
//int car(int l, int r)
//{
//	if (r - l - 1 > 3)
//	{
//		return 1 + car(l, (l + r) / 2) + car((l + r) / 2, r);
//	}
//	else if(r -l - 1 == 3)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n == 1 || n == 2)
//	{
//		printf("1");
//		return 0;
//	}
//	printf("%d", 2 + car(1, n));
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()//A
{
	int n, m, k;
	int i = 0;
	scanf("%d %d %d", &n, &m, &k);
	char ret[10001] = { 0 };
	memset(ret, '0', sizeof(char) * n);
		int x = k;
		int y = m;
		if (k == 0 && m >0)
		{
			printf("NO");
			return 0;
		}
		while (y > 0 && x > 0)
		{
			ret[i] = '1';
			i++;
			y--;
			x--;

		}
		if (i < n)
		{
			ret[i] = '0';
			i++;
		}
		int l = 0;
		while (y > 0)
		{
			if (i < n && l <= k)
			{
				ret[i] = '1';
				l++;
				y--;
			}
			else if (i < n && l > k)
			{
				ret[i] = '0';
				l = 0;
			}
			else if (i == n)
			{
				break;
			}
			i++;
		}
		int count = 0;
		for (i = 0; i < n; i++)
		{
			if (ret[i] == '1')
			{
				count++;
			}
		}
		if(count == m)
		{
			printf("YES\n");
			printf("%s", ret);
		}
		else
		{
			printf("NO");
		}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	int price[31] = { 0 };
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = 1; i <= n; i++)//录入数据，得到所有数的价格和。
	{
		scanf("%d", &price[i]);
		sum += price[i];
	}
	int max = sum - x;
	int dp[5][131] = { 0 };
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= max; j++)
		{
			if (price[i] > j)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = dp[i][j - price[i]] + price[i] > dp[i - 1][j] ? dp[i][j - price[i]] + price[i] : dp[i - 1][j];
			}
		}
	}
	printf("%d", sum - dp[n][max]);
	return 0;
}
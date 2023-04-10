#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int minPathSum(int grid[][3], int gridSize, int* gridColSize) {
//    int n = *gridColSize;
//    int m = gridSize;
//    int dp[3][3];
//    dp[0][0] = grid[0][0];
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            if (i == 0 && j > 0)
//            {
//                dp[i][j] = dp[i][j - 1] + grid[i][j];
//            }
//            else if (j == 0 && i > 0)
//            {
//                dp[i][j] = dp[i - 1][j] + grid[i][j];
//            }
//            else if (i > 0 && j > 0)
//            {
//                dp[i][j] = (dp[i][j - 1] < dp[i - 1][j] ?
//                    dp[i][j - 1] : dp[i - 1][j]) + grid[i][j];
//            }
//        }
//    }
//    return dp[m - 1][n - 1];
//}
//
//int main()
//{
//	int grid[][3] = { {1,3,1},{1,5,1},{4,2,1} };
//	int gridSize = 3;
//	int gridColSize = 3;
//	printf("%d\n", minPathSum(grid, gridSize, &gridColSize));
//	return 0;
//}


//递归会超时
//int move(int x, int y, int m, int n)
//{
//    if (x == m && y < n)
//    {
//        return move(x, y + 1, m, n);
//    }
//    else if (y == n && x < m)
//    {
//        return move(x + 1, y, m, n);
//    }
//    else if (x < m && y < n)
//    {
//        return move(x + 1, y, m, n) + move(x, y + 1, m, n);
//    }
//    else
//    {
//        return 1;
//    }
//}
//
//int uniquePaths(int m, int n) {
//    int x = 1;
//    int y = 1;
//    return move(x, y, m, n);
//}

//动态规划

int uniquePaths(int m, int n)
{

}

#include <stdio.h>

int main()
{
    printf("%d\n", uniquePaths(20, 4));
    return 0;
}
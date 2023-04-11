#define _CRT_SECURE_NO_WARNINGS 1
int uniquePaths(int m, int n) //数学组合和动态规划
{
    long long ans = 1;
    for (int x = n, y = 1; y < m; ++x, ++y) {
        ans = ans * x / y;
    }
    return ans;

    /*int dp[m][n];
    dp[0][0] = 1;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j>0)
            {
                dp[i][j] = dp[i][j-1];
            }
            else if(i>0 && j==0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else if(i>0 && j>0)
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[m-1][n-1];*/
//}


    bool isRobotBounded(char* instructions)//暴力破解
    {
        int len = strlen(instructions);
        int i = 0;
        int ans[2] = { 0 };
        int dest[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
        int k = 0;
        for (int j = 0; j < 400; j++)
        {
            for (i = 0; i < len; i++)
            {
                if (instructions[i] == 'G')
                {
                    ans[0] += dest[k][0];
                    ans[1] += dest[k][1];
                }
                else
                {
                    if (instructions[i] == 'L')
                    {
                        k++;
                    }
                    else if (instructions[i] == 'R')
                    {
                        k--;
                    }
                    if (k == 4)
                        k = 0;
                    else if (k == -1)
                        k = 3;
                }
            }
        }
        if (ans[0] == ans[1] && ans[0] == 0)
            return true;
        else
            return false;
    }

    //bool isRobotBounded(char* instructions) //数学模拟
    //{
    //    int direc[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    //    int direcIndex = 0;
    //    int x = 0, y = 0;
    //    int n = strlen(instructions);
    //    for (int i = 0; i < n; i++) {
    //        char instruction = instructions[i];
    //        if (instruction == 'G') {
    //            x += direc[direcIndex][0];
    //            y += direc[direcIndex][1];
    //        }
    //        else if (instruction == 'L') {
    //            direcIndex += 3;
    //            direcIndex %= 4;
    //        }
    //        else {
    //            direcIndex++;
    //            direcIndex %= 4;
    //        }
    //    }
    //    return direcIndex != 0 || (x == 0 && y == 0);
    //}
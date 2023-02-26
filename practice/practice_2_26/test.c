#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int image[3][3] = { {1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } } , sr = 1, sc = 1, color = 2;
    int n = 3, m = 3;
    //int n = imageSize, m = imageColSize[0];
    //*returnSize = n;
    //for (int i = 0; i < n; i++)
    //{
    //    (*returnColumnSizes)[i] = m;
    //}

    //int j = 0;
    //for (j = 0; j < 3; j++)
    //{
    //    int i = 0;
    //    for (i = 0; i < 3; i++)
    //    {
    //        printf("%d ", image[j][i]);
    //    }
    //    printf("\n");
    //}

    int dx[4] = { 1,0,0,-1 };
    int dy[4] = { 0, 1, -1, 0 };
    int curcolor = image[sr][sc];
    if (image[sr][sc] == color)
        return 0;
    int que[9][2];
    int l = 0;
    int r = 0;
    que[r][0] = sr, que[r++][1] = sc;
    image[sr][sc] = color;
    while (l < r)
    {
        int x = que[l][0], y = que[l++][1];
        int i = 0;
        for (i = 0; i < 4; i++)
        {
            if (((x + dx[i] >= 0) && (x + dx[i] <= n))
                && ((y + dy[i] >= 0) && (y + dy[i] <= m))
                && image[x + dx[i]][y + dy[i]] == curcolor)
            {
                image[x + dx[i]][y + dy[i]] = color;
                que[r][0] = x + dx[i], que[r++][1] = y + dy[i];
            }
        }
    }

    //for (j = 0; j < 3; j++)
    //{
    //    int i = 0;
    //    for (i = 0; i < 3; i++)
    //    {
    //        printf("%d ", image[j][i]);
    //    }
    //    printf("\n");
    //}

    return 0;
}

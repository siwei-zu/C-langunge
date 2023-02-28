#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

const int dx[4] = { 1, 0, 0, -1 };
const int dy[4] = { 0, 1, -1, 0 };
int n;
int m;

void dfs(int image[][3], int x, int y, int currColor, int color)
{
	if (image[x][y] == currColor) {
		image[x][y] = color;
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i], my = y + dy[i];
			if (mx >= 0 && mx < n && my >= 0 && my < m) {
				dfs(image, x + dx[i], y + dy[i], currColor, color);
			}
		}
	}

}

int main()
{
	int image[2][3] = { {0,0,0},{0,0,0} };
	int sr = 0;
	int sc = 0;
	int color = 2;
	m = 3;
	n = 2;
	int currColor = image[sr][sc];
	if (currColor != color) {
		dfs(image, sr, sc, currColor, color);
	}
	return image;
}




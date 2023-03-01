#define _CRT_SECURE_NO_WARNINGS 1
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * (gridSize - 2));
    for (int i = 0; i < gridSize - 2; i++) {
        res[i] = (int*)calloc(gridSize - 2, sizeof(int));
    }
    for (int i = 0; i < gridSize - 2; i++) {
        for (int j = 0; j < gridSize - 2; j++) {
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    res[i][j] = MAX(res[i][j], grid[x][y]);
                }
            }
        }
    }
    *returnSize = gridSize - 2;
    *returnColumnSizes = (int*)calloc(gridSize - 2, sizeof(int));
    for (int i = 0; i < gridSize - 2; i++) {
        (*returnColumnSizes)[i] = gridSize - 2;
    }
    return res;
}
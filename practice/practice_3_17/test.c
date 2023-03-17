#define _CRT_SECURE_NO_WARNINGS 1
#define max(a,b) a > b ? a : b 

int captureForts(int* forts, int fortsSize) {
    int ans = 0;
    for (int j = 0; j < fortsSize; j++) {
        if (forts[j] == -1 || forts[j] == 0) continue;
        //向左扫
        int i = j - 1;//从此时1左边的坐标开始
        while (i >= 0 && forts[i] == 0) i--;//如果它一直到左边边界前会一直缩小
        if (i >= 0 && forts[i] < 0) ans = max(ans, j - i - 1);//如果遇到-1,计算距离

        //向右扫
        i = j + 1;//从此时1右边的坐标开始
        while (i < fortsSize && forts[i] == 0) i++;//如果它一直到右边边界前会一直增大
        if (i < fortsSize && forts[i] < 0) ans = max(ans, i - j - 1);
        //如果遇到-1,计算距离
    }
    return ans;//返回距离
}

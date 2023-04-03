#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define IN_S_LEN 2//蛇的初始长度
#define FACE_SZ 22//界面的大小

typedef struct Snake//蛇的信息
{
	int** body_coor;
	int len;
}Snake;

//初始设置蛇的身体各个点的坐标（二维数组存储）
void snake_init(Snake* ps);
//打印游戏界面
void game_interface(char face [][FACE_SZ - 2], int sz);


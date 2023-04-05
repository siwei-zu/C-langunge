#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

#define IN_S_LEN 2//蛇的初始长度
#define FACE_SZ 30//界面的大小
#define TIME_REFRESH 500

typedef struct Snake//蛇的信息
{
	int** body_coor;
	int len;
}Snake;

//初始设置蛇的身体各个点的坐标（二维数组存储）
void snake_init(Snake* ps);
//打印游戏界面
void game_interface(char face [][FACE_SZ - 2], int sz);
//在游戏界面显示蛇身
void snake_body(Snake* snake, char face[][FACE_SZ - 2]);
//设置蛇要吃的东西在界面上的生成
void set_food(char face[][FACE_SZ - 2]);
//游戏实现
void game_play(Snake* snake, char face[][FACE_SZ - 2]);





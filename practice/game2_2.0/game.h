#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define ROW 9//棋盘的行数
#define COL 9//棋盘的列数
#define BOOM 10//棋盘中雷的个数

void init_board(char board[][COL], int row, int col);//棋盘初始化函数
void display_board(char board[][COL], int row, int col);//棋盘打印函数
void set_boom(char board[][COL], int row, int col);//设置雷的函数
int board_play(char board_display[][9], char board_ground[][9], int row, int col);//游戏的具体内容
int scan_boom(char board_display[][COL], char board_ground[][COL], int row, int col);//对当前位置扫描雷的方法

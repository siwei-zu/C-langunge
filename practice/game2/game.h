#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define COL 9
#define ROW 9
#define BOOM 10

void init_qipan(char qipan[ROW][COL],int row,int col);
void display_qipan(char qipan[ROW][COL],int row,int col);
void qipan_play(char qipan_display[ROW][COL],char qipan_ground[ROW][COL],int row,int col);
void set_boom(char qipan_ground[ROW][COL],int row,int col);
int scan_boom(char qipan_ground[ROW][COL],char qipan_display[ROW][COL],int row,int col,int x,int y);





#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define ROW 9//���̵�����
#define COL 9//���̵�����
#define BOOM 10//�������׵ĸ���

void init_board(char board[][COL], int row, int col);//���̳�ʼ������
void display_board(char board[][COL], int row, int col);//���̴�ӡ����
void set_boom(char board[][COL], int row, int col);//�����׵ĺ���
int board_play(char board_display[][9], char board_ground[][9], int row, int col);//��Ϸ�ľ�������
int scan_boom(char board_display[][COL], char board_ground[][COL], int row, int col);//�Ե�ǰλ��ɨ���׵ķ���

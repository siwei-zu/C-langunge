#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

#define IN_S_LEN 2//�ߵĳ�ʼ����
#define FACE_SZ 30//����Ĵ�С
#define TIME_REFRESH 500

typedef struct Snake//�ߵ���Ϣ
{
	int** body_coor;
	int len;
}Snake;

//��ʼ�����ߵ��������������꣨��ά����洢��
void snake_init(Snake* ps);
//��ӡ��Ϸ����
void game_interface(char face [][FACE_SZ - 2], int sz);
//����Ϸ������ʾ����
void snake_body(Snake* snake, char face[][FACE_SZ - 2]);
//������Ҫ�ԵĶ����ڽ����ϵ�����
void set_food(char face[][FACE_SZ - 2]);
//��Ϸʵ��
void game_play(Snake* snake, char face[][FACE_SZ - 2]);





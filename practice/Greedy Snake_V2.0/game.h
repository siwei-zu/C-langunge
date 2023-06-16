#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

#define NONE         "\033[m"
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"

//typedef struct _COORD {
//	short X; //������
//	short Y;//������
//}COORD;

#define IN_S_LEN 2//�ߵĳ�ʼ����
#define FACE_SZ 30//����Ĵ�С
#define TIME_REFRESH 300

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





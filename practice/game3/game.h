#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define IN_S_LEN 2//�ߵĳ�ʼ����
#define FACE_SZ 22//����Ĵ�С

typedef struct Snake//�ߵ���Ϣ
{
	int** body_coor;
	int len;
}Snake;

//��ʼ�����ߵ��������������꣨��ά����洢��
void snake_init(Snake* ps);
//��ӡ��Ϸ����
void game_interface(char face [][FACE_SZ - 2], int sz);


#pragma once
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#define TIME 200

#define BOARD_SIZE 22

typedef struct Snake {
	int** position;
	int len;
}Sk;

//��ʼ������
void InitSnake(Sk* sk);

//��ӡ����
void InitInterface();

//��ӡ����
void FllushSnakeBody(Sk* sk);

//����̨����ת��ͼ������
int CoToPh(int x);
//ͼ������ת������̨����
int PhToCo(int x);

//����ʳ��
void SetFood();

//�ߵ��ƶ�
void SnakeMove(Sk* sk, char move);

//�ߵ��ƶ��Ƿ�Ϸ�
bool LegalMove(Sk* sk, char move, int decide);

//���ʳ���Ƿ񱻳Ե�
bool ExistFood();

//�Ե�ʳ����ߵ�������������Ϊ
void ExtendSnake(Sk* sk, char trace);

//�ж���Ϸ�Ƿ�ʧ��
bool judge_fail(Sk* sk, char move);

//�˳���Ϸ
void Destroy(Sk* sk);

//��ʼ\�˳���Ϸ��ť
void AgainBotton();

//����/�˳���Ϸ��ť
void ContinueBotton();

//��Ϸ�ο�
void GameGuideline();

//������Ϸ
void StartGame();

//������Ͻ�
void ClearRT();
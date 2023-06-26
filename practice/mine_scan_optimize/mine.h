#pragma once
#include <easyx.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>



//��ӡ��ʼ����
void InitStartInterface();

//��ʼ��Ϸ��ť��ɫ
void StartDiscolour();
//�˳���Ϸ��ť��ɫ
void EndDiscolour();

//��Ϸ�Ѷ�ѡ�����
void InitDifficultyOptFace();

//��ģʽ��ɫ
void SimpleDiscolour();
//����ģʽ��ɫ
void difficultyDiscolour();
//�����Ѷȱ�ɫ
void HellDiscolour();

//������һ��
void GoBack();

//���õ���-��ģʽ
void SetMineSimple(char** simpleboard);
//��ģʽ����
void InitSimpleBoard();

void InitSimpleBoard_();

//��ģʽ�����ɫ
void SimpleBlockDiscolour(int x, int y);

//��Ϸʧ��
void GameFail();

//��Ϸ�ɹ�
void GameWin();

//��ģʽɨ��
void ScanSimple(char** simpleboard, int x, int y);

//���õ���-����ģʽ
void SetMineDifficulty(char** difficultyboard);

//����ģʽ����
void InitDifficultyBoard();

//����ģʽ�����ɫ
void DifficultyBlockDiscolour(int x, int y);

void InitDifficultyBoard_();


//����ģʽɨ��
void ScanDifficulty(char** difficultyboard, int x, int y);




//���õ���-����ģʽ
void SetMineHell(char** hellboard);

//����ģʽ����
void InitHellBoard();

//����ģʽ�����ɫ
void HellBlockDiscolour(int x, int y);

void InitHellBoard_();


//����ģʽɨ��
void ScanHell(char** hellboard, int x, int y);
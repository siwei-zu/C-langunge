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

//初始化蛇身
void InitSnake(Sk* sk);

//打印界面
void InitInterface();

//打印蛇身
void FllushSnakeBody(Sk* sk);

//控制台坐标转换图像坐标
int CoToPh(int x);
//图像坐标转换控制台坐标
int PhToCo(int x);

//设置食物
void SetFood();

//蛇的移动
void SnakeMove(Sk* sk, char move);

//蛇的移动是否合法
bool LegalMove(Sk* sk, char move, int decide);

//检测食物是否被吃掉
bool ExistFood();

//吃掉食物后蛇的身体增长的行为
void ExtendSnake(Sk* sk, char trace);

//判断游戏是否失败
bool judge_fail(Sk* sk, char move);

//退出游戏
void Destroy(Sk* sk);

//开始\退出游戏按钮
void AgainBotton();

//继续/退出游戏按钮
void ContinueBotton();

//游戏参考
void GameGuideline();

//启动游戏
void StartGame();

//清除右上角
void ClearRT();
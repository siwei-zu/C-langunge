#pragma once
#include <easyx.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>



//打印开始界面
void InitStartInterface();

//开始游戏按钮变色
void StartDiscolour();
//退出游戏按钮变色
void EndDiscolour();

//游戏难度选择界面
void InitDifficultyOptFace();

//简单模式变色
void SimpleDiscolour();
//困难模式变色
void difficultyDiscolour();
//地狱难度变色
void HellDiscolour();

//返回上一级
void GoBack();

//设置地雷-简单模式
void SetMineSimple(char** simpleboard);
//简单模式界面
void InitSimpleBoard();

void InitSimpleBoard_();

//简单模式方块变色
void SimpleBlockDiscolour(int x, int y);

//游戏失败
void GameFail();

//游戏成功
void GameWin();

//简单模式扫雷
void ScanSimple(char** simpleboard, int x, int y);

//设置地雷-困难模式
void SetMineDifficulty(char** difficultyboard);

//困难模式界面
void InitDifficultyBoard();

//困难模式方块变色
void DifficultyBlockDiscolour(int x, int y);

void InitDifficultyBoard_();


//困难模式扫雷
void ScanDifficulty(char** difficultyboard, int x, int y);




//设置地雷-地狱模式
void SetMineHell(char** hellboard);

//地狱模式界面
void InitHellBoard();

//地狱模式方块变色
void HellBlockDiscolour(int x, int y);

void InitHellBoard_();


//地狱模式扫雷
void ScanHell(char** hellboard, int x, int y);
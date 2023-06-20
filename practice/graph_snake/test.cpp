#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"

//测试游戏
//void Test()
//{
//	//游戏指导图片
//	GameGuideline();
//
//	////测试食物放置
//	//FllushSnakeBody(&sk);
//	//SetFood();
//
//	////测试开始游戏按钮
//	//AgainBotton();
//	//Sleep(3000);
//
//	////继续按钮测试
//	//ContinueBotton();
//
//	////测试移动
//	//char move = 'w';
//	//SnakeMove(&sk, move);
//	//FllushSnakeBody(&sk);
//	//Sleep(3000);
//	//move = 'a';
//	//SnakeMove(&sk, move);
//	//FllushSnakeBody(&sk);
//
//
//	//////测试合法移动
//	//move = 's';
//	//Sleep(3000);
//	//if (LegalMove(&sk, move))
//	//{
//	//	SnakeMove(&sk, move);
//	//	FllushSnakeBody(&sk);
//	//}
//	//else
//	//{
//	//	printf("1\n");
//	//}
//	//move = 'a';
//	//Sleep(3000);
//	//if (LegalMove(&sk, move))
//	//{
//	//	SnakeMove(&sk, move);
//	//	FllushSnakeBody(&sk);
//	//}
//	//else
//	//{
//	//	printf("1\n");
//	//}
//
//	//测试吃食物后蛇的变化
//
//	//Sleep(3000);
//	//char move = 'd';
//	//char trace = 's';
//	//SnakeMove(&sk, move);
//	//if(ExistFood())
//	//{
//	//	ExtendSnake(&sk, trace);
//	//}
//	//FllushSnakeBody(&sk);
//	//Sleep(3000);
//
//
//	while (1);
//}

void GamePlay(Sk* sk)
{
	char move;
	char trace;

	StartGame();
	while (1)
	{
		move = _getch();
		if (LegalMove(sk, move, 0))
		{
			ClearRT();
			trace = move;
			break;
		}
	}


	while (1)
	{
		int flag = 0;
		if (_kbhit() == 0)
		{
			if (judge_fail(sk, move))
			{
				Destroy(sk);
				exit(0);
			}
			else
			{
				SnakeMove(sk, move);
				if (ExistFood())
				{
					ExtendSnake(sk, trace);
					SetFood();
				}
				FllushSnakeBody(sk);
				Sleep(TIME);
			}
		}
		else
		{
			if (LegalMove(sk, move, 1))
			{
				trace = move;
			}
			move = _getch();

			if (move == ' ' || move == 27)//暂停游戏
			{
				ExMessage msg;
				ContinueBotton();
				while (1)
				{
					getmessage(&msg, EX_MOUSE);
					if (msg.lbutton == 1 && (msg.x >= 505 && msg.x <= 605) && (msg.y >= 45 && msg.y <= 85))
					{
						//继续游戏
						ClearRT();
						StartGame();
						while (1)
						{
							char tmp = _getch();
							if (LegalMove(sk, tmp, 0))
							{
								move = tmp;
								ClearRT();
								flag = 1;
								break;
							}
						}
					}
					else if (msg.lbutton == 1 && (msg.x >= 505 && msg.x <= 605) && (msg.y >= 125 && msg.y <= 165))
					{
						//退出游戏
						Destroy(sk);
						exit(0);
					}
					if (flag == 1)
					{
						break;
					}
				}
			}
			else if (LegalMove(sk, move, 1))
			{
				if (judge_fail(sk, move))
				{
					Destroy(sk);
					exit(0);
				}
				else
				{
					SnakeMove(sk, move);
					if (ExistFood())
					{
						ExtendSnake(sk, trace);
						SetFood();
					}
					FllushSnakeBody(sk);
					Sleep(TIME);
				}
			}
			else
			{
				move = trace;
				if (judge_fail(sk, move))
				{
					Destroy(sk);
					while (1);
					exit(0);
				}
				else
				{
					SnakeMove(sk, move);
					if (ExistFood())
					{
						ExtendSnake(sk, trace);
						SetFood();
					}
					FllushSnakeBody(sk);
					Sleep(TIME);
				}
			}
		}
	}
}


int main()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);
	
	
	//// 隐藏控制台窗口
	//HWND hwnd = GetConsoleWindow();
	//ShowWindow(hwnd, SW_HIDE);
	//// 将图形窗口移动到(-1000, -1000)的位置
	//HWND hwndGraph = GetHWnd();
	//SetWindowPos(hwndGraph, HWND_TOPMOST, -1000, -1000, 0, 0, SWP_NOSIZE | SWP_NOZORDER);


	setbkcolor(WHITE);
	cleardevice();//背景



	Sk sk = { 0 };
	InitSnake(&sk);//蛇初始化

	ExMessage msg;
	InitInterface();//界面初始化
	GameGuideline();
	AgainBotton();
	FllushSnakeBody(&sk);

	while(1)
	{
		getmessage(&msg, EX_MOUSE);
		if (msg.lbutton == 1 && (msg.x >= 505 && msg.x <= 605) && (msg.y >= 45 && msg.y <= 85))
		{
			//开始游戏
			ClearRT();
			SetFood();
			GamePlay(&sk);
		}
		else if (msg.lbutton == 1 && (msg.x >= 505 && msg.x <= 605) && (msg.y >= 125 && msg.y <= 165))
		{
			//退出游戏
			Destroy(&sk);
			break;
		}
	}
	
	
	closegraph();
	return 0;
}
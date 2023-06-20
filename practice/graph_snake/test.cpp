#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"

//������Ϸ
//void Test()
//{
//	//��Ϸָ��ͼƬ
//	GameGuideline();
//
//	////����ʳ�����
//	//FllushSnakeBody(&sk);
//	//SetFood();
//
//	////���Կ�ʼ��Ϸ��ť
//	//AgainBotton();
//	//Sleep(3000);
//
//	////������ť����
//	//ContinueBotton();
//
//	////�����ƶ�
//	//char move = 'w';
//	//SnakeMove(&sk, move);
//	//FllushSnakeBody(&sk);
//	//Sleep(3000);
//	//move = 'a';
//	//SnakeMove(&sk, move);
//	//FllushSnakeBody(&sk);
//
//
//	//////���ԺϷ��ƶ�
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
//	//���Գ�ʳ����ߵı仯
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

			if (move == ' ' || move == 27)//��ͣ��Ϸ
			{
				ExMessage msg;
				ContinueBotton();
				while (1)
				{
					getmessage(&msg, EX_MOUSE);
					if (msg.lbutton == 1 && (msg.x >= 505 && msg.x <= 605) && (msg.y >= 45 && msg.y <= 85))
					{
						//������Ϸ
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
						//�˳���Ϸ
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
	
	
	//// ���ؿ���̨����
	//HWND hwnd = GetConsoleWindow();
	//ShowWindow(hwnd, SW_HIDE);
	//// ��ͼ�δ����ƶ���(-1000, -1000)��λ��
	//HWND hwndGraph = GetHWnd();
	//SetWindowPos(hwndGraph, HWND_TOPMOST, -1000, -1000, 0, 0, SWP_NOSIZE | SWP_NOZORDER);


	setbkcolor(WHITE);
	cleardevice();//����



	Sk sk = { 0 };
	InitSnake(&sk);//�߳�ʼ��

	ExMessage msg;
	InitInterface();//�����ʼ��
	GameGuideline();
	AgainBotton();
	FllushSnakeBody(&sk);

	while(1)
	{
		getmessage(&msg, EX_MOUSE);
		if (msg.lbutton == 1 && (msg.x >= 505 && msg.x <= 605) && (msg.y >= 45 && msg.y <= 85))
		{
			//��ʼ��Ϸ
			ClearRT();
			SetFood();
			GamePlay(&sk);
		}
		else if (msg.lbutton == 1 && (msg.x >= 505 && msg.x <= 605) && (msg.y >= 125 && msg.y <= 165))
		{
			//�˳���Ϸ
			Destroy(&sk);
			break;
		}
	}
	
	
	closegraph();
	return 0;
}
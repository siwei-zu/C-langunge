#define _CRT_SECURE_NO_WARNINGS 1
#include "mine.h"


int main()
{
	initgraph(900, 480);
	srand((unsigned)time(NULL));
	HWND hwnd = GetHWnd();  // 获取绘图窗口句柄
	POINT point;
	TCHAR s[10];
start:
	setbkcolor(WHITE);
	cleardevice();

	ExMessage msg;

	InitStartInterface();
	while (1)//游戏开始逻辑
	{
		GetCursorPos(&point);   // 获取鼠标指针位置（屏幕坐标）
		ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
		if ((point.x >= 250 && point.x <= 650) && (point.y >= 20 && point.y <= 220))//开始游戏按钮
		{
			if (getpixel(270, 40) != RGB(215, 222, 10))
			{
				StartDiscolour();
			}
			if (peekmessage(&msg, EX_MOUSE))
			{
				if (msg.lbutton)
				{
				opt:
					//开始游戏
					setbkcolor(WHITE);
					cleardevice();//清屏
					//选择游戏难度
					InitDifficultyOptFace();
					GoBack();
					while (1)
					{
						GetCursorPos(&point);   // 获取鼠标指针位置（屏幕坐标）
						ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
						if (_kbhit())
						{
							char esc = _getch();
							if (esc == 27)
							{
								goto start;
							}
						}
						if ((point.x >= 100 && point.x <= 300) && (point.y >= 190 && point.y <= 290))
						{
							if (getpixel(120, 210) != RGB(6, 179, 9))
							{
								SimpleDiscolour();
								GoBack();
							}
							if (peekmessage(&msg, EX_MOUSE))
							{
								if (msg.lbutton)
								{
									setbkcolor(WHITE);
									cleardevice();//清屏
									//简单模式游戏开始
									if (_kbhit())
									{
										char esc = _getch();
										if (esc == 27)
										{
											goto opt;
										}
									}
									char** simpleboard = (char**)malloc(sizeof(char*) * 9);
									if (simpleboard == NULL)
									{
										perror("simpleboard malloc fail");
										return 0;
									}
									for (int i = 0; i < 9; i++)
									{
										simpleboard[i] = (char*)malloc(sizeof(char) * 9);
										if (simpleboard[i] == NULL)
										{
											perror("simpleboard_ malloc fail");
											return 0;
										}
										memset(simpleboard[i], '0', 9);
									}
									SetMineSimple(simpleboard);
									InitSimpleBoard();
									while (1)
									{
										GetCursorPos(&point);   // 获取鼠标指针位置（屏幕坐标）
										ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
										if (_kbhit())
										{
											char esc = _getch();
											if (esc == 27)
											{
												goto opt;
											}
										}
										int x = ((point.x - 225) / 50) * 50 + 225;
										int y = ((point.y) / 50) * 50;
										if ((x >= 225 && x <= 625) && (y >= 0 && y <= 400))
										{

											if (getpixel(x + 5, y + 5) == RGB(93, 78, 255))
											{
												SimpleBlockDiscolour(x, y);
											}
											if (peekmessage(&msg, EX_MOUSE))
											{
												if (msg.lbutton)//简单模式点击
												{
													if (getpixel(x + 5, y + 5) == RGB(69, 58, 191))
													{
														if (simpleboard[y / 50][(x - 225) / 50] == '*')
														{
															GameFail();
															Sleep(1000);
															for (int i = 0; i < 9; i++)
															{
																free(simpleboard[i]);
															}
															free(simpleboard);
															return 0;
														}
														else
														{
															ScanSimple(simpleboard, (x - 225) / 50, y / 50);
														}
													}
												}
											}
										}
										else
										{
											InitSimpleBoard_();
										}
									}

								}
							}
						}
						else if ((point.x >= 350 && point.x <= 550) && (point.y >= 190 && point.y <= 290))
						{
							if (getpixel(370, 210) != RGB(194, 137, 47))
							{
								difficultyDiscolour();
								GoBack();
							}
							if (peekmessage(&msg, EX_MOUSE))
							{
								if (msg.lbutton)
								{
									setbkcolor(WHITE);
									cleardevice();//清屏
									//困难模式游戏开始
									if (_kbhit())
									{
										char esc = _getch();
										if (esc == 27)
										{
											goto opt;
										}
									}
									char** difficultyboard = (char**)malloc(sizeof(char*) * 16);
									if (difficultyboard == NULL)
									{
										perror("difficultyboard malloc fail");
										return 0;
									}
									for (int i = 0; i < 16; i++)
									{
										difficultyboard[i] = (char*)malloc(sizeof(char) * 16);
										if (difficultyboard[i] == NULL)
										{
											perror("difficultyboard_ malloc fail");
											return 0;
										}
										memset(difficultyboard[i], '0', 16);
									}
									SetMineDifficulty(difficultyboard);
									InitDifficultyBoard();
									while (1)
									{
										GetCursorPos(&point);   // 获取鼠标指针位置（屏幕坐标）
										ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
										if (_kbhit())
										{
											char esc = _getch();
											if (esc == 27)
											{
												goto opt;
											}
										}
										int x = ((point.x - 210) / 40) * 40 + 210;
										int y = ((point.y) / 40) * 40;
										if ((x >= 210 && x <= 650) && (y >= 0 && y <= 440))
										{

											if (getpixel(x + 5, y + 5) == RGB(93, 78, 255))
											{
												DifficultyBlockDiscolour(x, y);
											}
											if (peekmessage(&msg, EX_MOUSE))
											{
												if (msg.lbutton)//简单模式点击
												{
													if (getpixel(x + 5, y + 5) == RGB(69, 58, 191))
													{
														if (difficultyboard[y / 40][(x - 210) / 40] == '*')
														{
															GameFail();
															Sleep(1000);
															for (int i = 0; i < 16; i++)
															{
																free(difficultyboard[i]);
															}
															free(difficultyboard);
															return 0;
														}
														else
														{
															ScanDifficulty(difficultyboard, (x - 210) / 40, y / 40);
														}
													}
												}
											}
										}
										else
										{
											InitDifficultyBoard_();
										}
									}

								}
							}
						}
						else if ((point.x >= 600 && point.x <= 800) && (point.y >= 190 && point.y <= 290))
						{
							if (getpixel(620, 210) != RGB(168, 48, 11))
							{
								HellDiscolour();
								GoBack();
							}
							if (peekmessage(&msg, EX_MOUSE))
							{
								if (msg.lbutton)
								{
									setbkcolor(WHITE);
									cleardevice();//清屏
									//地狱模式游戏开始
									if (_kbhit())
									{
										char esc = _getch();
										if (esc == 27)
										{
											goto opt;
										}
									}
									char** hellboard = (char**)malloc(sizeof(char*) * 16);
									if (hellboard == NULL)
									{
										perror("hellboard malloc fail");
										return 0;
									}
									for (int i = 0; i < 16; i++)
									{
										hellboard[i] = (char*)malloc(sizeof(char) * 30);
										if (hellboard[i] == NULL)
										{
											perror("hellboard_ malloc fail");
											return 0;
										}
										memset(hellboard[i], '0', 30);
									}
									SetMineHell(hellboard);
									InitHellBoard();
									while (1)
									{
										GetCursorPos(&point);   // 获取鼠标指针位置（屏幕坐标）
										ScreenToClient(hwnd, &point); // 将鼠标指针位置转换为窗口坐标
										if (_kbhit())
										{
											char esc = _getch();
											if (esc == 27)
											{
												goto opt;
											}
										}
										int x = ((point.x) / 30) * 30;
										int y = ((point.y) / 30) * 30;
										if ((x >= 0 && x <= 870) && (y >= 0 && y <= 450))
										{

											if (getpixel(x + 5, y + 5) == RGB(93, 78, 255))
											{
												HellBlockDiscolour(x, y);
											}
											if (peekmessage(&msg, EX_MOUSE))
											{
												if (msg.lbutton)//简单模式点击
												{
													if (getpixel(x + 5, y + 5) == RGB(69, 58, 191))
													{
														if (hellboard[y / 30][x / 30] == '*')
														{
															GameFail();
															Sleep(1000);
															for (int i = 0; i < 16; i++)
															{
																free(hellboard[i]);
															}
															free(hellboard);
															return 0;
														}
														else
														{
															ScanHell(hellboard, x / 30, y / 30);
														}
													}
												}
											}
										}
										else
										{
											InitHellBoard_();
										}
									}
								}
							}
						}
						else
						{
							if (getpixel(120, 210) == RGB(6, 179, 9)
								|| getpixel(620, 210) == RGB(168, 48, 11)
								|| getpixel(370, 210) == RGB(194, 137, 47))
							{
								InitDifficultyOptFace();
								GoBack();
							}
						}
					}
				}
			}
		}
		else if ((point.x >= 250 && point.x <= 650) && (point.y >= 260 && point.y <= 460))
		{
			if (getpixel(270, 280) != RGB(215, 222, 10))
			{
				EndDiscolour();
			}
			if (peekmessage(&msg, EX_MOUSE))
			{
				if (msg.lbutton)
				{
					//退出游戏
					return 0;
				}
			}
		}
		else/* if((point.x >= 250 && point.x <= 650) && (point.y >= 20 && point.y <= 220) == 0
			&& (point.x >= 250 && point.x <= 650) && (point.y >= 260 && point.y <= 460) == 0)*/
		{
			if (getpixel(270, 40) != RGB(247, 255, 10) || getpixel(270, 280) != RGB(247, 255, 10))
			{
				InitStartInterface();
			}
		}
	}


	closegraph();
	return 0;
}
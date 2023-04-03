#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void snake_init(Snake* ps)
{
	int** tmp = (int**)malloc(sizeof(int*) * IN_S_LEN);
	if (tmp == NULL)
	{
		perror("tmp_malloc");
		return NULL;
	}
	int i = 0;
	for (i = 0; i < IN_S_LEN; i++)
	{
		tmp[i] = (int*)malloc(sizeof(int) * 2);
		if (tmp[i] == NULL)
		{
			perror("tmp[i]_malloc");
			return NULL;
		}
	}
	ps->body_coor = tmp;
	ps->len = IN_S_LEN;
}

void game_interface(char face [][FACE_SZ - 2], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (i == 0 || i == sz - 1)
		{
			printf(" ");
			int j = 0;
			for (j = 0; j < sz - 2; j++)
			{
				printf("---");
			}
			printf(" ");
		}
		else
		{
			printf("|");
			int j = 0;
			for (j = 0; j < sz - 2; j++)
			{
				printf(" %c ", face[i - 1][j]);
			}
			printf("|");
		}
		printf("\n");
	}
}


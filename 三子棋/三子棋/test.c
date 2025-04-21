#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"

void menu()
{
	printf("							\n");
	printf("		1.play 0.exit		\n");
	printf("							\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);
	Displayboard(board,ROW,COL);
	if (whofirst() == 0)
	{
		while (1)
		{
			Displayboard(board, ROW, COL);
			Playermove(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'c')
			{
				break;
			}
			Displayboard(board, ROW, COL);
			Computermove(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'c')
			{
				break;
			}
			Displayboard(board, ROW, COL);
		}
	}
	else
	{
		while (1)
		{
			Computermove(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'c')
			{
				break;
			}
			Displayboard(board, ROW, COL);
			Playermove(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'c')
			{
				break;
			}
			Displayboard(board, ROW, COL);
		}
	}

	if (ret == '#')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '*')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
	}
	Displayboard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择：\n");
			break;
		}
	} while (input);

	return 0;
}
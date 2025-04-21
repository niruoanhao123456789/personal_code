#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"

void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//printf("———三子棋———\n\n");
	for (i = 0; i < COL; i++)
	{
		printf("—");
	}
	printf("—三子棋—");
	for (i = 0; i < COL; i++)
	{
		printf("—");
	}
	printf("\n\n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("___");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	//printf("\n————————————\n");
	printf("\n");
	for (i = 0; i < (COL) * 4; i++)
	{
		printf("—");
	}
	printf("\n");
}

int whofirst()
{
	int i = 0;
	int j = 0;
	printf("先与电脑玩石头剪刀布，谁赢谁就先手\n");
	there:
	again:
	printf("输入1表示石头，2表示剪刀，3表示布\n");
	printf("请输入数字:");
	scanf_s("%d", &i);

	switch (i)
	{
	case 1:
		printf("玩家出石头\n");
		break;
	case 2:
		printf("玩家出剪刀\n");
		break;
	case 3:
		printf("玩家出布\n");
		break;
	default:
		printf("输入错误，请重新输入\n");
		goto again;
		break;
	}

	j = rand() % 9 + 1;

	if (j <= 3)
	{
		printf("电脑出石头\n");
		j = 1;
	}
	else if (j > 3 && j <= 6)
	{
		printf("电脑出剪刀\n");
		j = 2;
	}
	else
	{
		printf("电脑出布\n");
		j = 3;
	}

	if (i == 1 && j == 2)
	{
		printf("玩家先手\n");
		return 0;
	}
	else if (i == 2 && j == 1)
	{
		printf("电脑先手\n");
		return 1;
	}
	else if (i == 2 && j == 3)
	{
		printf("玩家先手\n");
		return 0;
	}
	else if (i == 3 && j == 2)
	{
		printf("电脑先手\n");
		return 1;
	}
	else if (i == 3 && j == 1)
	{
		printf("玩家先手\n");
		return 0;
	}
	else if (i == 1 && j == 3)
	{
		printf("电脑先手\n");
		return 1;
	}
	else
	{
		printf("平局，再来一次\n");
		goto there;
	}
}

void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	while (1)
	{
		printf("请输入棋子的坐标:");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[col - y][x - 1] == ' ')
			{
				board[col - y][x - 1] = '#';
				break;
			}
			else
			{
				printf("位置被占用，请选择其他位置输入:\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
}

void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋：\n");
	while (1)//简单版本的人机
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
}

int Isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Iswin(char board[ROW][COL],int row,int col) //这存在bug
{
	int i = 0;
	int j = 0;
	int num = 1;
	//判断行
	for (i = 0; i < row; i++)
	{
		num = 1;
		for (j = 0; j < col; j++)
		{
			//if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+1] != ' ')
			//{
			//	return board[i][j+1];
			//}

			if ((board[i][j] == board[i][j + 1]) && board[i][j]!=' ')
			{
				num++;
			}
			else
			{
				num = 1;
			}
			if (num == NUM)
			{
				return board[i][j];
			}
		}

	}
	//判断列
	for (j = 0; j < col; j++)
	{
		num = 1;
		for (i = 0; i < row; i++)
		{
			//if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i+1][j] != ' ')
			//{
			//	return board[i+1][j];
			//}

			if ((board[i][j] == board[i + 1][j]) && board[i][j] != ' ')
			{
				num++;
			}
			else
			{
				num = 1;
			}
			if (num == NUM)
			{
				return board[i][j];
			}
		}
	}
	//判断对角线
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	//{
	//	return board[1][1];
	//}
	//if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	//{
	//	return board[1][1];
	//}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((board[i][j] == board[i + 1][j + 1]) && board[i][j] != ' ')
			{
				num++;
			}
			else
			{
				num = 1;
			}
			if (num == NUM)
			{
				return board[i][j];
			}
		}
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((board[i][col-1-j] == board[i + 1][col - j]) && board[i][col - 1 - j] != ' ')
			{
				num++;
			}
			else
			{
				num = 1;
			}
			if (num == NUM)
			{
				return board[i][col - 1 - j];
			}
		}
	}

	//平局
	if (Isfull(board, row, col) )
	{
		return 'q';
	}
	//继续
	return 'c';
}
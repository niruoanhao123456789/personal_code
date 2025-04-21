#include"game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int j = 0;
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int n = row;
	printf("——————-扫雷游戏-——————\n");
	printf("\n  ");
	for (j = 1; j <= col; j++)
	{
		printf("--");
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d|", n);
		n-- ;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("|\n");

	}
	printf("  ");
	for (j = 1; j <= col; j++)
	{
		printf("--");
	}
	printf("\n  ");
	for (j = 1; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n——————————————————————\n");
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//1、该位置是否有雷
//2、附近没有雷
//3、该位置是否被排查过
void Get_mine_count(char mine[ROWS][COLS],char show[ROWS][COLS], int y,int a)
{
	// '1' - '0' = 1
	// '0' - '0' = 0
	int i = 0;
	i = ( (mine[a - 1][y] + 
		mine[a - 1][y + 1] + 
		mine[a][y + 1] + 
		mine[a + 1][y + 1] + 
		mine[a + 1][y] + 
		mine[a + 1][y - 1] + 
		mine[a][y - 1] + 
		mine[a - 1][y - 1]) - 8 * '0' );
	if (i == 0)
	{
		show[a][y] = ' ';
	}
	else
	{
		show[a][y] = i + '0';//转化为数字字符
	}
}

int Is_right(char mine[ROWS][COLS],char show[ROWS][COLS], int a, int y)
{
	int i = 1;
	if (mine[a][y] == '1' && show[a][y] == '#')
		return i;
	else
		return 0;
}

void Searchmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int a = 0;
	int i = 0;
	int is = 0;
	int num = 0;
	int win = 0;
	int count = 0;
	while (1)
	{
	victory:
		if (i)
		{
			break;
		}
	there:
		printf("请输入要操作的位置坐标：");
		scanf_s("%d %d", &y, &x);
		a = row - x + 1;
		printf("操作: 1、标记为雷(#) 2、取消现有标记 3、进行排查\n");
	again:
		printf("请输入：");
		scanf_s("%d", &is);
		switch (is)
		{
			case 1:
				if (show[a][y] != '#')
				{
					show[a][y] = '#';
					count++;
					win += Is_right(mine, show,a, y);
					Displayboard(show, ROW, COL);
					if (win == Easy_count && count == Easy_count)
					{
						printf("恭喜你！你成功排查出全部的雷\n");
						Displayboard(mine, ROW, COL);
						i = 1;
						goto victory;
					}
					goto there;
				}
				else
				{
					printf("该坐标已被标记，请重新输入\n");
					goto again;
				}
				break;
			case 2:
				if (show[a][y] == '#')
				{
					show[a][y] = '*';
					count--;
					win += Is_right(mine, show,a, y);
					Displayboard(show, ROW, COL);
					goto there;
				}
				else
				{
					printf("该坐标未被标记，请重新输入\n");
					goto again;
				}
				break;
			case 3:
				break;
			default:
				printf("输入错误，请重新输入\n");
				goto again;
				break;
		}

		if (show[a][y] != '*')
		{
			printf("该位置已被排查或被标记，请重新排查\n");
		}
		else
		{
			if (a <= row && y <= col && a >= 1 && y >= 1)
			{
				if (mine[a][y] == '1')
				{
					printf("很遗憾，您踩雷了\n");
					Displayboard(mine, ROW, COL);
					break;
				}
				else
				{
					Get_mine_count(mine,show, y, a);
					Displayboard(show, ROW, COL);
					num++;
				}
			}
			else
			{
				printf("输入错误，请重新输入:");
			}
		}
	}
	if (num >= row * col - Easy_count)
	{
		printf("恭喜你！你成功排查出全部的雷\n");
		Displayboard(mine, ROW, COL);
	}
}
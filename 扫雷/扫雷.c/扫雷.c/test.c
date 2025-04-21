#include"game.h"

void menu()
{
	printf("							 \n");
	printf("		1、play 0、exit		 \n");
	printf("							 \n");
}

void game()
{
	//存放雷,有雷记1，无雷记0
	char mine[ROWS][COLS] = { 0 };
	//存探测，未探测的记*
	char show[ROWS][COLS] = { 0 };
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	//雷记#
	Setmine(mine, ROW, COL);
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	//排雷
	Searchmine(mine,show,ROW,COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏:扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请重新选\n");
			break;
		}
	} while (input);

	return 0;
}
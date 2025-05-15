#include"function.h"

void meun()
{
	printf("——————————————————————————————-——————————\n");
	printf("**************1.注册 0.退出**************\n");
	printf("——————————————————————————-——————————————\n");
}

void test()
{
	int input = 1;
	while (input)
	{
		if (logn_in())
		{
			operation();
		}
		printf("是否退出系统？ 1.是 2.否\n");
		again:
		printf("请输入：");
		scanf_s("%d", &input);
		input -= 1;
		if ((input != 1) && (input != 0))
		{
			printf("输入错误，请重新输入\n");
			goto again;
		}
	}
}

int main()
{
	int input = 0;
	do
	{
	again:
		meun();
		printf("请输入：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			//注册
			sign_up();
			test();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			goto again;
			break;
		}

	} while (input);

	return 0;
}
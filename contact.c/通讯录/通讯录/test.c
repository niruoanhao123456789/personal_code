#include"contact.h"

void meau()
{
	printf("————————————————— Meau —————————————————\n\n");
	printf("	1、添加		2、删除		\n");
	printf("	3、查找 	4、修改		\n");
	printf("	5、显示		6、排序		\n");
	printf("	0、退出					\n\n");
	printf("———————————————————————-————————————————\n");
}

int main()
{
	int input = 0;
	Contact con;//通讯录
	Initcontact(&con);//初始化线性表(通讯录)
	do
	{
		meau();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SearchContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 0:
			SaveContact(&con);
			//DestoryContact(&con);
			printf("程序退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}
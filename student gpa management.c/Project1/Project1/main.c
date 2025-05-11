#include "functions.h"

void test1(Users* plist)
{
	printf("学生用户添加\n");
	SeqListPushBack(plist, "students.txt");
	SeqListPushBack(plist, "students.txt");
	SeqListPushBack(plist, "students.txt");
	SeqListPrint(plist);
}

void test2(Users* plist)
{
	printf("教师用户添加\n");
	SeqListPushBack(plist, "teachers.txt");
	SeqListPushBack(plist, "teachers.txt");
	SeqListPushBack(plist, "teachers.txt");
	SeqListPrint(plist);
}

void UsersManage(Users* stu, Users* tea)
{
	int input = 0;
	int user = 0;
	do
	{
		printf("是否添加新用户：1、是 0、否\n");
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入新用户身份：1、教师	2、学生\n请输入：");
			scanf("%d", &user);
			if (user == 1)
				test2(tea);
			else if (user == 2)
				test1(stu);
			else
				printf("输入错误\n");
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			continue;
		}
	} while (input);
}

void menu() {
	printf("————————————————— Log in —————————————————\n\n");
	printf("	1、教师	2、学生	0、退出				\n\n");
	printf("——————————————————-———————————————————————\n\n");
}

int main() {
	int input = 0;
	Users tea, stu;
	SeqlistInit(&tea, "teachers.txt");
	SeqlistInit(&stu, "students.txt");
	load_course_list("courselist.txt");
	load_score_list("scorelist.txt");

	//UsersManage(&stu, &tea);//用来进行用户数据操作的临时函数，添加用户用这个

	do
	{
		menu();
		printf("请选择你的登录身份：\n请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("程序结束\n");
			break;
		case 1:
			user_interface(&tea, 1);
			break;
		case 2:
			user_interface(&stu, 2);
			break;
		default:
			printf("输入错误，请重新输入\n");
		}

	} while (input);

	save_user_data(&tea, "teachers.txt");
	save_user_data(&stu, "students.txt");
	save_score_list("scorelist.txt");
	save_course_list("courselist.txt");
	SeqListDestory(&tea);
	SeqListDestory(&stu);
	CourseListDestory(&course_head);
	return 0;
}
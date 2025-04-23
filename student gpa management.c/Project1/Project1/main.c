#include "functions.h"

void test(Users* plist)
{
	SeqListPushBack(plist, "teachers.txt");

	save_user_data(plist, "teachers.txt");
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

	//test(&tea);//用来进行用户数据操作的临时函数，添加用户用这个

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
	SeqListDestory(&tea);
	SeqListDestory(&stu);
	CourseListDestory(&course_head);
	return 0;
}
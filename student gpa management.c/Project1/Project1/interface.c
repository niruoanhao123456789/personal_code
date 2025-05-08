#include"interface.h"
#include "chain.h"

static void change_password(char* userpassword)
{
	assert(userpassword);
	char password[STR_BUFFER_SIZE] = { 0 };
	char password1[STR_BUFFER_SIZE] = { 0 };
	int flag = 1;
	printf("\n———————————————————————修改密码——————————————————————-\n");
	while (flag)
	{
		printf("请输入新密码：");
		scanf("%s", password);
		printf("请再输入一遍密码：");
		scanf("%s", password1);
		if (strcmp(password, password1) == 0)
		{
			strcpy(userpassword, password);
			printf("密码修改成功，请重新登录\n");
			flag = 0;
		}
		else
		{
			printf("两次密码不一致，请重新输入\n");
		}
	}
}

static void forget(Users* user,int identity)
{
	assert(user);
	assert(identity == 1 || identity == 2);
	int flag = 0;
	char id[5] = { 0 };
	char phone[20] = { 0 };
	char name[STR_BUFFER_SIZE] = { 0 };
	printf("\n———————————————————————忘记密码——————————————————————-\n\n");
	do
	{
		printf("请输入你的真实姓名：");
		scanf("%s", name);
		printf("请输入工号或学号：");
		scanf("%s", id);
		printf("请输入手机号：");
		scanf("%s", phone);
		int i = 0;
		int len1 = strlen(id);
		int len2 = strlen(phone);
		long long sum1 = 0;
		long long sum2 = 0;
		for (i = 0; i < len1; i++)
		{
			sum1 += (long long)((*(id + i) - '0') * pow(10, len1 - i - 1));
		}
		for (i = 0; i < len2; i++)
		{
			sum2 += (long long)((*(phone + i) - '0') * pow(10, len2 - i - 1));
		}
		int flag1 = 1;
		for (i = 0; i < user->count; i++)
		{
			if ((strcmp(user->data[i].name, name) == 0) 
				&& user->data[i].user_id == sum1
				&& user->data[i].phone_num == sum2)
			{
				flag1 = 0;
				change_password(user->data[i].password);
				save_user_data(user, identity == 1 ? "teachers.txt" : "students.txt");
				break;
			}
		}
		if(flag1)
		{
			printf("输入信息错误，请重新输入\n");
			flag = 1;
		}
	} while (flag);
}

bool login(Users* user, long long*user_id, int identity)
{
	assert(user);
	assert(identity == 1 || identity == 2);
	int input = 0;
	long long now_user_id;
	char password[STR_BUFFER_SIZE] = { 0 };
	printf("\n————————————————————————登录———————————————————————-\n");
	if (identity == 1)
	{
		printf("当前身份为教师\n");
	}
	else if (identity == 2)
	{
		printf("当前身份为学生\n");
	}
	do
	{
		
		printf("\n******* 1.登录 2.忘记密码 0.退出 *******\n\n");
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入工号或学号：");
			scanf("%lld", &now_user_id);
			printf("请输入密码：");
			scanf("%s", password);
			int i = 0;
			int flag = 1;
			for (i = 0; i < user->count; i++)
			{
				if (user->data[i].user_id == now_user_id && (strcmp(user->data[i].password, password) == 0))
				{
					*user_id = user->data[i].user_id;
					printf("登陆成功！\n欢迎用户：%s\n", user->data[i].name);
					input = 0;
					flag = 0;
					return true;
				}
			}
			if(flag)
			{
				printf("工号/学号或密码错误\n");
			}
			break;
		case 2:
			forget(user, identity);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return false;
}

void tea_interface(long long user_id)
{
	int input = 0;
    int course_id = 0;
	long long student_id = 0;
    struct score_node *now_score = NULL;
	char course_name[STR_BUFFER_SIZE] = { 0 };
	struct course_node* course = course_head;
	printf("\n———————————————————————教师端———————————————————————-\n");
	do
	{
		printf("\n******* 1.成绩录入 2.删除错误数据  3.查找学生成绩 *******\n");
		printf("******* 4.修改成绩 5.显示课程学生成绩 6.添加课程  *******\n");
        printf("******* 7.删除课程 8.列出全部课程     0.退出      *******\n\n");
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
            course_id = input_course_id(user_id);
            if (course_id == -1) 
			{
				printf("该课程不存在\n");
                break;
            }
            teacher_input_score(course_id);
			break;
		case 2:
            course_id = input_course_id(user_id);
            if (course_id == -1) 
			{
				printf("该课程不存在\n");
                break;
            }
            printf("请输入要删除成绩的学生id：");
            scanf("%lld", &student_id);
            delete_score(course_id, student_id);
			save_score_list("scorelist.txt");
            printf("删除成功\n");
			break;
		case 3:
            course_id = input_course_id(user_id);
            if (course_id == -1) 
			{
				printf("该课程不存在\n");
                break;
            }
            printf("请输入学生id：");
            scanf("%lld", &student_id);
            now_score = get_score_by_id(course_id, student_id);
            if (now_score == NULL)
			{
                printf("未查询到成绩\n");
                break;
            }
			printf("学生姓名为：%s\n", now_score->student_name);
            printf("成绩为：%.1f分\n", ((float)now_score->score)/10);
			break;
		case 4:
            course_id = input_course_id(user_id);
            if (course_id == -1) 
			{
				printf("该课程不存在\n");
                break;
            }
            printf("请输入要修改成绩的学生id：");
            scanf("%lld", &student_id);
            printf("请输入新成绩：");
            float score = 0;
            scanf("%f", &score);
            int status = update_score(course_id, student_id, (int)floor(score*10));
            if (status == -1) 
			{
                printf("不存在该学生的成绩\n");
                break;
            }
			save_score_list("scorelist.txt");
            printf("更新成功\n");
			break;
		case 5:
            course_id = input_course_id(user_id);
			if (course_id == -1)
			{
				printf("该课程不存在\n");
				break;
			}
            struct course_node *now_course = get_course_by_id(course_id);
            now_score = now_course->score_head;
            if (now_score == NULL) 
			{
                printf("暂无成绩\n");
            }
			printf("课程%s：\n", now_course->course_name);
			printf("学生姓名     学生ID     分数\n");
            while (now_score != NULL) 
			{
				printf("%-8s     %-6d     %-1f分\n", 
				now_score->student_name, now_score->student_id, ((float)now_score->score) / 10);
                now_score = now_score->next;
            }
			break;
        case 6:
            printf("请输入课程名称：");
            scanf("%s", course_name);
            printf("请输入课程id：");
            scanf("%d", &course_id);
            new_course(course_name, course_id, user_id);
			save_course_list("courselist.txt");
            printf("课程添加成功\n");
            break;
		case 7:
			course_id = input_course_id(user_id);
			if (course_id == -1) {
				break;
			}
			delete_course(course_id);
			save_course_list("courselist.txt");
			printf("课程删除成功\n");
			break;
		case 8:
			printf("\n课程列表：\n");
			while (course != NULL) 
			{
				printf("课程ID   课程名称\n");
				if (course->teacher_id == user_id) 
				{
					printf("%-10d%s\n", course->course_id, course->course_name);
				}
				course = course->next;
			}
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}

void stu_interface(long long user_id)
{
	int input = 0;
	printf("\n———————————————————————学生端———————————————————————-\n");
	do
	{
		printf("\n******* 1.单科成绩查询 2.全科成绩查询 0.退出 *******\n\n");
		printf("请输入：");
		scanf("%d", &input);
		int course_id = 0;
		struct score_node *now_score = NULL;
		struct course_node *now_course = NULL;
		switch (input)
		{
		case 1:
			course_id = input_course_id_student(user_id);
			if (course_id == -1) 
			{
				printf("该课程不存在\n");
				break;
			}
			now_course = get_course_by_id(course_id);
			now_score = get_score_by_id(course_id, user_id);
			if (now_score == NULL) 
			{
				printf("未查询到成绩\n");
				break;
			}
			printf("课程%s 成绩为%.1f分\n", now_course->course_name,((float)now_score->score)/10);
			break;
		case 2:
			now_course = course_head;
			printf("全科成绩列表：\n课程	成绩\n");
			while (now_course != NULL) 
			{
				now_score = get_score_by_course(now_course, user_id);
				if (now_score == NULL) 
				{
					now_course = now_course->next;
					continue;
				}
				printf("%s	%.1f分\n", now_course->course_name, ((float)now_score->score)/10);
				now_course = now_course->next;
			}
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}

void user_interface(Users* user,int identity)
{
	assert(user);
	assert(identity == 1 || identity == 2);
	long long user_id = 0;
	int input = 1;
	while (input)
	{
		if (login(user, &user_id, identity))
		{
			if (identity == 1)
				tea_interface(user_id);
			else if (identity == 2)
				stu_interface(user_id);
		}
		int flag = 0;
		do
		{
			printf("是否真退出登录？ 1.是 2.否\n");
			printf("请输入：");
			scanf("%d", &input);
			input -= 1;
			if (input == 0)
			{
				flag = 0;
				printf("退出\n");
			}
			if ((input != 1) && (input != 0))
			{
				printf("输入错误，请重新输入\n");
				flag = 1;
			}
		} while (flag);
        
	}
}
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//选择语句/分支语句  if else    switch
//int main()
//{
//	int a = 0;
//	printf("你有好好学习吗？\n是请call 1 ,否请call 0\n");
//	scanf_s ("%d", &a);
//	if (a == 1) //C语言中0为假，非0为真，()内为真if执行，否则执行else
//	{
//		printf("请继续努力，你会成功的");
//		printf("加油");//有{}的if语句才能执行多条语句
//		
//	}
//	else
//	{
//		printf("如果放弃则你会失败");
//	}
//	return 0;
//}

//多分支if语句
//int main()
//{
//	int age = 0;
//	printf("请输入年龄：");
//	scanf_s("%d", &age);
//	if (age < 18)
//	{
//		printf("未成年\n");
//	}
//	else if (age >= 18 && age < 28)//不能写成18<=age<28 的形式
//	{
//		printf("青年\n");
//	}
//	else if (age >= 28 && age < 40)
//	{
//		printf("中年\n");
//	}
//	else if (age >= 40 && age < 60)
//	{
//		printf("壮年\n");
//	}
//	else				//else只跟离其最近的if匹配和作用
//	{
//		printf("老年\n");
//	}
//	return 0;
//}
//一个{ }内就是一个代码块，执行多语句需要用代码块

//switch语句
//switch的()里必须是整型表达式或字符的ASCII值（入口） {}里是case语句,case后加整型常量  break用来终止跳出switch语句(出口)
// switch 允许嵌套使用
//int main()
//{
//	int day = 0;
//	printf("请输入1-7的数字来看星期几");
//	scanf_s("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("Monday\n");
//		break;
//	case 2:
//		printf("Tuesday\n");
//		break;
//	case 3 :
//		printf("Wednesday\n");
//		break;
//	case 4 :
//		printf("Thursday\n");
//		break;
//	case 5 :
//		printf("Friday\n");
//		break;
//	case 6 :
//		printf("Saturday\n");
//		break;
//	case 7 :
//		printf("Sunday\n");
//		break;
//	}
//	return 0;
//}
// 
//int main()
//{
//	int i = 0;
//	scanf_s("%d", &i);
//	switch (i) //switch 可以嵌套使用
//	{
//	case 1:
//	case 2:
//	case 3:
//		printf("hello");
//		break;
//	case 4:
//		printf("haha");
//		break;
//	default: //以上case无法匹配时转到default语句来,default可放在switch语句中任意位置
//		printf("hi");
//		break;
//	}
//	return 0;
//}
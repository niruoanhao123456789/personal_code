#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//循环语句  while  for  do……while三类
//int main()
//{
//	int line = 0;
//	printf("努力学习\n");
//	while (line < 20000)
//	{
//		printf("努力学习，写代码：%d\n", line);
//		line++;
//	}
//
//	if (line >= 20000);
//	{
//		printf("good offer\n");
//	}
//	return 0;
//}
//
//while循环中 break用于永久退出循环 continue用于跳过本次循环后面部分，直接去判断部分进行下一次循环
//int main()
//{
//	int n = 0;
//	while (n <= 10)
//	{
//		//if (n == 5)
//		//{
//		//	continue; //代码执行者将返回while前面
//		//}
//		//printf("%d ", n);
//		//n++;  这只打印到4
//		//
//		n++;
//		if (n == 5)
//		{
//			continue;
//		}
//		printf("%d ", n); //这1-11, 除了5以外都打印
//	}
//	return 0;
//}
//
//int main()
//{
//	//int ch = getchar(); //getchar获取字符
//	//putchar("%c\n", ch);
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch); //按ctrl+c停止运行
//	}
//	return 0;
//}
//
//int main()
//{
//	char keyword[20] = { 0 };
//	printf("请输入密码：");
//	scanf_s("%s", keyword);
//	int ch = 0;
//	while ((ch=getchar()) != '\n') //getchar()读取了\n
//	{
//		;
//	}
//	printf("请确认密码（Y/N）：");
//	int ret = getchar();
//	if ('Y' == ret)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
//}  //有点问题
//getchar scanf 后面存在读取缓冲区

// for 循环
//	  初始化 条件判断 调整   注：此处条件判断如果省略，for会将判断恒成立进入死循环
//for(exp1；exp2；exp3)  //可以多个变量来控制一个循环
// 条件判断处若是a=0即赋值为0判断为假跳出循环
//{
//	循环语句;
//}
//建议不要在for循环体内修改变量，防止其失去控制
//int main()
//{
//	//先写一个while循环来与for循环来对比
//	int i = 1;//初始化
//	while (i<=10)//条件判断
//	{
//		printf("%d\n", i);
//		i++;//调整
//	}
//	int t = 0;
//	for (t = 1; t < 11; t++)
//	{
//		if (t == 5)
//		{
//			break;//从break跳出循环
//		}
//		printf("%d\n", t);
//	}
//	return 0;
//}
//

//do while循环
//do
//{
// 循环语句;
// } while(exp);


//goto语句跳转功能 其不能跳转函数部分  适合深度嵌套循环
//int main()
//{
//again:
//	printf("hello\n");
//	printf("hihi\n");
//	goto again; //跳转到again:处
//	return 0;
//}
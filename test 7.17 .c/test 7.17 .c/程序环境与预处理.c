#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//程序环境		计算机组成原理
//C语言存在两个环境：
//翻译环境，源代码被转换成可执行的机器指令(二进制指令)
//执行环境，用于实际执行代码
// 
//源文件 .c   -- 编译 -->  目标文件 .obj  -- 链接 -->  可执行程序 .exe
//
//编译：预编译/预处理   -->	    编译			-->			汇编
//gcc test.c -E -> gcc test.i -S -> gcc test.s-c(汇编代码) -> test.o(二进制)
// 
//预处理阶段包含以下文本操作：
//1、头文件包含
//2、define 定义符号的替换，并删除定义符号
//3、删除注释
//……
// 
//编译阶段：语法分析、词法分析、符号汇总、语义分析
//将C语言代码转换为汇编代码
//
//汇编阶段：形成符号表
//将汇编代码转换为二进制指令
//
//链接阶段：合并段表、符号表的合并与重定位
//合并段表将不同目标文件.o和链接库生成elf文件，合并为exe文件
//符号表的合并与重定位 将符号表.o里函数的地址合并并选择有效地址(该过程会发现哪些函数未定义)
//《程序员的自我修养》

//运行环境
//1、程序载入内存中
//2、程序执行开始，调main函数
//3、执行程序代码，函数栈帧
//4、程序终止


//预处理详解
//预定义符号：
// __FILE__  进行编译的源文件
// __LINE__  文件当前行号
// __DATE__  文件被编译的日期
// __TIME__  文件被编译的时间
// __STDC__  如果编译器遵循ANSI C，其值为1，否则没有定义
//
//int main()
//{
//	int i = 0;
//	FILE* pf = fopen("log.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return EXIT_FAILURE;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf,"File:%s\nLine:%d\nDate:%s\nTime:%s\ni = %d\n", __FILE__ , __LINE__ ,__DATE__,__TIME__, i);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//#define
//#define MAX 100
//#define STR "hello world"
//#define PRINT printf("hehehe")
//#define 可以定义数字、字符串、关键字、语句（一段代码）、宏

//#define定义宏
//注意：1、宏参数和#define定义中可以出现其他#define定义的符号，但宏不能出现递归
//		2、当预处理器搜索#define定义的符号时，字符串常量的内容并不被搜索
//
//#define SQUARE(X) X*X
//#define SQUARE1(X) ((X)*(X))
//宏定义只有加上最外层的()才能作为一个整体，所以建议加上最外层的()
//#define DOUBLE(X) (X)+(X)
//#define DOUBLE1(X) ((X)+(X))
//
//int main()
//{
//	//int r = SQUARE(5);
//	//printf("%d\n", r);
//
//	//int ret = SQUARE(5 + 1);
//	////int ret = 5+1 * 5+1;//11
//	//printf("%d\n", ret);
//
//	//int ret1 = SQUARE1(5 + 1);
//	//printf("%d\n", ret1);
//
//	int ret2 = DOUBLE(3+1);//(3+1)+(3+1)
//	printf("%d\n", ret2);
//	int ret3 = 10 * DOUBLE(3 + 1);//10 * (3+1)+(3+1)
//	printf("%d\n", ret3);
//	int ret4 = 10 * DOUBLE1(3 + 1);//10 * ((3+1)+(3+1))
//	printf("%d\n", ret4);
//
//	return 0;
//}

//#和##
//
//#define PRINT(N,FORMAT) printf("The value of "#N" is "FORMAT"\n",N)
////#N将N转换为对应对的字符串
//int main()
//{
//	/*printf("hello world\n");
//	printf("hello ""world\n");*/
//	//上面两个代码结果是一样的
//
//	int a = 10;
//	PRINT(a,"%d");
//	float b = 20;
//	PRINT(b,"%f");
//
//	return 0;
//}
//
//#define CAT(Class,Num) Class##Num
////## 在预处理阶段将两个符号合成一个符号，其允许宏定义从分离的文本片段创建标识符
//int main()
//{
//	int Class106 = 106;
//	printf("%d\n", CAT(Class, 106));
//	printf("%d\n", Class106);
//	return 0;
//}

//带有副作用的宏参数
//#define MAX(x,y) ((x)>(y)?(x):(y))
////宏的参数是直接进行替换，而不会先进行计算
//int main()
//{
//	int a = 5;
//	int b = 4;
//	int m = MAX(a++, b++);
//	((a++)>(b++)?(a++):(b++))
//	//这使得宏里的值不确定，让宏变得危险，所以尽量不要让宏的参数带有副作用
//	printf("%d\n", m);//6
//	printf("a=%d b=%d\n", a, b);//7 5
//
//	return 0;
//}

//宏和函数
//宏优点：在执行简短代码时效率比函数高，且宏没有参数限制
//缺点：使用宏的时候，宏定义的代码是直接插入到程序中的，除非宏比较短，不然会增加代码长度
//		宏无法进行调试，且由于与类型无关存在不严谨，宏还会带来运算符优先级问题，宏不能实现递归
//#define MAX(x,y) ((x)>(y)?(x):(y))
////某种意义上宏还能实现传参数
//#define MALLOC(NUM,TYPE) (TYPE*)malloc((NUM)*sizeof(TYPE))
//
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	//int* p = MALLOC(4, int);
//
//	return 0;
//}

//#undef 移除宏定义
//#define M 100
//
//int main()
//{
//	printf("%d\n", M);
//#undef M
//	printf("%d\n", M);//这样M不在作为宏定义使用
//}

//命令行定义

//条件编译
// #if 常量表达式
// //……
// #endif
//多分支条件编译
//#if 常量表达式
// //……
//#elif 常量表达式
// //……
//#endif
//
//#define __DEBUG__
//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__  //如果__DEBUG__有被定义且为真，以下代码才进行编译
//		printf("%d ", arr[i]);
//#endif  //__DEBUG__ 
//		//上面代码注释方便说明
//	}
//#if 1
//	printf("hehe\n");
//#endif
//
//#ifndef __DEBUG__	//#ifndef 如果没定义才进行编译
//	printf("hahaha\n");
//#endif
//	return 0;
//}

//文件包含 #include
//多次包含相同头文件，会将头文件多次拷贝在预处理文件.i，导致代码冗余
//解决方法：
// 
//1、在用头文件中用条件编译
//#ifndef __Text.h__
//#define __Text.h__
//
//void test();
//
//#endif
//2、在头文件中用以下代码，使头文件只被包含一次
//#pragma once
//
//void text();

//#include<> 和#include""的区别是查找策略的不同
// <> 查找策略是直接在库目录下查找
// "" 查找策略是先去代码所在目录查找
//	  没找到则再去库目录下查找
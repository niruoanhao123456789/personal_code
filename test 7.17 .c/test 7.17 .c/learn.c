#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>
#define _CRT_SECURE_NO_WARNINGS 1

//C语言中main函数可以在程序的任意位置, 程序的执行从main开始到main结束
//一个工程中有多个 .c文件，但只有一个main主函数入口
//C语言中一行可以写多条语句但不建议
//C语言其本身没有输入和输出语句

//二进制、十进制、八进制、十六进制的转换
//注：十六进制位里10 - 15 表示为 a - f
// 
//二进制 -> 十进制（其他进制位转十进制一样的思路）
//  1   1   1   1  1  1  1  1		二进制
// 128 64  32  16  8  4  2  1		十进制
//
//二进制 -> 八进制		从二进制右边地位开始每3个二进制位转换为一个八进制位，二进制位不够直接转换
// 01   101   011		二进制   
//  1     5     3		八进制
//  1     0     7		十进制
//
//二进制 -> 十六进制    从二进制右边地位开始每4个二进制位转换为一个十六进制位，二进制位不够直接转换
//十六进制前面加0x
// 0110   1011			二进制 
//    6      b			十六进制
//   97  +  11  =  107 
//
//十进制、八进制、十六进制之间的转换通过先转为相应的二进制位在进行转换


//					内存
//
//栈区		 局部变量 函数参数
//
//堆区		 动态内存分配
//
//静态区	 全局变量 静态变量


//register 寄存器 用于加快计算速度，因寄存器是集成在CPU上的
//register int a;//表示建议放在寄存器中计算，因寄存器数量有限，所以由编译器来决定是否放在寄存器上计算


//sizeof()的括号里的式子是不会行进计算的，sizeof()只关注类型的大小
//int main()
//{
//	int a = 10;
//	short s = 2;
//	printf("%zd\n", sizeof(s = a + 1));//2
//	printf("%d\n", s);//2
//	return 0;
//}

//字符串  “\0”是字符串停止的标志 EOF是文件的结束标志
//int main() 
//{
//	char arr1[] = "abcdea";//字符串的结尾是以\0作为结束，故arr1中6个字符
//	char arr2[] = { 'a','b','c','d','e','\0'};//单个输入 这样arr2则是5个字符,但打印时会自动检索至\0才停止
//  char arr3[] = { 'a','b','c','d','e'};  //用strlen求arr3取决于后面空间内多久到\0，故结果是个随机值
//	printf("%s\n",arr1);
//	printf("%s\n", arr2);
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr3));
//	char* pch = NULL;
//	//printf("Looking for the 'a' character in \"%s\"...\n", arr1);
//	// 
//	//pch = strchr(arr1, 'a');
//	//char* pt = (char*)malloc(strlen(pch) + 1);
//	//strcpy_s(pt,50, pch);
//	//printf("%s\n", pt);
//	//free(pt);
//	// 
//	//while (pch != NULL )
//	//{
//	//	printf("found at %d\n", pch - arr1 + 1);
//	//	pch = strchr(pch + 1, 'a');
//	//}
// 
//		return 0;
//}
//strlen是求字符串长度的函数， 要用到库函数string.h，同样到\0结束
//char是字符类型函数也属于整型，因字符储存的是ASCII值
// 0是数字0  '0'是字符0其ASCII值为48
// EOF(-1) getchar读取到EOF才停止
// NULL(0地址)
//strchr(字符串，字符) 从左至右在字符串里检索所要的字符，返回的是地址


//转义字符
//注意计算字符数量时要考虑转义字符
// e.g
//int main()
//{
//	printf("abc \n");
//	printf("abcn \n") ;// \n是换行的意思，已由字符n转变为 换行
//	printf("abc0def \n");
//	printf("abc\0def");
//		return 0;
//}
// %d以十进制打印整型 %c打印字符 %s打印字符串 %f打印float %lf打印double %zu打印size of的返回值是size_t类型 
// %x以十六进制打印 %o 以八进制打印
// 常见转义字符（都算是一个字符）%u unsigned int %hd 十进制short int
// \'是'  \"是" \t是水平制表符=Tab \r是回车 \ddd八进制转十进制ASCII编码  \xdd十六进制转十进制ASCII编码（d为数字） \n换行
//  \?\?避免出现??的三字母词  \\是\  \b是退格
// 
//int main()
//{
//	printf("%c\n", '\130');
//	printf("%c\n", '\x63');
//	printf("%d\n", strlen("abc de"));
//	printf("%d\n", strlen("c:\test\628\test.c"));
//	return 0;
//}


//静态库的使用
//#pragma comment(lib,"名称.lib")
//鹏哥C语言函数的声明和定义有提及


//表达式求值
//计算顺序由操作符的优先级、结合性与是否控制求值顺序决定
//相邻操作符看优先级，优先级一样且操作符不相邻看结合性
//隐式类型转换：C语言中算术运算总是至少以缺省（默认）整型类型的精度来进行，
//因此表达式中字符和短整型在使用前会转换为普通整型，该转换称为整型提升
//整型提升是按照变量的数据类型的符号位来提升的
//字符也算整型家族，整型在内存中存的是补码
//当不同类型的变量进行比较时，都要进行算术转换，将小的类型转化为大的类型(向上转换)
//int 与 unsigned int  int会转换为unsigned int
// 
//int 4byte 32bit
//char 1byte 8bit
//int main()
//{
//	char a = 5;
//	//00000101
//	char b = 126;
//	//01111110
//	char c = a + b;//此处计算时char达不到整型的大小，便发生了整形提升
//	//00000101
//	//01111110
//	// ——> 整型提升
//	//00000000000000000000000000000101
//	//00000000000000000000000001111110
//	//00000000000000000000000010000011
//	//10000011
//	//11111111111111111111111110000011 补码
//	//10000000000000000000000001111101 源码 
//	printf("%d\n", c);//-125
//
//	char e = 1;
//	printf("%d\n", +c);
//
//	return 0;
//}
//问题表达式：计算路径（计算顺序）不唯一，无法通过优先级、结合性与是否控制求值顺序来有效判断
//e.g:1、 a*b+c*d+e*f	   其中abcdef可以是具体的值，也可以是表达式，如果前者的运算会影响到后者，就可能发生问题
//	  2、c + --c
//    3、
//int main()
//{
//	int a = 1;
//	int b = (++a) + (++a) + (++a);
//	printf("%d\n", b);//不同编译环境下结果不同
//
//	return 0;
//}
//因此要对这样的表达式进行优化与简化，确定唯一的计算路径，避免出现问题表达式
//调试中可从反汇编里看到程序的运算逻辑 ebp eax ebx ecx edx之类的是寄存器里面存放的是地址


//常见关键字
//typedef:类型重命名 （“类型换元法”）
//typedef unsigned int uint;
//int main()
//{
//	uint num1 = 1;// =unsigned int num1 = 1 
// 
//	return 0;
//}
//static//静态  可修饰全局、局部变量和函数
//static 修饰局部变量时，局部变量出了作用域时不消毁，本质上是改变了变量的存储位置,延长了其生命周期
//全局变量有外部连接属性 而static修饰全局变量时，该全局变量变为了内部连接属性，其他源文件无法引用，作用域变小了
//extern 声明外部变量符号
//void test()//void 表示函数无需return任何值
//{
//	static int a = 1;//此处a因static而保留之前运算留下的值（局部变量）
//	a++;
//	printf("%d ", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test();
//			i++;
//	}
// 
//		return 0;
//}
//register:寄存器  将变量放入寄存器中加快其读写效率
//const修饰常量，常量不能被改变，无论是数值还是指针


//#define 定义常量和宏  define不是关键字，是预处理指令
//宏是有参数的
//#define NUM 100//常量
//#define ADD(x,y) x+y//可承担部分函数的功能
////     宏名 参数（该参数是无类型的） 宏体
//int main()
//{
//	printf("%d\n", NUM);
//	int a = 250;
//	int b = 270;
//	int c = ADD(a,b);
//	printf("%d\n", c);
// 
//	return 0;
//}


//#pragma once
//头文件中使用，用于防止头文件被多次引用


//#include<windows.h>
//Sleep(1000); //1000毫秒  调整代码运行速度


//清空屏幕
//#include<stdlib.h>
//system("cls");   //system是一个可以执行系统命令的库函数


//布尔类型：bool 用来表示真假的变量(true or false)	其使用要头文件<stdbool.h>
//
//bool is_it(int a)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(a); j++)
//	{
//		if (a % j == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_it(i))
//		{
//			printf("%d ", i);
//		}
//	}
// 
//	return 0;
//}

//全局变量、静态变量都是放在静态区
//全局变量、静态变量不初始化的时候，会被默认初始化为0


//调试
//注：Debug版本为测试版 -程序调试版本
//	  Release版本为发布版 并会对代码进行优化
//了解一些并习惯用一些调试的快捷键
//断点的使用
//在调试中 逐语句可进入函数，而逐过程则会将会将函数运行完并不进去
//Ctrl + f 搜索

//《C陷阱和缺陷》
//栈区内存的使用习惯是从高地址到低地址，而数组随着下标增长地址是由低到高增长
//如果i和arr之间有适当的空间，利用数组的越界访问操作就可能会覆盖到i,就可能导致死循环的出现
//int  main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello\n");
//	}
//
//	return 0;
//}

//如何写好代码:
//能正常运行
//善于使用assert、const
//少bug
//效率高
//注释清晰
//可读性高
//可维护性高
//文档齐备
// 
////一般的代码
//void my_strcpy(char* dest, char* strc)
//{
//	while (*strc != '\0')
//	{
//		*dest = *strc;
//		dest++;
//		strc++;
//	}
//	*dest = *strc;
//}
//
//好代码
//char* my_strcpy(char* dest, const char* strc)//之所以返回char* 是为了实现链式访问，就可以作为其他函数的参数
//{
//	char* ret = dest;//确保返回目标空间的起始地址
//	//断言assert	需要库函数<assert.h>
//	assert(strc != NULL);
//	assert(dest != NULL);
//	//如果不小心给函数传入了个空指针NULL，这样断言可以让编译器报错，提醒你传入了NULL
//	//加了const后 (*strc++ = *dest++)就会报错，避免赋错值
// 
//	while (*dest++ = *strc++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxx";
//	char arr2[] = "hello world";
//	//strcpy_s(arr1, 20,arr2);//strcpy函数返回的是目标空间的起始地址
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//const常变量的使用
//int main()
//{
//	const int num = 10;
//	//num = 20;//这里num被const修饰后便不能直接赋值，编译器也会报错
//
//	//但可用指针来该变num的值(翻窗户)
//	//int* p = &num;
//	//*p = 20;
//
//	//避免被翻窗户
//	//const int* p = &num;
//	//*p = 20;//这样指针也无法改num的值
//
//	//const 修饰指针变量
//	//1. const放在*左边
//	//意味着：p所指向的对象不能通过p来改变，但p本身的值可以改变
//	//int n = 100;
//	//int const* p;
//	////*p = 20;//err
//	//p = &n;//ok
//	// 
//	//2. const放在*右边
//	//意味着：p指向的对象是可以通过p来改变，但p本身的值不能改变
//	//int* const p = &num;
//	//*p = 0;//ok
//	//int n = 100;
//	//p = &n;//err
//	//
//	//3. 如果const在*左右两边都放
//	//意味着：p所指向的对象和p本身的值都不能改变
//	//const int* const p = &num;
//
//	printf("%d\n", num);
//
//	return 0;
//}

//unsigned int my_strlen(const char* str)
//{
//	unsigned int count = 0;
//	assert(str != NULL);
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	printf("%d\n", my_strlen(arr1));
//
//	return 0;
//}


//任何一个变量/表达式都有两个属性：
//值属性
//类型属性
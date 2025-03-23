#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//指针
//指针是内存中最小单元(字节)的编号——地址（本质）
//内存
//int main()
//{
//	int a = 10;//向内存要4个字节作为存储
//	printf("%p\n", &a);// %p是以地址的形式打印数据（以十六进制表示）
//  int *p1, *p2, *p3; 
//	int* p = &a;//其中p就是指针变量
//	//内存单元中，数据编号 ->地址 也称为指针
//	*p = 20;//解引用操作符，通过p中存放的地址，找到p所指对象，*p就是p所指对象  &a *p
//	printf("%d\n", *p);
//	char ch = "w";
//	char* pc = &ch;
//	printf("%p\n", pc);
// 
//	return 0;
//}
//指针变量的大小
//不管什么类型的指针，都是在创建指针变量，而指针变量是用来存放地址的，其大小取决于地址存放时所需空间
//32位系统上的地址-32bit位-4字节  64位上的地址-64比特位-8字节，故32位指针变量大小4个字节、64位8个字节
//int main()
//{
//	int a = 0;//a占四个字节，其所占内存有四个地址
//	//&a取出的是第一个地址
//	int* pa = &a;//此处pa是个指针变量，是用于存放地址的变量，通过这个地址，可以找到对应的内存单元	 口头语中指针常为指针变量
//
//	return 0;
//}

//指针与指针类型
//指针类型的意义:不在与存储地址的大小，它们的大小都一样，在于解引用访问时访问的字节大小的不同
//指针类型决定了指针在解引用时访问几个字节
//32位下 int* 解引用访问4个字节
//		 char* 解引用访问2个字节
//以此推广到其他指针类型
//指针类型决定了指针 +或- 1操作时跳过几个字符 (决定指针的步长)
// int* 和 float* 在解引用和跳过字符时都是四个字节，但二者不能通用
//int main()
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	//*pa = 0;//
//	char* pc = (char*)&a;
//	//*pc = 0;
//	printf("pa   = %p\n", pa);
//	printf("pa+1 = %p\n", pa + 1);
//	printf("pc   = %p\n", pc);
//	printf("pc+1 = %p\n", pc + 1);
//
//	return 0;
//}

//野指针：指针指向的位置不可知位置（没有明确指向）
//野指针成因：指针未初始化、指针越界访问、指针指向的空间释放
//一个局部变量不初始化的化，放的是随机值
//int* test()
//{
//	int a = 10;
//	return &a;
//}//出了该函数后，此空间归还给了操作空间，不属于现在的程序了（销毁）
// 
//int main()
//{
//	//int arr[10] = { 0 };
//	//int* p = arr;//&arr
//	//int i = 0;
//	//for (i = 0; i <= 10; i++)//此便存在指针的越界访问,arr[10]是没有的
//	//{
//	//	*p = i;
//	//	p++;
//	//}
//
//	//int* p = test();
//	//在接受test()的返回值后，再使用p就是野指针，原因是test()中a=10是个局部变量，
//	//出了test()函数后就销毁了，p再去访问所存a的地址时就无法访问
//
//	int* p = NULL;//指针变量p的初始化，就像int a = 0, NULL = 0
//	//*p = 100;//这样使用是错误的
//	if (p != NULL)//这里建议写为(p != NULL)而不是(p),这样可明确表明这个p是指针变量，而不是其他变量
//	{
//		*p = 100;
//	}//这样使用没有问题
//
//	return 0;
//}

//指针的运算
//指针+-整数
//int main()
//{
//	//float values[5];
//	//float* vp;
//	//for (vp = &values[0]; vp < &values[5];)
//	//{
//	//	*vp++ = 0;// *vp = 0  vp++ 令*vp所指values[vp]里的内容为0再vp++
//	//}
//
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//数组下标的写法
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 1;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	//指针写法
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		*p++ = 2;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}
//
//指针-指针:得到的绝对值是指针和指针之间的元素个数
//但不是所有的指针都能相减，只有指向同一块空间的两个指针才能相减
//int main()
//{
//	int arr[10] = { 0 };
//	char  ch[5] = { 0 };
//	printf("%d\n", &arr[9] - &arr[0]);//9
//	printf("%d\n", &arr[0] - &arr[9]);//-9
//
//	//错误写法:
//	//printf("%d\n", &ch[0] - &arr[5]);
//
//	return 0;
//}

//指针的关系运算
//int main()
//{
//	float values[5] = { 0 };
//	float* vp;
//	for (vp = &values[5]; vp > &values[0];)
//	{
//		*--vp = 1;
//	}
//	//但不建议写成这样:
//	//for (vp = &values[4]; vp >= &values[0]; vp--)
//	//{
//	//	*vp = 1;
//	//}
//	//虽大多编译器支持这样写，但C语言标准规定：允许指向数组元素的指针跟最后一个元素后面内存位置的指针比较，
//	//但不允许与指向第一个元素之前内存位置的指针进行比较
//	int i = 0;
//	for (i = 0; i < 5; ++i)
//	{
//		printf("%d ", values[i]);
//	}
//
//	return 0;
//}

//指针与数组
//数组：一组相同元素的集合，在内存空间中开辟一段连续的空间
//指针变量：用于存放地址的变量
//void test(int* p,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ",*(p + i));
//	}
//}
////对比test()另一种写法
////void test(int arr[], int sz)
////{
////	int i = 0;
////	for (i = 0; i < sz; i++)
////	{
////		printf("%d ", arr[i]);
////	}
////}
//
//int main()
//{
//	int arr[10] = { 0 };
//	//数组名arr是首元素的地址 &arr[0]
//	int* p = arr;//这样p就指向了arr[0]的地址,p某种意义上 = arr
//	//可通过指针来访问数组
//	int i = 0; 
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", *(p + i));
//	//}
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%p ———— %p\n", &arr[i], p + i);//arr[i] --> *(arr + i)
//	}
//	//从上面两地址相同，可知下面三中打印效果是一样的
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//		printf("%d ", *(p + i));
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//	//这样方便下面这函数为什么能这样写
//	test(arr, sz);
//	printf("\n");
//
//	return 0;
//}

//二级指针
//二级指针变量是用来存放一级指针变量的地址
//int main()
//{
//	int a = 0;
//	int* pa = &a;//pa是一个一级指针
//	// int* pa 中*说明pa是指针变量，而int是pa指向的数据类型
//	//*pa = 20;
//	//printf("%d\n", a);
//	int** ppa = &pa;//第二个*说明ppa是指针变量,而*前面的int* 说明ppa指向的对象是int*类型
//	//此处ppa就是一个二级指针变量,而pa作为变量也有自己的内存地址
//	//*ppa 访问的是pa的地址
//	**ppa = 20;//访问的是a的地址
//	printf("%d\n", a);
//
//	return 0;
//}

//指针数组：用来存放指针的数组
//可利用指针数组模拟出一个二维数组，即将一堆一维数组放入指针数组中
//int main()
//{
//	////整型数组
//	//int a = 1;
//	//int b = 2;
//	//int c = 3;
//	//int arr[10] = { a,b,c };
//
//	////指针数组
//	//int* pa = &a;
//	//int* pb = &b;
//	//int* pc = &c;
//	//int* parr[10] = {&a,&b,&c};
//
//	//int i = 0;
//	//int sz = sizeof(parr) / sizeof(parr[0]);
//	//for (i = 0; i < 3; i++)
//	//{
//	//	printf("%d ", *(parr[i]));
//	//}
//
//	//二维数组
//	//int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
//	//int i = 0;
//	//int j = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	for (j = 0; j < 3; j++)
//	//	{
//	//		printf("%d ", arr[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	//指针数组
//	int arr1[4] = { 1,2,3,4 };
//	int arr2[4] = { 2,3,4,5 };
//	int arr3[4] = { 3,4,5,6 };
//	int* parr[3] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", parr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//			//又*(p+i) <--> p[i]
//			//printf("%d ", parr[i][j]);//所以也可用这种写法
//		}
//		printf("\n");
//	}
//	return 0;
//}


//字符指针
//int main()
//{
//	const char* p = "abcdef";//把字符串首元素a的地址赋值给了p，类似与数组，其他元素的地址是连续存储在a地址后面的
//	//因字符串是常变量，所以应加const会保证*p里的字符串不会被更改，且不加const直接赋值编译器也不会运行
//
//	char arr[] = "abcdef";//这种写法才是把整个字符串存入数组里
//	printf("%s\n", p);
//	return 0;
//}
// 
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	//这里的字符串是只读常量，所以p1与p2存的地址是同一个
//	char arr1[] = "abcedf";
//	char arr2[] = "abcdef";
//	//而这里是创建了两个数组来存相同字符串，两个数组的地址不同
//	if (p1 == p2)
//		printf("p1 == p2\n");
//	else
//		printf("p1 != p2\n");
//	if (arr1 == arr2)
//		printf("arr1 == arr2\n");
//	else
//		printf("arr1 != arr2\n");
//	return 0;
//}

//数组指针：指向数组的指针
//int (*arr)[10];//arr是个数组指针，arr可以指向一个数组，该数组有十个int类型的元素
//int *arr[10]是指针数组
//
//再看数组名
//数组名通常表示首元素的大小，但有两个例外
//1、sizeof(数组名) 这里数组名表示整个数组，计算时算的是整个数组的大小
//2、&数组名，这里数组名表示整个数组，所以 &数组名 取出的是整个数组的地址
//int main()
//{
//	//int arr[10] = { 0 };
//	//printf("%p\n", arr);
//	//printf("%p\n", arr + 1);//跳过四个字节
//
//	//printf("%p\n", &arr[0]);
//	//printf("%p\n", &arr[0] + 1);//跳过四个字节
//
//	//printf("%p\n", &arr);
//	//printf("%p\n", &arr + 1);//跳过四十个字节
//
//	//int sz = sizeof(arr);
//	//printf("%d\n", sz);
//
//	//int arr1[10] = { 0 };
//	//int* p = arr1;
//	//int (*p)[10] = &arr1;//数组指针，其类型为int(*)[]
//
//	//char* arr[5] = { 0 };
//	//char* (*pc)[5] = &arr;
//
//	//char ch = 'w';
//	//char* pc = &ch;
//	//char** ppc = &pc;
//	//这部分是二级指针，二级指针是用来存放一级指针地址的
//
//	//不建议用以下写法，这个只是用来理解
//	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	////int (*p)[] = &arr;//这种写法编译器运行时会报错,是个错误写法
//	//int(*p)[10] = &arr;
//	//int i = 0;
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", *(*p+i));//p是指向数组的，此时*p其实就相当于数组名，而数组名是首元素的地址
//	//	//所以*p本质上是数组首元素的地址
//	//}
//	//printf("\n");
//
//	return 0;
//}
// 
//常用写法
//void print1(int arr[3][5], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);//二维数组的首元素是它的第一行
//		}
//		printf("\n");
//	}
//}
//
//void print2(int (*p)[5],int row,int col)//这里的数组指针是指向二维数组里的一维数组
//{
//	int i = 0;
//	for (i = 0; i < row;i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			//printf("%d ", * (*(p + i) + j));
//			//*(p + i)拿到某一行的地址arr[i],(*(p + i)+j)进一步拿到具体某一列的地址
//
//			printf("%d ", p[i][j]);//也可以写成这种方式
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//	print1(arr,3,5);
//	print2(arr,3,5);//二维数组里arr标识第一行的地址是一个一维数组的地址
//	return 0;
//}
//其中int (*p)[5]
//p的类型是：int (*)[5]
//p是指向一个整型数组的，数组5个元素 int [5]
//p+1 -> 跳过一个有5个int元素的数组
// &arr -> int (*)[]
// arr --> int*
//
//辨析：
//int arr[5] -> 整型数组
//int *parr[5] <-> int *(arr[5]) -> 指针数组
//int (*parr1)[5] -> 数组指针
//int (*parr2[10])[5] -> 存放数组指针的数组（也是个指针数组,而且是个数组指针数组）

//数组、指针传参
//二级指针是用来存一级指针变量地址的，不能存一维数组的地址
// 
//函数参数是一级指针时，可传
//void test(int* p)
//{;}
//int a;
//int* str = &a;
//int arr[10];
//test(&a);
//test(str);
//test(arr);
//
//函数参数是二级指针时，可传
//void test(int** p)
//{;}
//int* p1;
//int** p2 = &p1;
//int*** p3 = &p2;
//int* arr[10];
//test(&1);
//test(p2);
//test(*p3)
//test(arr);

//函数指针：指向函数的指针
//可以和数组指针类比，数组指针是指向数组的指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//void calc(int(*pf)(int, int))
//{
//	printf("%d\n", pf(3, 5));
//}
//
//int main()
//{
//	//int arr[5] = { 0 };
//	//int (*p)[5] = &arr;//数组指针
//
//	//printf("%p\n", &Add);//&函数 ->取出函数的地址
//	//printf("%p\n", Add);
//	//对于函数来说，&函数名与函数名都是函数的地址
//
//	//int (*pf)(int, int) = &Add;//函数指针
//	int (*pf)(int, int) = Add;
//	//printf("%p\n", *pf);
//	//printf("%d\n", (*pf)(2, 3));//5
//	//printf("%d\n", pf(2, 3));//5
//	//这里结果说明:此处的*可以不写，甚至可写多个，效果是一样的，只不过写时要加(),但为了理解通常写上一种带(*)的标准写法
//	calc(Add);
//	printf("%d\n",sizeof(pf));//返回的是地址的大小
//
//	return 0;
//}
// 

//分析以下代码
//
//为了简便使用以下代码，可以用typedefine
//typedef void(*pf_t)(int);//把void(*)(int)类型重命名为 pf_t
//
//int main()
//{
//	(*(void(*)())0)();
//	// void(*)()是个函数指针类型
//	// ( void(*)() )0 其实是个强制类型转换，被转换的是0，它原本是int，这个过程将0转换为函数的地址
//	// *( void(*)() )0 将转换得到的指针解引用
//	// ( *( void(*)() )0 )() 最后就是对该函数的调用，最后的()表示没有给该函数传参数
//	// 调用的是以0作为地址的函数
//
//	//整个过程的总结：
//	//1、将0强制类型转换为：无参，返回类型为void的函数地址
//	//2、调用0地址处的这个函数
//
//	void(*signal(int, void(*)(int)))(int);
//	// void(* signal(int, void(*)(int)) )(int);
//	//这是个函数的声明，其中signal是个函数名,(int, void(*)(int))是singal函数的参数，singal函数的返回类型为void(*)(int) 是个函数指针
//	//这整个函数的参数是int,返回类型是void
//
//	//typedef后上面的代码就可以改写为：
//	pf_t signal(int, pf_t);
//
//	return 0;
//}

//函数指针的用途
//回调函数的机制
//一个有加减乘除功能的计算器的实现
//void menu()
//{
//	printf("——————————————Calculation———————————————\n");
//	printf(" 1、Add  2、Sub  3、Mul  4、Div 0、退出\n");
//	printf("————————————————————————————————————————\n");
//}
//
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//double Sub(double x, double y)
//{
//	return x - y;
//}
//
//double Mul(double x, double y)
//{
//	return x * y;
//}
//
//double Div(double x, double y)
//{
//	return x / y;
//}
//
//void cal(double (*pf)(double, double))
//{
//	double x = 0;
//	double y = 0;
//	double ret = 0;
//	printf("请输入要操作的两个数：");
//	scanf_s("%lf%lf", &x, &y);
//	ret = (*pf)(x, y);
//	printf("%.2f\n", ret);
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("退出计算器\n");
//			break;
//		case 1:
//			cal(Add);
//			break;
//		case 2:
//			cal(Sub);
//			break;
//		case 3:
//			cal(Mul);
//			break;
//		case 4:
//			cal(Div);
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//函数指针数组
//指针数组的一种，用于存放函数指针
//功能：转移表
//void menu()
//{
//	printf("——————————————Calculation———————————————\n");
//	printf(" 1、Add  2、Sub  3、Mul  4、Div 0、退出\n");
//	printf("————————————————————————————————————————\n");
//}
//
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//double Sub(double x, double y)
//{
//	return x - y;
//}
//
//double Mul(double x, double y)
//{
//	return x * y;
//}
//
//double Div(double x, double y)
//{
//	return x / y;
//}
//
////int main()
////{
////	double (*arr[4])(double, double) = { Add,Sub,Mul,Div };//这里arr就是函数指针数组
////	int i = 0;
////	for (i = 0; i < 4; i++)
////	{
////		double ret = (*arr[i])(4, 8);
////		printf("%.2f\n", ret);
////	}
////	return 0;
////}
//
////计算器的函数指针数组版
//int main()
//{
//	int input = 0;
//	double (*pfarr[5])(double, double) = { 0,Add,Sub,Mul,Div };
//	double x = 0, y = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf_s("%d", &input);
//		if (input==0)
//		{
//			printf("程序退出\n");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数：");
//			scanf_s("%lf%lf", &x, &y);
//			double ret = (*pfarr[input])(x, y);
//			printf("%.2f\n", ret);
//		}
//		else
//		{
//			printf("输入错误，请重新输入\n");
//		}
//	} while (input);
//	return 0;
//}

//指向函数指针数组的指针
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//double Sub(double x, double y)
//{
//	return x - y;
//}
//
//double Mul(double x, double y)
//{
//	return x * y;
//}
//
//double Div(double x, double y)
//{
//	return x / y;
//}
//
//int main()
//{
//	//函数数组指针
//	double (*pfarr[5])(double, double) = { 0,Add,Sub,Mul,Div };
//	//指向【函数指针数组】的指针
//	double (*(*pfarr)[5])(double, double) = &pfarr;
//	return 0;
//}

//回调函数
//一个通过函数指针调用的函数。把函数的指针（地址）作为参数传给另一个函数，当这个指针用来调用其所指向的函数时，这就是回调函数
//冒泡排序
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)//趟数
//	{
//		int flag = 1;//默认是有序排续
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//				flag = 0;
//			}
//			if (flag)
//			{
//				break;
//			}
//		}
//	}
//}
//上面的只能排序int类型的数据
//qsort()利用快速排序的思想实现的的一个排序函数，可以排序任意类型的数据
//该函数要用stdlib.h或search.h的头文件
//void qsort(void* base,//要排序的数据的起始位置
//	size_t num,//待排序的数据元素个数
//	size_t width,//待排序的数据元素大小
//	int(*cmp)(const void* e1, const void* e2)//函数指针_比较函数,e1 e2就是要比较的数据，
//  如果e1>e2返回>0的数 e1=e2返回0 e1<e2返回<0的数
//)
//{
//	;
//}
//__cdecl 函数调用约定
//int cmp_int(const void* e1,const void* e2)//void* 不能直接解引用
//{
//	return (*(int*)e1 - *(int*)e2);//升序逻辑
//	//return (*(int*)e2 - *(int*)e1);//降序逻辑
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);
//	qsort(arr,sz,sizeof(arr[0]),cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
// 
////测试用qsort()来排序结构体变量
//typedef struct stu stu;
//struct stu
//{
//	char name[20];
//	char ID[5];
//	double score;
//};
//
//int cmp_name(const void* e1, const void* e2)
//{
//	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
//}
//
//int cmp_score(const void* e1, const void* e2)
//{
//	return ( ((stu*)e1)->score - ((stu*)e2)->score );
//}
//
//void test()
//{
//	stu s[] = { {"zhang","1",60} ,{"li","3",90} ,{"zhao","2",80}};
//	int sz = sizeof(s) / sizeof(s[0]);
//	//qsort(s, sz, sizeof(s[0]), cmp_name);
//	qsort(s, sz, sizeof(s[0]), cmp_score);
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		printf("%s ", (*(s + i)).ID);
//	}
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//
//void* 补充说明
//int main()
//{
//	int a = 10;
//	//char* pa = &a;//a是int*，所以运行的时候系统会说不兼容
//	void* pv = &a;//void*是无具体类型的指针，可以接受任意类型的地址
//	//void* 是无具体类型的指针，所以不能解引用操作，也不能+-整数，解引用时要强制类型转换
//	return 0;
//}
//
////利用qsort()的逻辑来改造之前的冒泡排序代码,使它可以排序任何类型
//int cmp(const void* e1, const void* e2)
//{
//	return (*((int*)e1) - *((int*)e2));
//}
//
//void Swap(char* e1, char* e2, int width)
//{
//	int i = 0;
//	//一个字节为单位不断交换，直到达到要跳过的字节数
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *e1;
//		*e1 = *e2;
//		*e2 = tmp;
//		e1++;
//		e2++;
//	}
//}
//
//void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			//char是一个字节，加上j*width后,就知道它具体跳过几个字节
//			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				flag = 0;
//			}
//			if (flag)
//			{
//				break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz,sizeof(arr[0]),cmp);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//数组名的理解、指针运算和指针类型的意义
// sizeof 与 strlen 
//int main()
//{
//	//int arr[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(arr));//16
//	////sizeof加数组名，这里数组名表示整个数组，所以计算的是整个数组的大小
//
//	//printf("%d\n", sizeof(arr + 0));
//	////arr没有单独放在sizeof()内部，也没有取地址，所以arr+0仍表示首元素的地址，该地址大小在32位下结果是4，64位下是8
//
//	//printf("%d\n", sizeof(*arr));//4
//	////*arr中的arr是数组首元素的地址，*a就是对首元素地址的解引用，找到的就是首元素
//
//	//printf("%d\n", sizeof(arr + 1));
//	////这arr是首元素地址，arr+1就是第二个元素的地址，所以结果就是第二个元素地址的大小(32位下结果是4，64位下是8)
//
//	//printf("%d\n", sizeof(arr[1]));//4
//	////计算第二个元素的大小
//
//	//printf("%d\n", sizeof(&arr));
//	////&arr取出整个数组的地址，结果也就是一个地址的大小(32位下结果是4，64位下是8)
//
//	//printf("%d\n", sizeof(*&arr));//16
//	////&arr取出整个数组的地址，解引用得到的就是整个数组,便捷理解：*与&相抵消了
//
//	//printf("%d\n", sizeof(&arr + 1));
//	////这里&arr --> int(*)[4]，&arr+1是从arr的地址向后跳过了一个（四个整型元素的）数组大小后的一个地址
//
//	//printf("%d\n", sizeof(&arr[0]));
//	////&arr[0]第一个元素地址
//
//	//printf("%d\n", sizeof(&(arr[0]) + 1));
//	////&(arr[0]) + 1) --> &arr[1] 第二个元素的地址
//
//
//	//char arr1[] = { 'a','b','c','d','e','f' };
//
//	//printf("%d\n", strlen(arr1));//随机值
//	//printf("%d\n", strlen(arr1 + 0));
//
//	//printf("%d\n", strlen(*arr1));// -->strlen('a')-->strlen(97)  将随便一个数字当作地址给函数是非法的，属于野指针
//	//printf("%d\n", strlen(arr1[1]));//在调试中编译器会报错
//
//	//printf("%d\n", strlen(&arr1));//随机值，取出的地址起始和arr1是一样的
//	//printf("%d\n", strlen(&arr1 + 1));//上一行代码的结果减6
//	//printf("%d\n", strlen(&arr1[0] + 1)); //上上一行代码的结果减1
//
//	return 0;
//}
//
//int main()
//{
//	//sizeof是操作符，只关注占用内存空间的大小，不关注内存里的内容
//	//strlen是求字符串的长度的库函数，关注的是字符串中的\0，计算的是\0之前出现的字符个数
//	//char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));//7
//	//printf("%d\n", sizeof(arr + 0));//首地址的大小 4/8
//	//printf("%d\n", sizeof(*arr));//1
//	//printf("%d\n", sizeof(arr[1]));//1
//	//printf("%d\n", sizeof(&arr));//整个数组的地址 4/8
//	//printf("%d\n", sizeof(&arr + 1));// 4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));// 4/8
//
//	//printf("%d\n", strlen(arr));//6
//	//printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//野指针
//	//printf("%d\n", strlen(arr[1]));//野指针
//	//printf("%d\n", strlen(&arr));//6
//	//printf("%d\n", strlen(&arr + 1));//随机
//	//printf("%d\n", strlen(&arr[0] + 1));//5
//
//
//	//char* p = "abcdef";//常量字符串
//	//printf("%d\n", sizeof(p));// 4/8
//	//printf("%d\n", sizeof(p+1));// 4/8
//	//printf("%d\n", sizeof(*p));//1
//	//printf("%d\n", sizeof(p[0]));//1
//	//printf("%d\n", sizeof(&p));// 4/8
//	//printf("%d\n", sizeof(&p+1));// 4/8
//	//printf("%d\n", sizeof(&p[0] + 1));// 4/8
//
//	//printf("%d\n", strlen(p));//6
//	//printf("%d\n", strlen(p+1));//5
//	//printf("%d\n", strlen(*p));//err
//	//printf("%d\n", strlen(p[0]));//err
//	//printf("%d\n", strlen(&p));//随机值
//	//printf("%d\n", strlen(&p+1));//随机值
//	//printf("%d\n", strlen(&p[0] + 1));//5
//
//	return 0;
//}
//
//int main()
//{
//	int arr[3][4] = { 0 };
//	printf("%d\n", sizeof(arr));// 3*4*4=48
//	printf("%d\n", sizeof(arr[0][0]));//4
//	printf("%d\n", sizeof(arr[0]));//arr[0]是第一行这个一维数组的数组名，单独放在sizeof()内表示第一行一整个一维数组 16
//	printf("%d\n", sizeof(arr[0] + 1));//arr[0]既没有放在sizeof()内部,也没有&，arr[0]就表示首元素地址
//	//第一行第二个元素的地址 // 4/8
//	printf("%d\n", sizeof(*(arr[0] + 1)));//第一行第二个元素 4
//	printf("%d\n", sizeof(arr+1));//arr既没有放在sizeof()内部,也没有&，所以arr是二维数组的首元素地址，也就是第一行的地址
//	//arr+1就是第二行的地址  4/8
//	printf("%d\n", sizeof(*(arr + 1)));//对第二行的地址解引用，访问的就是整个第二行的元素  16
//	printf("%d\n", sizeof(&arr[0] + 1));//&arr[0]拿到整个第一行的地址，&arr[0] + 1就指向第二行
//	printf("%d\n", sizeof(*( & arr[0] + 1)));//整个第二行的元素 16
//	printf("%d\n", sizeof(*arr));//arr既没有放在sizeof()内部,也没有&，所以arr是二维数组的首元素地址，也就是第一行的地址，
//	//*arr拿到第一行的元素 16
//	printf("%d\n", sizeof(arr[3]));//16
//
//	return 0;
//}

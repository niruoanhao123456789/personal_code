#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//位段
//位段的声明和结构体类似，但其成员得是整型家族的(可以是 int、 unsigned int、 char)，且成员名后有冒号加数字
//一般来说位段的成员是相同类型
//struct A
//{
//	int a : 2;//分配2个比特位
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};//这就是一个位段
//// 
////位指bite位 在位段里冒号+数字表示内存分配多少个比特位
////在一些成员取值范围用不到这么多比特位时，位段里的冒号+数字能很好地节省内存
////所以位段可以用来节省内存空间
//int main()
//{
//	printf("%d\n", sizeof(struct A));//8
//	//struct A 47个比特位 一个字节8个比特位 
//	return 0;
//}

//位段的内存分配
//位段的空间是按照需要以 4字节或者 1字节来开辟的
//位段存在很多不确定因素，位段是不跨平台的，注重可移植性的程序应避免使用
//一个字节（内存）中是先从左开始使用还是从右位段是不确定的；剩余空间的bit位无法存下一个成员时是否被浪费也是不确定的
//在vs中是从左向右，剩余空间被浪费
//struct A
//{
//	//以四字节来开辟空间
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	//开辟了四字节32个比特位还剩下15个比特位
//	int d : 30;
//	//因此在这又开辟了四个字节
//	//所以sizeof(struct A)的结果是8个字节
//}s;
// 
////位段的应用	网络协议
////位段成员通常是相同类型的
////位段成员可能不是存储在内存的首位，因此位段成员是没有地址的，所以不能对位段进行位操作和取地址操作
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	s, a = a;
// //要对位段成员赋值可以采用以上方法
//}


//枚举
//枚举可增加代码的可读性，以及增加类型检查，会更严谨，可以一次性定义多个常量，而且枚举类型的变量是有作用域的
//枚举类型的定义
//enum Day
//{
//	Mon,//0
//	Tues,//1
//	Wed,//2
//	Thur,//3
//	Fri,//4
//	Sat,//5
//	Sun//6
//	//枚举常量，默认从0开始
//};
//
//#define M 10
//
//enum Day
//{
//	Mon=1,//1
//	Tues,//2
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//	//要修改默认值，可以这样来修改
//};
//
//int main()
//{
//	enum Day d = Mon;
//	d = 0;//在C++里会报类型错误
//	
//	//printf("%d\n", Mon);
//	//printf("%d\n", Tues);
//	//printf("%d\n", Wed);
//
//	int a = M;//在程序预处理阶段，因define了M，M会被替换成10，在调试中是看不到M的，只能看被替换后的10
//	//而枚举因其是个类型而不会这样
//
//	return 0;
//}
//
//像在写菜单时，枚举可增加代码的可读性
//以加减法为例
//enum Cal
//{
//	Exit,
//	Add,
//	Sub
//};
//
//void meun()
//{
//	ptintf("1、Add  2、Sub");
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		meun();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case Add:
//			//
//		case Sub:
//			//
//		case Exit:
//			//
//		default:
//			printf("重新输入\n");
//		}
//	} while (input);
//
//	return 0;
//}
//在规定权限、单片机引脚定义等枚举也有作用


//联合（共用体）
//联合里一系列成员公用同一块内存空间
//union un
//{
//	char a;
//	int i;
//};
//
//struct st
//{
//	int i;
//	char a;
//};
//
//int main()
//{
//	union un u;
//
//	printf("%d\n", sizeof(u));//4
//	printf("%p\n", &u);
//	printf("%p\n", &u.a);
//	printf("%p\n", &u.i);
//	//发现联合类型的变量和其成员的地址是相同的
//	//说明联合变量的成员是公用同一块内存空间的
//	//而结构体变量的成员是单独占用空间的
//
//	return 0;
//}

//联合体大小的计算
//联合体的大小至少是最大成员的大小，但联合体内存也存在内对齐，所以其内存大小不一定是最大成员的
//union un
//{
//	char arr[5];//5
//	int i;//4
//	//以上最大对齐数为4，所以内存大小为4的倍数
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union un));//8
//	return 0;
//}

//联合体的应用
//商品兑换单
//对于结构体中存在重复信息时，为避免内存空间的浪费，可将不重复且和其他礼品的不会同时存在的信息放在联合体中
//struct gift_list
//{
//	float price;
//	int num;
//	int size;
//	union
//	{
//		int characteristic1;
//		int characteristic2;
//		int characteristic3;
//	};
//};

//用联合来判断编译器的大小端存储
//int check_sys1()
//{
//	int i = 1;
//	return *(char*)&i;
//}
//
//int check_sys2()
//{
//	union //匿名
//	{
//		int i;
//		char a;
//	}u;
//	u.i = 1;
//	return u.a;
//}
//
//int main()
//{
//	//int i = 1;//0x 00 00 00 01
//	// 低 —————> 高
//	// 01 00 00 00  小端
//	// 00 00 00 01	大端
//	
//	//int ret = check_sys1();
//	int ret = check_sys2();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}
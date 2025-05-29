#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<stddef.h>

//结构体（自定义类型）struct:是把一些单一类型组合在一起的做法 不同类型的集合
//struct stu //结构体类型名
//{
//	char name[20];//成员变量
//	int age;
//	char sex[10];
//	int tele;
//};
//
//void print(struct stu* ps)
//{
//	printf("%s %d %s %d\n",(*ps).name,(*ps).age,(*ps).sex,(*ps).tele );
//	printf("%s %d %s %d\n", ps->name,ps->age,ps->sex,ps->tele);// 结构体指针变量->结构体成员
//}
//
//
//int main()
//{
//	struct stu s = { "zhangsan",20,"male",66666666 };
//	printf("%s %d %s %d\n", s.name, s.age, s.sex, s.tele);//访问结构体对象 结构体对象.成员名
//	print(&s);
// 
//	return 0;
//}

//结构体(类型)的声明、结构体变量的定义与初始化和结构体的传参
//结构是一些值的集合，这些值称为成员变量，成员变量的类型可不同
//将结构体变量传给函数的过程就是结构体的传参
// 
//struct peo
//{
//	char name[20];
//	char sex[5];
//	int height;
//	char phone[12];//成员变量列表
//}p1,p2;//变量列表  这样在声明类型的同时也定义了变量p1、p2
//struct peo p3;// 定义结构体变量p3
//p1和p2是使用struct peo结构类型创建的两个变量,并且p1和p2是两个全局变量，但通常不建议随意地去用全局变量
//这就是结构体的声明，其也可在main()中声明，但这样只能在main()中使用
//
//struct peo
//{
//	char name[20];
//	char sex[10];
//	int height;
//	char phone[12];
//};//这些类型可以比作是图纸，是不占内存空间的
//
//struct stu
//{
//	struct peo p;//这前提是struct peo存在
//	int num;
//	float f;
//};//也可以这样结构体中嵌套结构体
//
//void print1(struct peo p)
//{
//	printf("%s,%s,%d,%s\n", p.name, p.sex, p.height, p.phone);//结构体变量.成员变量
//}
//
//void print2(struct stu* ps)
//{
//	printf("%s,%s,%d,%s,%d,%f\n", ps->p.name, ps->p.sex, ps->p.height, ps->p.phone, ps->num, ps->f);//结构体指针->成员变量
//}
//
//int main()
//{
//	struct peo p1 = { "张三","male",180,"11111111" };//通常这样来创建p1这个变量,赋值完成初始化
//	//创建p1变量的过程可比作建起房子	这整个声明和使用的过程就是：类型 -> 变量 类 -> 对象 比作图纸 -> 房子
//	struct stu s = { {"Lily","female",175,"22222222"},15,100.0 };//含有嵌套结构体的结构体初始化
//	//注：浮点数在内存中不能精确保存
//	printf("%s,%s,%d,%s\n", p1.name, p1.sex, p1.height, p1.phone);
//	printf("%s,%s,%d,%s,%d,%f\n", s.p.name, s.p.sex, s.p.height, s.p.phone, s.num, s.f);
//
//	//函数形式
//	print1(p1);//将结构体对象直接传给函数可能造成空间和时间上的浪费
//	print2(&s);//结构体地址传参
//
//	return 0;
//}

//结构体特殊声明
//匿名声明  只能用一次，后面无法再次使用
//struct
//{
//	char name[20];
//	int age;
//}s1;
//
//struct
//{
//	char name[20];
//	int age;
//}arr[10],*p;
////尽管上面两个匿名声明的结构体类型的成员一样，但编译器不会将两者视为同一个结构体类型

//结构体的自引用
//链表
//一个节点存数据，另一个节点存指向下一个节点的指针
//struct Node
//{
//	int date;
//	struct Node* next;//一个相同结构体类型的指针
//};//这过程便是结构体的自引用
//
////错误形式：
//typedef struct
//{
//	int date;
//	Node* next;
//}Node;
////解决方案 ->
//typedef struct Node
//{
//	int date;
//	struct Node* next;
//}Node;
////这样之后
//struct Node n1;
//Node n2;//两种方式都可以
//
//常见链表形式
//typedef struct Node
//{
//	int date;
//	struct Node* next;
//}* linklist;
////与以下写法是一样的
//typedef struct Node
//{
//	int date;
//	struct Node* next;
//};
//typedef struct Node* linklist;

//结构体变量的定义与命名
//struct point
//{
//	int x;
//	int y;
//}p1 = { 2,3 };//声明类型的同时定义变量p1，并初始化

//结构体的内存对齐		用于计算结构体内存大小
//内对齐的计算
//偏移量：该内存位置离起始差几个字节(bite)
//对齐数：编译器默认的一个对齐数与该成员大小的最小值
//vs默认的对齐数是8,其他编译器可能没有默认对齐数
//第一个成员在结构体变量起始地址偏移量为0处，其他成员要对齐对齐数的整数倍的地址处开始分配内存空间，在此之前的地址
//无论是否被变量占用，都算进结构体变量的内存大小中
//结构体总大小为最大对齐数的整数倍
//如果嵌套了结构体，嵌套的结构体对齐到自己内部的最大对齐数的整数倍处，结构体的整体大小就是所有的最大对齐数(包括嵌套的结构体的对齐数)
//的整数倍 
// offsetof() 宏 能返回一个结构体成员的偏移量	需要头文件<stddef.h>
//struct s1
//{
//	char c1;//1 bite
//	char c2;//1
//	int i;//4
//};
//
//struct s2
//{
//	char c1;
//	int i;
//	char c2;
//};

//struct s3
//{
//	double i;
//	char c;
//	int k;
//};
//
//struct s4
//{
//	char c1;
//	struct s3;
//	double j;
//};
//
//int main()
//{
//	//printf("%d\n", sizeof(struct s1));//8
//	//printf("%d\n", sizeof(struct s2));//12
//
//	//printf("%d\n", offsetof(struct s2, c1));
//	//printf("%d\n", offsetof(struct s2, i));
//	//printf("%d\n", offsetof(struct s2, c2));
//
//	printf("%d\n", sizeof(struct s3));//16
//	printf("%d\n", sizeof(struct s4));//32
//
//	return 0;
//}
//
//为什么存在结构体内对齐
//1、某些硬件平台只能在某些地址处取某些特定的类型的数据类型，否则会硬件异常
//2、数据结构（尤其是栈）要尽可能在自然边界上对齐，使处理器访问内存只需一次
//3、总的来说结构体内对齐是用内存换时间的做法
//
//因此在设计结构体时，应让占用空间小的成员尽量集中在一起

//内对齐默认对齐数的修改   #pragma 预处理指令
//#pragma pack(4) //将默认对齐数改为4
//struct S
//{
//	int i;
//	double d;
//};
//#pragma pack() //将默认对齐数恢复为编译器初始的默认对齐数 8
//
//#pragma pack(1) //某种意义上实现了没有内对齐，虽节省空间但效率不高
//struct s1
//{
//	char a;
//	int j;
//	char b;
//};
//#pragma pack()
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));//12
//	printf("%d\n", sizeof(struct s1));//6
//	return 0;
//}

//结构体传参
//struct S
//{
//	int date[1000];
//	int num;
//};
//
//void print1(struct S s)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", s.date[i]);
//	}
//	printf("\n%d\n", s.num);
//}
//
//void print2(struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ps->date[i]);
//	}
//	printf("\n%d\n", ps->num);
//}
//
//int main()
//{
//	struct S s1 = { {1,2,3},100 };
//	print1(s1);//传值调用
//	print2(&s1);//传址调用
//	//为节省系统的空间和时间，提高效率，结构体传参尽可能使用传址调用
//	return 0;
//}

//写一个宏，计算结构体中某变量相对于首地址的偏移
//offsetof宏 的模拟实现
//
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//#define OFFSETOF(TYPE,M_NAME) ((size_t)&(((TYPE*)0)->M_NAME))
//
//int main()
//{
//	struct S s = { 0 };
//	printf("%zu\n", OFFSETOF(struct S, c1));
//	printf("%zu\n", OFFSETOF(struct S, i));
//	printf("%zu\n", OFFSETOF(struct S, c2));
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world\n" << endl;
//
//	return 0;
//}


//命名空间
//C中存在着在定义全局变量时如果变量名同某个库函数重名，运行时会报错的情况
//#include<stdio.h>
//#include<stdlib.h>
//
//int rand = 0;
//
//int main()
//{
//	
//	printf("%d\n", rand);
//	return 0;
//}
// 
//C++中命名空间得存在得以解决这个变量名命名的问题
//#include<stdio.h>
//#include<stdlib.h>
////命名空间中可以定义变量、函数、类型、甚至命名空间的嵌套定义，但命名空间只能定义在全局
//namespace cl
//{
//	int rand = 1;
//
//	int Add(int x, int y)
//	{
//		return (x + y);
//	}
//	
//	struct Node
//	{
//		int val;
//		struct Node* next;
//	};
//
//	namespace clt
//	{
//		int rand = 3;
//	}
//}
//
//int a = 1;
//
//int main()
//{
//	//编译器语法查找确认，默认先局部再全局，不会主动查找命名空间里的
//	//如果指定了作用域，就直接去该域里进行查找
//
//	int a = 0;
//	printf("%d\n", a);
//	//::域作用限定符
//	printf("%d\n", ::a);//全局
//
//	printf("%p\n", rand);
//	printf("%d\n", cl::rand);
//
//	//printf("%p\n", Add);//err
//	printf("%p\n", cl::Add);
//
//	/*struct Node s;*/
//	struct cl:: Node s;
//	printf("%d\n", cl::clt::rand);
//
//	return 0;
//}
//
//在多文件中定义同一个命名空间，系统会默认将它们合并来理解，因此命名空间能很好解决大型项目里不同文件命名冲突的情况


//输入输出流
//用于解决C语言单一的输入输出的问题
//#include<iostream>
//using namespace std;//展开命名空间
////::的建议在项目中使用，防止命名冲突；而展开命名空间可在平时写简易代码时使用
//
////部分展开
//using std::cout;
//using std::endl;
//
//int main()
//{
//	int i = 10;
//	i << 1;//<<在C++中和整型在一起时仍是移位操作符
//	double d = 1.1;
//
//	//当<< >>和cin cot这两个类在一起时，<<是流插⼊运算符，>>是流提取运算符
//	//流插⼊运算符就是将任何变量转换为字符串（窄字符），插入到流中；流提取运算符就是将变量转换为字符串来输出
//	std::cout << i<<"\n";
//	std::cout << "Hello World\n";
//	std::cout << i << " " << d<<std::endl;//endline C++中换行
//
//	std::cin >> i >> d;
//	std::cout << i << d << std::endl;
//
//	//展开命名空间后，就不用指明该命名空间了,但如果定义了重名的全局或局部变量就会出现命名冲突
//	/*int cout = 0;
//	cout << i << d << endl;*/
//
//	return 0;
//}


//缺省参数
//给函数一个默认参数（缺省值），如果没有给函数参数传值的话，函数就用缺省值
//#include<iostream>
//using namespace std;
//
//typedef struct SeqList
//{
//	int* data;
//	int size;
//	int capacity;
//}SL;
//
////注：函数声明和定义分离时，缺省参数不能在函数声明和定义中同时出现，规定必须函数声明给缺省值
////以顺序表为例，在知道具体要多大的范围数据后，利用缺省值直接初始化顺序表大小，可避免后面多次扩容带来的性能损耗
//void SeqListInit(SL* pl, int n = 4);
//
//int SLFind(SL* pl, int i = 5)//因该函数只能从左往右找，因此每次只能找到第一个所找的数，但要第n个的数时，可用缺省值，从缺省位置开始找
//{
//	//……
//}
//
//void fun(int a = 0)
//{
//	cout << "a = "<<a << endl;
//}
//
////全缺省
//void fun1(int a = 1, int b = 2, int c = 3)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << a << endl;
//	cout << "c = " << a << endl;
//}
//
////半缺省
//void fun2(int a, int b, int c = 3)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << a << endl;
//	cout << "c = " << a << endl;
//}
////但缺省值间要从左往右来放
////void fun3(int a =1, int b, int c=3)
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << a << endl;
////	cout << "c = " << a << endl;
////}
////也不能前面用着缺省，后面就不用了
////void fun4(int a=1, int b=2, int c)
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << a << endl;
////	cout << "c = " << a << endl;
////}
////因此如果有用缺省值的需要，就将缺省参数放在函数参数的后面
////
//int main()
//{
//	fun();
//	fun(1);
//
//	//可全缺省，也可以部分缺省
//	fun1();
//	fun1(1,2);
//	
//	/*fun1(1, , 3);*///但不能中间空出来用缺省值
//	SL list;
//	SeqListInit(&list);
//
//	return 0;
//}
//
//void SeqListInit(SL* pl, int n)
//{
//	//……
//}


//函数重载
//c++中在同一作用域里可用同名函数，但要求参数不同
//#include<iostream>
//using namespace std;
//
//int Add(int x, int y)
//{
//	return (x + y);
//}
//
//double Add(double x, double y)
//{
//	return (x + y);
//}
//
//void Add(int x, int y,int* z)
//{
//	*z = (x+y);
//}
//
//char Add(char x, int y)
//{
//	return (x + y);
//}
//
//char Add(int y,char x )
//{
//	return (x + y);
//}
//
////返回类型不同不能构成函数重载，因返回值不同的话，无法确定函数具体是哪一个
////char Add(int x, int y)
////{
////	return (x + y);
////}
//
//int Add()
//{
//	//
//	return;
//}
////与最开始的int Add构成函数重载，但是存在着是调用无参的Add还是缺省参数的Add，因此存在对重载函数调用不明确的问题
//
//
//int main()
//{
//	cout << Add(1, 1) << endl;
//	cout << Add(1.1, 2.1) << endl;
//	//这样实现表面上一个函数使用了不同类型的参数
//	return 0;
//}


//引用 
//给已存在的变量取别名，同一变量的不同别名指向的都是同一内存空间
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int i = 0;
//	cout << &i << endl;//此处&是取地址的作用
//
//	//引用
//	//类型&  引⽤别名 = 引⽤对象;
//	int& j = i;//引用必须要初始化
//
//	cout << &j << endl;//取地址
//	j++;
//	cout << j << endl;
//
//	int& k = j;
//	//引⽤⼀旦引⽤⼀个实体，再不能引⽤其他实体
//	/*int m = 0;
//	int& k = m;*///err
//
//	return 0;
//}

//引用是在大部分场景替代指针，但不能完全取代
//#include<iostream>
//using namespace std;
//
//typedef struct SLTNode
//{
//	int val;
//	struct STNode* next;
//}SLTNode,*pSLTNode;
////这样的写法等价于下面这样写
//typedef struct SLTNode SLTNode;
//typedef struct SLTNode* pSLTNode;
//
//void STLPush(pSLTNode& plist, int x)
//{
//	//……
//}
//
////传址调用
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap1(int**x, int**y)
//{
//	//……
//}
//
//void Swap2(int*& x, int*& y)//也可以对指针的指针进行重名
//{
//	//……
//}
//
//int main()
//{
//	int x = 1, y = 3;
//	cout << "x = " << x << " y = " << y << endl;
//	Swap(x, y);
//	cout << "x = " << x << " y = " << y << endl;
//	/*int* px = &x, * py = &y;
//	Swap1(&px, &py);*/
//
//
//	return 0;
//}

//引用虽然好用，但在链表、数结点定义位置只能使用指针
//原因是C++的引用无法改变指向，结点一定存在着改变指向的场景，所以这里无法用引用
//
//#include<iostream>
//using namespace std;
//
//int fun()
//{
//	int ret = 0;
//	return ret;
//}
////传值返回和形参的思路差不多一样都是进行临时拷贝的方式
////当数据比较小用一个寄存器来存该返回值，如果比较大则会开辟下一层栈空间。
//
//int& fun1()
//{
//	int ret = 0;
//	return ret;
//}
////传引用返回，返回了存储ret值临时变量的别名
////这样的返回方式存在危险，因临时变量已经销毁，用别名访问属于越界访问
////越界访问编译器不一定报错
////对于使用数组是否越界，主要采取抽查法，每个数组末尾都存在着类似于标志位的数据，如果越界这数据必然被改变，所以只用抽查后面这块空间
//
//int& fun2()
//{
//	int y = 123;
//	return y;
//}
//
//int& fun3()
//{
//	static int ret = 1;
//	return ret;
//}
//
//int main()
//{
//	//int a = fun();
//	//cout << a << endl;
//	//int a = fun1();
//	//cout << a << endl;
//	//int& x = fun1();
//	//cout << x << endl;
//	//fun2();
//	//cout << x << endl;
//	//为什么两次结果相同，因为fun2是在fun1销毁后在同一内存栈空间上建立的，别名指向的是同一内存空间
//	//以上为别名返回的错误写法
//
//	//int b = fun3();
//	//cout << b << endl;
//	//这才是正确写法
//
//	//如果函数表达式返回的是别名，还可以通过该别名改变其指向的值
//
//	//语法引用不需要开辟空间，而指针需要，但二者在汇编里是一样的，引用底层是用指针实现的
//	int a = 0;
//	int& b = a;
//	int* pa = &a;
//
//	b++;
//	(*pa)++;
//
//	return 0;
//}

//const引用
//#include<iostream>
//using namespace std;
//
////如果不存在要改变引用对象的值，建议用const引用，以防出现权限放大的情况
//void fun1(const int& x)
//{
//	//
//}
//
//void fun2(int& x)
//{
//	//
//}
//
//int main()
//{
//	const int a = 0;
//	//权限放大
//	//const int a 本身无法改变，而试图用引用的int& b来改变a的值是引用权限放大的情况，是不被允许的
//	//int& b = a;
//	const int b = a;
//
//	//这不是权限放大，只是个赋值拷贝
//	int e = a;
//
//	//权限缩小
//	int c = 0;
//	const int& d = c;
//
//	//权限的缩小和放大只存在于const 指针和引用里
//
//	int f = 1;
//	fun1(f);
//	const int z = 1;
//	fun1(z);
//
//	//fun2(f);
//	//fun2(z);//出现了权限放大的问题
//
//	return 0;
//}
//
//void fun(const int& pi)//可见const引用更多用于传参
//{
//	;
//}
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int i = 0;
//	double d = i;//在类型转换的情况下
//	
//	int p = (int)&i;
//
//	//double& rd = i;//一般的引用却不能这样使用
//	const double& rd = i;//const引用却可以
//
//	//int& pi = (int)&i;
//	const int& pi = (int)&i;
//
//	double a = 2.2;
//	fun(a);
//
//	return 0;
//}
//
//引用与指针的关系
//引用只是取别名不会额外开辟空间，而指针要开辟新的空间
//引⽤在定义时必须初始化，指针建议初始化，但是语法上不是必须的。
//引⽤在初始化时引⽤⼀个对象后，就不能再引⽤其他对象；⽽指针可以在不断地改变指向对象。
//引⽤可以直接访问指向对象，指针需要解引⽤才是访问指向对象。
//sizeof中含义不同，引⽤结果为引⽤类型的⼤⼩，但指针始终是地址空间所占字节个数(32位平台下占4个字节，64位下是8byte)
//指针很容易出现空指针和野指针的问题，引⽤很少出现，引⽤使⽤起来相对更安全⼀些
//不存在指向空值的引用，但是存在指向空值的指针


//对于宏可能易犯的问题，c++建议用const enum inline替代宏
//要注意宏发挥的作用其实是种替换，宏也不适合调控
//#include<iostream>
//using namespace std;
//
////默认debug版本下，inline不展开，是为了方便调试，在release才展开
//inline int Add(int x, int y)//inline修饰的函数为内敛函数
//{
//	return (x + y);
//}
//
//int main()
//{
//	int x = 0, y = 0;
//	cin >> x >> y;
//	int z = Add(x + y, x - y);
//	cout << z << endl;
//
//	return 0;
//}
//
//编译器会根据inline 修饰的内联函数的代码量来决定是否进行展开，inline对于编译器而言就是一个建议
//如果内联函数无限制展开，会导致代码膨胀，是可行性程序变得庞大。
//inline不建议声明和定义分离到两个⽂件，分离会导致链接错误


//nullptr
//NULL宏定义在cpp中的尴尬
//#ifndef NULL
//	#ifdef __cplusplus
//		#define NULL 0
//	#else
//		#define NULL ((void *)0)
//	#endif
//#endif
//
//而nullptr是⼀个特殊的关键字，nullptr是⼀种特殊类型的字⾯量，它可以转换成任意其他类型的指针类型，
//且nullptr只能被隐式地转换为指针类型，⽽不能被转换为整数类型。
//#include<iostream>
//using namespace std;
//
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(NULL);
//
//	f((int*)NULL);
//
//	f(nullptr);
//
//	return 0;
//}
//内存分布
//#include<iostream>
//using namespace std;
//
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
////选项: A.栈 B.堆 C.数据段(静态区) D.代码段(常量区)
//// globalVar在哪里？			C
//// staticGlobalVar在哪里？		C
//// staticVar在哪里？			C
//// localVar在哪里？				A 这些变量是在test的函数里，所以其内存是该函数的栈帧内
//// num1 在哪里？				A
//// char2在哪里？				A  
//// *char2在哪里？				A
//// pChar3在哪里？				A
//// *pChar3在哪里？				D
//// ptr1在哪里？					A
//// *ptr1在哪里？				B
//
//int main()
//{
//	test();
//
//	return 0;
//}


// c/c++内存管理方式
//#include<iostream>
//using namespace std;
//
////c 的malloc、realloc、calloc、free
//void test1()
//{
//	// malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？
//	// 对于realloc原地扩容的情况下 p3和p2指向同一块空间；异地扩容的情况下，p2只是一个野指针
//	free(p3);
//	p2 = p3 = nullptr;
//}
//
//void test2()
//{
//	//管理对象
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);// 这里()作用是初始化
//	
//	//管理对象数组
//	int* ptr6 = new int[3];// 这里[]里是对象的个数
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
//
//class A
//{
//public:
//	A(int a = 0)
//	: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	test1();
//	test2();
//
//	
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
// 
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
// 
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//
//	return 0;
//}
// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数


//operator new与operator delete函数 (!!!)
//平时用的new、delete是动态内存管理的操作符，而operator new与operator delete是全局函数
//new和delete的使用会调用operator new与operator delete这两个函数，
//而operator new与operator delete其底层也是调用malloc这个函数和free宏函数


//new和delete的实现原理
//内置类型
//与malloc、free相识
// 
//new/delete申请和释放的是单个元素的空间，new[]和delete[]申请的是连续空间
// 
//malloc申请失败返回的是空指针
//new申请失败会抛异常
//#include<iostream>
//using namespace std;
//void func()
//{
//	int i = 1;
//	int* ptr = nullptr;
//	do {
//		if (i == 495)
//		{
//			int x = 0;
//		}
//
//		ptr = new int[1024 * 1024];
//		cout << i++ << ":" << ptr << endl;
//	} while (ptr);
//
//	cout << i++ << ":" << ptr << endl;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}
//
//自定义类型
//new先调用operator new申请内存空间，再在已申请的空间上调用构造函数
//delete先调用析构函数，再调用operator delete释放空间
//new[]与delete[]则和前面一样但会在调用构造函数和析构函数那调用多次
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//A* p3= (A*)operator new(sizeof(A));
//	A* p1 = new A(1);
//	delete p1;
//
//	//在反汇编里我们发现在A有析构函数的时候申请的空间要比A没有析构函数时申请的多4个字节
//	//是因为在有显示析构函数下，多申请4个字节是用来存放进行析构函数的次数的
//	A* p2 = new A[10];
//	delete[] p2;
//
//	return 0;
//}
//
//class A
//{
//public:
//	A(int a)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = new A(1);
//
//	A* ptr = (A*)operator new(sizeof(A));
//	// 显示调用构造函数
//  //用operator new的话申请的同时进行初始化，必须要按照下面的方式来写
//	new(ptr)A(1);
//
//	ptr->~A();
//	operator delete(ptr);
//
//	return 0;
//}


//定位new表达式(placement-new) 
//
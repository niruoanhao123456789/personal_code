//类的定义
//#include<iostream>
//cpp面向对象三大特性：封装、继承、多态
//封装 体现的是更严格的管理
//c是将方法和数据分开的
//cpp则将数据与方法放在一起
// 
// 类中的变量称为类的属性或成员变量;   类中的函数称为类的⽅法或者成员函数
// 为了区分成员变量，⼀般习惯上成员变量会加⼀个特殊标识，如前面或者后面加_等等，在C++中这个并不是强制的
// 
// 访问限定符
// public	private   protected
//public修饰的成员在类外可以直接被访问；protected和private修饰的成员在类外不能直接被访问
//访问权限作⽤域从该访问限定符出现的位置开始直到下⼀个访问限定符出现时为⽌，如果后⾯没有访问限定符，作⽤域就到 }即类结束
//class定义成员没有被访问限定符修饰时默认为private，struct默认为public
//一般成员变量都会被限制为private/protected，需要给别⼈使⽤的成员函数会放为public
//class stack
//{
//public:
//	void Push(int x)
//	{
//		;
//	}
//	void Init()
//	{
//		;
//	}
//	//类与结构体不同在与其内部可定义函数的定义，且只适用该类
//	//定义在类面的成员函数默认为inline
//
//	//
//private:
//	int _top;
//	int _capapcity;
//	int* _arr;
//};
//
////兼容c struct的同时将struct升级为了类
//struct test
//{
//	void fun()
//	{
//
//	}
//	int a;
//};
//
//struct ListNode
//{
//	int val;
//	//struct ListNode* next;
//	//因类名就是类型，所以可以不用c的那种写法
//	ListNode* next;
//};
//
//int main()
//{
//	stack s1;//其中s1为对象
//	//在cpp里类名就是类型，不用像c里要struct加结构体名或者用typedef
//
//	s1.Push(1);
//
//	return 0;
//}

//类域
//类定义了⼀个新的作⽤域，类的所有成员都在类的作⽤域中，在类体外定义成员时需要使⽤ :: 作⽤域操作符指明成员属于哪个类域
//在不同类的类域里，同名函数得以实现如stack::push(),list::push()
//类域影响的是编译的查找规则
//#include<iostream>
//using namespace std;
//
//class Stack
//{
//public:
//	// 成员函数
//	void Init(int n = 4);
//private:
//	// 成员变量
//	int* array;
//	size_t capacity;
//	size_t top;
//	//以上成员变量都是在类里被声明
//};
//
//// 声明和定义分离，需要指定类域
//void Stack::Init(int n)
//{
//	array = (int*)malloc(sizeof(int) * n);
//	if (nullptr == array)
//	{
//		perror("malloc申请空间失败");
//		return;
//	} 
//
//	capacity = n;
//	top = 0;
//}
//
//int main()
//{
//	Stack s1;//这样定义，成员变量才被分配内存空间，及实例化对象
//
//	s1.Init(10);
//
//	//cpp里实例化的对象也要遵循内对齐的规则
//	cout << sizeof(Stack) << endl;
//	cout << sizeof(s1) << endl;
//
//	return 0;
//}


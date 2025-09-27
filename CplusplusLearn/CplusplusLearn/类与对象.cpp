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

//对象的大小
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	void print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;
//	int i;
//};
//
//class B
//{
//public:
//	void Print()
//	{
//
//	}
//};
//
//class C
//{
//
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	//开1byte是为了占位，表示对象存在过
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//
//	B b1;
//	C c1;
//
//	return 0;
//}

//this指针
//this指针是存在于内存的栈区
//在类的函数里隐藏着一个this指针，用于操作同一个类的不同变量
//#include<iostream>
//using namespace std;
//
//class Data
//{
//public:
//	//相当于
//	//void  Init(Data* const this, int year, int month,int day)
//	//但不允许写函数写成上面的形式
//	void  Init(int year, int month,int day)
//	{
//		_year = year;
//		_month = month;
//		this->_day = day;//但可用this指针来对成员进行操作
//	}
//	//C++规定不能在实参和形参的位置显⽰的写this指针(编译时编译器会处理)，但是可以在函数体内显⽰使⽤this指针
//
//	void Print()
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d1;
//	Data d2;
//
//	//d1.Init(&d1,1, 2, 3);
//	d1.Init(1, 2, 3);
//	d1.Print();
//	d2.Init(3, 4, 5);
//	d2.Print();
//
//	return 0;
//}
//
//class A
//{
//public:
//	//void Print(A* this)
//	void Print()
//	{
//		//这里this = nullptr但并未对其进行解引用，所代码是能正常运行的
//		cout << "hello world" << endl;
//		cout << this << endl;
//	}
//};
//
//class B
//{
//public:
//	void Print()
//	{
//		cout << "hehe" << endl;
//		cout << _a << endl;//这里运行错误的原因是cout << this->_a << endl;对this进行了解引用
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//
//	//p->Print(&p);
//	p->Print();
//	//该代码看上去是对空指针进行解引用，实则并不是
//	//因为函数的地址并不是存在类里，在汇编里调用函数的指令为call 函数地址
//	(*p).Print();
//
//	//下面代码就会运行错误
//	B* p1 = nullptr;
//	p1->Print();
//
//	return 0;
//}

//C语言是面向过程的语言，而C++是面向对象的

//类的默认成员函数
//默认成员函数就是⽤户没有显式实现，编译器会⾃动⽣成的成员函数称为默认成员函数
//
//构造函数
//构造函数主要任务对象实例化时初始化对象，而不是开辟空间创建对象
//构造函数特点： 
// 1、函数名与类名相同
// 2、无返回值
// 3、对象实例化时系统会⾃动调⽤对应的构造函数
// 4、可以函数重载
// 5、如果类中没有显式定义构造函数，则C++编译器会⾃动⽣成⼀个⽆参的默认构造函数
// 6、⽆参构造函数、全缺省构造函数、我们不写构造时编译器默认⽣成的构造函数，都叫做默认构造函数。
//	  且不传实参就可以调⽤的构造就叫默认构造
//#include<iostream>
//using namespace std;
//
//class Data
//{
//public:
//	//无参构造函数
//	/*Data()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}*/
//
//	//全缺省构造函数
//	//Data(int year = 1, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	//可见全缺省构造函数和无参构造函数作用是一样的，因此两者不能共存
//
//	//将上面代码都注释掉后就是不写构造时编译器默认⽣成的构造函数
//	//在c++中编译器默认生成的构造函数对内置类型成员变量的初始化没有要求，具体取决于编译器的不同
//	void Print()
//	{
//		cout << _year << ' ' << _month << ' ' << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//调用无参的构造函数不能这样写，编译器会误认为这个是函数的声明
//	//Data d1();
//	Data d1;
//
//	d1.Print();
//
//
//	return 0;
//}
//
//class Stack
//{
//public:
//	//如果这里没有默认构造，下面的队列类就会报错
//	Stack()
//	{
//		_arr = nullptr;
//		_top = 0;
//		_capacity = 0;
//	}
//private:
//	int* _arr;
//	int _top;
//	int _capacity;
//};
//
//class Queue
//{
//public:
//	
//private:
//	Stack _Pushst;
//	Stack _Popst;
//	//上面的内置类型因前面的默认构造有初始化，而下面的没有
//	int _size;
//};
//
//int main()
//{
//	Queue q1;
//}


//析构函数
//析构函数与构造函数功能相反,但不是完成对对象本⾝的销毁。
//C++规定对象在销毁时会⾃动调⽤析构函数，完成对象中资源的清理释放⼯作
//析构函数特点：
//1、析构函数名是在类名前加上字符 ~。  
//2、⽆参数⽆返回值。(这⾥跟构造类似，也不需要加void)
//3、⼀个类只能有⼀个析构函数。若未显式定义，系统会⾃动⽣成默认的析构函数
//4、对象⽣命周期结束时，系统会⾃动调⽤析构函数
//5、无论我们是否显示地写析构函数，自定义类型都会自动调用他的析构函数
//6、如果类中没有申请资源时，析构函数可以不写，直接使⽤编译器⽣成的默认析构函数；
// 但是有资源申请时，⼀定要⾃⼰写析构，否则会造成资源泄漏，因为编译器默认析构函数无法处理这些复杂地资源释放
//#include<iostream>
//using namespace std;
//
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		int* tmp = (int*)malloc(sizeof(int) * n);
//		if (tmp)
//		{
//			_arr = tmp;
//		}
//		else
//		{
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = n;
//
//	}
//
//	~Stack()
//	{
//		free(_arr);
//		_arr = nullptr;
//		_top = 0;
//		_capacity = 0;
//		cout << "~Stack()" << endl;
//	}
//private:
//	int* _arr;
//	int _top;
//	int _capacity;
//};
//
//class Queue
//{
//public:
//	~Queue()
//	{
//		cout << "~Queue" << endl;
//	}
//private:
//	Stack Pushst;
//	Stack Popst;
//};
//
//int main()
//{
//	Stack st;
//	Queue q1;
//
//	return 0;
//}
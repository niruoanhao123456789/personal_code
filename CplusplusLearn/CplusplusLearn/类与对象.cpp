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


//复制/拷贝构造函数
//如果⼀个构造函数的第⼀个参数是⾃⾝类类型的引⽤，且任何额外的参数都有默认值，则此构造函数也叫做拷⻉构造函数
//拷贝构造函数的特点：
// 1、拷⻉构造函数是构造函数的⼀个重载
// 2、拷⻉构造函数也可以多个参数，但是第⼀个参数必须是类类型对象的引⽤，后⾯的参数必须有缺省值。
//	  如果第一个参数使⽤传值⽅式编译器直接报错，因为语法逻辑上会引发⽆穷递归调⽤
// 3、C++规定⾃定义类型对象进⾏拷⻉⾏为必须调⽤拷⻉构造，所以这⾥⾃定义类型传值传参和传值返回都会调⽤拷⻉构造完成
//
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1,int month = 1,int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//这部分便是拷贝构造函数的代码
//	//用const引用是因为要拷贝的d不用改变，且避免跟const引用里权限放大的问题
//	//这里如果使用指针的话就是单纯的拷贝，而不是拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////对应特点3
////在给fun的d传参时，会先调用拷贝构造将值拷贝给参数d
//void fun(Date d)
//{
//	d.Print();
//}
//
//int main()
//{
//	Date d1(2025,9,27);
//	//拷贝构造
//	Date d2(d1);
//	d2.Print();
//	//这样也是拷贝构造
//	Date d3 = d1;
//
//	fun(d1);
//
//	return 0;
//}
//
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	} 
//
//	//浅拷贝
//	//Stack(const Stack& st)
//	//{
//	//	_a = st._a;
//	//	_top = st._top;
//	//	_capacity = st._capacity;
//	//}
//
//	//深拷贝
//	Stack(const Stack& st)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//class MyQueue
//{
//public:
//private:
//	Stack pushst;
//	Stack popst;
//};
//
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	//Stack不显⽰实现拷⻉构造，⽤⾃动⽣成的拷⻉构造完成浅拷⻉
//	//浅拷贝或值拷贝存在着以下的问题
//	//1、一个值的修改会影响另一个值
//	//多层的拷贝构造中会存在某次过程中将要拷贝的数值改变了，导致后面的拷贝出现问题
//	//2、析构时会对同一块空间释放多次。
//
//	//为了解决上面的问题，一种方法是深拷贝
//	//深拷贝不仅对成员拷贝，还要对指向的资源空间进行处理
//
//	return 0;
//}


//运算符重载
//当运算符被⽤于类类型的对象时，C++语⾔允许我们通过运算符重载的形式指定新的含义
//且类类型对象使⽤运算符时，必须转换成调⽤对应运算符重载，若没有对应的运算符重载，则会编译报错
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//
//	//int Get_year(const Date& x)//但这种解决方式会进行拷贝构造
//	//{
//	//	return x._year;
//	//}
//
//	//下面报错的原因是因为重载运算符函数的参数个数和该运算符作⽤的运算对象数量⼀样多，而类里的内置函数包含着隐藏的this指针
//	//bool operator==(const Date& x1, const Date& x2)
//	//{
//	//	return (x1._year == x2._year && x1._month == x2._month && x1._day == x2._day);
//	//}
//
//	bool operator==(const Date& d)
//	{
//		return (this->_year == d._year && this->_month == d._month && this->_day == d._day);
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
////private:
//};
//
////运算符重载是具有特殊名字的函数,它的名字是由operator和后⾯要定义的运算符共同构成
////和其他函数⼀样，它也具有其返回类型和参数列表以及函数体
//int operator-(const Date& x1, const Date& x2)
//{
//	return 0;
//}
//
////bool operator==(const Date& x1, const Date& x2)
////{
////	//return (x1._year == x2._year && x1._month == x2._month && x1._day == x2._day);
////	//这里在运算符重载要调用类里的成员函数就要迫使将类里的成员函数所在域改为public
////	//解决办法一：在类里定义一个获取值的函数
////	
////	//方法二：在类里定义运算符重载
////}
//
//int main()
//{
//	Date d1(2025,10,1);
//	Date d2(2025, 9, 30);
//	//⼆元运算符有两个参数，⼆元运算符的左侧运算对象传给第⼀个参数，右侧运算对象传给第⼆个参数
//	cout << (d1 == d2) << endl;
//	d1.operator==(d2);
//
//	return 0;
//}
//
//运算符重载以后，其优先级和结合性与对应的内置类型运算符保持⼀致。
//不能通过连接语法中没有的符号来创建新的操作符
//注意： .*   ::   sizeof	?:(三目操作符)	 . 这五个操作符是不能进行重载的，面试题中常考
//.*是cpp中的操作符
//重载操作符⾄少有⼀个类类型参数
//void fun1()
//{
//	cout << "void fun1()" << endl;
//}
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "A::fun()" << endl;
//	}
//};
//
//A operator+(const A& a, int b)
//{
//
//}
//
//int main()
//{
//	//普通指针函数的使用
//	void(*pf1)() = fun1;
//	(*pf1)();
//
//	//A类型的成员函数指针
//	void(A:: * pf2)() = &A::fun;//虽然函数名就是该函数地址，但语法规定里加&来区分成员函数的指针
//	//默认搜索会在全局和局部，不会主动到类域搜索
//	//类的成员函数和普通函数不同在于，成员函数并非无参，其有隐藏的this指针。所以得指明*pf2是A类域的函数指针
//	A aa;
//	(aa.*pf2)();
//
//	return 0;
//}


//赋值重载
//赋值运算符重载是⼀个默认成员函数，⽤于完成两个已经存在的对象直接的拷⻉赋值
//与拷贝构造不同的是，拷⻉构造是⽤于⼀个对象拷⻉初始化给另⼀个要创建的对象
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)//这里&是取地址的意思
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		return *this;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day<<endl;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2025, 8, 1);
//
//	//拷贝构造
//	Date d2(d1);
//	Date d3 = d1;
//
//	//运算符重载
//	Date d4(2025, 10, 1);
//	d1 = d4;
//	d1.Print();
//
//	d1 = d4 = d3;
//	d1.Print();
//	d4.Print();
//
//	return 0;
//}

//
//#include"Date.h"
//
//int main()
//{
//	//Date d1(2025, 8, 1);
//	//Date d2 = d1 += 100;
//	//d1.Print();
//	//d2.Print();
//
//	//Date d3(2025, 8, 1);
//	//Date d4 = d3 + 100;
//	//d3.Print();
//	//d4.Print();
//
//	//Date d1(2025, 8, 1);
//	//Date ret1 = d1++;
//	//// Date ret1 = d1.operator++(10); // 显示调用，实参只要是整形就可以
//
//	//ret1.Print();
//	//d1.Print();
//
//	//Date d2(2025, 8, 1);
//	//Date ret2 = ++d2;
//	////Date ret2 = d2.operator++();
//	//ret2.Print();
//	//d2.Print();
//
//	//Date d5 = d1 -= 4;
//	//Date d5 = d1--;
//	//d5.Print();
//
//	//Date d1(2025, 10, 10);
//	//Date d2(2023, 1, 1);
//	//cout << (d1 - d2) << endl;
//
//	testDate1();
//
//	return 0;
//}
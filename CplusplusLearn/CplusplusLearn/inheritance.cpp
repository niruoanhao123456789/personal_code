#include<iostream>
#include<vector>
using namespace std;

// 继承(inheritance)机制是⾯向对象程序设计使代码可以复⽤的最重要的⼿段
// 基类private成员在派⽣类中⽆论以什么⽅式继承都是不可⻅的
// 而基类protected成员在派生类中以非private方式继承，在派生类中能被访问，在类外不能。
// 基类的其他成员在派⽣类的访问⽅式 == Min(成员在基类的访问限定符，继承⽅式)，public > protected >private。
// 使⽤关键字class时默认的继承⽅式是private，使⽤struct时默认的继承⽅式是public，不过最好显⽰的写出继承⽅式
// 在实际运⽤中⼀般使⽤都是public继承

//class Person
//{
//public:
//	void indentity()
//	{
//		cout << "indentity()" << endl;
//	}
//
//	void func()
//	{
//		cout << _age << endl;
//	}
//	
//protected:
//	string _name ="AA";
//	string _address;
//	string _tel;
//private:
//	int _age = 18;
//};
//
//class student :public Person
//{
//public:
//	void study()
//	{
//		
//		// 基类私有成员，在派生类中不可见，语法上限制不能直接使用
//		// cout << _age << endl;
//
//		// 但是可以间接使用
//		func();
//	}
//
//protected:
//	string _stuID;
//};
//
//class teacher :public Person
//{
//public:
//	void teach()
//	{
//		;
//	}
//
//protected:
//	string _title;
//};
//
//namespace bit
//{
//	template<class T>
//	class stack : public vector<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			// 但是模版是按需实例化，调用了哪个成员函数，就实例化哪个
//			// push_back等成员函数未实例化，所以找不到
//			//push_back(x);
//			
//			vector<T>::push_back(x);
//		}
//
//		void pop()
//		{
//			vector<T>::pop_back();
//		}
//
//		const T& top()
//		{
//			return vector<T>::back();
//		}
//
//		bool empty()
//		{
//			return vector<T>::empty();
//		}
//	};
//}

//int main()
//{
//	//student s;
//	//s.func();
//
//	//bit::stack<int> st;
//	//st.push(1);
//	//st.push(2);
//	//st.push(3);
//	//while (!st.empty())
//	//{
//	//	cout << st.top() << " ";
//	//	st.pop();
//	//}
//
//	// 模版是按需实例化，调用了哪个成员函数，就实例化哪个
//	// 构造/析构/push_back， 其他成员函数就不会实例化
//  // 在构造的过程中要把基类视为一个整体
//	//vector<int> v;
//	//v.push_back(1);
//
//	return 0;
//}

//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	// 类型间进行隐式类型转换，在这过程中间会创建一个临时变量
//	//int i -> double i -> double d
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//	string s1 = "11111";
//	const string& rs = "11111";
//
//	// public继承的派⽣类对象 可以赋值给 基类的指针 / 基类的引⽤
//	// 基类指针或引⽤指向的是派⽣类中切出来的基类那部分
//	// 基类对象不能赋值给派⽣类对象
//	Student s;
//	Person p = s;
//	// 特殊处理
//	Person& rp = s;
//	Person* ptr = &s;
//
//	// 不支持
//	//s = (Student)p;
//
//
//	return 0;
//}

// 隐藏规则：
// 1、在继承体系中基类和派⽣类都有独⽴的作⽤域。  
// 2、派⽣类和基类中有同名成员，派⽣类成员将屏蔽基类对同名成员的直接访问，这种情况叫隐藏。
//   （在派⽣类成员函数中，可以使⽤ 基类::基类成员 显⽰访问）
// 3、需要注意的是如果是成员函数的隐藏，只需要函数名相同就构成隐藏
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _num << endl;			// 优先检索当前域内的成员变量不会去检索基类里的，构成隐藏
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	B b;
//	b.fun(10);
//	b.A::fun();
//
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//// 涉及到构造与析构：
//// 1、我们不写，默认生成的函数行为是什么？是否符合需求
//// 2、不符合，我们要自己实现，如何实现？（尤其深浅拷贝的问题）
//class Student : public Person
//{
//public:
//	// 派⽣类的构造函数必须调⽤基类的构造函数初始化基类的那⼀部分成员。如果基类没有默认的构造
//	// 函数，则必须在派⽣类构造函数的初始化列表阶段显⽰调⽤
//	//
//	Student(const char* name = "张三", int num = 18, const char* address = "西安")
//		:Person(name)
//		, _num(num)
//		, _address(address)
//	{
//		cout << "Student()" << endl;
//	}
//
//	//Student(const Student& s)
//	//	:Person(s)
//	//	,_num(s._num)
//	//	,_address(s._address)
//	//{
//	//	// 涉及深拷贝，需要自己实现
//	//}
//
//	//Student& operator=(const Student& s)
//	//{
//	//	if(this != &s)
//	//	{
//	//		Person::operator=(s);
//	//		_num = s._num;
//	//		_address = s._address;
//	//	}
//
//	//	return *this;
//	//	// 涉及深拷贝，需要自己实现
//	//}
//
//	//~Student()
//	//{
//	//	// 不用显示调用基类析构，编译器会在派生类析构结束后自动调用析构
//	//	// Person::~Person();
//	//	//...
//	//	cout << "~Student()" << endl;
//	//}
//
//protected:
//	int _num;		 // 学号
//	string _address; // 地址
//	// int* _ptr;
//};
//
//// 构造
//// 继承的基类成员变量(整体对象) + 自己的成员变量(遵循普通的规则，跟类和对象部分一样)
//// 默认生成的构造，派生类自己的成员，内置类型不确定，自定义类型调用默认构造，基类部分调用默认构造
//
//// 本质可以把派生类当做多了一个自定义类型成员变量(基类)的普通类总，跟普通类原则基本一样
//
//// 派生类一般要自己实现构造，不需要显示写析构、拷贝构造，赋值重载，除非派生类有深拷贝的资源需要处理
//
////构造的顺序是先基类后派生类，而析构的顺序是派生类再基类
//
//int main()
//{
//	Student s1;
//	//Student s2("小明", 10);
//	//Student s3(s2);
//
//	//s1 = s3;
//
//	//Person p = s1;
//
//
//	return 0;
//}
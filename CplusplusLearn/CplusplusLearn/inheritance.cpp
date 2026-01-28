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


//继承与友元
//友元关系不能被继承
//class Student;
//
//class Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//
//class Student
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	// 编译报错：error C2248: “Student::_stuNum”: 无法访问 protected 成员
//	// 解决方案：Display也变成Student 的友元即可
//	Display(p, s);
//
//	return 0;
//}


//继承与静态成员
//class Person
//{
//public:
//	string _name;
//	static int _count;
//};
//
//// 在内存中全局变量与静态变量会存储在静态区中，父类与子类在这一快共用同一块内存空间，因此显示这两空间是一样的地址
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	// 这里的运行结果可以看到非静态成员_name的地址是不一样的
//	// 说明派生类继承下来了，父派生类对象各有一份
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//
//	// 这里的运行结果可以看到静态成员_count的地址是一样的
//	// 说明派生类和基类共用同一份静态成员
//	cout << &p._count << endl;
//	cout << &s._count << endl;
//
//	// 公有的情况下，父派生类指定类域都可以访问静态成员
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//
//	return 0;
//}


// 多继承、菱形继承
// 在io库中会有使用菱形继承的情况
// 菱形继承会带来数据冗余和⼆义性的问题
// 
// 下面菱形继承例子中Student、Teacher都继承了Person，虽然是同一个person但内存却开了两个Person,即数据冗余
// 编译报错：error C2385: 对“_name”的访问不明确，访问内存中的Person中的_name，是Student里的还是Teacher里的？⼆义性
// 
// 解决方式：虚继承
// 
//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{}
//
//public:
//	string _name; // 姓名
//	/*int _age;
//	int _tel;
//	string _address;*/
//};

//// 菱形继承要在“腰部”的继承方式加virtual，虚继承
//class Student : public Person
//class Student : virtual public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{}
//protected:
//	int _num; //学号
//};
//
////class Teacher : public Person
//class Teacher : virtual public Person
//{
//public:
//	Teacher(const char* name, int id)
//		:Person(name)
//		, _id(id)
//	{}
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//public:
//	Assistant(const char* name1, const char* name2, const char* name3)
//		:Person(name1)
//		,Student(name2, 1)
//		,Teacher(name3, 2)
//		, _majorCourse("计算机")
//	{}
//
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 思考一下这里a对象中_name是"张三", "李四", "王五"中的哪一个？
//	Assistant a("张三", "李四", "王五");
//
//	// 编译报错：error C2385: 对“_name”的访问不明确
//	//Assistant a;
//	//a._name = "peter";
//
//	//a.Student::_name = "小张";
//	//a.Teacher::_name = "张老师";
//
//	cout  << endl;
//
//
//	return 0;
//}

// 多继承中指针偏移问题
// 
// A：p1 == p2 == p3              B：p1 < p2 < p3         C：p1 == p3 != p2        D：p1 != p2 != p3
//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//
//	return 0;
//}
//派生类对象给基类指针或引用时基类的指针或引用指向派生类中对应的基类的部分


// 继承和组合
// public继承是⼀种is-a的关系。也就是说每个派⽣类对象都是⼀个基类对象。 
// 组合是⼀种has-a的关系。假设B组合了A，每个B对象中都有⼀个A对象。
// 
// 继承这种通过⽣成派⽣类的复⽤通常被称为⽩箱复⽤，派⽣类和基类间的依赖关系很强，耦合度⾼。
// 
// 组合是类继承之外的另⼀种复⽤选择，这种复⽤⻛格被称为⿊箱复⽤(black-box reuse)，因为对象的内部细节是不可⻅的。组合类之间没有很强的依赖关
// 系，耦合度低。
//
// 二者都存在的情况下组合会更好，符合高内聚、低耦合
//
//
//// Tire(轮胎)和Car(⻋)更符合has-a的关系
//class Tire {
//protected:
//	string _brand = "Michelin"; // 品牌
//	size_t _size = 17; // 尺⼨
//};
//
//class Car {
//protected:
//	string _colour = "⽩⾊"; // 颜⾊
//	string _num = "陕ABIT00"; // ⻋牌号
//	Tire _t1; // 轮胎
//	Tire _t2; // 轮胎
//	Tire _t3; // 轮胎
//	Tire _t4; // 轮胎
//};
//class BMW : public Car {
//public:
//	void Drive() { cout << "好开-操控" << endl; }
//};
//
//// Car和BMW/Benz更符合is-a的关系
//class Benz : public Car {
//public:
//	void Drive() { cout << "好坐-舒适" << endl; }
//};
//template<class T>
//class vector
//{
//};
//
//// stack和vector的关系，既符合is-a，也符合has-a
//template<class T>
//class stack : public vector<T>
//{
//};
//
//template<class T>
//class stack
//{
//public:
//	vector<T> _v;
//};
#include<iostream>
using namespace std;

// 实现多态还有两个必须重要条件： 
// 必须是基类的指针或者引⽤调⽤虚函数
// 被调⽤的函数必须是虚函数，并且完成了虚函数重写 / 覆盖。

// 多态时重写是重写虚函数的实现部分

// 多态下基类的函数必须为虚函数，而派生类不用，但建议加
//class Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "吱吱" << std::endl;
//	}
//};
//
////class Animal
////{
////public:
////	void talk() const
////	{
////		std::cout << "吱吱" << std::endl;
////	}
////};
//
//class Dog : public Animal
//{
//public:
//	// 重写实现
//	void talk() const
//	{
//		std::cout << "汪汪" << std::endl;
//	}
//};
//
//class Cat : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "(>^ω^<)喵" << std::endl;
//	}
//};
//
//void letsHear(Animal& animal)
//{
//	animal.talk();
//}
//
//int main()
//{
//	Cat cat;
//	Dog dog;
//	letsHear(cat);
//	letsHear(dog);
//
//	return 0;
//}


//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	// 构成多态
//	// 多态调用：基类虚函数声明 + 派生类中虚函数的实现
//	B* p = new B;
//	p->test();
//
//	// 普通调用
//	// 普通调用看指针或引用的类型，多态则是对象
//	B* pa = new B;
//	pa->func();
//
//	return 0;
//}


// 析构函数的重写
// 基类的析构函数为虚函数，此时派⽣类析构函数只要定义，⽆论是否加virtual关键字，都与基类的析构函数构成重写
// 编译器对析构函数的名称做了特殊处理，编译后析构函数的名称统⼀处理成destructor，所以基类的析构函数加了
// vialtual修饰，派⽣类的析构函数就构成重写
//
//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B : public A {
//public:
//	//virtual ~B()
//	~B()
//	{
//		cout << "~B()->delete:" << _p << endl;
//		delete _p;
//	}
//protected:
//	int* _p = new int[10];
//};
//
////// 基类只要保障了析构函数是虚函数，下面场景就不会存在内存泄漏
//int main()
//{
//	/*A a;
//	B b;*/
//	A* ptr1 = new B;
//	delete ptr1;
//
//	A* ptr2 = new A;
//	delete ptr2;
//
//	return 0;
//}


// override 和 final关键字 
// override 检查派生类虚函数是否构成重写
// final 不让基类虚函数构成重写
// final修饰的类不能被继承

//class Car {
//public:
//	virtual void Dirve()
//	{ }
//	//virtual void Drive() final
//	//{}
//};
//
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{
//	return 0;
//}


//class Base
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//private:
//	// C++98的方法：构造函数私有的类不能被继承
//	Base()
//	{}
//};
// 
// class Base final
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//};
//
//class Derive : Base
//{};
//
//int main()
//{
//	//Derive d;
//
//	return 0;
//}


// 纯虚函数
// 在虚函数的后⾯写上 =0 ，则这个函数为纯虚函数
// 如果派⽣类继承后不重写纯虚函数，那么派⽣类也是抽象类
// 纯虚函数某种程度上强制了派⽣类重写虚函数，因为不重写实例化不出对象
//class Car
//{
//public:
//	virtual void Drive() = 0
//	{
//	}
//};
//
//class Benz :public Car
//{
//	void Drive()
//	{
//		cout << "Benz" << endl;
//	}
//};
//
//class BMW :public Car
//{
//	void Drive()
//	{
//		cout << "BWM" << endl;
//	}
//};
//
//int main()
//{
//	// 抽象类无法实例化出对象
//	//Car car;
//
//	Car* benz = new Benz;
//	benz->Drive();
//
//	Car* bmw = new BMW;
//	bmw->Drive();
//
//	return 0;
//}


// 多态的实现原理
// 虚函数指针表：虚表指针
//class Base
//{
//public:
//	virtual void fun()
//	{
//		cout << "fun" << endl;
//	}
//private:
//	int _a;
//	char _b;
//};
//
//// 若单纯根据成员变量来算的化是8，
//// 但是实际结果是16（x64）环境下,
//// 这是因为若有虚函数则还有个虚表指针，指针在x64下大小为8
//// 在调试里可以看到对象中存在着__vfptr的数组指针
//
//// ⼀个含有虚函数的类中都⾄少都有⼀个虚函数表指针，因为⼀个类所有虚函数的地址要被放到这个类对象的虚函数表中，虚函数表也简称虚表
//// 虚函数表是一个用于存储虚函数指针的数组，其在内存的代码段
//// 基类对象的虚函数表中存放基类所有虚函数的地址。同类型的对象共⽤同⼀张虚表，不同类型的对象各⾃有独⽴的虚表，
//// 所以基类和派⽣类有各⾃独⽴的虚表
//// 派⽣类由两部分构成，继承下来的基类和⾃⼰的成员，⼀般情况下，继承下来的基类中有虚函数表
//// 指针，⾃⼰就不会再⽣成虚函数表指针。但是要注意的这⾥继承下来的基类部分虚函数表指针和基
//// 类对象的虚函数表指针不是同⼀个
//// 派⽣类中重写的基类的虚函数，派⽣类的虚函数表中对应的虚函数就会被覆盖成派⽣类重写的虚函数地址。
//// 派⽣类的虚函数表中包含，(1)基类的虚函数地址，(2)派⽣类重写的虚函数地址完成覆盖，派⽣类⾃⼰的虚函数地址三个部分
// 
//int main()
//{
//	Base b;
//	cout << sizeof(b) << endl;
//
//	return 0;
//}

// 满⾜多态条件后，底层不再是编译时通过调⽤对象确定函数的地址，⽽是运⾏时到指向的对象的虚表中确定对应的虚函数的地址
// 这样就实现了指针或引⽤指向基类就调⽤基类的虚函数，指向派⽣类就调⽤派⽣类对应的虚函数
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//private:
//	string _name;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-打折" << endl; }
//private:
//	string _id;
//};
//
//void Func(Person ptr)
//{
//	// 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
//	// 但是跟ptr没关系，而是由ptr指向的对象决定的。
//	ptr.BuyTicket();
//}
//
//// 满足多态，运行时到指向对象的虚函数表中找到对应的虚函数进行调用
//// 不满足多态，编译时直接调用基类的虚函数
//// 
//// 对不满⾜多态条件(指针或者引⽤+调⽤虚函数)的函数调⽤是在编译时绑定，也就是编译时确定调⽤函数的地址，叫做静态绑定
//// 满⾜多态条件的函数调⽤是在运⾏时绑定，也就是在运⾏时到指向对象的虚函数表中找到调⽤函数的地址，也就做动态绑定
//int main()
//{
//	Person ps;
//	Student st;
//	Person* pps = new Student;
//
//	Func(ps);
//	Func(st);
//	pps->BuyTicket();
//
//	Person p1;
//	Person p2;
//	Person p3;
//
//	return 0;
//}

//
//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//};
//
//class Derive : public Base
//{
//public:
//	// 重写基类的func1
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func1" << endl; }
//	void func4() { cout << "Derive::func4" << endl; }
//protected:
//	int b = 2;
//};
// 
//int main()
//{
//
//	int i = 0;
//	static int j = 1;
//	int* p1 = new int;
//	const char* p2 = "xxxxxxxx";
//	printf("栈:%p\n", &i);
//	printf("静态区:%p\n", &j);
//	printf("堆:%p\n", p1);
//	printf("常量区:%p\n", p2);
//
//	Base b;
//	Derive d;
//
//	printf("Base虚函数表地址:%p\n", *((int*)&b));
//	printf("Derive虚函数表地址:%p\n", *((int*)&d));
//
//	printf("虚函数地址:%p\n", &Base::func1);
//	printf("普通函数地址:%p\n", &Base::func5);
//}
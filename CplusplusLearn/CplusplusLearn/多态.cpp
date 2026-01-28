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
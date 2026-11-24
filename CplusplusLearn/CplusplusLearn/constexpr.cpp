#include <iostream>
#include <vector>
#include <string>
#include <thread>
using namespace std;

// 常量表达式是指值不会改变并且在编译过程中就能得到计算结果的表达式，字⾯值、常量表达式初始化的const对象都是常量表达式，
// 要注意变量初始化的const对象不是常量表达式

// constexpr ⽤于指定常量表达式。它允许在编译时计算表达式的值，从⽽提⾼运⾏时性能并增强类型安全性。

// constexpr可以修饰变量，constexpr修饰的变量⼀定是常量表达式，且必须⽤常量表达式初始化，否则会报错。
// constexpr可以修饰指针，constexpr修饰的指针是顶层const，也就是指针本⾝
//int size()
//{
//	int n = 10;
//	return n;
//}
//
//int main()
//{
//	// 以下为常量表达式
//	const int a = 1;
//	const int b = a + 1;
//
//	// 以下为非常量表达式
//	int c = 1; // c不是常量表达式
//	const int d = c; // d不是常量表达式
//	const int e = size(); // e不是常量表达式
//
//	// 常量表达式可以做数组⼤⼩，vs不⽀持变⻓数组，所以这⾥数组⼤⼩必须是编译时确认的
//	int arr[a];
//
//	constexpr int aa = 1;
//	constexpr int bb = aa + 1;
//
//	//constexpr int cc = c; // 报错
//	//constexpr int cc = size(); // 报错
//	// constexpr int* p1 = &d; //报错，权限放⼤了，constexpr修饰的是p1本⾝
//
//	const int* p2 = &d;
//	constexpr const int* p3 = &d; //constexpr修饰的是p1本⾝，所以同样报错，const修饰 *p3
//
//	return 0;
//}

// constexpr 函数 
// c++11
// constexpr普通函数，要求函数声明的参数和返回值都是字⾯值类型(整形、浮点型、指针、引⽤等)，函数返回值类型不能是空。
// 要求函数体中，只包含⼀条 return 返回语句，不能定义局部变量，循环条件判断等控制流，并且返回值必须是常量表达式。

// c++14
// 局部变量 ：允许声明和初始化局部变量（只要在constexpr上下⽂中使⽤）
// 控制流语句 ：⽀持if条件分⽀、for / while循环、switch语句等
// 多return语句 ：函数体不再限于单⼀return语句
// ⽀持更复杂的返回类型：如void返回，⾃定义类、STL容器(std::array)、其他符合constexpr要求的复合类型

// constexpr构造函数，constexpr不能修饰⾃定义类型，但是⽤constexpr修饰类的构造函数后可以就可以。
// 该类的所有成员变量必须是字⾯类型(literal type)，
// constexpr构造函数必须在初始化列表初始化所有成员变量，构造对象实参必须使⽤常量表达式，函数体必须为空，析构函数必须是平凡的不做任何实际清理⼯作。

// constexpr成员函数，constexpr成员函数⾃动成为 const 成员函数，这意味着它们不能修改对象的成员变量，其他与constexpr修饰普通函数同，
// constexpr成员函数不能是虚函数，c++20后可以

// if constexpr - 编译期条件分⽀ 
// 允许在编译时根据常量表达式的结果决定编译哪部分代码，未选择的分⽀代码不会编译成指令，直接丢弃

// constexpr lambda 表达式 lambda表达式可标记为constexpr，捕获必须是编译期常量，函数体需满⾜constexpr函数要求

// 动态内存分配的编译期⽀持
// new / delete  ⽀持：允许在  constexpr  上下⽂中使⽤动态内存分配
// 编译期容器：使得  std::vector  和  std::string  等容器的编译期实现成为可能
// 内存⽣命周期：所有分配的内存在编译期必须被释放

//  constexpr 与 try-catch
// 实际限制：不能真正抛出异常（否则不是常量表达式）
// 错误处理：主要⽤于模板约束和编译期错误检测，异常必须在编译期捕获和处理，不能传播到运⾏时


// consteval 是为了解决  constexpr  的“不确定性”⽽引⼊的。 consteval  的核⼼思想是
// 创建⼀个必须在编译期求值的函数，它被称为⽴即函数。它⽐ constexpr  更严格，它修饰的函
// 数必须在编译时被调⽤和求值。如果⼀个  consteval  函数不能在编译时被求值，那么程序将⽆
// 法通过编译。将上⾯代码square函数改成 consteval  修饰会编译报错

// c++20 constinit
// constexpr 和 constinit 都可以修饰变量，它们的核⼼区别在于 "初始化时机" 和 "可变性"。
// constexpr ：必须在编译时初始化，并且其值在 整个程序⽣命周期内不可变（是常量）。
// constinit ：必须在 编译时初始化，但其值在运⾏时可以改变（⾮常量）。
// constinit 只能⽤于具有 静态存储期 或 线程存储期 的变量（如全局变量、 static 变量、thread_local  变量），不能⽤于函数内的局部变量（⾃动存储期）
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <bitset>
#include <utility>
#include <tuple>
#include <cstddef>
#include <string>
#include <string_view>
#include <array>
#include <chrono>
#include <thread>
using namespace std;

// 变量模板
// C++14 允许模板不仅⽤于类和函数，还可以⽤于变量
//template<class T>
//constexpr T pi = T(3.1415926535897932385L); // 变量模板
//
//template<class T>
//T circular_area(T r)
//{
//	return pi<T> *r * r;
//}
//
//template<size_t N>
//constexpr size_t factorial = N * factorial<N - 1>;
//
//// 特化
//template<>
//constexpr std::size_t factorial<0> = 1;
//
//int main() {
//	// 使⽤不同精度的π
//	std::cout.precision(6);
//	std::cout << "float π: " << pi<float> << std::endl;
//	std::cout.precision(10);
//	std::cout << "double π: " << pi<double> << std::endl;
//	std::cout.precision(6);
//	float radius1 = 2.5;
//	std::cout << "半径为 " << radius1 << " 的圆⾯积: " << circular_area(radius1)
//		<< std::endl;
//	std::cout.precision(10);
//	double radius2 = 2.5;
//	std::cout << "半径为 " << radius2 << " 的圆⾯积: " << circular_area(radius2)
//		<< std::endl;
//	std::cout << factorial<5> << std::endl;
//	std::cout << factorial<10> << std::endl;
//
//	return 0;
//}


// 泛型 lambda 表达式
// 允许 lambda 表达式使⽤ auto 作为参数类型，使其成为泛型。
// 和前⾯模板的语法⾼度类似，
// auto& 代表左值引⽤的形参，
// auto&& 代表万能引⽤的的形参，
// auto&&...代表可变模板参数的万能引⽤
//
// C++14 允许在 lambda 捕获中使⽤表达式初始化捕获的变量，
// 这个变量可以是当前域定义的，也可以是没有定义的
//
//int main()
//{
//	vector<int> nums = { 1,2,3,4,5 };
//
//	// 使用表达式初始化捕获的变量
//	auto p = make_unique<int>(10);
//	auto lamda1 = [value = 5, ptr = move(p), &nums]() {
//		std::cout << "捕获的值: " << value << std::endl;
//		std::cout << "捕获的智能指针值: " << *ptr << std::endl;
//		std::cout << "捕获的vector大小: " << nums.size() << std::endl;
//		};
//
//	lamda1();
//
//	// 在捕获时计算值
//	int x = 10;
//	auto lambda2 = [y = x * 2]() {
//		cout << "y = x * 2 = " << y << endl;
//		};
//
//	lambda2();
//
//	return 0;
//}

// C++20以后开始⽀持在捕捉列表和参数中间直接类似模板语法写模板参数
//int main()
//{
//	// 泛型 lambda，operator() 是⼀个拥有两个（模板）形参的模板
//	auto glambda = []<class T>(T a, auto&& b) {
//		return a < b;
//	};
//
//	// // 泛型 lambda，operator() 是⼀个拥有⼀个形参包的模板
//	vector<string> v;
//	auto f2 = [&v]<typename... Args>(Args&&... ts) {
//		v.emplace_back(forward<Args>(ts)...);
//	};
//
//	string s1("hello world");
//	f2(s1);
//	f2("111111");
//	f2(10, 'y');
//
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


// C++14直接⽀持auto推导，如果函数声明的声明说明符序列 包含关键词 auto，那么尾随返回类型可以省略，
// 且编译器将从未舍弃的返回语句中所⽤的操作数的类型推导出它，如果有多条返回语句，那么它们必须推导出相同的类型

// C++14 普通函数可以直接⽤auto做返回类型，⾃动推导返回类型
//int x = 1;
//auto f1() { return x; } // 返回类型是 int
//auto& f2() { return x; } // 返回类型是 int&
//auto f3(int x) { return x * 1.5; } // 返回类型是double
//// 报错，多返回语句需类型⼀致
//auto f4(int x) {
//	if (x > 0)
//		return 1.0; // double
//	else
//		return 2; // int → 错误：类型不⼀致
//}
//
//int main()
//{
//	cout << f1() << endl;
//	int& ret = f2();
//	cout << f3(3) << endl;
//	ret++;
//	cout << x << endl;
//	cout << ret << endl;
//	return 0;
//}
//
// 
//int x = 1;
//decltype(auto) f1() { return x; } // 返回类型是 int，同 decltype(x)
//decltype(auto) f2() { return (x); } // 返回类型是 int&，同 decltype((x))
//// C++14引⼊的decltype(auto)常⽤于完美转发返回类型：
//// 需要精确保持返回值的值类别（左值/右值）
//template<typename F, typename... Args>
//decltype(auto) call(F&& f, Args&&... args)
//{
//	return std::forward<F>(f)(std::forward<Args>(args)...);
//}
//	
//int main()
//{
//	cout << f1() << endl;
//	int& ret = f2();
//	ret++;
//	cout << x << endl;
//	cout << ret << endl;
//	return 0;
//}


// ⼆进制字⾯量
// ⼗进制字⾯量 是⼀个⾮零⼗进制数字（1、2、3、4、5、6、7、8、9）后随零或多个⼗进制数字（0、1、2、3、4、5、6、7、8、9）
// ⼋进制字⾯量 是数字零（0）后随零或多个⼋进制数字（0、1、2、3、4、5、6、7）
// ⼗六进制字⾯量 是字符序列 0x 或字符序列 0X 后随⼀或多个⼗六进制数字（0、1、2、3、4、5、6、7、8、9、a、A、b、B、c、C、d、D、e、E、f、F）
// ⼆进制字⾯量 是字符序列 0b 或字符序列 0B 后随⼀或多个⼆进制数字（0、1）
// 其中⼆进制字⾯量是C++14开始⽀持的
//int main()
//{
//	int d = 42;
//	int o = 052;
//	int x = 0x2a;
//	int X = 0x2A;
//	int b = 0b101010;
//
//	cout << d << endl;
//	cout << o << endl;
//	cout << x << endl;
//	cout << X << endl;
//	cout << b << endl;
//
//	// 实际应⽤⽰例 - 位标志
//	const int FLAG_A = 0b0001; // 1
//	const int FLAG_B = 0b0010; // 2
//	const int FLAG_C = 0b0100; // 4
//	const int FLAG_D = 0b1000; // 8
//
//	int flags = FLAG_A | FLAG_C; // 0b0101
//
//	std::cout << "标志位: " << std::bitset<4>(flags) << std::endl;
//	
//	if (flags & FLAG_A) {
//		std::cout << "FLAG_A 被设置" << std::endl;
//	} 
//
//	if(flags & FLAG_B) {
//		std::cout << "FLAG_B 被设置" << std::endl;
//	} 
//	else{
//		std::cout << "FLAG_B 未被设置" << std::endl;
//	}
//
//	return 0;
//}


// C++14 允许在数字字⾯量中使⽤单引号作为分隔符，提⾼可读性
//int main()
//{
//	int million = 100'0000;
//	long hexValue = 0xDEAD'BEEF;
//	double pi = 3.141'592'653'59;
//	unsigned long long bidBinary = 0b1010'1010'1010'1010;
//
//	return 0;
//}


// C++14 起允许非静态数据成员有类内默认初始化器
// 
// 什么是聚合类：
//聚合类是指满⾜以下条件的类(包括结构体)：
//1. 没有⽤⼾提供的构造函数
//2. 没有私有或受保护的⾮静态数据成员
//3. 没有基类
//4. 没有虚函数

// 聚合类就是满足“没有用户构造函数、没有私有/保护非静态成员、没有虚函数等条件”的类，可以用 {} 按成员顺序直接初始化，常用于简单的数据结构

// 关键不同点：
//1. 默认成员初始化器：当使⽤默认构造或值初始化时，成员会使⽤这些默认值
//2. 聚合初始化：仍然可以使⽤花括号初始化列表，未指定的成员会使⽤默认值
//3. 初始化顺序：初始化列表中的值按成员声明顺序应⽤于成员

//struct Point {
//    int x;
//    int y;
//}; // 聚合类
//
//Point p{ 1, 2 }; // 聚合初始化，不调用用户构造函数
//
//struct A {
//    int x = 1;
//    int y = 2;
//}; // C++14 起是聚合类
//
//A a{}; // x=1, y=2


// exchange
// 需包含<utility>
// 提供
// 其提供了⼀种简洁⾼效的⽅式来替换⼀个对象的值并返回其旧值
//class stream
//{
//public:
//	using flags_type = int;
//	flags_type flags() const { return _flags; }
//
//	// 以 newf 替换 flags_ 并返回旧值
//	flags_type flags(flags_type newf) { return std::exchange(_flags, newf); }
//
//private:
//	flags_type _flags = 0;
//};
//
//void f() { std::cout << "f()"; }
//
//int main()
//{
//	stream s;
//
//	cout << s.flags() << endl;
//	cout << s.flags(12) << endl;
//	cout << s.flags() << "\n\n";
//
//	vector<int> v = { 10,20,30 };
//
//	// 下⽅表达式等价于 std::exchange(v, std::vector<int>{1, 2, 3, 4});
//	vector<int> ret = exchange(v, { 1,2,3,4 });
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto& e : ret)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	std::cout << "\n\n斐波那契数列: ";
//	for (int a{ 0 }, b{ 1 }; a < 100; a = std::exchange(b, a + b))
//		std::cout << a << ", ";
//	std::cout << "...\n";
//
//	return 0;
//}


// make_unique
// std::make_unique 是C++14引⼊的⼀个智能指针创建⼯具函数，⽤于安全地创建和管理std::unique_ptr 对象


// integer_sequence 
// std::integer_sequence  定义在  <utility>  头⽂件中，⽤于在编译时表⽰⼀个整数序列
//template<typename T,T... ints>
//void print_sequence(int id, std::integer_sequence<T, ints...> int_seq)
//{
//	std::cout << id << ") 大小为 " << int_seq.size() << " 的序列: ";
//	((std::cout << ints << ' '), ...);
//	std::cout << '\n';
//}
//
//int main()
//{
//	print_sequence(1, std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{});
//	print_sequence(2, std::make_integer_sequence<int, 12>{});
//	print_sequence(3, std::make_index_sequence<10>{});
//	print_sequence(4, std::index_sequence_for<std::ios, float, signed>{});
//
//	return 0;
//}

// 使用std::integer_sequence来用于解包打印tuple
//template<typename... Args,std::size_t... Indices>
//void print_tuple_impl(const std::tuple<Args...>& t, std::index_sequence<Indices...>)
//{
//	// 使用折叠表达式打印元组元素
//	((cout << get<Indices>(t) << " "), ...);
//	cout << endl;
//}
//
//template<typename... Args>
//void print_tuple(const tuple<Args...>& t)
//{
//	print_tuple_impl(t, index_sequence_for<Args...>());
//
//}
//
//template<typename Array, std::size_t... I>
//void print_array_impl(const Array& arr, std::index_sequence<I...>) {
//	((std::cout << arr[I] << ' '), ...);
//} 
//
//template<typename T, std::size_t N>
//void print_array(const std::array<T, N>& arr) {
//	print_array_impl(arr, std::make_index_sequence<N>{});
//}
//
//int main()
//{
//	array<int, 4> arr{ 1,2,3,4 };
//	print_array(arr);
//	cout << endl;
//
//	// 打印元组
//	auto t = make_tuple(10, 3.14, "hello", 'a');
//	cout << "元组内容: ";
//	print_tuple(t);
//
//	return 0;
//}


// std::quoted
// 需要包含<iomanip>
// 是 C++14 引⼊的⼀个 I/O 操纵器，⽤于简化带引号字符串的输⼊输出操作
//主要⽤于:
//输出时：⾃动为字符串添加引号；
//输⼊时：⾃动去除字符串周围的引号；
//处理转义字符：⾃动处理引号内的转义序列

//#include <iomanip>
//#include <sstream>
//int main()
//{
//	// 输出带引号的字符串
//	string text = "hello world";
//	cout << "Without quoted: " << text << endl;
//	cout << "With quoted: " << quoted(text) << endl;
//
//	// 输出带引号的字符串
//	istringstream input("\"hello world\"");
//	input >> quoted(text);
//	cout << "Extracted: " << text << std::endl;
//
//	return 0;
//}

// ⾃定义分隔符和转义字符
//#include <iomanip>
//#include <sstream>
//
//int main()
//{
//	// 使用单引号作为分隔符
//	string text = "It is a test";
//	
//	std::cout << "Default: " << std::quoted(text) << std::endl;
//	std::cout << "Single quotes: " << std::quoted(text, '\'') << std::endl;
//
//	// 处理包含分隔符的字符串
//	std::string complex = R"(He said "Hello" and left)";
//	std::cout << "Complex string: " << std::quoted(complex) << std::endl;
//
//	// 使⽤字符串流测试输⼊输出
//	std::stringstream ss1;
//	ss1 << std::quoted(complex);
//	std::string extracted;
//	ss1 >> std::quoted(extracted);
//	std::cout << "Extracted: " << extracted << std::endl;
//
//	// 包含转义字符的字符串
//	std::stringstream ss2;
//	text = "Line1\nLine2\tTabbed";
//	ss2 << std::quoted(text);
//
//	std::cout << "Original: " << text << std::endl;
//	std::cout << "Quoted: " << ss2.str() << std::endl;
//	ss2 >> std::quoted(extracted);
//	std::cout << "Extracted: " << extracted << std::endl;
//
//	return 0;
//}


// std::shared_timed_mutex和std::shared_mutex
// 
// shared_timed_mutex 是提供的⼀种同步原语，能⽤于保护数据免受多个线程同时访问。
// 与其他促进独占访问的互斥体类型相反
// 它拥有两个访问层次：
// 共享 - 多个线程能共享同⼀互斥体的所有权。
// 独占 - 仅⼀个线程能占有互斥体。

// shared_mutex 类是C++17提供的⼀个同步原语，可⽤于保护共享数据不被多个线程同时访问。
// 与便于独占访问的其他互斥体类型不同，shared_mutex 拥有两个访问级别：
// 共享 - 多个线程能共享同⼀互斥体的所有权。
// 独占 - 仅⼀个线程能占有互斥

// 其实就是读写锁
// 若⼀个线程已获取独占 锁（通过 lock、try_lock），则⽆其他线程能获取该锁（包括共享的）。
// 若⼀个线程已获取共享 锁（通过 lock_shared、try_lock_shared），则⽆其他线程能获取独占锁，但可以获取共享锁。
// 仅当任何线程均未获取独占 锁时，共享 锁能被多个线程获取；在⼀个线程内，同⼀时刻只能获取⼀个锁（共享或独占）

// shared_timed_mutex 和 shared_mutex的主要区别是 shared_timed_mutex 提供超时锁定相关系列的接⼝try_lock_for / try_lock_until 和 try_lock_shared_for / try_lock_shared_until
// C++14还提供了⼀个shared_lock的RAII管理共享锁的类型，⼀般建议，共享锁时使⽤shared_lock，独占锁时使⽤unique_lock


// 字⾯量后缀
// 字⾯量后缀是附加在字⾯量后⾯的标识符，⽤于明确指定该字⾯量的具体类型
// 其主要通过重载  operator""  实现的。它允许程序员为字⾯量（数字、字符、字符串）定义⾃⼰的后缀，从⽽将这些“裸”字⾯量⾃动转换为具有特定类型和语义的对象
//
//string operator""_s(const char* str, size_t len)
//{
//	return string(str, len);
//}
//
//string_view operator""_sv(const char* str, size_t len)
//{
//	return string_view(str, len);
//}
//
//float operator ""_e(const char* str)
//{
//	return std::stof(std::string(str));
//} 
//
//constexpr long double operator "" _km(unsigned long long int x) {
//	return x * 1000.0; // 将公⾥转换为⽶
//} 
//
//constexpr long double operator "" _pi(long double x) {
//	return x * 3.14159265358979323846L;
//}
//
//int main()
//{
//	auto s1 = "hello"_s;
//	auto s2 = "hello\0world"_s;
//	auto sv1 = "hello"_sv;
//	auto dis = 5_km;
//	auto angle = 2.0_pi;
//	auto x = 12.3_e;
//
//	return 0;
//}

// C++14 起，标准库提供了⼤量开箱即⽤的字⾯量，它们定义在内联命名空间  std::literals 中
//using namespace std::literals;
//
//int main()
//{
//	auto str = "hello"s; // 类型是 std::string，不是 const char*
//	cout << str.size() << endl;
//
//	this_thread::sleep_for(chrono::milliseconds(500));
//	// 时间字面量
//	this_thread::sleep_for(500ms);
//
//	return 0;
//}
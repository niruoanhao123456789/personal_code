//泛式编程：写与类型无关的通用代码，是代码复用的一种手段。模板是泛型编程的基础
//#include<iostream>
//using namespace std;
//
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap(double& x, double& y)
//{
//	double tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap(char& x, char& y)
//{
//	char tmp = x;
//	x = y;
//	y = tmp;
//}
//像上面想实现不同的类型的交换函数，虽然可以利用函数重载，但代码量多且重复，效率较低
//所以有了函数模板
//格式：
//template<typename T1, typename T2,......,typename Tn>
//返回值类型 函数名(参数列表) {}
// 
// template<>的<>里的类型名命名时最好要根据其特殊含义
//
//typename是用来定义模板参数关键字，也可以使用class(切记：不能使用struct代替class)
//template<typename T>
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
////函数模板只是个蓝图，其本身并不是个函数，
////在编译阶段，对于模板函数的使用，编译器会根据传入的实参类型来推演生成对应类型的函数以供调用
//
//int main()
//{
//	int i = 1, j = 2;
//	double k = 2.1;
//	char c1 = 'a', c2 = 'b';
//
//	//Swap(i, j);
//	//cout << "i = " << i << " j = " << j << endl;
//	
//	
//	return 0;
//}


//函数模板的实例化
//用不同类型的参数使用函数模板时，称为函数模板的实例化
//#include<iostream>
//using namespace std;
//
//template<class T>
//T Add(const T& x, const T& y)
//{
//	return (x + y);
//}
//
//template<class T>
//void Func(size_t n)
//{
//	T* ptr = new T[n];
//	cout << ptr << endl;
//	// ...
//}
//
//int main()
//{
//	int i = 1, j = 2;
//	double d1 = 2.1, d2 = 3.4;
//
//	// 隐式实例化：让编译器根据实参推演模板参数的实际类型
//	cout << Add(i, j) << endl;
//	cout << Add(d1, d2) << endl;
//
//	//通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//	//因此编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	//在模板中，编译器一般不会进行类型转换操作
//	//Add(i, d1);
//	//此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//	cout << Add((double)i, d1) << endl;
//	cout << Add(i, (int)d1) << endl;
//  //函数模板不支持隐式类型转换
//
//	// 显式实例化：在函数名后的<>中指定模板参数的实际类型
//	cout << Add<int>(i, d1) << endl;
//	cout << Add<double>(i, d1) << endl;
//
//	Func<int>(10);
//	Func<double>(10);
//
//
//	return 0;
//}


//模板参数的匹配原则
//#include<iostream>
//using namespace std;
//
////1. 一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函数
//// 
////专门处理int的加法函数
//int Add(const int& x, const int& y)
//{
//	return (x + y);
//}
//
////通用加法函数
//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//
////2. 对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而
////不会从该模板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
//
//template<class T1 ,class T2>
//T2 Add(const T1& x, const T2& y)
//{
//	return x + y;
//}
//
////3. 模板函数不允许自动类型转换，但普通函数可以进行自动类型转换
//
//int main()
//{
//
//	cout << Add(1, 2) << endl;//与非模板函数匹配,直接调用专门处理的函数，编译器不用特化
//	cout << Add<int>(1, 2) << endl;//以函数名后加<>，就是直接调用模板，经编译器特化的Add版本
//
//	cout << Add(3, 2) << endl;////与非模板函数匹配,直接调用专门处理的函数，编译器不用特化
//	cout << Add(1, 2.1) << endl;//编译器根据函数模板的实参生成更加匹配的Add函数
//
//	return 0;
//}


//类模板
//格式：
//template<class T1, class T2, ..., class Tn>
//class 类模板名
//{
//	// 类内成员定义
//};
//
//#include<iostream>
//using namespace std;
//
//// 泛型编程
//// 模板不支持声明和定义分离定义.h 和 .cpp
//template<class T>
//class Stack
//{
//public:
//	Stack(size_t n = 4)
//		:_arr(new T[n])
//		,_top(0)
//		,_capacity(n)
//	{
//
//	}
//	//法一：
//	//void Push(const T& x)
//	//{
//	//	// 扩容
//	//	// ...
//	//	_arr[_top++] = x;
//	//}
//
//	void Push(const T& x);
//
//private:
//	T* _arr;
//	size_t _top;
//	size_t _capacity;
//};
//
////法二
//template<class T>
//void Stack<T>::Push(const T& x)
//{
//	// 扩容
//	// ...
//	_a[_top++] = x;
//}
//
////模板的类型也可以用缺省的方式
//template<class T = int>
//class A
//{
//public:
//	T x1;
//	T x2;
//};
//
////其不像类那样给缺省值一定要从左往右给
//template<class T1, class T2 = int>
//class B
//{
//public:
//	T1 x1;
//	T2 x2;
//};
//
//
//int main()
//{
//	//类模板的实例化
//	//Stack是类名，Stack<type>才是类型
//	Stack<int> st1;   //存放int数据
//	st1.Push(1);
//
//	Stack<double>st2; //存放double数据
//	st2.Push(2.1);
//
//	A<> aa1;
//	A<double> aa2;
//
//	B<double> bb1;
//	B<double, double> bb2;
//
//
//	return 0;
//}
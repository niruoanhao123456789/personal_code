#include<iostream>
using namespace std;

//int main()
//{
//	//initializer_list<int> mylist;
//	//mylist = { 10, 20, 30 };
//	//cout << sizeof(mylist) << endl;
//	//// 这里begin和end返回的值initializer_list对象中存的两个指针
//	//// 这两个指针的值跟i的地址跟接近，说明数组存在栈上
//	//int i = 0;
//	//cout << mylist.begin() << endl;
//	//cout << mylist.end() << endl;
//	//cout << &i << endl;
//
//	//	// 左值：可以取地址
//	//	// 以下的p、b、c、*p、s、s[0]就是常见的左值
//	//	int* p = new int(0);
//	//	int b = 1;
//	//	const int c = b;
//	//	*p = 10;
//	//	string s("11111111111111111111111111111");
//	//	s[0] = 'x'; 
//	//
//	//	cout << &p << endl;
//	//	cout << &b << endl;
//	//	cout << &c << endl;
//	//	cout << &(*p) << endl;
//	//	cout << &s << endl;
//	//	cout << (void*)&s[0] << endl;
//	//
//	//	// 右值：不能取地址
//	//	double x = 1.1, y = 2.2;
//	//	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值
//	//	10;
//	//	x + y;
//	//	fmin(x, y);
//	//	string("11111");
//	//	
//	//	// 编译报错
//	//	/*cout << &10 << endl;
//	//	cout << &(x+y) << endl;
//	//	cout << &(fmin(x, y)) << endl;
//	//	cout << &string("11111") << endl;*/
//
//	// 左值：可以取地址
//	//	// 以下的p、b、c、*p、s、s[0]就是常见的左值
//	//	int* p = new int(0);
//	//	int b = 1;
//	//	const int c = b;
//	//	*p = 10;
//	//	string s("111111");
//	//	s[0] = 'x';
//	//	double x = 1.1, y = 2.2;
//	//
//	//	// 左值引用给左值取别名
//	//	int& r1 = b;
//	//	int*& r2 = p;
//	//	int& r3 = *p;
//	//	string& r4 = s;
//	//	char& r5 = s[0];
//	//
//	//	// 右值引用给右值取别名
//	//	int&& rr1 = 10;
//	//	double&& rr2 = x + y;
//	//	double&& rr3 = fmin(x, y);
//	//	string&& rr4 = string("11111");
//	//
//	//	// 左值引用不能直接引用右值，但是const左值引用可以引用右值
//	//	const int& rx1 = 10;
//	//	const double& rx2 = x + y;
//	//	const double& rx3 = fmin(x, y);
//	//	const string& rx4 = string("11111");
//	//
//	//	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
//	//	int&& rrx1 = move(b);
//	//	int*&& rrx2 = move(p);
//	//	int&& rrx3 = move(*p);
//	//	string&& rrx4 = move(s);
//	//	string&& rrx5 = (string&&)s;
//	//
//	//	// int&& rrrx1 = move(rrx1);
//
//	return 0;
//}

int main()
{

	return 0;
}
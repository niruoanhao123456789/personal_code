//先浅谈STL
//STL六大组件：仿函数、算法、迭代器、空间适配器（内存池）、容器（数据结构）、配接器（适配器）

//串通过编码的方式来存储信息
//编码表：值（二进制）和符号映射关联集合
//常见的：
// ASCII
// Unicode、UTF-8 变长编码，能兼容ASCII，有5个bit位标记
// GBK 双字节编码加一个标记位用以查表，并将同音字编在一起（范围集）

#include<iostream>
#include<string>
#include<list>
using namespace std;

//string的构造和赋值初始化
void test1()
{
	string s1;					// 构造空string对象，空字符串
	string s2("hello world");	// 构造
	string s3(s2);				// 拷贝构造，深拷贝

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	// string (const string& str, size_t pos, size_t len = npos);
	string s4(s2, 0, 5);		// 将s2从下标从0开始拷贝5个长度到s4
	cout << s4 << endl;

	string s5(s2, 6, 15);		//从pos位置拷贝到结尾
	cout << s5 << endl;
	
	// 此处sting参数使用的还是
	// string (const string& str, size_t pos, size_t len = npos);
	string s6(s2, 6);			//只不过len处没有给值，因npos是整型的最大值，此处从string会从pos位置拷贝到字符串结尾
	cout << s6 << endl;

	// string (const char* s, size_t n);
	string s7("hello world", 6);
	cout << s7 << endl;

	// string (size_t n, char c);
	string s8(10, '*');
	cout << s8 << endl;

	//将sting的内容进行更改
	s7 = "*****";
	cout << s7 << endl;
}

void Print(const string& str)
{
	// begin和end是左闭右开的
	//对于const对象，迭代器得用下面的形式
	string::const_iterator it1 = str.begin();
	while (it1 != str.end())
	{
		// (*it1) = 'x'; //不允许修改
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//反向迭代器
	string::const_reverse_iterator it2 = str.rbegin();
	while (it2 != str.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}

void test2()
{
	string s1("hello world");
	cout << s1 << endl;

	// char& operator[] (size_t pos);	//类似于下标
	s1[0] = 'x';
	cout << s1 << endl;

	// const char& operator[] (size_t pos) const;
	cout << s1[0] << endl;

	// 在string中的at与[]有一样的作用
	// 越界有严格断言检查，两者不一样在于
	//s1[12];	 // 断言
	//s1.at(12); // 抛异常

	//二者都是求串string的长度但计算时都不算'\0'
	//更推荐使用size，因为size可以针对更宽泛的类型，而length只对于string
	cout << s1.size() << endl;
	cout << s1.length() << endl;

	// 遍历 or 修改
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout << s1 << endl;

	// 迭代器
	// 行为像指针一样的东西
	string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		// 修改
		(*it1)--;

		//历遍
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//迭代器的作用不仅在string这样的顺序表里，也可以用于链表这样的链式结构上
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);

	list<int>::iterator lit = l1.begin();
	while (lit != l1.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;

	Print(s1);

	// find
	string::iterator ret1 = find(s1.begin(), s1.end(), 'x');
	if (ret1 != s1.end())
	{
		cout << "找到了x" << endl;
	}

	list<int>::iterator ret2 = find(l1.begin(), l1.end(), 2);
	if (ret2 != l1.end())
	{
		cout << "found 2" << endl;
	}

	// auto与范围for
	//c++11后有的特性
	int i = 0;
	// 通过初始化表达式值类型自动推荐对象类型
	auto j = i;
	auto k = 10;

	// auto与auto*作用是一样的
	auto p1 = &i;
	// 但用auto*这样指针写法就一定是指针
	auto* p2 = &i;
	cout << p1 << endl;
	cout << p2 << endl;

	// 引用
	int& r1 = i;
	// r2的类型不是int&引用，是int
	auto r2 = r1;
	//r3的类型是int& 引用
	auto& r3 = r1;
	cout << &r2 << endl;
	cout << &r1 << endl;
	cout << &i << endl;
	cout << &r3 << endl;

	// 范围for
	// 自动取容器数据赋值，自动迭代++，自动判断结束
	// 范围for的底层逻辑其实就是用迭代器实现
	// for (auto ch : s1)
	//for (char ch : s1)//ch相当于一个临时变量，对其进行修改，不会改变string本身
	//{
	//	ch -= 1;
	//	cout << ch << ' ';
	//}
	//cout << endl;
	//cout << s1 << endl;
	//
	// 要对string本身进行更改应采用&引用的方式
	for (auto& ch : s1)
	{
		ch -= 1;
	}
	//cout << s1 << endl;
	for (const auto& ch : s1)
	{
		cout << ch << ' ';
	}
	cout << endl;

	//for (auto l:l1)
	//{
	//	cout << l << ' ';
	//}
	//cout << endl;

	// 所以支持迭代器的容器都可以用范围for
	int arr[10] = { 1,2,3 };
	for (const auto& e : arr)
	{
		cout << e << ' ';
	}
	cout << endl;
}
// 迭代器
// 1、提供了统一的方式来历遍与修改容器
// 2、算法可以泛型化，算法借助迭代器处理容器的数据


void TestCapacity()
{
	string s1("hello world");
	//s1.reserve(100);		//确定要扩的容量，提前扩容，减少系统损耗，提高效率

	//观察每次插入数据后，string的扩容机制
	//发现在vs2022下除第一次扩容为 *2，后面扩容为 *1.5；而gcc则都为 *2
	//因c++ STL规定只容量满后要扩容，但具体扩容机制由各编译器进行实现
	size_t last = s1.capacity();
	cout << last << endl;
	for (size_t i = 0; i < 100; i++)
	{
		s1.push_back('x');
		if (s1.capacity() != last)
		{
			cout << s1.capacity() << endl;
			last = s1.capacity();
		}
	}
	cout << endl;
}

void test3()
{
	string s1("hello world");
	cout << s1.max_size() << endl;		//大小为string::npos

	//以下两者在计算时都不算'/0'
	cout << s1.size() << endl;			//表示实际存储数据多少
	cout << s1.capacity() << endl;		//表示目前能存储实际有效字符个数

	s1.clear();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;
}

void test4()
{
	string s1("hello world");
	// 用reverse调整string的容量n>=capacity时
	s1.reserve(20);

	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	// 缩容
	// 要求不改变原数据内容，所以通常不会缩容到要求的值，有时编译器即使对于reserve缩容不会真进行缩容，而是保持不变
	//s1.reserve(5);
	s1.shrink_to_fit();		
	// 一般不用，因为缩容的性能代价比较大，其逻辑是拷贝目前容器里的内容并异地扩容相对小的空间，再把原有空间归还给系统
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;

	string s2("hello world");
	cout << s2 << endl;

	// 调整当前对象大小，如果该对象的空间大于目标值，则多的内容会进行删除
	s2.resize(5);
	cout << s2 << endl;
	// 如果该对象的空间小于目标值，则会进行进行扩容并初始化
	// void resize (size_t n, char c);
	s2.resize(15,'*');
	cout << s2 << endl;
	// 没有指定初始化内容就初始化为空字符
	s2.resize(20);
	cout << s2 << endl;
}

void test5()
{
	// // 追加
	string s1("hello world");
	s1.push_back('%');
	// string& append (const char* s);
	s1.append("hello friend");
	cout << s1 << endl;

	// 在末尾追加几个什么字符
	// string& append (size_t n, char c);
	s1.append(10, '#');
	cout << s1 << endl;

	string s2(" apple hello!");
	// 指定要追加的内容范围
	// 如不要开头的空格和结尾的!
	s1.append(++s2.begin(), --s2.end());
	cout << s1 << endl;

}

int main()
{
	try
	{
		//test1();
		//test2();
		//test3();
		//TestCapacity();
		//test4();
		test5();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
//边看课编写代码除了课上解释语法写的例子代码还行，但对带有思维性的问题这样学效果非常差
//对比代码来找错误效果也是差的，要学会自己调试或者逐字看来找问题
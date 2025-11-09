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
	//对于const对象，迭代器得用下面的形式
	string::const_iterator it1 = str.begin();
	while (it1 != str.end())
	{
		// (*it1) = 'x'; //不允许修改
		cout << *it1 << " ";
	}
	cout << endl;

	//反向迭代器
	string::const_reverse_iterator it2 = str.rbegin();
	while (it2 != str.rend())
	{
		cout << *it2 << " ";
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
}

int main()
{
	//test1();

	test2();

	return 0;
}
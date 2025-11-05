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
using namespace std;

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


}

int main()
{
	test1();

	return 0;
}
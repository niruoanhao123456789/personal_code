#include"vector.h"
using namespace std;

namespace my_vector
{
	void Print(const vector<int>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	void vector_test1()
	{
		vector<int> v1;
		v1.reserve(3);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		Print(v1);
		v1[0]++;
		Print(v1);
		v1[0]--;
		Print(v1);
	}

	void vector_test2()
	{
		vector<int> v1;
		v1.reserve(8);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		Print(v1);
		v1.insert(v1.begin(), 0);
		Print(v1);

		auto it = v1.begin() + 3;
		// insert以后，it是否失效？
		// 迭代器失效
		// it失效了，也就意味着，insert以后，it失效了，it就不能使用了
		// 如果函数内部进行了扩容机制，那么因形参的改变不会影响实参，导致it指向的仍是原来已经被释放的旧空间，
		// 此时it为野指针，所以说insert以后，it失效了
		v1.insert(it, 30);
		Print(v1);
	}

	void vector_test3()
	{
		vector<int> v1;
		v1.reserve(4);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		Print(v1);

		v1.erase(v1.begin());
		Print(v1);

		auto it = v1.begin() + 2;
		v1.erase(it);
		// erase以后，it是否失效？
		// 失效，不能访问，访问结果未定义
		// 如果用erase进行尾删后，it所指位置可能是随机值，不能再使用it来访问
		Print(v1);
	}

	void vector_test4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		Print(v);

		// 删除偶数
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);			// 对与erase带来的迭代器失效问题可以这样来解决
			}
			else
			{
				++it;
			}
		}
		Print(v);
	}

	void vector_test5()
	{
		vector<int> v1;
		v1.resize(10);
		Print(v1);
		vector<int> v2;
		v2.resize(10,3);
		Print(v2);
	}

	void vector_test6()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		
		vector<int> v2(v1);
		Print(v2);

		vector<int> v3 = v1;
		Print(v3);

		vector<int> v4 = { 10,20,30,40 };
		v1 = v4;
		Print(v1);

		// 此处参数为int int如果没有专门的函数，会对应到目前其认为最合适的模板函数
		vector<int> v5(10, 1);
		Print(v5);
		vector<char> v6(10, 'x');
		for (auto e : v6)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void vector_test7()
	{
		vector<string> v1;
		v1.push_back("111111111111111111111111");
		v1.push_back("111111111111111111111111");
		v1.push_back("111111111111111111111111");
		v1.push_back("111111111111111111111111");
		v1.push_back("111111111111111111111111");
		for (auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

int main()
{
	//my_vector::vector_test1();
	//my_vector::vector_test2();
	//my_vector::vector_test3();
	//my_vector::vector_test4();
	//my_vector::vector_test5();
	//my_vector::vector_test6();
	my_vector::vector_test7();

	return 0;
}
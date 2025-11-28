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
		v1.reverse(3);
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
		v1.reverse(8);
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
		v1.reverse(4);
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
}

int main()
{
	//my_vector::vector_test1();
	//my_vector::vector_test2();
	//my_vector::vector_test3();
	my_vector::vector_test4();

	return 0;
}
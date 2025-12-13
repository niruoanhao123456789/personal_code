#include"List.h"
using namespace std;

namespace my_list
{
	template<class T>
	void Print(list<T> l)
	{
		for (auto e : l)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test1()
	{
		list<int> l1;
		l1.push_back(0);
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		Print(l1);

		l1.push_front(-1);
		l1.push_front(-2);
		Print(l1);
		l1.pop_back();
		l1.pop_back();
		Print(l1);
		
		l1.insert(l1.end(), 3);
		l1.insert(l1.begin(), -3);
		Print(l1);
		l1.erase(l1.end());
		l1.erase(l1.begin());
		Print(l1);
		
		list<int> l2;
		l2.push_back(0);
		l2.push_back(1);
		l2.push_back(2);
		Print(l2);
		list<int>::iterator it = l2.begin();
		while (it != l2.end())
		{
			it = l2.erase(it);
		}
		Print(l2);
	}

	void test2()
	{
		list<int> l1;
		l1.push_back(0);
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		
		list<int> l2(l1);
		Print(l2);
		list<int> l3 = { 1,2,3,4,5 };
		Print(l3);
		l3 = l1;
		Print(l3);
		list<int> l4(l1.begin(), l1.end());
		Print(l4);

	}

	struct A
	{
		int a = 0;
		int b = 0;
	};

	void test3()
	{
		list<A> lt;
		lt.push_back({ 1,2 });
		lt.push_back({ 3,4 });
		lt.push_back({ 5,6 });
		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << (*it).a << " " << (*it).b << " ";
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			// 为了可读性省略一个->
			//cout << it->_a1 << ":" << it->_a2 << endl;
			//cout << it.operator->()->_a1 << ":" << it.operator->()->_a2 << endl;
			++it;
		}
		cout << endl;
	}
}
using namespace my_list;

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}
#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Date1
{
public:
	Date1(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
	}

	bool operator<(const Date1& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date1& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date1& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date1& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

// 仿函数/函数对象   对象可以像函数一样使用
template<class T>
struct less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y ? x : y;
	}
};

struct PDateLess
{
	bool operator()(const Date1* x, const Date1* y) const
	{
		return *x < *y;
	}
};

struct DelEven
{
	bool operator()(const int& x) const
	{
		return x % 2 == 0;
	}
};

//void test1()
//{
//	// 优先级队列，其实其特性是二叉树里的堆
//	//priority_queue<int> pq; // 默认是大的优先级高（大堆）
//
//	//由于deque的优点比较适合栈和队列，所以其容器的缺省值会为deque
//	priority_queue<int, deque<int>, greater<int>> pq;   // 调整小的优先级高（小堆）
//
//	pq.push(3);
//	pq.push(5);
//	pq.push(4);
//	pq.push(6);
//	pq.push(1);
//	pq.push(2);
//
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}
//
//void test2()
//{
//	priority_queue<Date1*, vector<Date1*>,PDateLess> pq;
//	pq.push(new Date1(2025, 1, 1));
//	pq.push(new Date1(2025, 1, 3));
//	pq.push(new Date1(2025, 1, 2));
//
//	//在没有写特定的仿函数下，直接是地址比较，这样的比较对于日期类来说是无意义的
//	//这是需根据需要显示写自己所需的仿函数
//	while (!pq.empty())
//	{
//		cout << *pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}

// 仿函数具体作用
//void test3()
//{
//	//vector<int> v1 = { 1,6,1,7,3,8,9,3 };
//	////默认是升序
//	//sort(v1.begin(),v1.end());
//	////使用仿函数来控制成降序
//	//sort(v1.begin(), v1.end(),greater<int>());
//	//for (auto e : v1)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	list<int> l1 = { 1,4,2,3,8,9 };
//	for (auto e : l1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 按某个条件去删除，条件用仿函数控制
//	// 比如删除所有的偶数
//	l1.remove_if(DelEven());
//
//	for (auto e : l1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//int main()
//{
//	//test1();
//	//test2();
//	test3();
//
//	return 0;
//}
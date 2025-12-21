#include<iostream>
#include<queue>
using namespace std;

// 仿函数/函数对象   对象可以像函数一样使用
template<class T>
struct less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y ? x : y;
	}
};

void test()
{
	// 优先级队列，其实其特性是二叉树里的堆
	//priority_queue<int> pq; // 默认是大的优先级高（大堆）

	//由于deque的优点比较适合栈和队列，所以其容器的缺省值会为deque
	priority_queue<int, deque<int>, greater<int>> pq;   // 调整小的优先级高（小堆）

	pq.push(3);
	pq.push(5);
	pq.push(4);
	pq.push(6);
	pq.push(1);
	pq.push(2);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//int main()
//{
//	test();
//	return 0;
//}
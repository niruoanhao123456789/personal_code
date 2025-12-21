#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// 适配器
void test_stack()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void test_queue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.emplace(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

//int main()
//{
//	//test_stack();
//	test_queue();
//
//	return 0;
//}

// deque 双端队列
// vector的优点：1、支持随机访问数据
//				 2、尾部插入与删除效率高
//				 3、CPU高速缓存访问命中率高
//         缺点：1、扩容会有性能损耗，扩容过大会造成内存浪费
//				 2、头部插入删除效率不高

// 对于计算机里的三级缓存：
// 1、检查要访问的数据是否在缓存，在（命中）直接访问
// 2、不在（不命中），先把内存数据加载到缓存中再访问

//list的优点：1、头尾插入删除效率高
//			  2、按需申请与释放空间、空间利用率高
//      缺点：1、不支持随机访问，数据访问效率低

// deque双端队列的优点：1、头尾插入删除效率都不错
//						2、CPU高速缓存命中率也不错，数据访问效率也高
//				  缺点：1、随然支持随机访问，但相对于vector不够极致（其随机访问是基于访问目标位于第几个buffer中来实现的）
//						2、中间插入删除效率低
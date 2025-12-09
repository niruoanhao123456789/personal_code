#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void Print(list<int> l)
{
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test1()
{
	list<int> l1;
	list<int> l2 = { 1,2,3,4,5,6 };
	
	auto pos = find(l2.begin(), l2.end(), 3);
	if (pos != l2.end())
	{
		l2.insert(pos, 30);		// pos迭代器没有失效，因为没有扩容
		l2.erase(pos);			// pos迭代器失效，其相当与野指针
	}
	//Print(l2);

	list<int> l3 = { 4,3,2,1 };
	l3.sort();
	//Print(l3);
	// 算法库的sort不支持list的排序
	// 其要求的迭代器是RandomAccessIterator，而list的是bidirectional iterator
	// sort(l3.begin(), l3.end());

	// 在功能方面迭代器分为：单向forward iterator 支持++ ；双向bidirectional iterator 支持++ -- ；随机RandomAccessIterator 支持++ -- + -

	list<int> l4 = { 1,2,2,3,3,2,3,4,5 };
	Print(l4);
	//l4.unique();	// 去重
	//Print(l4);		// 发现在3后面的2没被去掉
	//所以unique要搭配sort使用
	l4.sort();
	l4.unique();
	Print(l4);

	// 4这个节点挪到头位置
	list<int> l5 = { 1,2,3,4,5 };
	Print(l5);
	pos = find(l5.begin(), l5.end(),4);
	l5.splice(l5.begin(), l5, pos);
	Print(l5);
}

int main()
{
	test1();

	return 0;
}
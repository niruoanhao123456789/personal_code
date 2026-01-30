#include<iostream>
#include<set>
using namespace std;

//void test1()
//{
//	set<int> s;
//	s.insert(3);
//	s.insert(1);
//	s.insert(2);
//	s.insert(5);
//	s.insert(3);
//	s.insert(5);
//	s.insert(6);
//
//	// 去重 + 遍历
//	// set底层是棵不允许等值插入的平衡二叉搜索树
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	int x = 0;
//	cin >> x;
//	s.erase(x);
//
//	// 单纯判断在不在
//	// 在set里因为去重所以元素存在其个数就是一
//	if (s.count(x))
//	{
//
//	}
//
//}

//void test2()
//{
//	set<int> s;
//	//s.insert(3);
//	s.insert(1);
//	s.insert(2);
//	s.insert(5);
//	//s.insert(3);
//	s.insert(5);
//	s.insert(6);
//	s.insert(7);
//	s.insert(9);
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// 删除[3, 8]区间值
//	// >= 3
//	auto it1 = s.lower_bound(3);
//	// > 8
//	auto it2 = s.upper_bound(8);
//	s.erase(it1, it2);
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//void test3()
//{
//	multiset<int> s;
//	s.insert(3);
//	s.insert(1);
//	s.insert(2);
//	s.insert(5);
//	s.insert(3);
//	s.insert(5);
//	s.insert(6);
//	s.insert(3);
//	s.insert(3);
//
//	// 遍历结果：有序
//	// 及支持等值插入
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	multiset<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		// *it = 1; // 不能修改，改变结点的值会破坏整个树的结构
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// 查找中序遍历里的第一个3
//	auto pos = s.find(3);
//
//	while (pos != s.end() && *pos == 3)
//	{
//		cout << *pos << " ";
//		++pos;
//	}
//	cout << endl;
//
//	// [ )
//	//std::pair<multiset<int>::iterator, multiset<int>::iterator> ret = s.equal_range(3);
//	auto ret = s.equal_range(3);
//	cout << s.count(3) << endl;
//	cout << s.erase(3) << endl;
//
//	for (auto e : s)
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
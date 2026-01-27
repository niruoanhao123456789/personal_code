#include<iostream>
#include<list>
#include<vector>
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

//void test1()
//{
//	list<int> l1;
//	list<int> l2 = { 1,2,3,4,5,6 };
//	
//	auto pos = find(l2.begin(), l2.end(), 3);
//	if (pos != l2.end())
//	{
//		l2.insert(pos, 30);		// pos迭代器没有失效，因为没有扩容
//		l2.erase(pos);			// pos迭代器失效，其相当与野指针
//	}
//	//Print(l2);
//
//	list<int> l3 = { 4,3,2,1 };
//	l3.sort();
//	//Print(l3);
//	// 算法库的sort不支持list的排序
//	// 其要求的迭代器是RandomAccessIterator，而list的是bidirectional iterator
//	// sort(l3.begin(), l3.end());
//
//	// 在功能方面迭代器分为：单向forward iterator 支持++ ；双向bidirectional iterator 支持++ -- ；随机RandomAccessIterator 支持++ -- + -
//
//	list<int> l4 = { 1,2,2,3,3,2,3,4,5 };
//	Print(l4);
//	//l4.unique();	// 去重
//	//Print(l4);		// 发现在3后面的2没被去掉
//	//所以unique要搭配sort使用
//	l4.sort();
//	l4.unique();
//	Print(l4);
//
//	// 4这个节点挪到头位置
//	list<int> l5 = { 1,2,3,4,5 };
//	Print(l5);
//	pos = find(l5.begin(), l5.end(),4);
//	l5.splice(l5.begin(), l5, pos);
//	Print(l5);
//}
//
//void test2()
//{
//	srand(time(0));
//	const int N = 1000000;
//
//	list<int> lt1;
//	vector<int> v;
//
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand() + i;
//		lt1.push_back(e);
//		v.push_back(e);
//	}
//
//	int begin1 = clock();
//	// 
//	sort(v.begin(), v.end());
//	int end1 = clock();
//
//	int begin2 = clock();
//	lt1.sort();
//	int end2 = clock();
//
//	printf("vector sort:%d\n", end1 - begin1);
//	printf("list sort:%d\n", end2 - begin2);
//}
//
//void test3()
//{
//	srand(time(0));
//	const int N = 1000000;
//
//	list<int> lt1;
//	list<int> lt2;
//
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand() + i;
//		lt1.push_back(e);
//		lt2.push_back(e);
//	}
//
//	int begin1 = clock();
//	// vector
//	vector<int> v(lt2.begin(), lt2.end());
//	// 
//	sort(v.begin(), v.end());
//
//	// lt2
//	lt2.assign(v.begin(), v.end());
//
//	int end1 = clock();
//
//	int begin2 = clock();
//	lt1.sort();
//	int end2 = clock();
//
//	printf("list copy vector sort copy list sort:%d\n", end1 - begin1);
//	printf("list sort:%d\n", end2 - begin2);
//}
// 物理上连续空间的vector的排序要比list的优，当要对list的大量数据进行排序时可以用vector装这些数据，在vector排好后再放回list 

//int main()
//{
//	//test1();
//	//test2();
//	test3();
//
//	return 0;
//}
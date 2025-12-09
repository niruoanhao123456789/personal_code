#include<iostream>
#include<vector>
using namespace std;

void Print(const vector<int>& v)
{
	// 法一
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	// 法二
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << "";
	//}
	//cout << endl;

	// 法三
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void vector_test1()
{
	vector<int> v1;
	// explicit vector (size_type n, const value_type& val = value_type(),
	//					const allocator_type& alloc = allocator_type());
	vector<int> v2(10, 2);// 十个数据全初始化为2
	Print(v2);
	string s1("xxxxxxxxxxxxxx");		//类似于隐式类型转换
	vector<int> v3(s1.begin(), s1.end());
	vector<int> v4(v3);

	//vector<int> v5({ 1,2,3,4,5 });		//{}为initializer_list
	vector<int> v6 = { 1,2,3,4,5,6 };

	auto il = { 10, 20, 30,1,2,2 };
	for (auto e : il)						// the type of il is an initializer_list
	{
		cout << e << " ";
	}
	cout << endl;
}

void vector_test2()
{
	vector<int> v1;
	const int n = 3;
	v1.reserve(n);			//关于预先知道扩容大小，使用reserve的会带来的效率提升
	size_t begin = clock();
	for (size_t i = 0; i < n; i++)
	{
		v1.push_back(i);
	}
	size_t end = clock();
	cout << end - begin << endl;

	vector<int> v2;
	v2.resize(100, 1);
	Print(v2);

}

void vector_test3()
{
	vector<int> v1 = { 1,2,3,4,5 };
	v1.push_back(6);

	v1.insert(v1.end(), 7);
	v1.insert(v1.begin(), 0);
	Print(v1);
	v1.insert(v1.begin() + 3, 3);
	Print(v1);

	v1.erase(v1.begin());
	Print(v1);
	v1.erase(v1.begin() + 3);
	Print(v1);
}

struct AA
{
	int _a1 = 1;
	int _a2 = 1;

	AA(int a1 = 1, int a2 = 1)
		:_a1(a1)
		, _a2(a2)
	{
	}
};

void vector_test4()
{
	AA aa1 = { 0, 0 };
	vector<AA> v = { aa1,{1,1},{2,2} };
	auto it = v.begin();
	while (it != v.end())
	{
		cout << it->_a1 << "," << it->_a2 << endl;
		++it;
	}
	cout << endl;

	// 只能传AA对象
	v.push_back(aa1);

	// 可以传AA对象，也可以传构造AA对象的参数
	v.emplace_back(aa1);
	v.emplace_back(aa1._a1,aa1._a2);

	v.emplace_back(1, 1);
	v.push_back({ 2,2 });


	it = v.begin();
	while (it != v.end())
	{
		cout << it->_a1 << "," << it->_a2 << endl;
		++it;
	}
	cout << endl;
}

//int main()
//{
//	//vector_test1();
//	//vector_test2();
//	//vector_test3();
//	//vector_test4();
//
//	return 0;
//}
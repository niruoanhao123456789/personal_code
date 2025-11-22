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

int main()
{
	//vector_test1();
	//vector_test2();

	return 0;
}
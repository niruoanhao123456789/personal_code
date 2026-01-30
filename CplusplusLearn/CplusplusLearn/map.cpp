#include<iostream>
#include<string>
#include<map>
using namespace std;

//void test1()
//{
//	map<string, string> dict;
//	// c++98
//	pair<string, string> kv1("sort", "排序");
//	dict.insert(kv1);
//	dict.insert(pair<string, string>("left", "左边"));
//	dict.insert(make_pair("right", "右边"));
//
//	// c++11
// 
// // 插入加查找
// // pair<iterator,bool> insert (const value_type& val);
// // 如果要插入的key已经存在，返回<key所在节点的迭代器，false>
// // 如果要插入的key不存在，返回<新插入的key所在节点的迭代器，true>
// 
//	dict.insert({ "right", "右边" });
//	//dict.insert({kv1, pair<string, string>("left", "左边")});
// 
// // void insert (initializer_list<value_type> il)
//	dict.insert({ {"string", "字符串"}, {"map", "图,映射"} });
//
//	// key相同就不会再插入，value不相同也不会插入
//	dict.insert({ "right","右边xxx" });
//
//	map<string, string>::iterator it = dict.begin();
//	while (it != dict.end())
//	{
//		//cout << (*it).first <<":"<< (*it).second << endl;
//		cout << it->first << ":" << it->second << endl;
//		//cout << it.operator->()->first << ":" << it.operator->()->second << endl;
//		++it;
//	}
//	cout << endl;
//
//	for (auto& e : dict)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	cout << endl;
//
//	//  结构化绑定 C++17
//	auto [x, y] = kv1; // 考虑到深拷贝问题，不建议这么写
//	//for (auto [k, v] : dict)
//	//for (auto& [k, v] : dict)
//	for (const auto& [k, v] : dict)
//	{
//		cout << k << ":" << v << endl;
//	}
//	cout << endl;
//
//	auto pos = dict.find("left");
//	if (pos != dict.end())
//	{
//		dict.erase(pos);
//	}
//
//	for (const auto& [k, v] : dict)
//	{
//		cout << k << ":" << v << endl;
//	}
//	cout << endl;
//}

//void test2()
//{
//	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
//	map<string, int> countMap;
//
//	//for (auto& e : arr)
//	//{
//	//	auto it = countMap.find(e);
//	//	if (it != countMap.end())
//	//	{
//	//		it->second++;
//	//	}
//	//	else
//	//	{
//	//		countMap.insert({e,1});
//	//	}
//	//}
//
//	for (auto& e : arr)
//	{
//		countMap[e]++;
//	}
//
//	for (const auto& [k , v] : countMap)
//	{
//		cout << k << ":" << v << endl;
//	}
//
//
//	// (*((this->insert(make_pair(k,mapped_type()))).first)).second
//	// 
//	// (this->insert(make_pair(k,mapped_type())))		->		pair<iterator,bool>
//	// ((this->insert(make_pair(k,mapped_type()))).first)		->		iterator
//	// *((this->insert(make_pair(k,mapped_type()))).first)		->		pair<key_type,map_type>
//	// (*((this->insert(make_pair(k,mapped_type()))).first)).second		->		map_type
//
//	map<string, string> dict;
//	// 插入
//	dict["sort"];
//	// 插入 + 修改
//	dict["left"] = "左边";
//	// 修改
//	dict["sort"] = "排序";
//	// 查找
//	cout << dict["sort"] << endl;
//
//	// 纯粹的查找+修改
//	// at
//	dict.at("sort") = "xxx";
//	// key不存在，会抛异常
//	// dict.at("insert") = "xxxxx";
//}

//void test3()
//{
//	multimap<string, string> dict;
//	dict.insert({ "right", "右边" });
//	dict.insert({ "left", "左边" });
//	dict.insert({ "right", "右边xx" });
//	dict.insert({ "right", "右边" });
//
//
//	for (const auto& [k, v] : dict)
//	{
//		cout << k << ":" << v << endl;
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
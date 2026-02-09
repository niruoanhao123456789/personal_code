#include<iostream>
#include<unordered_map>
#include"hash.h"
using namespace std;

namespace open_address
{
	void TestHT1()
	{
		//int a[] = { 19,30,5,36,13,20,21,12,58 };
		int a[] = { 5,58 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert({ e, e });
		}

		ht.Insert({ -2, 2 });
		ht.Insert({ 22, 22 });

		cout << ht.Find(5) << endl;

		ht.Erase(5);

		cout << ht.Find(5) << endl;
		cout << ht.Find(58) << endl;
	}

	struct HashFuncString
	{
		// BKDR
		size_t operator()(const string& key)
		{
			size_t hash = 0;
			for (auto ch : key)
			{
				hash += ch;
				hash *= 131;
			}

			return hash;
		}
	};

	void TestHT2()
	{
		//HashTable<string, string, HashFuncString> dict;
		HashTable<string, string> dict;
		dict.Insert({ "string", "字符串" });
		dict.Insert({ "string", "字符串1" });
		dict.Insert({ "left", "左边" });
		dict.Insert({ "right", "右边" });

		cout << dict.Find("string") << endl;
		cout << dict.Find("left") << endl;
		cout << dict.Find("left ") << endl;

		HashFuncString hfs;
		cout << hfs("abcd") << endl;
		cout << hfs("acbd") << endl;
		cout << hfs("aadd") << endl;

		unordered_map<string, string> dictmap;
		dictmap.insert({ "string", "字符串" });

		// 编译报错，需要自己实现Hash的仿函数把key转成整形
		//unordered_map<pair<string, int>, string> um;
		//um.insert({ {"string", 1}, "字符串" });
	}
}

int main()
{
	//open_address::TestHT1();
	//open_address::TestHT2();
	return 0;
}
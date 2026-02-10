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
		dict.Insert({ "string", "×Ö·û´®" });
		dict.Insert({ "string", "×Ö·û´®1" });
		dict.Insert({ "left", "×ó±ß" });
		dict.Insert({ "right", "ÓÒ±ß" });

		cout << dict.Find("string") << endl;
		cout << dict.Find("left") << endl;
		cout << dict.Find("left ") << endl;

		HashFuncString hfs;
		cout << hfs("abcd") << endl;
		cout << hfs("acbd") << endl;
		cout << hfs("aadd") << endl;

		unordered_map<string, string> dictmap;
		dictmap.insert({ "string", "×Ö·û´®" });

		// ±àÒë±¨´í£¬ÐèÒª×Ô¼ºÊµÏÖHashµÄ·Âº¯Êý°Ñkey×ª³ÉÕûÐÎ
		//unordered_map<pair<string, int>, string> um;
		//um.insert({ {"string", 1}, "×Ö·û´®" });
	}
}

namespace hash_bucket
{
	void TestHT1()
	{
		int a[] = { 19,30,5,36,13,20,21,12,58 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert({ e, e });
		}

		ht.Insert({ -2, 2 });
		ht.Insert({ 22, 22 });
		ht.Insert({ 44, 44 });

		ht.Erase(58);
		ht.Erase(36);
	}

	void TestHT2()
	{
		HashTable<string, string> dict;
		dict.Insert({ "string", "×Ö·û´®" });
		dict.Insert({ "string", "×Ö·û´®1" });
		dict.Insert({ "left", "×ó±ß" });
		dict.Insert({ "right", "ÓÒ±ß" });

		cout << dict.Find("string") << endl;
		cout << dict.Find("left") << endl;
		cout << dict.Find("left ") << endl;
	}
}


int main()
{
	//open_address::TestHT1();
	//open_address::TestHT2();

	hash_bucket::TestHT1();
	hash_bucket::TestHT2();

	return 0;
}
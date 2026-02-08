#include<iostream>
#include"set.h"
#include"map.h"
#include"RBTree.h"
using namespace std;

void test_set()
{
	Set::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(1);
	s.insert(5);
	s.insert(0);
	s.insert(10);
	s.insert(8);

	Set::set<int>::iterator it = s.begin();
	// *it += 10;
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

void test_map()
{
	Map::map<string, string> dict;
	dict.insert({ "sort", "ÅÅĞò" });
	dict.insert({ "left", "×ó±ß" });
	dict.insert({ "right", "ÓÒ±ß" });

	dict["string"] = "×Ö·û´®"; // ²åÈë+ĞŞ¸Ä
	dict["left"] = "×ó±ßxxx";  // ĞŞ¸Ä

	auto it = dict.begin();
	while (it != dict.end())
	{
		// it->first += 'x'; // ²»ÄÜĞŞ¸Ä
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& [k, v] : dict)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;

	string arr[] = { "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };
	Map::map<string, int> countMap;
	for (auto& e : arr)
	{
		/*auto it = countMap.find(e);
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert({ e, 1 });
		}*/
		countMap[e]++;
	}

	for (auto& [k, v] : countMap)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;
}

int main()
{
	//test_set();
	test_map();

	return 0;
}
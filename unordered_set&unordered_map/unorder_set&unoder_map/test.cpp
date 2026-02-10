#include<iostream>
#include"unordered_map.h"
#include"unordered_set.h"
using namespace std;

namespace bit
{
	void test_set()
	{
		unordered_set<int> us;
		us.insert(3);
		us.insert(1000);
		us.insert(2);
		us.insert(102);
		us.insert(2111);
		us.insert(22);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			// *it = 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert({ "string", "1"});
		dict.insert({ "string", "ַ字符串"});
		dict.insert({ "left", "" });
		dict.insert({ "right", "右边" });
		// ޸
		dict["left"] = "左边";

		// 
		dict["insert"];

		//
		dict["map"] = "映射";

		for (auto& [k, v] : dict)
		{
			//k += 'x';
			//v += 'x';

			cout << k << ":" << v << endl;
		}
	}
}

int main()
{
	bit::test_set();
	bit::test_map();

	return 0;
}
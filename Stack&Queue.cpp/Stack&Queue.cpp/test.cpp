#include<iostream>
#include"Stack.h"
#include"Queue.h"
using namespace std;

namespace my
{
	void test1()
	{
		//stack<int, vector<int>> st;
		//stack<int, list<int>> st;
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}

	void test2()
	{
		queue<int> q;
		q.push(4);
		q.push(5);
		q.push(6);
		while (!q.empty())
		{
			cout << q.front()<<" ";
			q.pop();
		}
		cout << endl;
	}
}
using namespace my;

int main()
{
	test1();
	test2();

	return 0;
}
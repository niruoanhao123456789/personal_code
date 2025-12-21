#include<iostream>
#include"priority_queue.h"
using namespace std;

namespace heap
{
	void test1()
	{
		int arr[] = { 1,3,5,2,4 };
		priority_queue<int> pq(arr, arr + 5);
		pq.push(7);
		pq.push(6);
		pq.push(9);
		pq.push(8);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}

int main()
{
	heap::test1();

	return 0;
}
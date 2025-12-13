#pragma once
#include<vector>
#include<list>
#include<deque>

namespace my
{
	// 以下这种写法无法突出适配器的特点
	//template<class T>
	//class stack
	//{
	//	// ...
	//private:
	//	T* _a;
	//	size_t _top;
	//	size_T _capacity;
	//};

	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}
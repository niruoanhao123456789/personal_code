#pragma once
#include<vector>

namespace heap
{
	//利用仿函数实现建大小堆的快速替换
	template<class T>
	struct Less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct Greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	// 默认是建大堆
	template<class T, class Container = std::vector<T>,class Compare = Less<T>>
	class priority_queue
	{
	public:

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first,last)
		{
			for (int i = (_con.size() - 2 / 2); i >= 0; i--)
			{
				adjust_down(i);
			}
		}


		// 强制编译器生成默认构造
		priority_queue() = default;

		void adjust_up(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				//if (_con[parent] < _con[child])
				if(com(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}

		void adjust_down(int parent)
		{
			Compare com;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				//if (child+1<_con.size()&&_con[child] < _con[child + 1])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
					child++;

				//if (_con[child] > _con[parent])
				//if (_con[parent] < _con[child])
				if(com(_con[parent],_con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size()-1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		const T& top() const
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}
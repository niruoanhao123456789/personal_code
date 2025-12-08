#pragma once
#include<assert.h>
#include<iostream>
#include<stdbool.h>

namespace my_vector
{
	template<class T>
	class vector
	{
	public:
		// typedef T* iterator;
		using iterator = T*;
		using const_iterator = const T*;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
		{
		}

		vector(std::initializer_list<T> il)
		{
			reserve(il.size());
			for (const auto& e : il)
			{
				push_back(e);
			}
		}


		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _finish = _end_of_storage = nullptr;
			}

		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		// c++ 对内置类型进行了升级，使其有了构造和析构的过程
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		// 传统写法
		// v2(v1)
		//vector(const vector<T>& v)
		//{
		//	reserve(v.capacity());
		//	for (const auto& e : v)			// 如果单纯使用auto e:v，但v是复杂的类型，则v每次赋值给e时都会有拷贝构造和析构的过程，代价高。
		//	{								// 所以得使用const auto& e : v
		//		push_back(e);
		//	}
		//}

		//// v2 = v1
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		clear();
		//		reserve(v.capacity());
		//		for (const auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			// reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}

		}

		// 现代写法
		vector(const vector<T>& v)
		{
			vector<T>tmp(v.begin(), v.end());
			swap(tmp);
		}

		vector<T>& operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		void clear()
		{
			_finish = _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						// 如果是string，调用string的赋值深拷贝
						//tmp[i] = _start[i];
						
						// 深拷贝对于交换而言没那么优
						// 因要被拷贝的对象是要析构的，所该空间被创建但很快被销毁，多出了构造和析构的操作，某种意义上是个性能被浪费的环节
						std::swap(tmp[i], _start[i]);
					}

					//memcpy(tmp, _start, sizeof(T)*sz);	// 此处进行的是浅拷贝
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, T val = T())
		{
			if (size() > n)
			{
				// 删除数据
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(empty());
			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				it++;
			}
			_finish--;

			return pos;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
}
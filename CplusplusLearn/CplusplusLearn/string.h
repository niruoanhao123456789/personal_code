#pragma once
#include<cstring>
#include<assert.h>
#include<algorithm>

namespace my_string
{
	class string
	{
	public:
		class string(const char* str = "");		// ""为字符串，其自带了'\0'

		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size && pos>=0);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size && pos >= 0);
			return _str[pos];
		}

		size_t size() const
		{
			return _size;
		}

		const char* c_str() const
		{
			return _str;
		}

		void reserve(size_t n);
		void push_back(const char ch);
		void append(const char* str);

		string& operator+=(const char* str)
		{
			assert(str);
			append(str);
			return *this;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = npos);

		~string();

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		// const static目前只有整形可以这么用，特殊处理
		const static size_t npos = -1;

		// 或者声明与定义分离
		//const static size_t npos；
	};
}
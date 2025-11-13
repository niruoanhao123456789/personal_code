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
		void push_back(char ch);
		void append(const char* str);

		~string();

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
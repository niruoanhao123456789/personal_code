#pragma once
#include<cstring>
#include<assert.h>
#include<algorithm>
#include<iostream>

namespace my_string
{
	class string
	{
	public:
		string(const char* str = "");		// ""为字符串，其自带了'\0'
		string(const string& s);
		string& operator=(const string& s);

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
		void resize(size_t n, char ch = '\0');
		void push_back(const char ch);
		void append(const char* str);
		void swap(string& s);
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

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
		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);

		string substr(size_t pos = 0, size_t len = npos);
		bool operator<(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;


		~string();

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		// const static目前只有整形可以这么用，特殊处理
		const static size_t npos = -1;

		// 或者声明与定义分离
		//const static size_t npos；
	};

	std::ostream& operator<<(std::ostream& out, const string& s);
	std::istream& operator>>(std::istream& in, string& s);
	std::istream& getline(std::istream& is, string& str, char delim = '\n');

	// 模拟algorithm算法库中的swap模板，其进行的是深拷贝，在交换过程中进行了三次深拷贝，拷贝代价太高
	template <class T>
	void swap(T& a, T& b)
	{
		T c(a); a = b; b = c;
	}

	// string中的实现的swap
	// void swap(string& s);

	// 为了适配算法库或者更常见的swap用法，所以将string里的swap封装为一个全局函数
	inline void swap(string& a, string& b)
	{
		a.swap(b);
	}
}
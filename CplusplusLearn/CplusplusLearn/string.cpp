#include"string.h"

namespace my_string
{
	//const static size_t npos = -1;

	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size;
		strncpy(_str, str, _size + 1);
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n];
			strncpy(tmp, _str, _size+1);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(const char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		assert(str);
		size_t len = strlen(str);
		if (len + _size > _capacity)
		{
			reserve(std::max(_size + len, _capacity * 2));		//为了避免频繁扩容，又能保证空间足够，故扩二者间最大值
		}
		strncpy(_str + _size, str, len + 1);
		_size += len;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos >= 0 && pos <= _size);
		if (_size >= _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		long long end = _size;
		// 不同类型进行计算时会进行类型转换，而整型间会涉及整型提升，类型小的向类型大转换，有符号向无符号转换
		// 将pos在while()中强转为有符号类型，为了使其在头插时，end能变成负数退出循环
		while (end >= (long long)pos)
		{									
			_str[end + 1] = _str[end];		// 最后的'\0'也要挪动
			end--;
		}
		_str[pos] = ch;
		_size++;
	}

	void string::insert(size_t pos, const char* str)
	{
		assert(pos >= 0 && pos <= _size);
		assert(str);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(std::max(_size + len, _capacity * 2));
		}
		long long end = _size;
		while (end >= (long long)pos)
		{
			_str[end + len] = _str[end];
			end--;
		}
		for (size_t i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}
		_size += len;
	}

	void string::erase(size_t pos, size_t len)
	{
		assert(pos >= 0 && pos <= _size);
		size_t begin = pos;
		if (len == npos || pos + len > _size)
		{
			_str[pos] = '\0';
		}
		else
		{
			while (begin + len <= _size)
			{
				_str[begin] = _str[begin + len];
				begin++;
			}
			_str[begin] = '\0';
		}
	}
}
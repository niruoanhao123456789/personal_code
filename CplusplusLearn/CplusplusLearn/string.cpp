#include"string.h"

namespace my_string
{
	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size + 1;
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

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{

		}
	}
}
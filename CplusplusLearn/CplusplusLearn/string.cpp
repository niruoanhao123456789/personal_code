#include"string.h"

namespace my_string
{
	//const static size_t npos = -1;

	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size;
		memcpy(_str, str, _size + 1);
	}

	string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		memcpy(_str, s._str, s._size + 1);
		_size = s._size;
		_capacity = s._capacity;
	}

	string& string::operator=(const string& s)
	{
		// 进行深拷贝
		if (this != &s)
		{
			char* tmp = new char[s._capacity + 1];
			memcpy(tmp, s._str, s._size + 1);
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
		}

		return *this;
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
			memcpy(tmp, _str, _size+1);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::resize(size_t n, char ch)
	{
		if (n <= _size)
		{
			_size = n;
			_str[n] = '\0';
		}
		else
		{
			reserve(n);
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
			_size = n;
			_str[_size] = '\0';
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
		memcpy(_str + _size, str, len + 1);
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
		assert(pos >= 0 && pos < _size);		//删除删的是\0前面的有效字符，所以pos < _size
		size_t begin = pos;
		if (len == npos || pos + len >=  _size)
		{
			_str[begin] = '\0';
			_size = begin;
		}
		else
		{
			while (begin + len <= _size)
			{
				_str[begin] = _str[begin + len];
				begin++;
			}
			_size -= len;
		}
	}

	size_t string::find(char ch, size_t pos)
	{
		assert(pos >= 0 && pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}

		return npos;
	}

	size_t string::find(const char* str, size_t pos)
	{
		assert(pos >= 0 && pos < _size && str);
		const char* ptr = strstr(_str+pos, str);
		if (ptr)
		{
			return ptr - _str;
		}
		else
		{
			return npos;
		}
	}

	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size&&pos>=0);

		if (len == npos || len > _size - pos)
		{
			len = _size - pos;
		}

		string sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			sub += _str[pos + i];
		}

		return sub;
	}

	bool string::operator==(const string& s) const
	{
		return strcmp(_str, s._str) == 0;
	}

	bool string::operator!=(const string& s) const
	{
		return !(*this == s);
	}

	bool string::operator<(const string& s) const
	{
		return strcmp(_str, s._str) < 0;
	}

	bool string::operator<=(const string& s) const
	{
		return *this < s || *this == s;
	}

	bool string::operator>(const string& s) const
	{
		return strcmp(_str, s._str) > 0;
	}

	bool string::operator>=(const string& s) const
	{
		return *this > s || *this == s;
	}

	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();

		// 使用缓存区来减少扩容的次数
		char buff[256] = { 0 };
		int i = 0;
		char ch = 0;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 255)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	std::istream& getline(std::istream& is, string& str, char delim)
	{
		str.clear();

		// 使用缓存区来减少扩容的次数
		char buff[256] = { 0 };
		int i = 0;
		char ch = 0;
		ch = is.get();
		while (ch != delim)
		{
			buff[i++] = ch;
			if (i == 255)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			ch = is.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}

		return is;
	}

	void string::swap(string& s)
	{
		// 进行的是浅拷贝，交换两个指针值
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
}
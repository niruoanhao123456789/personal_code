#pragma once
#include<assert.h>

namespace my_vector
{
	template<class T>
	class vector
	{
	public:
		// typedef T* iterator;
		using iterator = T*;
		using const_iterator = const T*;

		vector()
			: _start(nullptr)
			, _finsh(nullptr)
			, _end_of_storage(nullptr)
		{
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finsh = _end_of_storage = nullptr;
			}
		}

	private:
		iterator _start;
		iterator _finsh;
		iterator _end_of_storage;
	};
}
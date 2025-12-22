#pragma once
#include<iostream>

namespace my_list
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _data;

		ListNode(const T& x = T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(x)
		{
		}
	};

	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		using Self = list_iterator<T, Ref,Ptr>;
		using Node = ListNode<T>;
		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{
		}

		// *it = 1
		// Ref实例化为 T& 或 const T&
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		// ++it
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// --it
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};

	template<class Iterator, class Ref, class Ptr>
	struct list_reverse_iterator
	{
		using Self = list_reverse_iterator<Iterator, Ref, Ptr>;
		Iterator _it;

		list_reverse_iterator(Iterator it)
			:_it(it)
		{
		}

		Ref operator*()
		{
			return (*_it);
		}

		Ptr operator->()
		{
			return &(*_it);
		}

		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			--_it;
			return tmp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			++_it;
			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _it != s._it;
		}

		bool operator==(const Self& s) const
		{
			return _it == s._it;
		}

	};

	// 可以发现要实现list_const_itterator的过程和list_iterator一样，如何化简代码有上面的方案
	// 设计迭代器的类
	//template<class T>
	//struct list_iterator
	//{
	//	using Self = list_iterator<T>;
	//	using Node = ListNode<T>;
	//	Node* _node;

	//	list_iterator(Node* node)
	//		:_node(node)
	//	{
	//	}

	//	// *it = 1
	//	T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	Self& operator++(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	Self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	Self& operator--(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	bool operator!=(const Self& s) const
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const Self& s) const
	//	{
	//		return _node == s._node;
	//	}
	//};

	//template<class T>
	//struct list_const_iterator
	//{
	//	using Self = list_const_iterator<T>;
	//	using Node = ListNode<T>;
	//	Node* _node;

	//	list_const_iterator(Node* node)
	//		:_node(node)
	//	{}

	//	// *it
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	// ++it
	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	Self operator++(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	// --it
	//	Self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	Self operator--(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	bool operator!=(const Self& s) const
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const Self& s) const
	//	{
	//		return _node == s._node;
	//	}
	//};

	template<class T>
	class list
	{
		using Node = ListNode<T>;
	public:
		using iterator = list_iterator<T, T&, T*>;
		using const_iterator = list_iterator<T, const T&, const T*>;
		using reverse_iterator = list_reverse_iterator<iterator, T&, T*>;
		using const_reverse_iterator = list_reverse_iterator<const_iterator, const T&, const T*>;
		
		// using iterator = list_iterator<T>;
		// using const_iterator = list_const_iterator<T>;

		void EmptyInit()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			EmptyInit();
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
			_size = 0;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(--end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(end());
		}

		//const_reverse_iterator rbegin() const
		//{
		//	return const_reverse_iterator(--end());
		//}

		//const_reverse_iterator rend() const
		//{
		//	return const_reverse_iterator(end());
		//}

		list(std::initializer_list<T> il)
		{
			EmptyInit();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			EmptyInit();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(size_t n, T val = T())
		{
			EmptyInit();
			size_t i = 0;
			for (i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		list(int n, T val = T())
		{
			EmptyInit();
			int i = 0;
			for (i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		// 传统写法
		list(const list<T>& lt)
		{
			EmptyInit();
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (const auto& e : lt)
				{
					push_back(e);
				}
			}
			return *this;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		//void push_back(const T& x)
		//{
		//	Node* newnode = new Node(x);
		//	Node* tail = _head->_prev;
		//	tail->_next = newnode;
		//	newnode->_next = _head;
		//	newnode->_prev = tail;
		//	_head->_prev = newnode;
		//	_size++;
		//}

		void push_back(const T& x)
		{
			insert(end(),x);
		}

		//void push_front(const T& x)
		//{
		//	Node* newnode = new Node(x);
		//	Node* next = _head->_next;
		//	_head->_next = newnode;
		//	newnode->_prev = _head;
		//	newnode->_next = next;
		//	next->_prev = newnode;
		//	_size++;
		//}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		//void pop_back()
		//{
		//	Node* cur = _head->_prev;
		//	if (cur != _head)
		//	{
		//		Node* next = cur->_next;
		//		Node* prev = cur->_prev;
		//		prev->_next = next;
		//		next->_prev = prev;
		//		delete cur;
		//		_size--;
		//	}
		//}

		void pop_back()
		{
			erase(--end());
		}

		//void pop_front()
		//{
		//	Node* cur = _head->_next;
		//	if (cur != _head)
		//	{
		//		Node* next = cur->_next;
		//		Node* prev = cur->_prev;
		//		prev->_next = next;
		//		next->_prev = prev;
		//		delete cur;
		//		_size--;
		//	}
		//}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* next = cur->_next;
			Node* prev = cur->_prev;
			if (cur != _head)
			{
				prev->_next = next;
				next->_prev = prev;
				delete cur;
				_size--;
			}
			//return iterator(next);
			return next;
		}

		size_t size() const
		{
			return _size;
		}

	private:
		Node* _head;
		size_t _size = 0;
	};
}
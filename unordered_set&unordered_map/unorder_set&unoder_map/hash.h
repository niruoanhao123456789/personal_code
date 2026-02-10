#pragma once
#include<vector>
#include<string>
#include<algorithm>

static const int __stl_num_primes = 28;
static const unsigned long __stl_prime_list[__stl_num_primes] =
{
  53,         97,         193,       389,       769,
  1543,       3079,       6151,      12289,     24593,
  49157,      98317,      196613,    393241,    786433,
  1572869,    3145739,    6291469,   12582917,  25165843,
  50331653,   100663319,  201326611, 402653189, 805306457,
  1610612741, 3221225473, 4294967291
};

inline unsigned long __stl_next_prime(unsigned long n)
{
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	// >= n
	const unsigned long* pos = std::lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 特化
template<>
struct HashFunc<std::string>
{
	size_t operator()(const std::string& key)
	{
		size_t hash = 0;
		for (auto ch : key)
		{
			hash += ch;
			hash *= 131;
		}

		return hash;
	}
};

	template<class V>
	struct HashNode
	{
		V _data;
		HashNode* _next;

		HashNode(const V& data)
			:_data(data)
			, _next(nullptr)
		{ }
	};

	template<class K, class V, class KeyOfT, class Hash>
	class HashTable;

	template<class K,class V,class Ref,class Ptr,class KeyOfT,class Hash>
	struct HTIterator
	{
		using Node = HashNode<V>;
		using HT = HashTable<K, V, KeyOfT, Hash>;
		using Self = HTIterator<K, V, Ref, Ptr, KeyOfT, Hash>;

		Node* _node;
		const HT* _pht;

		HTIterator(Node* node,const HT* pht)
			:_node(node)
			, _pht(pht)
		{ }

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				Hash hs;
				// 算出当前所在桶的位置
				size_t hashi = hs(kot(_node->_data)) % _pht->_tables.size();
				hashi++;
				while (hashi < _pht->_tables.size())
				{
					// 找到下一个不为空的桶
					if (_pht->_tables[hashi])
					{
						_node = _pht->_tables[hashi];
						break;
					}
					else
					{
						hashi++;
					}
				}

				if (hashi == _pht->_tables.size()) // 最后一个桶走完了,要++到end()位置
				{
					_node = nullptr;
				}
			}
			return *this;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}
	};

	// hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	// hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
	template<class K, class V, class KeyOfT, class Hash>
	class HashTable
	{
		template<class K, class V, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct HTIterator;

		using Node = HashNode<V>;
	public:
		using Iterator = HTIterator<K, V, V&, V*, KeyOfT, Hash>;
		using const_Iterator = HTIterator<K, V, const V&, const V*, KeyOfT, Hash>;

		HashTable()
			:_tables(__stl_next_prime(1),nullptr)
			,_n(0)
		{
		}

		~HashTable()
		{
			size_t i = 0;
			for (i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
			_n = 0;
		}

		Iterator Begin()
		{
			if (_n == 0)
				return { nullptr,this };

			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return { _tables[i],this };
				}
			}

			return { nullptr,this };
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		const_Iterator Begin() const
		{
			if (_n == 0)
				return { nullptr,this };

			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return { _tables[i],this };
				}
			}

			return { nullptr,this };
		}

		const_Iterator End() const
		{
			return const_Iterator(nullptr, this);
		}

		std::pair<Iterator,bool> Insert(const V& data)
		{
			KeyOfT kot;
			if (auto it = Find(kot(data)); it != End())
				return {it,false};

			Hash hs;
			// 负载因子 == 1就开始扩容
			if (_n == _tables.size())
			{
				std::vector<Node*> newtables(__stl_next_prime(_tables.size() + 1), nullptr);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						// 头插
						size_t hashi = hs(kot(cur->_data)) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtables);
			}
			size_t hashi = hs(kot(data)) % _tables.size();
			// 头插
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			_n++;

			return { Iterator (newnode,this),true};
		}

		Iterator Find(const K& key)
		{
			Hash hs;
			KeyOfT kot;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return {cur,this};
				}
				cur = cur->_next;
			}
			return { nullptr ,this};
		}

		bool Erase(const K& key)
		{
			Hash hs;
			KeyOfT kot;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					_n--;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

	private:
		std::vector<Node*> _tables;
		size_t _n;
	};

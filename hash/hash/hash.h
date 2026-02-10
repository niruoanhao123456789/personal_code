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

namespace open_address
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		std::pair<K, V> _kv;
		State _state = EMPTY;
	};


	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_tables(__stl_next_prime(1))
			, _n(0)
		{
		}

		bool Insert(const std::pair<K, V> kv)
		{
			if (Find(kv.first))
				return false;

			// 负载因子 >= 0.7就扩容
			if ((double)_n / (double)_tables.size() >= 0.7)
			{
				//std::vector<HashData> newtables(_tables.size()*2);
				//for (size_t i = 0; i < _tables.size(); i++)
				//{
				//	if (_tables[i]._state == EXIST)
				//	{
				//		// 重新映射到新表
				//		// ...
				//	}
				//}
				//_tables.swap(newtables);
				HashTable<K, V, Hash> newht;
				newht._tables.resize(__stl_next_prime(_tables.size() + 1));
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// 遍历旧表，旧表数据插入到newht
					if (_tables[i]._state == EXIST)
					{
						newht.Insert(_tables[i]._kv);
					}
				}
				_tables.swap(newht._tables);
			}

			Hash hs;
			size_t hash_base = hs(kv.first) % _tables.size();
			// 线性探测
			size_t i = 1;
			size_t hashi = hash_base;
			while (_tables[hashi]._state == EXIST)
			{
				hashi = (hash_base + i) % _tables.size();
				i++;
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			_n++;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hs;
			size_t hash_base = hs(key) % _tables.size();
			// 线性探测
			size_t i = 1;
			size_t hashi = hash_base;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state != DELETE && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				hashi = (hash_base + i) % _tables.size();
				i++;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				_n--;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		std::vector<HashData<K, V>> _tables;
		size_t _n;
	};
}

namespace hash_bucket
{
	template<class K,class V>
	struct HashNode
	{
		std::pair<K, V> _kv;
		HashNode* _next;

		HashNode(const std::pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{ }
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		using Node = HashNode<K, V>;
	public:
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

		bool Insert(const std::pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

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
						size_t hashi = hs(cur->_kv.first) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtables);
			}
			size_t hashi = hs(kv.first) % _tables.size();
			// 头插
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			_n++;

			return true;
		}

		Node* Find(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
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
}
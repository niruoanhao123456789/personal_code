#pragma once
#include"hash.h"

namespace bit
{
	template<class K,class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		using iterator = typename HashTable<K, const K, SetKeyOfT, Hash>::Iterator;
		using const_iterator = typename HashTable<K, const K, SetKeyOfT, Hash>::const_Iterator;

		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		const_iterator begin() const
		{
			return _ht.Begin();
		}

		const_iterator end() const
		{
			return _ht.End();
		}

		std::pair<iterator,bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}

	private:
		HashTable<K, const K, SetKeyOfT, Hash> _ht;
	};
}
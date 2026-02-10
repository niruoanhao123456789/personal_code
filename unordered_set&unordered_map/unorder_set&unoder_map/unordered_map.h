#pragma once
#include"hash.h"

namespace bit
{
	template<class K,class V,class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		using iterator = typename HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash>::Iterator;
		using const_iterator = typename HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash>::const_Iterator;

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

		std::pair<iterator, bool> insert(const std::pair<K,V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			std::pair<iterator, bool> ret = insert({ key,V() });
			return ret.first->second;
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
		HashTable<K, std::pair<const K,V>, MapKeyOfT, Hash> _ht;
	};
}
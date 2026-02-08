#pragma once
#include"RBTree.h"

namespace Map
{
	template<class K,class V>
	class map
	{
		struct MapKeyOFT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOFT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOFT>::const_Iterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		const_iterator begin() const
		{
			return _t.Begin();
		}

		const_iterator end() const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}

		V& operator[](const K& key)
		{
			//pair<iterator, bool> ret = _t.Insert({key,V()});
			auto [it,flag] = _t.Insert({ key,V() });
			return it->second;
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyOFT> _t;
	};
}
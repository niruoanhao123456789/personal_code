#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

template<class K>
struct BSTNode
{
	BSTNode<K>* _left;
	BSTNode<K>* _right;
	K _key;

	BSTNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{
	}
};

// 不允许等值插入的版本
// 非递归实现
template<class K>
class BSTree
{
	using Node = BSTNode<K>;
public:
	bool Insert(const K& key)
	{
		if (!_root)
		{
			_root = new Node(key);
			return true;
		}

		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			parent = cur;
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key > cur->_key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				if (!cur->_left)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;
					return true;
				}
				else if (!cur->_right)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
						delete cur;
						return true;
					}
				}
				else
				{
					// ⽆法直接删除N结点，因为N的两个孩⼦⽆处安放，只能⽤替换法删除。
					// 找N左⼦树的值最⼤结点R(最右结点)或者N右⼦树的值最⼩结点R(最左结点)替代N
					// 
					// 找cur右子树的最小节点替代
					Node* replaceParent = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						replaceParent = replace;
						replace = replace->_left;
					}
					cur->_key = replace->_key;

					if (replaceParent->_left == replace)
					{
						replaceParent->_left = replace->_right;
					}
					else
					{
						replaceParent->_right = replace->_right;
					}
					delete replace;
					return true;
				}
			}
		}
		return false;
	}

	void InOder()
	{
		_InOder(_root);
		cout << endl;
	}

private:
	void _InOder(Node* root)
	{
		if (!root)
			return;

		_InOder(root->_left);
		cout << root->_key << " ";
		_InOder(root->_right);
	}

	Node* _root = nullptr;
};

// key/value的搜索场景实现的⼆叉树搜索树⽀持修改，但是不⽀持修改key，修改key破坏搜索树性质了，可以修改value
namespace key_value
{
	template<class K,class V>
	struct BSTNode
	{
		BSTNode<K,V>* _left;
		BSTNode<K,V>* _right;
		K _key;
		V _value;

		BSTNode(const K& key,const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{
		}
	};

	template<class K,class V>
	class BSTree
	{
		using Node = BSTNode<K,V>;
	public:
		bool Insert(const K& key,const V& value)
		{
			if (!_root)
			{
				_root = new Node(key,value);
				return true;
			}

			Node* cur = _root;
			Node* parent = cur;
			while (cur)
			{
				parent = cur;
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key,value);
			if (parent->_key > cur->_key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			return true;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = cur;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					if (!cur->_left)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
						return true;
					}
					else if (!cur->_right)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
							delete cur;
							return true;
						}
					}
					else
					{
						// ⽆法直接删除N结点，因为N的两个孩⼦⽆处安放，只能⽤替换法删除。
						// 找N左⼦树的值最⼤结点R(最右结点)或者N右⼦树的值最⼩结点R(最左结点)替代N
						// 
						// 找cur右子树的最小节点替代
						Node* replaceParent = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}
						cur->_key = replace->_key;

						if (replaceParent->_left == replace)
						{
							replaceParent->_left = replace->_right;
						}
						else
						{
							replaceParent->_right = replace->_right;
						}
						delete replace;
						return true;
					}
				}
			}
			return false;
		}

		void InOder()
		{
			_InOder(_root);
			cout << endl;
		}

	private:
		void _InOder(Node* root)
		{
			if (!root)
				return;

			_InOder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOder(root->_right);
		}

		Node* _root = nullptr;
	};
}
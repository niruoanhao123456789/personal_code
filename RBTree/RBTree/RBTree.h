#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class K,class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K,V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		, _parent(nullptr)
		,_col(RED)
	{
	}
};

template<class K,class V>
class RBTree
{
	using Node = RBTreeNode<K, V>;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (!_root)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			// 寻找插入位置
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}

			// 新增结点
			cur = new Node(kv);
			cur->_col = RED;
			if (parent->_kv.first<cur->_kv.first)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			cur->_parent = parent;

			// 更新颜色
			while (parent && parent->_col == RED)
			{
				Node* grandparent = parent->_parent;
				if (grandparent->_left == parent)
				{
					//    g
					//  p   u
					Node* uncle = grandparent->_right;
					// 叔叔存在且为红
					if (uncle && uncle->_col == RED)
					{
							// 变色+继续往上处理
						parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;
						cur = grandparent;
						parent = cur->_parent;
					}
					else	// 叔叔不存在或者叔叔存在且为黑
					{
						//    g
						//  p   u
						//c
						// 单旋+变色
						if (cur == parent->_left)
						{
							RotateR(grandparent);
							parent->_col = BLACK;
							grandparent->_col = RED;
						}
						else
						{
							//    g
							//  p   u
							//	  c
							// 双旋+变色
							RotateL(parent);
							RotateR(grandparent);
							cur->_col = BLACK;
							grandparent->_col = RED;
						}
						break;
					}
				}
				else
				{
					//   g
					// u   p
					Node* uncle = grandparent->_left;
					if (uncle && uncle->_col == RED)
					{
						parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						if (cur == parent->_right)
						{
							RotateL(grandparent);
							parent->_col = BLACK;
							grandparent->_col = RED;
						}
						else
						{
							RotateR(parent);
							RotateL(grandparent);
							cur->_col = BLACK;
							grandparent->_col = RED;
						}
						break;
					}
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent;
		}
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

	int Size()
	{
		return _Size(_root);
	}

	int Height()
	{
		return _Height(_root);
	}

	bool IsBalanceTree()
	{
		if (_root && _root->_col == RED)
			return false;

		// 最左路径黑色节点的数量做参考值去比较其他路径
		int left_bn = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				left_bn++;
			cur = cur->_left;
		}
		return _CheckColour(_root, 0, left_bn);
	}

	~RBTree()
	{
		_RBTreeDestory(_root);
	}

private:
	int _Size(Node* root)
	{
		if (!root)
			return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	void _InOrder(Node* root)
	{
		if (!root)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	// root_cur_bn 根到当前节点路径上黑色节点的数量
	// 前序递归
	bool _CheckColour(Node* root, int root_cur_bn, const int left_bn)
	{
		if (!root)
		{
			// 检查每条路径的黑色节点的数量
			if (root_cur_bn != left_bn)
			{
				cout << "黑色节点的数量不相等" << endl;
				return false;
			}

			return true;
		}
		if (root->_col == BLACK)
			root_cur_bn++;

		// 检查连续的红色节点
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		return _CheckColour(root->_left, root_cur_bn, left_bn) && _CheckColour(root->_right, root_cur_bn, left_bn);
	}

	void _RBTreeDestory(Node* root)
	{
		if (!root)
			return;
		_RBTreeDestory(root->_left);
		_RBTreeDestory(root->_right);
		delete root;
	}

	Node* _root = nullptr;
};
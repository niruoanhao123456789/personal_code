#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		,_bf(0)
	{ }
};

template<class K, class V>
class AVLTree
{
	using Node = AVLTreeNode<K, V>;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (!_root)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		// 控制平衡
		// 更新平衡因子
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				// parent所在的子树高度不变，不会再影响上一层，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// parent所在的子树高度变了，会再影响上一层，继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// parent所在的子树已经不平衡了，需要旋转处理
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else
				{
					assert(false);
				}

				break;
			}
			else
			{
				assert(false);
			}

		}


		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parentParent = subR;

		if (parent = _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			subR->_parent = parentParent;
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
		}
		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		Node* parentParent = parent->_parent;
		parentParent = subL;

		if (parent = _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			subL->_parent = parentParent;
			if (parent == parentParent->_left)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
		}
		parent->_bf = subL->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		// 平衡因子的调节
		if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}

	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		// 平衡因子的调节
		if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	Node* find(const pair<K, V>& kv)
	{
		if (!_root)
		{
			return nullptr;
		}
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
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

	int Height()
	{
		return _Height(_root);
	}


	bool IsBalanceTree()
	{

		return _IsBalanceTree(_root);
	}

private:
	int _Height(Node* root) 
	{
		if (!root)
			return 0;

		int heightLeft = _Height(root->_left);
		int heightRight = _Height(root->_right);

		return heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
	}

	bool _IsBalanceTree(Node* root)
	{
		// 空树也是AVL树
		if (nullptr == root)
			return true;
		// 计算pRoot结点的平衡因⼦：即pRoot左右⼦树的⾼度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		// 如果计算出的平衡因⼦与pRoot的平衡因⼦不相等，或者
		// pRoot平衡因⼦的绝对值超过1，则⼀定不是AVL树
		if (abs(diff) >= 2)
		{
			cout << root->_kv.first << "⾼度差异常" << endl;
			return false;
		} 
		if(root->_bf != diff)
		{
			cout << root->_kv.first << "平衡因⼦异常" << endl;
			return false;
		} 
		// pRoot的左和右如果都是AVL树，则该树⼀定是AVL树
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}

	Node* _root = nullptr;
};
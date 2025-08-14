#include"BinaryTree.h"

//“根左右”
void PreOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}

//“左根右”
void InOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	PreOrder(root->left);
	printf("%c ", root->val);
	PreOrder(root->right);
}

//“左右根”
void PostOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}

//int size = 0;//创建全局变量会导致下次调用该函数时size会在原基础上累加
//int BinaryTreeSize(BTNode* root)
//{
//	if (!root)
//	{
//		return 0;
//	}
//	size++;
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//
//	return size;
//}
//下面方法和全局变量效果一样
//int BinaryTreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (!root)
//	{
//		return 0;
//	}
//	size++;
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//
//	return size;
//}
//
//结点个数 = 1（根节点数）+ 左节点数 + 右节点数
int BinaryTreeSize(BTNode* root)
{
	if (!root)
	{
		return 0;
	}
	return (1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right));
}

//叶子结点个数 = 左子树叶子结点个数 + 右子树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (!root)
		return 0;
	if ((root->left == NULL) && (root->right == NULL))
		return 1;
	return (BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right));
}

//第k层结点个数 = 左子树第k层结点个数 + 右子树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root,int k)
{
	if (!root)
		return 0;
	if (k == 1)
	{
		return 1;
	}
	return (BinaryTreeLevelKSize(root->left, k-1) + BinaryTreeLevelKSize(root->right, k-1));
}

//二叉树深度 = 根节点数 + 左子树深度与右子树深度的最大值
int BinaryTreeDepth(BTNode* root)
{
	if (!root)
		return 0;
	int leftdepth = BinaryTreeDepth(root->left);
	int rightdepth = BinaryTreeDepth(root->right);
	return (1 + (leftdepth > rightdepth ? leftdepth : rightdepth));
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (!root)
		return NULL;
	if (root->val == x)
	{
		return root;
	}
	BTNode* leftfind = BinaryTreeFind(root->left, x);
	if (leftfind)
	{
		return leftfind;
	}
	BTNode* rightfind = BinaryTreeFind(root->right, x);
	if (rightfind)
	{
		return rightfind;
	}
	return NULL;
}

void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));
	free(*root);
	*root = NULL;
}
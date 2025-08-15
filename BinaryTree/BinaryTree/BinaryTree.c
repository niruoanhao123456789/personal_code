#include"BinaryTree.h"
#include"Queue.h"
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

//将根节点保存到队列中，是队列不为空，循环判断队列是否为空，不为空则取队头出队列并将不为空得根节点入队列
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		//去队头，打印队头
		BTNode* top = QueueFront(&q);
		printf("%c ", top->val);
		QueuePop(&q);
		//队头结点不为空的孩子节点入队列
		if (top->left)
			QueuePush(&q,top->left);
		if (top->right)
			QueuePush(&q, top->right);
	}

	QueueDestroy(&q);
}

//判断每层结点个数、叶子节点是否满足从左到右依次排序
//根节点先入队列，保证队列不为空，循环判断队列是否为空，不为空则取队头出队列，将对头左右孩子都入队列
//取对头时遇到空结点，判断队列剩余结点是否为空来判断，不为空则不是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* top = QueueFront(&q);
		QueuePop(&q);
		if (top == NULL)
		{
			break;
		}
		QueuePush(&q, top->left);
		QueuePush(&q, top->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* top = QueueFront(&q);
		QueuePop(&q);
		if (top)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}
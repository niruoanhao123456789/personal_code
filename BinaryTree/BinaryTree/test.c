#include"BinaryTree.h"

BTNode* BuyMemonry(char x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->val = x;
	newnode->right = NULL;
	newnode->left = NULL;
}

void test1()
{
	BTNode* nodeA = BuyMemonry('A');
	BTNode* nodeB = BuyMemonry('B');
	BTNode* nodeC = BuyMemonry('C');
	BTNode* nodeD = BuyMemonry('D');
	BTNode* nodeE = BuyMemonry('E');
	BTNode* nodeF = BuyMemonry('F');
	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;

	//PreOrder(nodeA);
	//InOrder(nodeA);
	//PostOrder(nodeA);

	//printf("%d\n",BinaryTreeSize(nodeA));
	//printf("%d\n", BinaryTreeSize(nodeA));

	//printf("%d\n", BinaryTreeLeafSize(nodeA));

	//printf("%d\n", BinaryTreeLevelKSize(nodeA, 3));

	//printf("%d\n", BinaryTreeDepth(nodeA));

	//BTNode* node = BinaryTreeFind(nodeA, 'G');
	//if (node)
	//{
	//	printf("found！\n");
	//}
	//else
	//{
	//	printf("no find\n");
	//}

	//LevelOrder(nodeA);
	
	if (BinaryTreeComplete(nodeA))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	BinaryTreeDestory(&nodeA);
}

//单值二叉树
//先比较根节点和左右子树根节点的值，再进行递归
//bool isUnivalTree(BTNode* root) 
//{
//	if (root == NULL)
//		return true;
//	if (root->left && root->val != root->left->val)
//		return false;
//	if (root->right && root->val != root->right->val)
//		return false;
//
//	return(isUnivalTree(root->left) && isUnivalTree(root->right));
//}

//相同二叉树
//要求结构与数据都相同
bool isSameTree(BTNode* p, BTNode* q) 
{
	//都为空
	if (p == NULL && q == NULL)
		return true;
	//都不为空
	if (q == NULL || p == NULL)
		return false;
	if (p && q)
	{
		if (q->val != p->val)
		{
			return false;
		}
		return (isSameTree(p->left, q->left) && isSameTree(q->right, p->right));
	}
}

//另一颗子树
//求一棵二叉树中是否有另一颗二叉树作为其子树
//先比较根节点所在子树是否相同，在比较左右子树的根节点是否相同
bool isSameTree(BTNode* p, BTNode* q)
{
	//都为空
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	//都不为空
	if (p->val != q->val)
		return false;

	return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

bool isSubtree(BTNode* root, BTNode* subRoot) {
	if (root == NULL)
		return false;
	if (isSameTree(root, subRoot))
		return true;
	return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}

//前序遍历，用数组来返回遍历结果
int BinaryTreeSize(BTNode* root)
{
	if (!root)
	{
		return 0;
	}
	return (1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right));
}

void PreOrder(BTNode* root, int* arr, int* pi)
{
	if (!root)
		return;
	arr[(*pi)++] = root->val;
	PreOrder(root->left, arr, pi);
	PreOrder(root->right, arr, pi);
}

int* preorderTraversal(BTNode* root, int* returnSize) {
	*returnSize = BinaryTreeSize(root);
	int* arr = (int*)malloc(*returnSize * sizeof(int));
	int i = 0;
	PreOrder(root, arr, &i);
	return arr;
}

int main()
{
	test1();

	return 0;
}
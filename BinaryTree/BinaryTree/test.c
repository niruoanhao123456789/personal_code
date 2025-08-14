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

	BTNode* node = BinaryTreeFind(nodeA, 'G');
	if (node)
	{
		printf("found£¡\n");
	}
	else
	{
		printf("no find\n");
	}

	BinaryTreeDestory(&nodeA);
}

int main()
{
	test1();

	return 0;
}
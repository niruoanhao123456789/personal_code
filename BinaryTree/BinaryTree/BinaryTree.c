#include"BinaryTree.h"

//¡°¸ù×óÓÒ¡±
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

//¡°×ó¸ùÓÒ¡±
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

//¡°×óÓÒ¸ù¡±
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
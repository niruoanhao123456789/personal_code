#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<assert.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTNode;

//前序遍历：先根遍历，再编历根节点，然后遍历左子树，最后遍历右子树 “根左右”
void PreOrder(BTNode* root);

//中序遍历：先遍历左子树，再遍历根节点，最后遍历右子树 “左根右”
void InOrder(BTNode* root);

//后序遍历：先遍历左子树，在遍历右子树，最后遍历根结点 “左右根”
void PostOrder(BTNode* root);

//层序遍历：按照层次进行依次遍历（从上到下，从左往右）
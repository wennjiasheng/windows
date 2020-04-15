#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	BTDataType val;
}BTNode;

//前序遍历
void beforeOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->val);
		beforeOrder(root->left);
		beforeOrder(root->right);
	}
}
//中序遍历
void inOrder(BTNode* root)
{
	if (root)
	{
		inOrder(root->left);
		printf("%d ", root->val);
		inOrder(root->right);
	}
}
//后序遍历
void endOrder(BTNode* root)
{
	if (root)
	{
		endOrder(root->left);
		endOrder(root->right);
		printf("%d ", root->val);
	}
}
//层序遍历
//void evelOrder(BTNode* root)
//{
//	if (root == NULL) return;
//	Queue q;
//	init(&q);
//	push(&q, root);
//
//	while (!queueEmpty(&q))
//	{
//		BTNode* pCur = queueFront(&q);
//		queuepop(&p);
//
//		printf("%d ", pCur->val);
//		if (pCur->right)
//			queuepush(&q, pCur->left);
//		if (pCur->right)
//			queuepush(&q, pCur->right);
//	}
//}
//void BTdestory(BTNode* root);
BTNode* BTCreatetree();
int BTSize(BTNode* root);//二叉树节点的个数
int BTleafSize(BTNode* root);//二叉树叶子节点的个数
int BTcoutKsize(BTNode* root, int k);//二叉树第K层节点的个数
BTNode* FindX(BTNode* root,BTDataType x);//查找值尾X的节点
int BTHigh(BTNode* root);//获取二叉树的高度
BTNode* GetParent(BTNode* root, BTNode* Node);//获取Node的双亲
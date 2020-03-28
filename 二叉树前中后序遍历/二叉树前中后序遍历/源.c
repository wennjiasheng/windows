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
void inOrder(BTNode * root)
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

int main()
{
	
	system("pause");
	return 0;
}

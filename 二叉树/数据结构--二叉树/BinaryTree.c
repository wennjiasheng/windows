#include "BinaryTree.h"
//在递归进行中，index需要一直++，因此在递归中，不能传值，应该传地址，在index修改之后，可以获取修改后的值
BTNode* _BTCreatetree(int *array, int size, int* index, int invalid)//invalid代表无效值,index传地址
{
	BTNode* root = NULL;
	if (array[*index] != invalid&&index<size)
	{
		root = BuyBinTreeNode(array[*index]);//创建根节点
		//递归创建根结点的左右子树
		root->left = _BTCreatetree(array, size, ++(*index), invalid);
		root->right = _BTCreatetree(array, size, ++(*index), invalid);
	}
	return root;
}
BTNode* BTCreatetree(int *array,int size,BTDataType invalid)
{
	int index = 0;//不能直接把函数中index设为0，编译时可能以为是空，所以先定义下
	return _BTCreatetree(array, size, &index, invalid);
}
BTNode* BuyBinTreeNode(BTDataType val)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	pNewNode->left = NULL;
	pNewNode->right = NULL;
	pNewNode->val = val;
	return pNewNode;
}
//BTNode* BTCreatetree()//验证方法是否正确
//{
//	BTNode* node1 = BuyBinTreeNode(1);
//	BTNode* node2 = BuyBinTreeNode(2);
//	BTNode* node3 = BuyBinTreeNode(3);
//	BTNode* node4 = BuyBinTreeNode(4);
//	BTNode* node5 = BuyBinTreeNode(5);
//	BTNode* node6 = BuyBinTreeNode(6);
//
//	BTNode* root = node1;
//	node1->left = node2;
//	node1->right = node4;
//	node2->left = node3;
//	//node2->right = NULL;
//	node4->left = node5;
//	node4->right = node6;
//	//node5->left = NULL;
//	//node5->right = NULL;
//	return root;
//}

//void BTdestory(BTNode* root);
int BTSize(BTNode* root)//二叉树节点的个数
{
	if (root)
		return 1 + BTSize(root->left) + BTSize(root->right);
	return 0;
}
int BTleafSize(BTNode* root)//二叉树叶子节点的个数:没有左右子树的节点
{
	if (root == NULL) return 0;
	if (root->left&&root->right)
		return BTleafSize(root->left)+BTleafSize(root->right);
	return 1;
}
int BTcoutKsize(BTNode* root, int k)//二叉树第K层节点的个数
{
	if (k<=0||root == NULL) return 0;
	if (k == 1) return 1;
	return BTcoutKsize(root->left,k-1) + BTcoutKsize(root->right,k-1);
}
BTNode* FindX(BTNode* root, BTDataType x)//查找值尾X的节点
{
	BTNode* Node = NULL;
	if (root == NULL) return NULL;
	if (root->val == x) return root;
	if ((Node = FindX(root->left, x)) || (Node = FindX(root->right, x)))
		return Node;
	return NULL;
	//return FindX(root->left, x) || FindX(root->right, x);这样不行，结果返回是真或假
}

int BTHigh(BTNode* root)//获取二叉树的高度
{
	if (root == NULL) return 0;
	int leftH =1+ BTHigh(root->left);
	int rightH =1+ BTHigh(root->right);
	return leftH > rightH ? leftH : rightH;
	//if (root == NULL) return 0;
	//int leftH = BTHigh(root->left);
	//int rightH = BTHigh(root->right);
	//return leftH > rightH ? leftH+1 : rightH+1;
}
BTNode* GetParent(BTNode* root, BTNode* Node)//获取Node的双亲
{
	BTNode* Cur = NULL;
	if (root == NULL || Node == NULL || root == Node) return NULL;
	if (root->left == Node || root->right == Node)	return root;
	if ((Cur = GetParent(root->left, Node)) || (Cur = GetParent(root->right, Node)))
		return Cur;
	return NULL;
}
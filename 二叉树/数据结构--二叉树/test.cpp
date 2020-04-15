#include "BinaryTree.c"
int main()
{
	int array[] = { 1, 2, 3, -1, -1, -1, 4, 5, -1, -1, 6 };
	BTNode* root = BTCreatetree(array, sizeof(array)/sizeof(array[0]), -1);
	printf("前序：");
	beforeOrder(root);
	printf("\n");
	printf("中序：");
	inOrder(root);
	printf("\n");
	printf("后序：");
	endOrder(root);
	printf("\n");

	//void BTdestory(BTNode* root);
	printf("二叉树节点的个数:%d \n", BTSize(root));//
	printf("二叉树叶子节点的个数:%d \n", BTleafSize(root));
	printf("二叉树第K层节点的个数:%d \n", BTcoutKsize(root, 2));
	FindX(root, 3);//查找值尾X的节点
	printf("获取二叉树的高度:%d \n", BTHigh(root));
	GetParent(root, FindX(root, 3));//获取Node的双亲
	system("pause");
	return 0;
}
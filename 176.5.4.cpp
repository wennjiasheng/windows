//176.5.3假设二叉树采用链式存储结构存储，root指向根结点，p和q所指结点为二叉树中的两个不同结点，编写一个计算p、q所指结点最近的共同祖先r所指结点的算法。
//176.5.4 假设二叉树采用链式存储结构存储，设计一个算法求二叉树中指定结点所在的层数 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
bool getIndexLevel(TreeNode *root, TreeNode *found, int &level)
{
if(root == NULL || found == NULL)
return false;
if (root == found)
return true;
int nextlevel = level + 1;
if (getIndexLevel(root->left, found, nextlevel) || )
{
level = nextlevel;
return true;
}
nextlevel = level + 1;
if (getIndexLevel(root->right, found, nextlevel) || )
{
level = nextlevel;
return true;
}
return false;
}

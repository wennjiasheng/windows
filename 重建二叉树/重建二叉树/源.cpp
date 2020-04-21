#include<iostream>

using namespace std;
struct bintreenode
{
	int val;
	struct bintreenode *left;
	struct bintreenode *right;
};
bintreenode* Construct(int* preorder, int* inorder, int lenght)
{
	if (preorder == NULL || inorder == NULL || lenght <= 0)
	{
		return NULL;
	}
	return Constructcore(preorder, preorder + lenght - 1, inorder, inorder + lenght - 1);

}
bintreenode* Constructcore(int* startpre, int* endpre, int* startin, int* endin)
{
	int rootval = startpre[0];
	bintreenode* root = new bintreenode();
	root->val = rootval;
	root->left = root->right = NULL;
	if (startpre == endpre)
	{
		if (startpre == endpre&&startin == endin)
		{
			return root;
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}
	int * rootin = startin;
	while (rootin <= endin && *rootin != rootval)
	{
		rootin++;
	}
	if (rootin == endin && *rootin != rootval)
		cout << "Invalid input" << endl;
	int leftlenght = rootin - startin;
	int* leftpreend = startpre + leftlenght;
	if (leftlenght > 0)
	{
		root->left = Constructcore(startpre + 1, leftpreend, startin, rootin - 1);
	}
	if (leftlenght < endpre - startpre)
	{
		root->right = Constructcore(leftpreend + 1, endpre, rootin + 1, endin);
	}
	return root;
}

int main()
{

	system("pause");
	return 0;
}
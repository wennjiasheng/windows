#include<iostream>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	bool issumtree(TreeNode* s, TreeNode* t)
	{
		if (s == NULL&&t == NULL)
		{
			return true;
		}
		if (s == NULL || t == NULL)
		{
			return false;
		}
		return s->val == t->val &&issumtree(s->left, t->left) && issumtree(s->right, t->right);
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == NULL)
		{
			return  false;
		}
		if (t == NULL)
		{
			return true;
		}
		if (s->val == t->val&&issumtree(s, t))
		{
			return true;
		}
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};
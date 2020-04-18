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
	bool isUnivalTree(TreeNode* root) {
		if (root){
			int pre = root->val;
			if (root->left != NULL && root->left->val != pre) return false;
			if (root->right != NULL && root->right->val != pre) return false;

			if (!isUnivalTree(root->left)) return false;
			if (!isUnivalTree(root->right)) return false;
		}
		return true;

	}
};
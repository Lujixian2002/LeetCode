#include<iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode * ans;
	void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target)
	{
		if (original == target)
		{
			ans = cloned;
			return;
		}
		if (original->left != nullptr)
			dfs(original->left, cloned->left, target);
		if (original->right != nullptr)
			dfs(original->right, cloned->right, target);
		return;



	}
	TreeNode* getTargetCopy(
		TreeNode* original, TreeNode* cloned, TreeNode* target) {
		TreeNode* p = original, * q = cloned;
		dfs(p, q, target);

		return ans;
	}
};

//  ¾«Á¶´úÂë
class Solution1 {
public:
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
	{
		if (original == target)
			return cloned;
		TreeNode* l = nullptr, * r = nullptr;

		if (original->left != nullptr)
			l = getTargetCopy(original->left, cloned->left, target);
		if (l != nullptr)
			return l;
		if (original->right != nullptr)
			r = getTargetCopy(original->right, cloned->right, target);
		return r;
	}
};
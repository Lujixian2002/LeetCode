#include<iostream>
#include<vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool dfs(TreeNode* n1, TreeNode* n2)
	{
		if (n1->left == nullptr && n1->right == nullptr && n1->val == n2->val)
			return true;
		if (n1->val != n2->val 
			|| (n1->left == nullptr && n2->right != nullptr) 
			|| (n1->left != nullptr && n2->right == nullptr)
			|| (n1->right == nullptr && n2->left != nullptr)
			|| (n1->right != nullptr && n2->left == nullptr)
			)
			return false;
		else
			if (n1->left != nullptr && n1->right != nullptr)
				return dfs(n1->left, n2->right) && dfs(n1->right, n2->left);
			else if (n1->left == nullptr)
				return dfs(n1->right, n2->left);
			else
				return dfs(n1->left, n2->right);
	}


	bool isSymmetric(TreeNode* root) {
		// 两棵树是否全等
		if ((root->left == nullptr && root->right != nullptr) || root->right == nullptr && root->left != nullptr)
			return false;
		else if (root->left == nullptr && root->right == nullptr)
			return true;
		if (root->left->val != root->right->val)
			return false;
		else
			return dfs(root->left, root->right);
	}
};


int main()
{
	Solution s;
	TreeNode n4 = TreeNode(0);
	TreeNode n5 = TreeNode(3);
	TreeNode n6 = TreeNode(0);
	TreeNode n7 = TreeNode(3);

	TreeNode n2 = TreeNode(1, &n4, &n5);
	TreeNode n3 = TreeNode(1, &n6, &n7);
	TreeNode n1 = TreeNode(1, &n2, &n3);

	cout << s.isSymmetric(&n1);



}
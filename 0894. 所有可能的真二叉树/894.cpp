#include<iostream>
#include<vector>
using namespace std;



//Definition for a binary tree node.
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
	vector<TreeNode*> allPossibleFBT(int n) {
		vector<TreeNode*> ans;

		// 不可能有偶数个node
		if (n % 2 == 0)
			return ans;

		// 只剩一个node就是该node本身
		if (n == 1)
			return { new TreeNode{ 0 } };

		for (int i = 1;i < n;i += 2)
		{
			vector<TreeNode*>left;
			vector<TreeNode*>right;
			// 左子树的所有可能
			left = allPossibleFBT(i);
			// 右子树的所有可能
			right = allPossibleFBT(n - 1 - i);
			for (TreeNode* l : left)
				for (TreeNode* r : right)
				{
					// 左子树和右子树在root处结合，形成一种可能
					TreeNode* root = new TreeNode(0, l, r);
					ans.push_back(root);
				}
		}
		return ans;
	}
};
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
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

class BSTIterator {
public:
	stack<TreeNode*> s;
	TreeNode* p;

	BSTIterator(TreeNode* root):p(root) {	}

	int next() {
	
		while (p != nullptr)
		{
			s.push(p);
			p = p->left;
		}
		// ×ó×ÓÊ÷Îª¿Õ
		int value = s.top()->val;
		p = s.top()->right;

		s.pop();

		return value;
	}

	bool hasNext() {
		return !(s.empty() && p == nullptr);
	}
};


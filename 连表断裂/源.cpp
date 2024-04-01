#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	vector<bool> canSorted(vector<ListNode*>& lists) {
		vector<bool> ans;

		// write code here
		for (int i = 0;i < lists.size();i++)
		{

			int flag = 2;

			ListNode* p = lists[i];
			int start = p->val;

			while (p->next != nullptr)
			{
				if (p->val >= p->next->val)
				{
					flag--;
					if (flag == 0)
					{
						ans.push_back(false);
						break;
					}
				}
				p = p->next;
			}
			if (flag == 0)
				continue;

			if (p->val >= start && flag == 1)
			{
				ans.push_back(false);
				continue;
			}
			ans.push_back(true);

		}

		return ans;


	}
};
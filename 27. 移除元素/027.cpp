#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		for (int i = 0;i < len;i++)
		{
			if (i == len - 1 && nums[i] == val)
			{
				len--;
				break;

			}
			if (nums[i] == val)
			{
				len--;
				for (int j = i;j < len;j++)
					nums[j] = nums[j + 1];
				i--;

			}
		}
		return len;

	}
};


int main()
{
	Solution s;
	vector<int> v = {1,2,4,5};
	cout << s.removeElement(v, 2);

}
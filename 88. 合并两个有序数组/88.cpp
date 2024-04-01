#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		if (m == 0)
		{
			nums1 = nums2;
			return;
		}
		
		m -= 1;
		n -= 1;
		
		while (m > -1 && n > -1)
		{
			if (nums1[m] > nums2[n])
			{
				nums1[m + n + 1] = nums1[m];
				m--;
			}
			else
			{
				nums1[m + n + 1] = nums2[n];
				n--;
			}
			if (m == -1 && n >= 0)
				while (n >= 0)
				{
					nums1[n] = nums2[n];
					n--;
				}

		}

	}
};
int main() 
{
	Solution s;
	vector<int> nums1 = { 1, 2, 0,0,0 };
	vector<int> nums2 = { 2, 5, 6 };
	s.merge(nums1, 2, nums2, 3);
	// 使用范围循环输出元素
	for (const auto& num : nums1) {
		cout << num << " ";
	}
}
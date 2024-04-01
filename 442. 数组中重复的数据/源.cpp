#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            if (i + 1 < nums.size())
                if (nums[i] == nums[i + 1]) {
                    ans.push_back(nums[i]);
                    i++;
                }
        return ans;
    }
};

// 方法二：将元素交换到对应的位置
class Solution2 {



};

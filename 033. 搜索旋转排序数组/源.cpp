#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if (target < nums[0] && target>nums[nums.size() - 1])
            return -1;
        else if (target >= nums[0])
        {
            for (int i = 0;i < nums.size();i++)
                if (nums[i] < nums[0])
                    return -1;
                else if (target == nums[i])
                    return i;
        }
        else
        {
            for (int i = nums.size() - 1;i >= 0;i--)
                if (nums[i] > nums[0])
                    return -1;
                else if (target == nums[i])
                    return i;
        }
        return -1;
    }
};



// 改进：左右分别二分

int main()
{

}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        if (intervals.size() == 0)
            return ans;
        int num = 0;
        ans.push_back(intervals[0]);
        for (int i = 0;i < intervals.size();i++)
        {
            if (intervals[i][0] > ans[num][1])
            {
                num++;
                ans.push_back(intervals[i]);
                continue;
            }
            ans[num][1] = max(intervals[i][1], ans[num][1]);
        
        }



        return ans;
    }
};


int main()
{
	Solution s;

    
    vector<vector<int>> intervals = { {1, 3},{2, 6},{8, 10},{15, 18} };
    s.merge(intervals);
   
    

}
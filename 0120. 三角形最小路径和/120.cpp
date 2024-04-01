#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int minRoute(vector<vector<int>>& triangle, int starti, int startj)
    {
        cout << starti << startj << dp[starti * (starti + 1) / 2 + startj] << " ";


        if (starti == triangle.size() - 1)
        {
            dp[starti * (starti + 1) / 2 + startj] = triangle[starti][startj];
            return dp[starti * (starti + 1) / 2 + startj];

        }
        if (dp[starti * (starti + 1) / 2 + startj] != -1)
            return dp[starti * (starti + 1) / 2 + startj];

        dp[starti * (starti + 1) / 2 + startj] = (triangle[starti][startj]
            + min(minRoute(triangle, starti + 1, startj), minRoute(triangle, starti + 1, startj + 1)));
        return dp[starti * (starti + 1) / 2 + startj];
    }



    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 0; i < triangle.size() * (triangle.size() + 1) / 2; i++)
            dp.push_back(-1);
        return minRoute(triangle, 0, 0);
    }
};
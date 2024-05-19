#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int s = tasks.size();

        sort(tasks.begin(),tasks.end());
        int ans = 0;
        int p = 0;
        while (p < s)
        {
            int num = 0;
            int tar = tasks[p];
            while (p < s && tasks[p] == tar)
            {
                p++;
                num++;
            }
            if (num == 1)
                return -1;
            ans += (num + 2) / 3;
        }
        return ans;
    }
};
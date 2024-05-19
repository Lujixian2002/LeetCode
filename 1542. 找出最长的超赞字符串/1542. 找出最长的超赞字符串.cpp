#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool huiwen(string s)
    {
        int num[10];
        int odd = 0;
        for (int i = 0;i < s.size();i++)
            num[s[i] - '0']++;
        for (int i = 0;i < 10;i++)
            if (num[i] % 2 == 1)
                odd++;
        if (odd > 1)
            return false;
        return true;
    }
    int longestAwesome(string s) {
        int ans = 0;
        for (int i = 0;i < s.size();i++)
            for (int j = 0;j < s.size() - i + 1;j++)
                if (huiwen(s.substr(i, j)))
                    ans = max(ans, j);
        return ans;
    }
};
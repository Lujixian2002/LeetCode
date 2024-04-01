#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'i')
            
                for (int j = 0; j < ans.size() / 2; j++)
                    swap(ans[j], ans[ans.size() - 1 - j]);
            
            else
                ans+=s[i];

        return ans;

    }
};
// i
// 
//class Solution2 {
//public:
//    string finalString(string s) {
//        vector<char> ans;
//        
//        ans.
//        for (int i = 0; i < s.size(); i++)
//            if (s[i] == 'i')
//
//                for (int j = 0; j < ans.size() / 2; j++)
//                    swap(ans[j], ans[ans.size() - 1 - j]);
//
//            else
//                ans += s[i];
//
//        return ans;
//
//    }
//
//
//};
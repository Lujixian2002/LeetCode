#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> s;
        int p = 0;
        int len = preorder.length();

        if (len == 1 && preorder[0] == '#')
            return true;
        for (int i = 0; i < preorder.length(); i++)
        {
            char c = preorder[i];
            if (c == ',')
                continue;
            else if (c == '#') {
                if (s.empty())
                    return false;
                int temp = s.top();
                s.pop();
                if (temp - 1 == 1)
                    s.push(1);
            }
            else {
                while (i + 1 < len && preorder[i + 1] >= '0' &&
                    preorder[i + 1] <= '9')
                    i++;
                if (!s.empty()) {
                    int temp = s.top();
                    s.pop();
                    if (temp - 1 == 1)
                        s.push(1);
                }
                s.push(2);
            }
            if (i != len - 1 && s.empty())
                return false;
        }
        if (s.empty())
            return true;
        return false;
    }
};


int main()
{

}
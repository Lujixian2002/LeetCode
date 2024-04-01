#include<iostream>
#include<vector>
#include<String>
#include<stack>

using namespace std;



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0;i < tokens.size();i++)
            if (Solution::isOperator(tokens[i]))
            {
                int num1 = s.top();
                cout << s.top() << " ";

                s.pop();

                int num2 = s.top();
                cout << s.top() << " ";

                s.pop();

                if (tokens[i] == "+")
                    s.push(num1 + num2);
                if (tokens[i] == "-")
                    s.push(num1 - num2);
                if (tokens[i] == "*")
                    s.push(num1 * num2);
                if (tokens[i] == "/")
                    s.push(num2 / num1);
                cout << s.top() << " ";
            }
            else
                s.push(atoi(tokens[i].c_str()));
        return s.top();
    }

    bool isOperator(string token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};

int main() {
    Solution s;
    vector<string> tokens = { "4", "13", "5", "/", "+" };
    cout<<s.evalRPN(tokens);

}
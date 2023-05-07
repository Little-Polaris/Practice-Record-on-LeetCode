#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto i : s)
        {
            if (i == '(' || i == '[' || i == '{')
            {
                stk.push(i);
            }
            else if(!stk.empty())
            {
                if (i == ')' && stk.top() == '(')
                {
                    stk.pop();
                }
                else if (i == ']' && stk.top() == '[')
                {
                    stk.pop();
                }
                else if (i == '}' && stk.top() == '{')
                {
                    stk.pop();
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        if (stk.empty())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    ;
}
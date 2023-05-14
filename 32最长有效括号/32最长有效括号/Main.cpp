#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        stack<int> stk;
        stk.push(-1);
        int count = 0;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it == '(')
            {
                stk.push(it - s.begin());
            }
            else
            {
                int temp = stk.top();
                stk.pop();
                if (stk.empty())
                {
                    stk.push(it - s.begin());
                }
                else
                {
                    max = std::max(max, (int)((it - s.begin() - stk.top())));
                }
            }
        }
        return max;
    }
};

int main()
{
    string s = "()";
    cout << Solution().longestValidParentheses(s) << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1)
        {
            return { "()" };
        }
        vector<string> t = generateParenthesis(n - 1);
        set<string> s;
        for (auto i : t)
        {
            stack<int> stk;
            string str = i;
            for (int j = 0; j < i.size(); j++)
            {
                if (i[j] == '(')
                {
                    stk.push(j);
                }
                else if (i[j] == ')')
                {
                    str.insert(stk.top() + 1, 1, '(');
                    str.insert(j + 1, 1, ')');
                    s.insert(str);
                    str = i;
                    stk.pop();
                }
            }
            s.insert("()" + str);
            s.insert(str + "()");
            s.insert("(" + str + ")");
        }
        t.resize(s.size());
        copy(s.begin(), s.end(), t.begin());
        return t;
        
    }
};

int main()
{
    auto v = Solution().generateParenthesis(4);
    for (auto i : v)
    {
        cout << i << endl;
    }
    return 0;
}
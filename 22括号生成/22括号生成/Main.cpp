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
            for (auto it = i.begin(); it != i.end(); it++)
            {
                string str = i;
                str.insert(it - i.begin(), "()");
                s.insert(str);
            }
            s.insert("()" + i);
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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       /* string rs;
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[0][i])
                {
                    rs.assign(strs[0].begin(), strs[0].begin() + i);
                    return rs;
                }
            }
        }
        if (rs.empty())
        {
            rs.append(strs[0]);
        }
        return rs;*/
        sort(strs.begin(), strs.end());
        string fs = strs.front();
        string es = strs.back();
        for (int i = 0; i < fs.size(); i++)
        {
            if (fs[i] != es[i])
            {
                return string(fs, 0, i);
            }
        }
        return fs;
    }
};

int main()
{
    vector<string> v = { "a", "b", "c"};
    cout << Solution().longestCommonPrefix(v) << endl;
    return 0;
}
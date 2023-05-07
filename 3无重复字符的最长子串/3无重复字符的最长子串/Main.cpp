#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongeqSubqring(string s) {
        int max = 0;
        int left = 0;
        vector<char> v;
        for (int i = 0; i < s.length(); i++)
        {
            auto it = find(v.begin(), v.end(), s[i]);
            if (v.empty() || it == v.end())
            {
                v.push_back(s[i]);
            }
            else
            {
                while (*v.begin() != s[i])
                {
                    v.erase(v.begin());
                    left++;
                }
                v.erase(v.begin());
                v.push_back(s[i]);
                left++;
            }
            max = max > i - left + 1 ? max : i - left + 1;
        }
        return max;
    }
};

int main()
{
    string s;
    //cin >> s;
    s = "au";
    cout << Solution().lengthOfLongeqSubqring(s) << endl;
    return 0;
}
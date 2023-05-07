#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1)
        {
            return s;
        }
        string r_s;
        string t_s(s);
        for (int i = 0; i < s.size(); i++)
        {
            while (t_s.rfind(s[i]) != string::npos)
            {
                auto pos = t_s.rfind(s[i]);
                int left = i;
                int right = pos;
                int flag = 1;
                while (left <= right)
                {
                    if (s[left] != s[right])
                    {
                        flag = 0;
                        break;
                    }
                    left++;
                    right--;
                }
                string str = string(t_s.begin() + i, t_s.begin() + pos + 1);
                if (flag)
                {
                    r_s = r_s.size() >= str.size() ? r_s : str;
                    t_s.assign(t_s.begin(), t_s.end() - 1);
                    break;
                }
                t_s.assign(t_s.begin(), t_s.end() - 1);
            }
            if (r_s.size() == s.size())
            {
                break;
            }
            t_s.assign(s);
        }
        return r_s;
    }
};

int main()
{
    string s;
    s = "abcba";
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}
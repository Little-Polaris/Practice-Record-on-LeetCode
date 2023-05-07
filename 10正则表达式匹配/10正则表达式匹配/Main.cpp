#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        /*int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) 
        {
            if (i == 0) 
            {
                return false;
            }
            if (p[j - 1] == '.') 
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                if (p[j - 1] == '*') 
                {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) 
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else 
                {
                    if (matches(i, j)) 
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];*/
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            if (p[i - 1] != '*')
            {
                dp[0][i] = 0;
            }
            else
            {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (p[j] == '*')
                {
                    if (s[i] == p[j - 1] || p[j-1] == '.')
                    {
                        dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j + 1];
                    }
                    dp[i + 1][j + 1] = dp[i + 1][j + 1] + dp[i + 1][j - 1];
                }
                else if(p[j] == '.')
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if (p[j] == s[i])
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    string s;
    string p;
    //s = "aa";
    //p = "a*";
    //s = "aab";
    //p = "c*a*b";
    //s = "aaa";
    //p = "ab*a";
    //s = "ab";
    //p = ".*c";
    //s = "mississippi";
    //p = "mis*is*ip*.";
    //s = "mississippi";
    //p = "mis*is*p*.";
    //s = "aaa";
    //p = "a*a";
    //s = "aa";
    //p = "a*c*a";
    //s = "a";
    //p = "ab*";
    //s = "abcbabcbd";
    //p = "abcb.*d";
    s = "ab";
    p = ".*";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}
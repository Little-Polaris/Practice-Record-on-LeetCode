#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
        dp[0][0] = 1;
        for (int i = 0; i < p.size() - 1; i++) {
            if (p[i] == '*' && p[i + 1] == '*') {
                dp[0][i + 1] = 1;
                dp[0][i + 2] = 1;
                continue;
            }
            break;
        }
        if (p.front() == '*') {
            dp[0][1] = 1;
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if(p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1];                
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main() {
    string s = "aab";
    string p = "c*a*b";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}
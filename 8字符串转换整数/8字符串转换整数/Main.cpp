#include<iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int re = 0;
        while (s[0] == ' ')
        {
            s.erase(s.begin());
        }
        if (s[0] == '.')
        {
            return 0;
        }
        int flag = 0;
        if (s[0] == '-' || s[0] == '+')
        {
            if (s[0] == '-')
            {
                flag = 1;
            }
            s.erase(s.begin());
        }
        while (s[0] >= '0' && s[0] <= '9' && s.size())
        {
            if (re > 214748364 || re < -214748364)
            {
                if (flag)
                {
                    return -pow(2, 31);
                }
                else
                {
                    return pow(2, 31) - 1;
                }
            }
            else if (re == 214748364 && s[0] - '0' >= 8)
            {
                if (flag && s[0] - '0' == 9)
                {
                    return -pow(2,31);
                }
                else if(!flag && s[0] - '0' >= 8)
                {
                    return pow(2,31) - 1;
                }
            }
            if (flag)
            {
                re = re * 10 - (s[0] - '0');
            }
            else
            {
                re = re * 10 + (s[0] - '0');
            }
            s.erase(s.begin());
        }
        return re;
    }
};

int main()
{
    string str = "42";
    cout << Solution().myAtoi(str) << endl;
    return 0;
}
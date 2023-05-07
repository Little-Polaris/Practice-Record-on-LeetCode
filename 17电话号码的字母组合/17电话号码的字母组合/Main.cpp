#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<int, vector<char>> m =
{
    {2, {'a', 'b', 'c'}},
    {3, {'d', 'e', 'f'}},
    {4, {'g', 'h', 'i'}},
    {5, {'j', 'k', 'l'}},
    {6, {'m', 'n', 'o'}},
    {7, {'p', 'q', 'r', 's'}},
    {8, {'t', 'u', 'v'}},
    {9, {'w', 'x', 'y', 'z'}}
};


class Solution {
public:
    vector<string> s;
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        {
            return s;
        }
        if (digits[0] >= '0' && digits[0] <= '9')
        {
            ;
        }
        else
        {
            s.push_back(digits);
            return s;
        }
        int num = digits[0] - '0';
        string t_s;
        digits.erase(digits.begin());
        for (auto it = digits.begin(); it != digits.end(); it++)
        {
            if (*it >= '2' && *it <= '9')
            {
                continue;
            }
            else
            {
                t_s.resize(digits.end() - it);
                copy(it, digits.end(), t_s.begin());
                digits.resize(it - digits.begin());
                break;
            }
        }
        auto v = m[num];
        for (auto it = v.begin(); it != v.end(); it++)
        {
            if (it != v.begin())
            {
                t_s.erase(t_s.end() - 1);
            }
            t_s.push_back(*it);
            letterCombinations(digits + t_s);
        }
        return s;
    }
};

int main()
{
    string str = "234";
    auto it = Solution().letterCombinations(str);
    for (auto i = it.begin(); i != it.end(); i++)
    {
        cout << *i << ' ';
    }
    return 0;
}
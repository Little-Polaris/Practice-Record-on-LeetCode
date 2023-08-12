#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> rv;
        vector<map<char, int>> vm;
        for (auto i : strs)
        {
            map<char, int> tm;
            for (auto j = i.begin(); j != i.end(); j++)
            {
                if (tm.find(*j) != tm.end())
                {
                    tm[*j]++;
                }
                else
                {
                    tm[*j] = 1;
                }
            }
            auto it = find(vm.begin(), vm.end(), tm);
            if (it != vm.end())
            {
                rv[it - vm.begin()].emplace_back(i);
            }
            else
            {
                vm.emplace_back(tm);
                rv.emplace_back();
                rv.back().emplace_back(i);
            }
        }
        return rv;
    }
};

int main()
{
    vector<string> vs = {"a"};
    auto rev = Solution().groupAnagrams(vs);
    for (auto i : rev)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
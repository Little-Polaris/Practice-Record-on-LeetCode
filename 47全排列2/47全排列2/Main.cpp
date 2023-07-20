#include <iostream>
#include <vector>
#include <set>

using namespace std;

//1,2,3

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 1) {
            return { {nums.front()} };
        }
        vector<vector<int>>rev;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            auto temp = nums;
            temp.erase(it - nums.begin() + temp.begin());
            auto rev_v = permuteUnique(temp);
            for (auto &i : rev_v) {
                i.emplace_back(*it);
            }
            rev.insert(rev.end(), rev_v.begin(), rev_v.end());
        }
        set<vector<int>>res(rev.begin(), rev.end());
        rev.resize(res.size());
        copy(res.begin(), res.end(), rev.begin());
        return rev;
    }
};

int main() {
    vector<int> v = { 1,3,2 };
    auto rev = Solution().permuteUnique(v);
    for (auto i : rev) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
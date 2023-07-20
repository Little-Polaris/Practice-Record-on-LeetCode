#include <iostream>
#include <vector>

using namespace std;

//1,2,3

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) {
            return { {nums.front()} };
        }
        vector<vector<int>>rev;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            auto temp = nums;
            temp.erase(it - nums.begin() + temp.begin());
            auto rev_v = permute(temp);
            for (auto &i : rev_v) {
                i.emplace_back(*it);
            }
            rev.insert(rev.end(), rev_v.begin(), rev_v.end());
        }
        return rev;
    }
};

int main() {
    vector<int> v = { 1 };
    auto rev = Solution().permute(v);
    for (auto i : rev) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (find(nums.begin(), nums.end(), 1) == nums.end()) {
            return 1;
        }
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (*it <= 0 || *it > nums.size()) {
                *it = 1;
            }
        }
        for (auto i : nums) {
            if (i == 1 || i == -1) {
                nums[0] = -abs(nums[0]);
            }
            else if (i > 0) {
                nums[i - 1] = -abs(nums[i - 1]);
            }
            else {
                nums[-i - 1] = -abs(nums[-i - 1]);
            }
        }
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (*it > 0) {
                return it - nums.begin() + 1;
            }
        }
        return -*(min_element(nums.begin(), nums.end())) + 1;
    }
};

int main() {
    vector<int> v = { 0,2,2,1,1 };
    cout << Solution().firstMissingPositive(v) << endl;
    return 0;
}
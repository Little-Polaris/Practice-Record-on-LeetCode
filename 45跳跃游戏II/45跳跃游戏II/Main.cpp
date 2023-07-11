#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int step = 0;
        int cur = 0;
        int next = 0;
        for (int i = 0; i < n; i++) {
            if (i > cur) {
                step++;
                cur = next;
            }
            next = max(next, i + nums[i]);
        }
        return step;
    }
};

int main() {
    vector<int> v = { 2,3,1,1,4};
    cout << Solution().jump(v) << endl;
    return 0;
}
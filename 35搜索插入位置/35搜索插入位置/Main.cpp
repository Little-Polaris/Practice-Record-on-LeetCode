#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
				right = mid;
			}
        }
        int mid = (left + right) >> 1;
        if (nums[mid] < target)
        {
			return mid + 1;
		}
        else
        {
			return mid;
		}
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    Solution sol;
    cout << sol.searchInsert(nums, target) << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return { -1,-1 };
        }
        int left = 0;
        int right = nums.size() - 1;
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
        while ((left > 0 && nums[left - 1] == target) || (right < nums.size() - 1 && nums[right + 1] == target))
        {
            if (left > 0 && nums[left - 1] == target)
            {
                left--;
            }
            if (right < nums.size() - 1 && nums[right + 1] == target)
            {
				right++;
			}
		}
        mid = (left + right) >> 1;
        if (nums[mid] != target)
        {
            return { -1,-1 };
        }
        return { left, right };
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> res = s.searchRange(nums, 6);
    for (auto i : res)
    {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
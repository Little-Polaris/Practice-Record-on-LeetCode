#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>v;
        if (nums.size() < 4)
        {
            return v;
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (auto it1 = nums.begin(); it1 != nums.end() - 3; it1++)//-2 -1 0 0 1 2
        {
            for (auto it2 = it1 + 1; it2 != nums.end() - 2; it2++)
            {
                int left = it2 - nums.begin() + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    long long temp = (long long)*it1 + *it2 + nums[left] + nums[right];
                    if (temp < target)
                    {
                        left++;
                    }
                    else if (temp > target)
                    {
                        right--;
                    }
                    else
                    {
                        s.insert(vector<int>({ *it1, *it2, nums[left], nums[right] }));
                        left++;
                        right--;
                    }
                }
            }
        }
        v.resize(s.size());
        copy(s.begin(), s.end(), v.begin());
        return v;
    }
};

int main()
{
    int target = 0;
    vector<int> v;
    int i = 1e9;
    v = { i,i,i,i };
    vector<vector<int>> answer = Solution().fourSum(v, target);
    for (auto it1 : answer)
    {
        for (auto it2 : it1)
        {
            cout << it2 << ' ';
        }
        cout << endl;
    }
    return 0;
}
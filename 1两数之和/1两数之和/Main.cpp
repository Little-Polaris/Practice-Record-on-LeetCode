#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(nums);
        sort(v.begin(), v.end());
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            if (find(v.begin(), v.end(), target - v[i]) != v.end() && find(v.begin(), v.end(), target - v[i]) - v.begin() != i)
            {
                break;
            }
        } 
        vector<int>v1;
        auto temp1 = find(nums.begin(), nums.end(), v[i]);
        v1.push_back(temp1 - nums.begin());
        auto temp2 = find(nums.begin(), nums.end(), target - v[i]);
        if (temp2 == temp1)
        {
            *temp2++;
        }
        temp2 = find(nums.begin(), nums.end(), target - v[i]);
        v1.push_back(temp2 - nums.begin());
        return v1;
    }
};

void print(int val)
{
    cout << val << ' ';
}

int main()
{
    vector<int>v;
    v.push_back(-1);
    v.push_back(-2);
    v.push_back(-3);
    v.push_back(-4);
    v.push_back(-5);
    v = Solution().twoSum(v, -8);
    for_each(v.begin(), v.end(), print);
    return 0;
}
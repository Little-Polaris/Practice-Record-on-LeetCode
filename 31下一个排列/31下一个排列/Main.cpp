#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (auto it = nums.end() - 1; it != nums.begin(); it--)
        {
            if (*it > *(it - 1))
            {
                for (auto it1 = nums.end() - 1; it1 != it - 1; it1--)
                {
                    if (*it1 > *(it - 1))
                    {
                        auto temp = *(it - 1);
                        *(it - 1) = *it1;
                        *it1 = temp;
                        sort(it, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};

int main()
{
    vector<int> v = { 1,3,2 };
    Solution().nextPermutation(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
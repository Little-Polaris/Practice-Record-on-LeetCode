#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        /*vector<vector<int>> rv;    
        if (nums.size() < 3)
        {
            return rv;
        }
        set<set<int>> s;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        set<int>s1;
                        s1.insert(nums[i]);
                        s1.insert(nums[j]);
                        s1.insert(nums[k]);
                        s.insert(s1);
                    }
                }
            }
        }
        vector<vector<int>>v;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            vector<int> tv;
            tv.resize((*it).size());
            copy((*it).begin(), (*it).end(), tv.begin());
            if (tv.size() == 2)
            {
                tv.push_back(-tv[0] - tv[1]);
            }
            else if (tv.size() == 1)
            {
                tv = { 0,0,0 };
            }
            v.push_back(tv);
        }
        return v;*/
        /*sort(nums.begin(), nums.end());
        auto re_nums = nums;
        reverse(re_nums.begin(), re_nums.end());
        int left = 0;
        int right = nums.size() - 1;
        set<set<int>>rs;
        while (left != right)
        {
            int temp = nums[left] + nums[right];
            if (temp >= 0)
            {
                auto it = find(nums.begin() + left + 1, nums.end() - (nums.size()  - right), -temp);
                if (it != nums.end() - (nums.size() - right))
                {
                    set<int> ts;
                    ts.insert(nums[left]);
                    ts.insert(nums[right]);
                    ts.insert(*it);
                    rs.insert(ts);
                }
                right--;
            }
            else
            {
                auto it = find(re_nums.begin() + (re_nums.size() - right), re_nums.end() - left - 1, -temp);
                if (it != re_nums.end() - left - 1)
                {
                    set<int>ts;
                    ts.insert(nums[left]);
                    ts.insert(nums[right]);
                    ts.insert(*it);
                    rs.insert(ts);
                }
                left++;
            }
        }
        vector<vector<int>> rv;
        for (auto it = rs.begin(); it != rs.end(); it++)
        {
            vector<int> tv;
            tv.resize((*it).size());
            copy((*it).begin(), (*it).end(), tv.begin());
            if (tv.size() == 1)
            {
                tv = { 0,0,0 };                
            }
            else if (tv.size() == 2)
            {
                tv.push_back(-tv[0] - tv[1]);              
            }           
            rv.push_back(tv);            
        }
        return rv;*/
        sort(nums.begin(), nums.end());
        int l0 = 0;
        int r0 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                l0 = i;
                break;
            }
        }
        vector<int> rn;
        rn.resize(nums.size());
        reverse_copy(nums.begin(), nums.end(), rn.begin());
        for (int i = 0; i < rn.size(); i++)
        {
            if (rn[i] <= 0)
            {
                r0 = rn.size() - i - 1;
                break;
            }
        }
        vector<vector<int>> rv;
        set<set<int>> rs;
        if (r0 - l0 >= 2 && nums[l0] == 0)
        {
            set<int> ts;
            ts.insert(0);
            rs.insert(ts);
        }
        for (int i = 0; i < l0; i++)
        {
            int left = nums[i];
            for (int j = nums.size() - 1; j > r0; j--)
            {
                int right = nums[j];
                int temp = -left - right;
                if (binary_search(nums.begin() + i + 1, nums.begin() + j, temp))
                {
                    set<int> ts;
                    ts.insert(left);
                    ts.insert(right);
                    ts.insert(temp);
                    rs.insert(ts);
                }
            }
        }
        for (auto it = rs.begin(); it != rs.end(); it++)
        {
            vector <int> tv;
            tv.resize((*it).size());
            copy((*it).begin(), (*it).end(), tv.begin());
            if (tv.size() == 1)
            {
                tv = { 0,0,0 };
            }
            else if (tv.size() == 2)
            {
                tv.push_back(-tv[0] - tv[1]);
            }
            rv.push_back(tv);
        }
        return rv;
    }
};

int main()
{
    vector<int> v = { -1,0,1,2,-1,-4,-2,-3,3,0,4 };//-4,-3,-2,-1,-1,0,0,1,2,3,4,
    //v = {1, 2, -2, -1};//-2,-1,1,2
    vector<vector<int>> vv = Solution().threeSum(v);
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int maximizeGreatness(vector<int>& nums) {
        int count = 0;
        vector<int>perm;
        perm.reserve(nums.size());
        vector<int>order(nums);
        sort(order.begin(), order.end());
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = order.begin();
            int left = 0, right = order.size() - 1;
            while (left < right - 1)
            {
                if (order[(left + right) / 2] > nums[i] + 1)
                {
                    right = (left + right) / 2;
                }
                else
                {
                    left = (left + right) / 2;
                }
            }
            it += left;
            while (it != order.end())
            {
                if (*it > nums[i])
                {
                    break;
                }
                it++;
            }
            if (it !=  order.end())
            {
                perm.push_back(*it);
            }
            else
            {
                perm.push_back(order[0]);
                it = order.begin();
            }
            order.erase(it);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < perm[i])
            {
                count++;
            }
        }
        return count;
    }
};

class Solution2 :
{
public:
    int maximizeGreatness(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        for (; j < nums.size(); j++)
        {
            if (nums[j] > nums[i])
            {
                i++;
            }
        }
        return i;
    }
}

int main()
{
    vector<int> v;
    /*int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }*/
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            v.push_back(i * 1000 + j);
        }
    }
    cout << Solution1().maximizeGreatness(v) << endl;
    return 0;
}
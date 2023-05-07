#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        nums1.resize(nums1.size() + nums2.size());
        copy(nums2.begin(), nums2.end(), nums1.begin() + size1);
        sort(nums1.begin(), nums1.end());
        int pos = nums1.size();
        if (pos % 2)
        {
            return nums1[pos / 2];  
        }
        else
        {
            return (double)(nums1[pos / 2] + nums1[pos / 2 - 1]) / 2;
        }
    }
};

int main()
{
    vector<int>v1 = { 1,3 };
    vector<int>v2 = { 2 };
    cout << Solution().findMedianSortedArrays(v1, v2) << endl;
    return 0;
}
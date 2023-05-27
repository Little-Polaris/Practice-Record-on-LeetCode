#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)
        {
            if (nums.front() == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] > nums[left])//{7,8,1,2,3,4,5,6}
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        if (nums[0] < nums.back())
        {
            left = 0;
            right = nums.size() - 1;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    return mid;
                }
            }
        }
        /*else if (target < nums.front() && target > nums.back())
        {
            return -1;
        }*/
        else if (nums[0] > target)
        {
            left++;
            right = nums.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
        }
        else
        {
            left = 0;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
        }
        if (left < nums.size() && nums[left] == target)
        {
            return left;
        }
        else if (right >= 0 && nums[right] == target)
        {
            return right;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    vector<int> v = { 2,1};
    clock_t start = clock();
    cout << Solution().search(v, 1) << endl;
    clock_t end = clock();
    cout << end - start << endl;
    return 0;
}
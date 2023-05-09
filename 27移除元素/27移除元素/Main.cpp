#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (*it == val)
            {
                it--;
                nums.erase(it + 1);
            }
        }
        return nums.size();
    }
};

int main()
{
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (auto it = nums.begin(); it != nums.end() - 1; it++)
        {
            if (*it == *(it + 1))
            {
                nums.erase(it+1);
                it--;
            }
        }
        return nums.size();
    }
};

int main()
{
	return 0;
}
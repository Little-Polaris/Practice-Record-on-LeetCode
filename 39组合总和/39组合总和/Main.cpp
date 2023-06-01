#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        combinationSum(candidates, target, result, 0, target);
        set<vector<int>> s(result.begin(), result.end());
        result.assign(s.begin(), s.end());
        if (result.front().empty())
        {
			result.erase(result.begin());
		}
        return result;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, vector<vector<int>>& result, int index, int original_target)
    {
        if (target == 0)
        {
			return result;
		}
        if (target < 0)
        {
            return {};
		}
        if (target == original_target)
        {
            result.push_back({});
        }
        for (int i = index; i < candidates.size(); i++)
        {            
			result.back().push_back(candidates[i]);                
            if (!combinationSum(candidates, target - candidates[i], result, i, original_target).empty())
            {
                result.push_back(vector<int>(result.back().begin(), result.back().end() - 1));
            }
            else
            {
				result.back().pop_back();
			}
		}
        return {};
	}
};

int main()
{
    Solution s;
    vector<int> v = {2,3,5};
    vector<vector<int>> result = s.combinationSum(v, 8);
    for (auto i : result)
    {
        for (auto j : i)
        {
			cout << j << " ";
		}
		cout << endl;
	}
    return 0;
}